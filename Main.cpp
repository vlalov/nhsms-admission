//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <dialogs.hpp>
#include "Main.h"
#include "DataModule.h"
#include "Library.h"
#include "Options.h"
#include "ReceptionRes.h"
#include "CurrentReceptionRes.h"
#include "AllReception.h"
#include "History.h"
#include "Login.h"
#include "RoomsUsage.h"
#include "RoomsUsageGraph.h"
#include "RoomChooser.h"
#include "GeneratePoints.h"
#include "ExamResultSearcher.h"
#include "ExamResultsRes.h"
#include "RegisterRes.h"
#include "RegisterSearcher.h"
#include "QuickRepPage.h"
#include "Classificate.h"
#include "HelpShow.h"
#include "OperatorTaxes.h"
#include "CheckEGN.h"
#include "ReceptionMap.h"
#include "BlankLoad.h"
#include "PrintBlanks.h"
#include "RoomUsageAuto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsPropSaver"
#pragma link "rsStorage"
//#pragma link "rsXmlData"
#pragma link "LMDBaseDialog"
#pragma link "LMDContainerComponent"
#pragma link "LMDCustomComponent"
#pragma link "LMDWindowListDlg"
#pragma link "CSPIN"
#pragma link "LMDAboutDlg"
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDControl"
#pragma link "LMDFill"
#pragma link "LMDGraphicControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomPanel"
#pragma link "LMDCustomStatusBar"
#pragma link "LMDStatusBar"
#pragma link "rsIniData"
#pragma resource "*.dfm"
#define MAXUSRHISTORY 10
// Shortcuts for datasets editing & movements
#define PREV 1
#define NEXT 10
#define FIRST 100
#define LAST 1000
#define DEL 5000
#define SAVE 10000


bool DEBUG;

//------------------
TMainForm *MainForm;
extern AnsiString Arguments;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
   : TForm(Owner)
{
 char dir[1000];
   Application->HintHidePause=10000;
   //GetWindowsDirectory(dir,1000);
   GetTempPath(1000,dir);
   //dir[3]='\0'; // get only the letter
   strcat(dir,"\\Reception.log");
   Arg=Arguments;
   if (AnsiPos("-debug",Arg)!=0) DEBUG=true;
   else DEBUG=false;
   if (AnsiPos("-help",Arg)!=0) {
      Application->MessageBox("USAGE:\n -help\t\tShow program parameters on start\
\n -debug\t\tProgram starts in debug mode (for advanced users only)\n -nolog\
\t\tDisable log generation (not recommended)\n -startXXXXX\tAdd offset in generated numbers, where XXXXX is the number\
\n -nofillholes\tIf there are holes in input numbers they are not filled when adding person\
\n -RA\t\tEnable Remote Administration\n -NCD\t\tThe date in person's report won't be the current","Command line options",MB_ICONINFORMATION|MB_OK);
   }
   if (AnsiPos("-nolog",Arg)!=0) {
      mainlog=new TLog(StrPas(dir),true);
   } else mainlog=new TLog(StrPas(dir));

   if (AnsiPos("-start",Arg)!=0) {
      strcpy(dir,Arg.c_str()+AnsiPos("-start",Arg)+5);
      startIndex=atoi(dir);
   } else startIndex=0;
   if (AnsiPos("-nofillholes",Arg)!=0) {
      NOFillHoles=true;
   } else NOFillHoles=false;

   if (AnsiPos("-RA",Arg)!=0) {
      RemoteAdminServer->Active=true;
   }
   if (AnsiPos("-NCD",Arg)!=0) {
      NCD=true;
   } else NCD=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetFont(TFont *Font) {
   MainForm->Font=Font;
   OptionsForm->Font=Font;
}
void __fastcall TMainForm::ShowProgress(AnsiString message,int current,int total) {
   if (total!=0)
      StatusBar1->Panels->Items[0]->Text=message+" "+String((current*100)/total)+"%";
   else {
    // total is 0
      if (current>0) {
         StatusBar1->Panels->Items[0]->Text=message;
         for (int x=1;x<=current;x++) {
            StatusBar1->Panels->Items[0]->Text=StatusBar1->Panels->Items[0]->Text+".";
         }
      } else {
         StatusBar1->Panels->Items[0]->Text=message;
      }
   }
   StatusBar1->Refresh();
}
void __fastcall TMainForm::ConnectToServer1Execute(TObject *Sender)
{
   //ShowMessage("Alias :SQLServer");
   if (LoginForm->Visible) return;
   try {
      StatusBar1->Panels->Items[0]->Text="Свързване...";
      LoginForm->Caption="Идентификация - "+Data->Database1->AliasName;
      if (Sender==NULL) {
         LoginForm->CancelBtn->Enabled=false;
         LoginForm->flag=true;
      } else {
         LoginForm->CancelBtn->Enabled=true;
         LoginForm->flag=false;
      }
      LoginForm->ShowModal();
      StatusBar1->Panels->Items[0]->Text="Моля, изчакайте докато връзката бъде осъществена...";
      StatusBar1->Refresh();
      if (LoginForm->Tag==-1) {
         StatusBar1->Panels->Items[0]->Text="";
         return;
      }
      Data->Database1->Params->Clear();
      Data->Database1->Params->Add("USER NAME="+LoginForm->UserNameEdit->Text);
      Data->Database1->Params->Add("PASSWORD="+LoginForm->PasswordEdit->Text);
      Data->Session1->Active=true;
      Data->Database1->Connected=true;
      StatusBar1->Panels->Items[0]->Text="Свързан";
      Data->NameQuery->Active=true;
      MainForm->Caption="Прием на НПМГ - "+Data->NameQuery->FieldByName("operator")->AsString;
      Application->Title=Data->NameQuery->FieldByName("operator")->AsString;
      Data->NameQuery->Active=false;
      if ((LoginForm->UserNameEdit->Items->Strings[0].LowerCase()!=LoginForm->UserNameEdit->Text.LowerCase())||
         (LoginForm->UserNameEdit->Items->Count==0))
         LoginForm->UserNameEdit->Items->Insert(0,LoginForm->UserNameEdit->Text);

      while (LoginForm->UserNameEdit->Items->Count>MAXUSRHISTORY) {
         LoginForm->UserNameEdit->Items->Delete(MAXUSRHISTORY);
      }

   } catch (Exception *e) {
      StatusBar1->Panels->Items[0]->Text="Грешка при свързването!";
      Data->Database1->Connected=false;
      mainlog->WriteException(e->Message);
      if (DEBUG) {
         Application->ShowException(e);
      } else {
         if (e->Message.AnsiPos("Unknown database.")!=0) {
            Application->MessageBox("Грешка при свързването! Моля, проверете DSN връзката (Настройки -> Параметри)!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            return;
         }
         if (e->Message.AnsiPos("Borland Database Engine")!=0) {
            Application->MessageBox("Грешка при инициализирането на BDE! Вероятно не е инсталиран?","ФАТАЛНА грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            Application->MessageBox("Намерена е фатална грешка! Програмата не може да продължи работата си!","ВНИМАНИЕ",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            Exit1Execute(NULL);
            return;
         }
         if (e->Message.AnsiPos("Specified SQL server not found")!=0||e->Message.AnsiPos("SQL Server does not exist")!=0) {
            Application->MessageBox("Грешка при свързването! Сървърът не е намерен!\nМоля, потърсете системния администратор!","Грешка при свързването",MB_ICONERROR|MB_APPLMODAL|MB_OK);
            return;
         }
         if (e->Message.AnsiPos("Unknown user name or password.")!=0) {
            Application->MessageBox("Потребителят или паролата са невалидни!","Грешка при свързването",MB_ICONERROR|MB_APPLMODAL|MB_OK);
            return;
         }
         Application->MessageBox("Грешка при свързването! Неизвестна грешка!\nМоля, потърсете системния администратор!","Грешка при свързването",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      }
      return;
   }
// Connection OK
   try {
      ConnectToServer1->Enabled=false;
      DisconnectFromServer1->Enabled=true;
      RefreshServer1->Enabled=true;
      Data->SetDataSets(true);
   } catch (Exception *ex) {
      if (DEBUG) {
         Application->ShowException(ex);
         mainlog->WriteException(ex->Message);
      } else {
         Application->MessageBox("Грешка при инициализирането на данните!\nМоля, потърсете системния администратор!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      }
   }
   if (TreeView->Selected!=NULL) {
      TreeViewChange(NULL,TreeView->Selected);
   } else {
      TreeViewChange(NULL,TreeView->Items->Item[6]);
      HelpShowForm->SetText(1);
   }
   mainlog->WriteString("User connected.");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DisconnectFromServer1Execute(TObject *Sender)
{
   Data->Database1->Connected=false;
   Data->Session1->Active=false;

   ConnectToServer1->Enabled=true;
   DisconnectFromServer1->Enabled=false;
   RefreshServer1->Enabled=false;
   StatusBar1->Panels->Items[0]->Text="";
   MainForm->Caption="Прием на НПМГ";
   Application->Title="Прием на НПМГ";
   TreeViewChange(NULL,NULL);
   mainlog->WriteString("User logged off");
   HelpShowForm->SetText(0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshServer1Execute(TObject *Sender)
{
   Data->SetDataSets(false);
   Data->SetDataSets(true);
   if (PageControl->ActivePage==PointsScoreTab) {
      RefreshExamsLookup();
   }
   if (PageControl->ActivePage==ResultTab) {
      //RefreshResultsLookup();
      ResultsExamLookupChange(NULL);
   }
   Data->NameQuery->Active=true;
   MainForm->Caption="Прием на НПМГ - "+Data->NameQuery->FieldByName("operator")->AsString;
   Application->Title=Data->NameQuery->FieldByName("operator")->AsString;
   Data->NameQuery->Active=false;
   mainlog->WriteString("Database refreshed.");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exit1Execute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   if (Data->Database1->Connected==true) {
      //if (Application->MessageBox("Сигурни ли сте, че искате да затворите програмата?","Внимание",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)==ID_YES) {
      Data->Database1->Connected=false;
      Data->Session1->Active=false;
      CanClose=true;
      //} else CanClose=false;
   } else CanClose=true;
   delete mainlog;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RefreshResultsLookup() {
 AnsiString temp;
   if (Data->Database1->Connected!=true) return;
   temp=ResultsExamLookup->Text;
   ResultsExamLookup->Items->Clear();
   ResultsExamLookup->Items->Add("Общ изпит");

   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      ResultsExamLookup->Items->Add(Data->ProfilesTable->FieldByName("Name")->AsString);
      Data->ProfilesTable->Next();
   }
   ResultsExamLookup->Text="Общ изпит";
  // ProfileLookupChange(NULL);
}
void __fastcall TMainForm::TreeViewChange(TObject *Sender, TTreeNode *Node)
{
   if (Data->Database1->Connected==true&&Node!=NULL) {
      if (Node->Text=="Такси") {
         InitializeTabs();
         PageControl->ActivePage=TaxesTab;
         return;
      }
      if (Node->Text=="Профили") {
         InitializeTabs();
         PageControl->ActivePage=ProfilesTab;
         return;
      }
      if (Node->Text=="Кандидати") {
         InitializeTabs();
         PageControl->ActivePage=ReceptionTab;
         return;
      }
      if (Node->Text=="Текстове") {
         InitializeTabs();
         PageControl->ActivePage=TextsTab;
         return;
      }
      if (Node->Text=="Сгради") {
         InitializeTabs();
         PageControl->ActivePage=PlacesTab;
         return;
      }
      if (Node->Text=="Точки<->Оценка") {
         InitializeTabs();
         PageControl->ActivePage=PointsScoreTab;
         if (Data->Database1->Connected==true) RefreshExamsLookup();
         return;
      }
      if (Node->Text=="Резултати от изпити") {
         InitializeTabs();
         PageControl->ActivePage=ResultTab;
         if (Data->Database1->Connected==true&&Data->ExamResultsQuery->Active!=true) RefreshResultsLookup();
         return;
      }
      if (Node->Text=="Класиране") {
         InitializeTabs();
         PageControl->ActivePage=ClassificateTab;
         return;
      }
      if (Node->Text=="Записване") {
         InitializeTabs();
         PageControl->ActivePage=RegisterTab;
         return;
      }
   }
   InitializeTabs();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InitializeTabs() {
   WelcomeTab->TabVisible=false;
   TaxesTab->TabVisible=false;
   ProfilesTab->TabVisible=false;
   ReceptionTab->TabVisible=false;
   TextsTab->TabVisible=false;
   PlacesTab->TabVisible=false;
   PointsScoreTab->TabVisible=false;
   ResultTab->TabVisible=false;
   RegisterTab->TabVisible=false;
   ClassificateTab->TabVisible=false;
   PageControl->ActivePage=WelcomeTab;
}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
   InitializeTabs();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddPerson1Execute(TObject *Sender)
{

   if (Data->Database1->Connected!=true) {
      if (LoginForm->Active==true) {
         LoginForm->OKBtnClick(NULL);
      }
      //ConnectToServer1Execute(NULL);
      //if (Data->Database1->Connected!=true)
      return;
   }
   if (PageControl->ActivePage==ResultTab) {
      if (this->ActiveControl==FkSearchEdit) {
         FkSearchBtnClick(NULL);
         return;
      }
      if (this->ActiveControl==ResultPIDEdit) {
         ResultsPIDBtnClick(NULL);
         return;
      }
      if (Data->ExamResultsQuery->State==dsEdit||Data->ExamResultsQuery->State==dsInsert) {
         Data->ExamResultsQuery->Post();
      } else {
         Data->ExamResultsQuery->Insert();
      }
      return;
   }
   if (PageControl->ActivePage!=ReceptionTab) return;
   if (this->Active!=true) return;
   if (this->ActiveControl==PersIDSearchEdit) {
      PersSearchBtnClick(NULL);
      return;
   }
   if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert) {
      SaveChangesExecute(this);
      return;
   }
   Data->PersonsQuery->Insert();
   Data->PersonsQueryPreferedSchool->AsBoolean=true; // default value
   MainForm->ActiveControl=PersNameEdit;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelUpdate1Execute(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      //ConnectToServer1Execute(NULL);
      //if (Data->Database1->Connected!=true)
      return;
   }
   if (PageControl->ActivePage==ResultTab) {
      if (this->Active==true) {
         Data->ExamResultsQuery->Cancel();
      }
   }
   if (PageControl->ActivePage==RegisterTab&&this->Active==true) {
      RegisterQuery->Cancel();
   }
   if (PageControl->ActivePage!=ReceptionTab) return;
   if (this->Active!=true) return;
   Data->PersonsQuery->Cancel();
   WishesQuery->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PersEGNEditExit(TObject *Sender)
{
 char str[12];
 // What's his/her sex?
   strcpy(str,PersEGNEdit->Text.c_str());
   if ((str[8]-'0')%2==0) {
    // Male
      if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
         Data->PersonsQuery->FieldByName("Sex")->AsInteger=1;
   } else {
      // Female
      if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
         Data->PersonsQuery->FieldByName("Sex")->AsInteger=0;
   }
   if (CheckEGN(PersEGNEdit->Text.c_str())!=true&&!PersEGNEdit->Text.IsEmpty()) {
      PersEGNEdit->Font->Color=clRed;
      Application->MessageBox("Въведеното ЕГН е НЕВАЛИДНО!","Внимание!",MB_OK|MB_ICONWARNING|MB_APPLMODAL);
   } else {
      PersEGNEdit->Font->Color=clWindowText;                                       
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WishesQueryAfterPost(TDataSet *DataSet)
{
 TQuery *pQuery;
 int id;
 TLocateOptions p;
 int prior;
   id=Data->PersonsQuery->FieldByName("ID")->AsInteger;

   pQuery=WishesUpdateSQL->Query[ukInsert];
   pQuery->ParamByName("ID")->AsInteger=id;

   pQuery=WishesUpdateSQL->Query[ukModify];
   pQuery->ParamByName("ID")->AsInteger=id;

   try {
      prior=WishesQuery->FieldByName("Priority")->AsInteger;
      WishesQuery->CommitUpdates();
      WishesQuery->Active=false;
      WishesQuery->Active=true;
      WishesQuery->Locate("Priority",prior,p);
   } catch (...) {
      WishesQuery->CancelUpdates();
      return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
   StatusBar1->Panels->Items[1]->Text=FormatDateTime("tt @ ddddd",Now());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N13Click(TObject *Sender)
{
   OptionsForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OlympCheckClick(TObject *Sender)
{
   OlympScoreEdit->Enabled=OlympCheck->Checked;
   GoToExamCheck->Enabled=OlympCheck->Checked;
   if (OlympCheck->Checked==false&&WishesQuery->Active==true) {
      try {
         WishesQuery->FieldByName("GoToExam")->AsBoolean=true;
         WishesQuery->FieldByName("OlympScore")->Clear();
      } catch (...) {};
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WishesQueryAfterScroll(TDataSet *DataSet)
{
   OlympCheckClick(NULL);
   WishesQueryAfterEdit(DataSet);
   if (MainForm->WishesQuery->Active==true)
      MainForm->WishesCountLabel->Caption="Желания: "+String(MainForm->WishesQuery->RecordCount);

   if (WishesQuery->Tag==1&&WishesQuery->RecordCount>0&&WishesQuery->FieldByName("FromOlymp")->AsBoolean==true) {
      if (WishesQuery->FieldByName("GoToExam")->AsBoolean==true)
         ReceptionResForm->GoToExamLabel->Caption="Да";
      else
         ReceptionResForm->GoToExamLabel->Caption="Не";
   } else ReceptionResForm->GoToExamLabel->Caption="";
   AllTaxQuery->Active=false;
   AllTaxQuery->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WishesQueryAfterInsert(TDataSet *DataSet)
{
   WishesQuery->FieldByName("FromOlymp")->AsBoolean=false;
   WishesQuery->FieldByName("GoToExam")->AsBoolean=true;
   WishesQuery->FieldByName("Priority")->AsInteger=WishesQuery->RecordCount+1;
   MainForm->ActiveControl=WishesProfileLookup;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddWish1Execute(TObject *Sender)
{
   //if (WishesPriorityLookup->Enabled!=true) return;
   //Data->CommitPersonsChanges();
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (PageControl->ActivePage!=ReceptionTab) return;
   if (this->Active!=true) return;
   try {
      if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
         Data->PersonsQuery->Post();
   } catch (...) {return;}
   WishesQuery->Append();
 // ---
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Preview1Execute(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (TextPrintCheck->Checked) {
      if (DoTextPreview()==1)
         return;
   }
 // Current Person in Reception
   if (PageControl->ActivePage==ReceptionTab) {
      CalcAllTaxQuery->Active=true;

      QuickRepEditorForm->SetPageValues(ReceptionResForm->QuickRep1);

      ReceptionResForm->ViewPreview();
      WishesQuery->Tag=0;
      CalcAllTaxQuery->Active=false;
   }
 // Exam Results
   if (PageControl->ActivePage==ResultTab) {
      ResolveProfileLookupCode(ResultsExamLookup->Text);
      if (ProfileLookupCode!=-1) {      // Даден е изпит
         ExamResultsResForm->OfficialQuery->Active=false;

         ExamResultsResForm->OfficialQuery->SQL->Clear();
         if (ProfileLookupCode!=0) {
          // първи изпит
            ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.GoToExam=1 AND w.Profile_ID=:SET_EXAM) \
AND EXISTS(SELECT * FROM ExamsResults ee WHERE ee.Exam=0 AND ee.Person_ID=p.ID AND ee.Score>=3) \
ORDER BY p.ID");
            ExamResultsResForm->OfficialQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
         } else {
          // първи изпит
            ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY p.ID");
         }

         ExamResultsResForm->OfficialQuery->Active=true;
         if (ResultsExamLookup->Text=="Общ изпит")
            ExamResultsResForm->ShowExamLabel2->Caption="Математика (общ)";
         else ExamResultsResForm->ShowExamLabel2->Caption=ResultsExamLookup->Text;
         QuickRepEditorForm->SetPageValues(ExamResultsResForm->OfficialQuickRep);
         ExamResultsResForm->OfficialQuickRep->Preview();
         ExamResultsResForm->OfficialQuery->Active=false;
      }
   }
 // Register Tab
   if (PageControl->ActivePage==RegisterTab) {
      N34Click(Sender);
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Print1Execute(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (TextPrintCheck->Checked) {
      if (DoTextPrint()==1)
         return;
   }
   if (PageControl->ActivePage==ReceptionTab) {
   // Reception Tab
      if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
        Data->PersonsQuery->Post();

      if (WishesQuery->State==dsEdit||WishesQuery->State==dsInsert)
        WishesQuery->Post();

      TaxShower->Font->Color=clRed; // turn the tax shower to red
      CalcAllTaxQuery->Active=true;

      QuickRepEditorForm->SetPageValues(ReceptionResForm->QuickRep1);

      ReceptionResForm->PrintReport();
      WishesQuery->Tag=0;
      CalcAllTaxQuery->Active=false;
   }
 // Exam Results
   if (PageControl->ActivePage==ResultTab) {
      ResolveProfileLookupCode(ResultsExamLookup->Text);
      if (ProfileLookupCode!=-1) {      // Даден е изпит
         ExamResultsResForm->OfficialQuery->Active=false;
         ExamResultsResForm->OfficialQuery->SQL->Clear();
         if (ProfileLookupCode!=0) {
            ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.Profile_ID=:SET_EXAM AND w.GoToExam=1) \
ORDER BY p.ID,er.ID ");
            ExamResultsResForm->OfficialQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
         } else {                      // Изпит по профил
            ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY p.ID,er.ID ");
         }
         ExamResultsResForm->OfficialQuery->Active=true;
         if (ResultsExamLookup->Text=="Общ изпит")
            ExamResultsResForm->ShowExamLabel2->Caption="Математика (общ)";
         else ExamResultsResForm->ShowExamLabel2->Caption=ResultsExamLookup->Text;
         QuickRepEditorForm->SetPageValues(ExamResultsResForm->OfficialQuickRep);
         
         ExamResultsResForm->OfficialQuickRep->Print();
         ExamResultsResForm->OfficialQuery->Active=false;
      }
   }
 // Register Tab
   if (PageControl->ActivePage==RegisterTab) {
      N34Click(NULL);
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N19Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   CurrentReceptionResForm->DataQuery->Active=false;
   CurrentReceptionResForm->DataQuery->Active=true;
   CurrentReceptionResForm->CalcAllTaxQuery->Active=false;
   CurrentReceptionResForm->CalcAllTaxQuery->Active=true;
   CurrentReceptionResForm->DeletedWishesQuery->Active=false;
   CurrentReceptionResForm->DeletedWishesQuery->Active=true;
   if (TextPrintCheck->Checked) {
      DoTextPreview(1);
   } else CurrentReceptionResForm->QuickRep1->Preview();

   CurrentReceptionResForm->CalcAllTaxQuery->Active=false;
   CurrentReceptionResForm->DeletedWishesQuery->Active=false;
   CurrentReceptionResForm->DataQuery->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N20Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   AllReceptionForm->Show();
}

void __fastcall TMainForm::N21Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   HistoryForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N22Click(TObject *Sender)
{
   LMDWindowListDlg1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N23Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   //Application->CreateForm(__classid(TRoomsUsageForm), &RoomsUsageForm);
   /*
   RoomsUsageForm->RoomsAllocatedQuery->Active=true;
   RoomsUsageForm->QuickRep1->Preview();
   RoomsUsageForm->RoomsAllocatedQuery->Active=false;
   */
   RoomUsageAutoForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N25Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
//   Application->CreateForm(__classid(TRoomsUsageGraphForm), &RoomsUsageGraphForm);
   RoomsUsageGraphForm->RoomsAllocatedQuery->Active=true;
   RoomsUsageGraphForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N26Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
//   Application->CreateForm(__classid(TRoomChooserForm), &RoomChooserForm);
//   Application->CreateForm(__classid(TRoomProtocolResForm), &RoomProtocolResForm);
   RoomChooserForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PointsToScoreQueryAfterPost(TDataSet *DataSet)
{
 TQuery *pQuery;
   if (Data->Database1->Connected!=true) return;
   if (ProfileLookup->Text.IsEmpty()) {
      PointsToScoreQuery->CancelUpdates();
      return;
   }
   ResolveProfileLookupCode(ProfileLookup->Text);
   if (ProfileLookupCode<0)  {
      PointsToScoreQuery->CancelUpdates();
      return;
   }
   pQuery=PointsToScoreUpdateSQL->Query[ukInsert];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=ProfileLookupCode;

   pQuery=PointsToScoreUpdateSQL->Query[ukModify];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=ProfileLookupCode;

   pQuery=PointsToScoreUpdateSQL->Query[ukDelete];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=ProfileLookupCode;

   try {
      PointsToScoreQuery->CommitUpdates();
   } catch(...) {
      PointsToScoreQuery->CancelUpdates();
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RefreshExamsLookup() {
 AnsiString temp;
   if (Data->Database1->Connected!=true) return;
   temp=ProfileLookup->Text;
   ProfileLookup->Items->Clear();
   ProfileLookup->Items->Add("Общ изпит");

   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      ProfileLookup->Items->Add(Data->ProfilesTable->FieldByName("Name")->AsString);
      Data->ProfilesTable->Next();
   }
   ProfileLookup->Text="Общ изпит";
   ProfileLookupChange(NULL);
}
void __fastcall TMainForm::ResolveProfileLookupCode(AnsiString text) {
   if (Data->Database1->Connected!=true) return;
   if (text=="Общ изпит") {
      ProfileLookupCode=0;
      return;
   }
   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      if (text==Data->ProfilesTable->FieldByName("Name")->AsString) {
         ProfileLookupCode=Data->ProfilesTable->FieldByName("ID")->AsInteger;
         return;
      }
      Data->ProfilesTable->Next();
   }
   ProfileLookupCode=-1;
}
void __fastcall TMainForm::ProfileLookupChange(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   ResolveProfileLookupCode(ProfileLookup->Text);
   PointsToScoreQuery->Active=false;
   PointsToScoreQuery->ParamByName("SET_PROF")->AsInteger=ProfileLookupCode;
   PointsToScoreQuery->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearPoints() {
   ResolveProfileLookupCode(ProfileLookup->Text);
   WorkQuery->SQL->Clear();
   WorkQuery->SQL->Add("DELETE FROM PointsToScore WHERE Profile_ID="+String(ProfileLookupCode));
   WorkQuery->ExecSQL();
   ProfileLookupChange(NULL);
}
void __fastcall TMainForm::ClearPointsBtnClick(TObject *Sender)
{
   ResolveProfileLookupCode(ProfileLookup->Text);
   if (Data->Database1->Connected!=true) return;
   if (ProfileLookup->Text.IsEmpty()||ProfileLookupCode<0) {
      return;
   }
   if (Application->MessageBox("Сигурни ли сте, че искате да изтриете всички записи за текущият изпит?","Внимание",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)!=IDYES)
      return;
   ClearPoints();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GenerateBtnClick(TObject *Sender)
{
   ResolveProfileLookupCode(ProfileLookup->Text);
   if (Data->Database1->Connected!=true) return;
   if (ProfileLookup->Text.IsEmpty()||ProfileLookupCode<0) {
      return;
   }
   if (Application->MessageBox("Текущите стойности ще бъдат изтрити!","Внимание",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)!=IDYES)
      return;
//   Application->CreateForm(__classid(TGeneratePointsForm), &GeneratePointsForm);
   GeneratePointsForm->Tag=ProfileLookupCode;
   GeneratePointsForm->Show();
   ProfileLookupChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ProfileLookupDropDown(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ResultsExamLookup->Items->Clear();
      return;
   }
   RefreshExamsLookup();
   ResolveProfileLookupCode(ProfileLookup->Text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResultsExamLookupChange(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   ResolveProfileLookupCode(ResultsExamLookup->Text);
   Data->ExamResultsQuery->Active=false;
   Data->ExamResultsQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
   Data->ExamResultsQuery->Active=true;

   MainForm->PointsToScoreQuery->Active=false;
   MainForm->PointsToScoreQuery->ParamByName("SET_PROF")->AsInteger=MainForm->ProfileLookupCode;
   MainForm->PointsToScoreQuery->Active=true;
   if (PointsToScoreQuery->RecordCount==0) {
      ERExamResultsGrid->Columns->Items[3]->ReadOnly=true;
      ERExamResultsGrid->Columns->Items[3]->Visible=false;
      Application->MessageBox("Няма въведено отношение Точки-Оценка за изпита!","Информация",MB_ICONINFORMATION|MB_OK|MB_APPLMODAL);
   } else {
      ERExamResultsGrid->Columns->Items[3]->ReadOnly=false;
      ERExamResultsGrid->Columns->Items[3]->Visible=true;
   }
   MainForm->PointsToScoreQuery->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResultsExamLookupDropDown(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ResultsExamLookup->Items->Clear();
      return;
   }
   RefreshResultsLookup();
}
//---------------------------------------------------------------------------

void DoMove(TDataSet* target,int movetype) {
   switch (movetype) {
     case PREV: target->Prior();
     break;
     case NEXT: target->Next();
     break;
     case FIRST: target->First();
     break;
     case LAST: target->Last();
     break;
     case DEL:
      if (Application->MessageBox("Сигурни ли сте, че искате да изтриете записа?","Изтриване",MB_APPLMODAL|MB_YESNO|MB_ICONQUESTION)!=ID_YES)
         return;
      target->Delete();
     break;
   }
}
void __fastcall TMainForm::MoveInDataSets(int movetype) {
   if (Data->Database1->Connected!=true) return;
   if (!this->Active) return;
 // Persons editing (Data->PersonsQuery)
   if (this->ActiveControl==PersNameEdit||this->ActiveControl==PersEGNEdit||
    this->ActiveControl==PersSexEdit||this->ActiveControl==PersTaxEdit||this->ActiveControl==PersTelEdit||
    this->ActiveControl==PersAddrEdit||this->ActiveControl==PersRoomView||this->ActiveControl==GroupBox1) {
      if (movetype!=SAVE) {
         if (movetype!=DEL)
            DoMove(Data->PersonsQuery,movetype);
      } else {
         if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
            Data->PersonsQuery->Post();
      }
   }
 // Wishes editing (WishesQuery)
   if (this->ActiveControl==WishesPriorityLookup||this->ActiveControl==WishesProfileLookup||
    this->ActiveControl==WishesScoreEdit||this->ActiveControl==OlympCheck||this->ActiveControl==OlympScoreEdit||
    this->ActiveControl==GoToExamCheck||this->ActiveControl==WishesDBGrid) {
      if (movetype!=SAVE) {
        DoMove(WishesQuery,movetype);
      } else {
         if (WishesQuery->State==dsEdit||WishesQuery->State==dsInsert&&!WishesQuery->FieldByName("Profile_ID")->IsNull)
            WishesQuery->Post();
      }
   }
 // ExamResults editing (Data->ExamResultsQuery)
   if (this->ActiveControl==ERExamResultsGrid||this->ActiveControl==ResultsExamLookup) {
      if (movetype!=SAVE) {
         DoMove(Data->ExamResultsQuery,movetype);
      } else {
         if (Data->ExamResultsQuery->State==dsEdit||Data->ExamResultsQuery->State==dsInsert)
            Data->ExamResultsQuery->Post();
      }
   }
 // Register editing (RegisterQuery)
   if (this->ActiveControl==RegisterDBGrid||this->ActiveControl==RegisterProfileCombo) {
      if (movetype==SAVE&&RegisterQuery->State==dsEdit) {
         RegisterQuery->Post();
      }
   }
}
void __fastcall TMainForm::PrevRecordExecute(TObject *Sender)
{
   MoveInDataSets(PREV);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NextRecordExecute(TObject *Sender)
{
   MoveInDataSets(NEXT);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FirstRecordExecute(TObject *Sender)
{
   MoveInDataSets(FIRST);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LastRecordExecute(TObject *Sender)
{
   MoveInDataSets(LAST);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteRecordExecute(TObject *Sender)
{
   MoveInDataSets(DEL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveChangesExecute(TObject *Sender)
{
   MoveInDataSets(SAVE);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ERExamResultsGridColExit(TObject *Sender)
{
   if (Data->ExamResultsQuery->FieldByName("Points")->IsNull) return;
   if (!Data->ExamResultsQuery->FieldByName("Score")->IsNull) return;
   if (Data->ExamResultsQuery->State!=dsEdit&&Data->ExamResultsQuery->State!=dsInsert) return;
   Data->ResolvePointsToScore();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
   StatusBar1Resize(this);
   if (OptionsForm->AutoLogOnCheck->Checked) {
      ConnectToServer1Execute(NULL);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersSearchBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (Data->PersonsQuery->Active!=true) return;
   Data->PersonsQuery->Locate("ID",PersIDSearchEdit->Value,p);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WishesQueryAfterEdit(TDataSet *DataSet)
{
   if (WishesQuery->FieldByName("FromOlymp")->AsBoolean==true) {
//      WishesQuery->FieldByName("OlympScore")->ReadOnly=false;
//      WishesQuery->FieldByName("GoToExam")->ReadOnly=false;
      WishesDBGrid->Columns->Items[4]->ReadOnly=false;
      WishesDBGrid->Columns->Items[5]->ReadOnly=false;
   } else {
//      WishesQuery->FieldByName("OlympScore")->ReadOnly=true;
//      WishesQuery->FieldByName("GoToExam")->ReadOnly=true;
      WishesDBGrid->Columns->Items[4]->ReadOnly=true;
      WishesDBGrid->Columns->Items[5]->ReadOnly=true;
   }
   //ShowMessage("Changed to "+String((short)WishesDBGrid->Columns->Items[4]->ReadOnly));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersIDSearchEditKeyPress(TObject *Sender,
      char &Key)
{
   if (Key=='\r') {
      PersSearchBtnClick(NULL);
      this->ActiveControl=PersNameEdit;
      Key='\0';
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WishesDBGridColExit(TObject *Sender)
{
   WishesQueryAfterEdit(WishesQuery);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N28Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
//   Application->CreateForm(__classid(TExamsResultSearcherForm), &ExamsResultSearcherForm);
//   Application->CreateForm(__classid(TExamStatsGraphForm), &ExamStatsGraphForm);
   ExamsResultSearcherForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N29Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (ResultsExamLookup->Text.IsEmpty()) {
      Application->MessageBox("Моля, изберете изпит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      PageControl->ActivePage=ResultTab;
      this->ActiveControl=ResultsExamLookup;
      return;
   }
   ResolveProfileLookupCode(ResultsExamLookup->Text);
   if (ProfileLookupCode!=-1) {      // Даден е изпит
      ExamResultsResForm->MainQuery->Active=false;
      ExamResultsResForm->MainQuery->SQL->Clear();
      if (ProfileLookupCode!=0) {
         ExamResultsResForm->MainQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.Profile_ID=:SET_EXAM AND w.GoToExam=1) \
ORDER BY p.ID,er.ID ");
         ExamResultsResForm->MainQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
      } else {                      // Изпит по профил
         ExamResultsResForm->MainQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY p.ID,er.ID ");
      }
      ExamResultsResForm->MainQuery->Active=true;
      ExamResultsResForm->ExamShowLabel->Caption=ResultsExamLookup->Text;
      ExamResultsResForm->QuickRep1->Preview();
      ExamResultsResForm->MainQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N31Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (ResultsExamLookup->Text.IsEmpty()) {
      Application->MessageBox("Моля, изберете изпит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      PageControl->ActivePage=ResultTab;
      this->ActiveControl=ResultsExamLookup;
      return;
   }
   ResolveProfileLookupCode(ResultsExamLookup->Text);
   if (ProfileLookupCode!=-1) {      // Даден е изпит
      ExamResultsResForm->CurrentQuery->Active=false;
      ExamResultsResForm->CurrentQuery->SQL->Clear();
      if (ProfileLookupCode!=0) {
         ExamResultsResForm->CurrentQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.Profile_ID=:SET_EXAM AND w.GoToExam=1) \
ORDER BY er.ID,p.ID ");
         ExamResultsResForm->CurrentQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
      } else {                      // Изпит по профил
         ExamResultsResForm->CurrentQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY er.ID,p.ID ");
      }
      ExamResultsResForm->CurrentQuery->Active=true;
      ExamResultsResForm->QRCurrentShow->Caption=ResultsExamLookup->Text;
      ExamResultsResForm->CurrentQuickRep->Preview();
      ExamResultsResForm->CurrentQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SearchPersonIDExecute(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   MainForm->Show();
   PageControl->ActivePage=ReceptionTab;
   ActiveControl=PersIDSearchEdit;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClassificateClearBtnClick(TObject *Sender)
{
 AnsiString p;
 TDateTime start,end;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (Sender!=NULL)
   if (Application->MessageBox("Сигурни ли сте, че искате да изтриете ЦЯЛОТО класиране?","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)!=ID_YES)
      return;
   MainForm->StatusBar1->Panels->Items[0]->Text="Изтриване на приема...";
   start=Now();
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("DELETE FROM Register");
   ClassificateClearBtn->Enabled=false;
   ClassificateBtn->Enabled=false;
   ScndClassificateBtn->Enabled=false;

   Data->RegisterNumQuery->Active=true;
   if (Sender==NULL) {
      Data->RegisterNumQuery->Edit();
      Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger=1;
      Data->RegisterNumQuery->Post();
      Data->RegisterNumQuery->CommitUpdates();
   } else {
      if (Data->RegisterNumQuery->RecordCount>0) {
         Data->RegisterNumQuery->Delete();
         Data->RegisterNumQuery->CommitUpdates();
      }
   }
   Data->RegisterNumQuery->Active=false;

   try {
      Data->SingleQuery->ExecSQL();
   } catch (Exception *e) {
      Application->ShowException(e);
      ClassificateClearBtn->Enabled=true;
   }

   ClassificateClearBtn->Enabled=true;
   ClassificateBtn->Enabled=true;
   ScndClassificateBtn->Enabled=true;

   end=Now();
   start=end-start;
   MainForm->ShowProgress("Изтриването завършено ("+FormatDateTime("hh:nn:ss.z",start)+")",0,0);
   if (Sender!=NULL) {
      p.printf("Изтрити бяха %d записа.",Data->SingleQuery->RowsAffected);
      Application->MessageBox(p.c_str(),"Информация",MB_ICONINFORMATION|MB_APPLMODAL|MB_OK);
   }
   MessageBeep(MB_OK);
   MessageBeep(0xFFFFFFFF);
}
//---------------------------------------------------------------------------
/*
==================================================================================================
                                       Register Tab
==================================================================================================
*/

void __fastcall TMainForm::ClassificateBtnClick(TObject *Sender)
{
 int id;
 TLocateOptions p;
 int flag=0;
 TClassificate *firstclassificate;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }

   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("SELECT * FROM Register");
   Data->SingleQuery->Active=true;
   if (Data->SingleQuery->RecordCount>0) flag=1;
   if (flag==1) {
      Data->SingleQuery->Active=false;
      Data->SingleQuery->SQL->Clear();
      Data->SingleQuery->SQL->Add("SELECT * FROM Register WHERE IsIn=1");
      Data->SingleQuery->Active=true;
      if (Data->SingleQuery->RecordCount>0) flag=2;
   }
   switch (flag) {
     case 1:
      if (Application->MessageBox("Вече има направено класиране.\nИскате ли то да бъде изтрито?","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)!=ID_YES)
         return;
     break;
     case 2:
      if (Application->MessageBox("Вече има направено класиране.\nИскате ли то да бъде изтрито?\n\n\nНамерени са записани кандидати!","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)!=ID_YES)
         return;
      if (Application->MessageBox("Моля, направете копие на данните!","В Н И М А Н И Е",MB_ICONHAND|MB_SYSTEMMODAL|MB_OKCANCEL|MB_DEFBUTTON2)!=ID_OK)
         return;
     break;
   }
   Data->SingleQuery->Active=false;
   ClassificateClearBtnClick(NULL);

   id=Data->PersonsQuery->FieldByName("ID")->AsInteger;
   Data->PersonsQuery->Active=false;
   Data->PersonsQuery->Active=true;
   ClassificateBtn->Enabled=false;
   try {
      firstclassificate=new TClassificate(true);
      MainForm->Tag=1;
      firstclassificate->FreeOnTerminate=true;
      firstclassificate->Priority=tpLowest;
      ClassificateBtn->Enabled=false;
      ClassificateClearBtn->Enabled=false;
      ScndClassificateBtn->Enabled=false;
      firstclassificate->Resume();
   } catch (Exception *e) {
      ClassificateBtn->Enabled=true;
      ClassificateClearBtn->Enabled=true;
      Application->ShowException(e);
   }
   //delete firstclassificate;

   //ClassificateBtn->Enabled=true;
   Data->PersonsQuery->Locate("ID",id,p);
   /*
   ClassificateBtn->Enabled=true;
   ClassificateClearBtn->Enabled=true;
   ScndClassificateBtn->Enabled=true;
   */
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterProfileComboCloseUp(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (RegisterProfileCombo->KeyValue.IsNull()) return;
   Data->ProfilesTable->Locate("ID",RegisterProfileCombo->KeyValue,p);
   RegisterMaleRadio->Enabled=Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean;
   RegisterFemaleRadio->Enabled=Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean;

   index=1;
   RegisterQuery->Active=false;
   RegisterQuery->SQL->Clear();
   RegisterQuery->SQL->Add("SELECT r.*,p.Sex FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID \
WHERE Profile_ID=:SET_PROFILE ");
   if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean) {
      RegisterQuery->SQL->Add(" AND p.Sex="+String((int)RegisterMaleRadio->Checked));
   }
   RegisterQuery->SQL->Add(" ORDER BY Classificated DESC,Profile_ID,Amount DESC,Person_ID ");
   RegisterQuery->ParamByName("SET_PROFILE")->AsInteger=RegisterProfileCombo->KeyValue;
   RegisterQuery->Active=true;
   //---------- delmeQuery
   delmeQuery->Active=false;
   delmeQuery->SQL->Clear();
   //---------- generating SQL...
   delmeQuery->SQL->Add("SELECT TOP 1 r.amount,count(*) counter,inline1.amount inl_amount,inline1.cnt notcl FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID, \
(SELECT TOP 1 r.amount,count(*) cnt FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID \
WHERE Profile_ID=:SET_PROFILE AND classificated=0 ");
   if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean) {
      delmeQuery->SQL->Add(" AND p.Sex="+String((int)RegisterMaleRadio->Checked));
   }
   delmeQuery->SQL->Add(" GROUP BY r.amount ORDER BY Amount DESC) inline1 \
WHERE Profile_ID=:SET_PROFILE AND classificated=1 ");
    if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean) {
      delmeQuery->SQL->Add(" AND p.Sex="+String((int)RegisterMaleRadio->Checked));
   }
   delmeQuery->SQL->Add(" GROUP BY r.amount, inline1.cnt,inline1.amount ORDER BY r.Amount");

   delmeQuery->ParamByName("SET_PROFILE")->AsInteger=RegisterProfileCombo->KeyValue;
   delmeQuery->Active=true;

   //---------- status
   if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean)
      StatusBar1->Panels->Items[0]->Text=RegisterProfileCombo->Text+" ("+
      ((RegisterMaleRadio->Checked)?"младежи":"девойки")+")";
   else StatusBar1->Panels->Items[0]->Text=RegisterProfileCombo->Text;
   StatusBar1->Panels->Items[0]->Text=StatusBar1->Panels->Items[0]->Text+": "+String(RegisterQuery->RecordCount);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterPersSearchBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (RegisterProfileCombo->KeyValue.IsNull()) return;
   if (RegisterQuery->Active!=true) return;
   RegisterQuery->Locate("Person_ID",RegisterPersIDSearch->Value,p);
   this->ActiveControl=RegisterDBGrid;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterPersIDSearchKeyPress(TObject *Sender,
      char &Key)
{
   if (Key=='\r') {
      RegisterPersSearchBtnClick(NULL);
      Key='\0';
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterQueryAfterPost(TDataSet *DataSet)
{
   if (Data->Database1->Connected!=true) return;
   try {
      try {
         RegisterQuery->CommitUpdates();
      } catch (...) {
         ShowMessage("Грешка при записването!");
         RegisterQuery->CancelUpdates();
      }
   } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ScndClassificateBtnClick(TObject *Sender)
{
 TLocateOptions p;
 int id;
 TClassificate *secondclassificate;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   //return;
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("SELECT * FROM Register");
   Data->SingleQuery->Active=true;
   if (Data->SingleQuery->RecordCount==0) {
      Application->MessageBox("Няма класирани кандидати.\nМоля, използвайте 'Първо Класиране'!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      return;
   }
 // Checking whether numbers of IsIns are no more than entered free space...
 int desired;
 AnsiString text;
 bool flag=false;
   Data->ProfilesTable->First();
   Data->CheckIsInQuery->Active=true;
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean==false) {
         desired=Data->CheckIsInQuery->FieldByName("male")->AsInteger+Data->CheckIsInQuery->FieldByName("female")->AsInteger;
         if (desired>Data->ProfilesTable->FieldByName("Space")->AsInteger) {
            text.printf("Записаните кандидати са повече от обявените места!\nПрофил:\t\t%s\nЗаписани:\t%d\nОбявени места:\t%d",Data->ProfilesTable->FieldByName("Name")->AsString,desired,Data->ProfilesTable->FieldByName("Space")->AsInteger);
            flag=true;
            Application->MessageBox(text.c_str(),"Грешка при инициализиране на кланирането",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            break;
         }
      } else {
         if (Data->CheckIsInQuery->FieldByName("male")->AsInteger>Data->ProfilesTable->FieldByName("SpaceOther")->AsInteger) {
            text.printf("Записаните кандидати са повече от обявените места!\nПрофил:\t\t%s (младежи)\nЗаписани:\t%d\nОбявени места:\t%d",Data->ProfilesTable->FieldByName("Name")->AsString,Data->CheckIsInQuery->FieldByName("male")->AsInteger,Data->ProfilesTable->FieldByName("SpaceOther")->AsInteger);
            flag=true;
            Application->MessageBox(text.c_str(),"Грешка при инициализиране на кланирането",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            break;
         }
         if (Data->CheckIsInQuery->FieldByName("female")->AsInteger>Data->ProfilesTable->FieldByName("SpaceW")->AsInteger) {
            text.printf("Записаните кандидати са повече от обявените места!\nПрофил:\t\t%s (девойки)\nЗаписани:\t%d\nОбявени места:\t%d",Data->ProfilesTable->FieldByName("Name")->AsString,Data->CheckIsInQuery->FieldByName("female")->AsInteger,Data->ProfilesTable->FieldByName("SpaceW")->AsInteger);
            flag=true;
            Application->MessageBox(text.c_str(),"Грешка при инициализиране на кланирането",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            break;
         }
      }
      Data->ProfilesTable->Next();
   }
   Data->ProfilesTable->First();
   Data->CheckIsInQuery->Active=false;
   if (flag==true) {
      Application->MessageBox("Създаването на следващо класиране е прекратено!\nТекущото класиране не е променено.","Прием на НПМГ - Следващо класиране",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
      return;
   }
 // -----------------
   Data->SingleQuery->Active=false;
   id=Data->PersonsQuery->FieldByName("ID")->AsInteger;
   Data->PersonsQuery->Active=false;
   Data->PersonsQuery->Active=true;
   try {
      secondclassificate=new TClassificate(true);
      MainForm->Tag=2;
      secondclassificate->FreeOnTerminate=true;
      secondclassificate->Priority=tpLowest;
      ClassificateBtn->Enabled=false;
      ClassificateClearBtn->Enabled=false;
      ScndClassificateBtn->Enabled=false;

      secondclassificate->Resume();
   } catch (Exception *e) {
      Application->ShowException(e);
      ClassificateBtn->Enabled=true;
      ClassificateClearBtn->Enabled=true;
      ScndClassificateBtn->Enabled=true;
   }
   Data->PersonsQuery->Locate("ID",id,p);
   /*
   ClassificateBtn->Enabled=true;
   ClassificateClearBtn->Enabled=true;
   ScndClassificateBtn->Enabled=true;
   */
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11Click(TObject *Sender)
{
   //ShowMessage("И това ще стане! Сега нямам време да пиша Help.");
   Application->HelpCommand(HELP_CONTENTS,0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ODBC1Click(TObject *Sender)
{
 char dir[1000];
   GetSystemDirectory(dir,1000);
   strcat(dir,"\\ODBCAD32.exe");
   if (WinExec(dir,0)<31) {
      Application->MessageBox("Грешка при стартирането на ODBC Администратора!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SexTypeBtnClick(TObject *Sender)
{
   if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
      PersEGNEditExit(Sender);
   else {
      Data->PersonsQuery->Edit();
      PersEGNEditExit(Sender);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N34Click(TObject *Sender)
{
 int classificate_num;
 bool last=false;
 AnsiString text;
 bool includePrefered=false;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   this->PageControl->ActivePage=RegisterTab;
   if (RegisterProfileCombo->KeyValue.IsNull()) {
      Application->MessageBox("Моля, изберете профил и пол!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      return;
   }
   Data->RegisterNumQuery->Active=true;
   try {
      classificate_num=Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger;
   } catch (...) {
      classificate_num=0;
   }
/*
// not used in practic, so removed
   if (classificate_num>2) {
      if (Application->MessageBox("Искате ли краен протокол (крайно класиране)?","Прием на НПМГ",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)==ID_YES) {
         last=true;
      }
   }
*/
   if (classificate_num==0) {
      Application->MessageBox("Няма направено класиране!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      return;
   }
   switch (Application->MessageBox("Желаете ли да бъде добавена информация за предпочитанието на кандидата?","Протокол за изпит",MB_YESNOCANCEL|MB_APPLMODAL|MB_ICONQUESTION|MB_DEFBUTTON2)) {
      case IDYES:
         includePrefered=true;
      break;
      case IDNO:
         includePrefered=false;
      break;
      default:
         Data->RegisterNumQuery->Active=false;
         return;
   }

   text=RegisterProfileCombo->Text;
   if (RegisterMaleRadio->Enabled&&RegisterFemaleRadio->Enabled) {
      if (RegisterMaleRadio->Checked)
         text=text+" (младежи)";
      else
         text=text+" (девойки)";
   }
//   Application->CreateForm(__classid(TRegisterResForm), &RegisterResForm);
   // setting includePrefered flag...
   RegisterResForm->QRPrefered->Enabled=includePrefered;
   if (last==false) {
      switch (classificate_num) {
        case 1: RegisterResForm->PageHeaderText->Caption="Първо класиране по "+text;
        break;
        case 2: RegisterResForm->PageHeaderText->Caption="Второ класиране по "+text;
        break;
        case 3: RegisterResForm->PageHeaderText->Caption="Трето класиране по "+text;
        break;
        case 4: RegisterResForm->PageHeaderText->Caption="Четвърто класиране по "+text;
        break;
        case 5: RegisterResForm->PageHeaderText->Caption="Пето класиране по "+text;
        break;
        case 6: RegisterResForm->PageHeaderText->Caption="Шесто класиране по "+text;
        break;
      }

   } else {
      RegisterResForm->PageHeaderText->Caption="Крайно класиране по "+text;
   }
   RegisterResForm->Classificated10Query->Active=false;
   RegisterResForm->Classificated10Query->ParamByName("SET_PROFILE")->AsInteger=RegisterProfileCombo->KeyValue;
   RegisterResForm->Classificated10Query->Active=true;

   RegisterResForm->ClassificatedQuery->Active=false;
   if (RegisterMaleRadio->Enabled==false) {
      RegisterResForm->ClassificatedQuery->ParamByName("SET_SEX1")->AsInteger=1;
      RegisterResForm->ClassificatedQuery->ParamByName("SET_SEX2")->AsInteger=0;
   } else {
      RegisterResForm->ClassificatedQuery->ParamByName("SET_SEX1")->AsInteger=(RegisterMaleRadio->Checked==true?1:0);
      RegisterResForm->ClassificatedQuery->ParamByName("SET_SEX2")->AsInteger=(RegisterMaleRadio->Checked==true?1:0);
   }
   RegisterResForm->ClassificatedQuery->ParamByName("SET_PROFILE")->AsInteger=RegisterProfileCombo->KeyValue;
//   RegisterResForm->Classificated10Query->First();
   RegisterResForm->ClassificatedQuery->Active=true;


 // Setting page format...
   //QuickRepEditorForm->SetPageValues(RegisterResForm->QuickRep1);

   if (Sender!=NULL) RegisterResForm->QuickRep1->Preview();
   else RegisterResForm->QuickRep1->Print();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N35Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
//   Application->CreateForm(__classid(TRegisterSearcherForm), &RegisterSearcherForm);
//   Application->CreateForm(__classid(TRegisterResForm), &RegisterResForm);
   RegisterSearcherForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
   QuickRepEditorForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ApplyToAll() {
   QuickRepEditorForm->SetPageValues(ReceptionResForm->QuickRep1);
}

void __fastcall TMainForm::ResultsPIDBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return;
   if (Data->ExamResultsQuery->Active!=true) return;
   try {
      Data->ExamResultsQuery->Locate("Person_ID",ResultPIDEdit->Value,p);
      this->ActiveControl=ERExamResultsGrid;
   } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ResultPIDEditKeyPress(TObject *Sender,
      char &Key)
{
   if (Key=='\r') {
      ResultsPIDBtnClick(NULL);
      Key='\0';
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersNameEditKeyPress(TObject *Sender, char &Key)
{
   if (strchr("1234567890=_+!@#$%^&*(){}[]:;<>?/,.|§~`",Key)!=NULL) Key='\0';
   if (NameSMARTCaseBtn->Down==true) {
      if (PersNameEdit->Text.IsEmpty()) MustBeUpper=true;
      MustBeUpper=CheckKey(MustBeUpper,Key);
   }
   FormKeyPress(NULL,Key);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddGradeBtnClick(TObject *Sender)
{
 int num,id;
 AnsiString comment="";
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   Data->RegisterNumQuery->Active=false;
   Data->RegisterNumQuery->Active=true;
   if (Data->RegisterNumQuery->RecordCount==0) {
      num=0;
   } else {
      num=Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger;
      //id=Data->RegisterNumQuery->FieldByName("RegisterIndex")->AsInteger;
   }
   Data->RegisterNumQuery->Active=false;

   if (num==0) {
      Application->MessageBox("Няма създадено класиране!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      this->Tag=0;
      return;
   }
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("SELECT COUNT(*) CNT FROM Register_Catalog WHERE Grade=:SET_GRADE");
   Data->SingleQuery->ParamByName("SET_GRADE")->AsInteger=num;
   Data->SingleQuery->Active=true;
   /*
   if (Data->SingleQuery->RecordCount==0) index=1;
   else index=Data->SingleQuery->FieldByName("CNT")->AsInteger+1;
   */
   if (!InputQuery("Добавяне на класиране","Моля, въведете коментар за класирането:",comment)) {
      this->Tag=0;
      return;
   }
   try {
      Data->SingleQuery->Active=false;
      Data->SingleQuery->SQL->Clear();
      Data->SingleQuery->SQL->Add("INSERT INTO Register_Catalog(Grade,Information) VALUES(:SET_GRADE,:SET_INFO)");
      Data->SingleQuery->ParamByName("SET_GRADE")->AsInteger=num;
      Data->SingleQuery->ParamByName("SET_INFO")->AsString=comment;

      Data->SingleQuery->ExecSQL();
      Data->SingleQuery->SQL->Clear();
   } catch (Exception *e) {
      Application->MessageBox("Грешка при добавянето на класирането!\nВероятно нямате права за изискваната операция.","Комуникационна грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      //Data->RegisterGradeQuery->Active=false;
      return;
   }
//   Data->ProfilesHistShowQuery->Active=false;
//   Data->ProfilesHistShowQuery->Active=true;

   Data->RegisterGradeQuery->Active=false;
   Data->RegisterGradeQuery->Active=true;
   this->Tag=1;

   Data->RegisterNumQuery->Active=false;
   Data->RegisterNumQuery->Active=true;
   Data->RegisterNumQuery->Edit();
   Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger=num;
   //Data->RegisterNumQuery->FieldByName("RegisterIndex")->AsInteger=index;
   Data->RegisterNumQuery->Post();
   Data->RegisterNumQuery->CommitUpdates();

   Data->RegisterNumQuery->Active=false;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoveGradeBtnClick(TObject *Sender)
{
 int num,index,parent;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
//   index=Data->RegisterGradeQuery->FieldByName("GradeIndex")->AsInteger;
   num=Data->RegisterGradeQuery->FieldByName("Grade")->AsInteger;
//   parent=Data->RegisterGradeQuery->FieldByName("ParentIndex")->AsInteger;

   if (Application->MessageBox("Моля, потвърдете! Изтриването е необратимо!","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)!=ID_YES) return;
   //if (Application->MessageBox("Моля, потвърдете!","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)!=ID_YES) return;

   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("DELETE FROM Register_Catalog WHERE Grade=:SET_GRADE");
   Data->SingleQuery->ParamByName("SET_GRADE")->AsInteger=num;
//   Data->SingleQuery->ParamByName("SET_INDEX")->AsInteger=index;
   Data->SingleQuery->ExecSQL();

//   Data->RegisterIndexQuery->Active=false;
//   Data->RegisterIndexQuery->Active=true;

   Data->RegisterGradeQuery->Active=false;
   Data->RegisterGradeQuery->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClassifProfileLookupClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   Data->RegisterHistoryQuery->Active=false;
   if (ClassifProfileLookup->KeyValue.IsNull()) return;
   Data->RegisterHistoryQuery->SQL->Clear();
   Data->ProfilesHistoryQuery->Active=false;
   Data->ProfilesHistoryQuery->ParamByName("SET_GRADE")->AsInteger=Data->RegisterGradeQuery->FieldByName("Grade")->AsInteger;
//   Data->ProfilesHistoryQuery->ParamByName("SET_INDEX")->AsInteger=Data->RegisterGradeQuery->FieldByName("GradeIndex")->AsInteger;
   Data->ProfilesHistoryQuery->Active=true;

   Data->ProfilesHistoryQuery->Locate("ID",ClassifProfileLookup->KeyValue,p);
   if (Data->ProfilesHistoryQuery->FieldByName("DiffMW")->AsBoolean) {
      ClassMaleRadio->Enabled=true;
      ClassFemaleRadio->Enabled=true;
      Data->RegisterHistoryQuery->SQL->Add("SELECT rh.*,p.sex FROM Register_History rh, Persons p \
WHERE rh.Person_id=p.ID AND rh.Grade=:Grade AND rh.Profile_ID=:SET_PROFILE AND p.sex=:SET_SEX ");
      Data->RegisterHistoryQuery->ParamByName("SET_SEX")->AsInteger=(ClassMaleRadio->Checked==true?1:0);
   } else {
      ClassMaleRadio->Enabled=false;
      ClassFemaleRadio->Enabled=false;
      Data->RegisterHistoryQuery->SQL->Add("SELECT rh.*,p.sex FROM Register_History rh, Persons p \
WHERE rh.Person_id=p.ID AND rh.Grade=:Grade AND rh.Profile_ID=:SET_PROFILE ");
   }
   if (AcceptedCheck->State!=cbGrayed) {
      Data->RegisterHistoryQuery->SQL->Add("AND rh.Classificated=:SET_CLASSIFICATED ");
      Data->RegisterHistoryQuery->ParamByName("SET_CLASSIFICATED")->AsInteger=(AcceptedCheck->State==cbChecked?1:0);
   }
   Data->RegisterHistoryQuery->SQL->Add(" ORDER BY Classificated DESC, Amount DESC, Person_ID");
   Data->RegisterHistoryQuery->ParamByName("SET_PROFILE")->AsInteger=ClassifProfileLookup->KeyValue;
   Data->RegisterHistoryQuery->Active=true;
   ShowProgress("Кандидати: "+String(Data->RegisterHistoryQuery->RecordCount),0,0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClassifPIDBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return;
   if (Data->RegisterHistoryQuery->Active!=true) return;
   try {
      Data->RegisterHistoryQuery->Locate("Person_ID",ClassifPIDEdit->Value,p);
   } catch (...) {}
}
//--------------------------------------------------------------------------

void __fastcall TMainForm::ClassifPIDEditKeyPress(TObject *Sender,
      char &Key)
{
   if (Key=='\r') {
      Key='\0';
      ClassifPIDBtnClick(NULL);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ActivateGradeBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   Data->SingleQuery->Active=false;
   Data->SingleQuery->SQL->Clear();
   Data->SingleQuery->SQL->Add("SELECT * FROM Register");
   Data->SingleQuery->Active=true;
   if (Data->SingleQuery->RecordCount>0)
      if (Application->MessageBox("Вече има направено класиране.\nИскате ли то да бъде добавено към историята и след това изтрито?","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_YESNO)==ID_YES) {
         AddGradeBtnClick(NULL);
         if (this->Tag!=1) return;
      } else {
         if (Application->MessageBox("Съществуващото класиране ще бъде изтрито?","Внимание",MB_ICONQUESTION|MB_APPLMODAL|MB_OKCANCEL)!=ID_OK)
            return;
      }
   Data->SingleQuery->Active=false;
   ClassificateClearBtnClick(NULL);
   try {
      Data->SingleQuery->Active=false;
      Data->SingleQuery->SQL->Clear();
      Data->SingleQuery->SQL->Add("INSERT INTO Register(Classificated,Person_id,Profile_Id,Amount,isIn) \
   SELECT Classificated,Person_id,Profile_id,Amount,isIn FROM Register_History WHERE Grade=:SET_GRADE");
      Data->SingleQuery->ParamByName("SET_GRADE")->AsInteger=Data->RegisterGradeQuery->FieldByName("Grade")->AsInteger;
      //Data->SingleQuery->ParamByName("SET_INDEX")->AsInteger=Data->RegisterGradeQuery->FieldByName("GradeIndex")->AsInteger;
      Data->SingleQuery->ExecSQL();
   } catch (Exception *e) {
      if (!DEBUG) Application->MessageBox("Грешка при връщането на класирането!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      else Application->ShowException(e);
      mainlog->WriteException(e->Message);
      return;
   }
   Data->SingleQuery->Active=false;
   try {
      Data->SingleQuery->SQL->Clear();
      Data->SingleQuery->SQL->Add("UPDATE Profiles SET DiffMW=h.DiffMW,Space=h.Space,SpaceOther=h.SpaceOther \
   FROM Profiles_History h WHERE h.ID=Profiles.ID AND h.Grade=:SET_GRADE ");
      Data->SingleQuery->ParamByName("SET_GRADE")->AsInteger=Data->RegisterGradeQuery->FieldByName("Grade")->AsInteger;
      //Data->SingleQuery->ParamByName("SET_INDEX")->AsInteger=Data->RegisterGradeQuery->FieldByName("GradeIndex")->AsInteger;
      Data->SingleQuery->ExecSQL();
   } catch (Exception *e) {
      if (!DEBUG) Application->MessageBox("Грешка при връщането на свободните места!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      else Application->ShowException(e);
      mainlog->WriteException(e->Message);
      return;
   }
   try {
      Data->RegisterNumQuery->Active=false;
      Data->RegisterNumQuery->Active=true;
      Data->RegisterNumQuery->Edit();
      Data->RegisterNumQuery->FieldByName("RegisterNumber")->AsInteger=Data->RegisterGradeQuery->FieldByName("Grade")->AsInteger;
      //Data->RegisterNumQuery->FieldByName("RegisterIndex")->AsInteger=Data->RegisterGradeQuery->FieldByName("GradeIndex")->AsInteger;
      Data->RegisterNumQuery->Post();
      Data->RegisterNumQuery->CommitUpdates();
   } catch (Exception *e) {
      if (!DEBUG) Application->MessageBox("Грешка при връщането на класирането!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      else Application->ShowException(e);
      mainlog->WriteException(e->Message);
      return;
   }
   RefreshServer1Execute(this);
   Application->MessageBox("Процесът завърши успешно!","Информация",MB_ICONINFORMATION|MB_APPLMODAL|MB_OK);

   ClassificateBtn->Enabled=true;
   ClassificateClearBtn->Enabled=true;
   ScndClassificateBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WishUpBtnClick(TObject *Sender)
{
 if (Data->Database1->Connected!=true) return;
 int Priority1=WishesQuery->FieldByName("Priority")->AsInteger,
      Priority2=Priority1-1,Person=WishesQuery->FieldByName("Person_ID")->AsInteger;
 TLocateOptions p;
// (-1- Prior) --> 0
   if (Priority2<1) return;
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=0;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=Priority2;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();

// (-2- Prior) --> -1
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=Priority2;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=Priority1;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();

// 0 --> (2 Prior)
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=Priority1;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=0;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();
   WishesQuery->Active=false;
   WishesQuery->Active=true;
   WishesQuery->Locate("Priority",Priority2,p);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WishDownBtnClick(TObject *Sender)
{
 if (Data->Database1->Connected!=true) return;
 int Priority1=WishesQuery->FieldByName("Priority")->AsInteger,
      Priority2=Priority1+1,Person=WishesQuery->FieldByName("Person_ID")->AsInteger;
 TLocateOptions p;
// (-1- Prior) --> 0
   if (Priority2>WishesQuery->RecordCount) return;
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=0;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=Priority2;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();

// (-2- Prior) --> -1
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=Priority2;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=Priority1;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();

// 0 --> (2 Prior)
   ExchangeQuery->ParamByName("SET_NEWPRIORITY")->AsInteger=Priority1;
   ExchangeQuery->ParamByName("SET_OLDPRIORITY")->AsInteger=0;
   ExchangeQuery->ParamByName("SET_PERSON")->AsInteger=Person;
   ExchangeQuery->ExecSQL();
   WishesQuery->Active=false;
   WishesQuery->Active=true;
   WishesQuery->Locate("Priority",Priority2,p);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WishesQueryUpdateError(TDataSet *DataSet,
      EDatabaseError *E, TUpdateKind UpdateKind,
      TUpdateAction &UpdateAction)
{
  if (dynamic_cast<EDBEngineError*>(E) != 0) {
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind!=ukDelete) {
        Application->MessageBox("Грешка при записването на данните.\nВероятно повтарящ се профил или липсващи данни!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
        return;
     }
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind==ukDelete) {
        Application->MessageBox("Грешка при записването на данните.\nЗаписа не може да бъде изтрит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
        return;
     }
  }
  MainForm->mainlog->WriteException(E->Message);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PersEGNEditKeyPress(TObject *Sender, char &Key)
{
   if (!isdigit(Key)&&Key!='\b'&&Key!='\r') Key='\0';
   FormKeyPress(NULL,Key);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N8Click(TObject *Sender)
{
   LMDAboutDlg1->Execute();   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Online1Click(TObject *Sender)
{
   if (HelpShowForm->Showing) HelpShowForm->Close();
   else HelpShowForm->Show();
   this->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::rsPropSaver1AfterLoad(TObject *Sender)
{
   if (Online1->Checked) Online1Click(NULL);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GroupBox1Enter(TObject *Sender)
{
   HelpShowForm->SetText(1);
   MustBeUpper=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Panel1Enter(TObject *Sender)
{
   HelpShowForm->SetText(2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersSexEditExit(TObject *Sender)
{
   if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert) {
      try {
         Data->PersonsQuery->Post();
      } catch (...) {return;}
      this->ActiveControl=WishesProfileLookup;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersNameEditEnter(TObject *Sender)
{
   MustBeUpper=true;   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersAddrEditEnter(TObject *Sender)
{
   MustBeUpper=true;   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PersAddrEditKeyPress(TObject *Sender, char &Key)
{
   if (AddressSMARTCaseBtn->Down) {
      if (PersAddrEdit->Text.IsEmpty()) MustBeUpper=true;
      MustBeUpper=CheckKey(MustBeUpper,Key);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N39Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   OperatorTaxesForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N40Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   CheckEGNForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SaveBtnClick(TObject *Sender)
{
 FILE *out;
 AnsiString text;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   SaveDialogCSV->Title="Запис на класиране...";
   if (SaveDialogCSV->Execute()) {
      out=fopen(SaveDialogCSV->FileName.c_str(),"w");
      Data->SingleQuery->Active=false;
      Data->SingleQuery->SQL->Clear();
      Data->SingleQuery->SQL->Add("SELECT * FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID WHERE r.Classificated=1 AND r.Profile_ID=:SET_PROFILE");
      Data->SingleQuery->ParamByName("SET_PROFILE")->AsInteger=Data->ProfilesTable->FieldByName("ID")->AsInteger;
      if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean) {
         text=RegisterProfileCombo->Text+" ("+
         ((RegisterMaleRadio->Checked)?"младежи":"девойки")+")";
         Data->SingleQuery->SQL->Add(" AND p.Sex="+String(RegisterMaleRadio->Checked==true?1:0));
      } else {
         text=RegisterProfileCombo->Text;
      }
      Data->SingleQuery->Active=true;
      text=text+": "+String(Data->SingleQuery->RecordCount);
      text="\""+text+"\"\n";
      fprintf(out,text.c_str());
      fprintf(out,"\"№\";\"Вх. №\";\"Име\";\"От дипл.\";\"Общ изпит\";\"Изпит\";\"Бал\"\n");
      ClassificatedQuery->Active=false;
      //ClassificatedQuery->ParamByName("Classificated")->AsInteger=1;
      ClassificatedQuery->ParamByName("SET_PROFILE")->AsInteger=Data->ProfilesTable->FieldByName("ID")->AsInteger;
      if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean) {
         if (RegisterMaleRadio->Checked) {
            ClassificatedQuery->ParamByName("SET_SEX1")->AsInteger=1;
            ClassificatedQuery->ParamByName("SET_SEX2")->AsInteger=1;
         } else {
            ClassificatedQuery->ParamByName("SET_SEX1")->AsInteger=0;
            ClassificatedQuery->ParamByName("SET_SEX2")->AsInteger=0;
         }
      } else {
         ClassificatedQuery->ParamByName("SET_SEX1")->AsInteger=1;
         ClassificatedQuery->ParamByName("SET_SEX2")->AsInteger=0;
      }
      ClassificatedQuery->Active=true;
      ClassificatedQuery->First();

      for (int i=0;i<ClassificatedQuery->RecordCount;i++) {
         fprintf(out,"\"%d\";\"%d\";\"%s\";\"%s\";\"%s\";\"%s\";\"%s\"\n",i+1,
           ClassificatedQuery->FieldByName("Person_ID")->AsInteger,ClassificatedQuery->FieldByName("Name")->AsString.c_str(),
           FormatFloat("#0.00",ClassificatedQuery->FieldByName("SchoolScore")->AsFloat).c_str(),FormatFloat("#0.00",ClassificatedQuery->FieldByName("FirstExamScore")->AsFloat).c_str(),
           FormatFloat("#0.00",ClassificatedQuery->FieldByName("ExamScore")->AsFloat).c_str(),FormatFloat("#0.00",ClassificatedQuery->FieldByName("BAL")->AsFloat).c_str());
         ClassificatedQuery->Next();
      }
      Data->SingleQuery->Active=false;
      fclose(out);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveBtn2Click(TObject *Sender)
{
 FILE *out;
 AnsiString text;
 float s;
   if (Data->Database1->Connected!=true) return;
   SaveDialogCSV->Title="Запис на резултати от изпити...";
   if (SaveDialogCSV->Execute()) {
      out=fopen(SaveDialogCSV->FileName.c_str(),"w");
      if (out==NULL) {
         ShowMessage("Грешка при създаването на файла!");
         return;
      }
   } else return;

   ResolveProfileLookupCode(ResultsExamLookup->Text);
   if (ProfileLookupCode!=-1) {      // Даден е изпит
      ExamResultsResForm->OfficialQuery->Active=false;
      ExamResultsResForm->OfficialQuery->SQL->Clear();
      if (ProfileLookupCode!=0) {
         ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.Profile_ID=:SET_EXAM AND w.GoToExam=1) \
ORDER BY p.ID,er.ID ");
         ExamResultsResForm->OfficialQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
      } else {                      // Изпит по профил
         ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY p.ID,er.ID ");
      }
      ExamResultsResForm->OfficialQuery->Active=true;
   }
   ExamResultsResForm->OfficialQuery->First();

   text=ResultsExamLookup->Text;
   if (text=="Общ изпит") text="Математика (общ)";

   fprintf(out,"\"Резултати от изпит по %s\"\n",text.c_str());
   fprintf(out,"\"Вх. №\";\"Фк. №\";\"Име\";\"Оценка\"\n");

   for (int i=0;i<=Data->ExamResultsQuery->RecordCount;i++) {
      fprintf(out,"\"%d\";",ExamResultsResForm->OfficialQuery->FieldByName("ID")->AsInteger);
      if (ExamResultsResForm->OfficialQuery->FieldByName("FK")->AsInteger!=0)
         fprintf(out,"\"%d\";",ExamResultsResForm->OfficialQuery->FieldByName("FK")->AsInteger);
      else fprintf(out,"\"\";");
      fprintf(out,"\"%s\";",ExamResultsResForm->OfficialQuery->FieldByName("Name")->AsString);

      fprintf(out,"\"%s ",ExamResultsResForm->OfficialQuery->FieldByName("ScoreLabel")->AsString);
      if (!ExamResultsResForm->OfficialQuery->FieldByName("Score")->IsNull)
         fprintf(out,"%s\"\n",ExamResultsResForm->OfficialQuery->FieldByName("ScoreString")->AsString);
      else fprintf(out,"\"\n");
      ExamResultsResForm->OfficialQuery->Next();
   }
   fprintf(out,"\"Общо: %d\"\n",Data->ExamResultsQuery->RecordCount);
   ExamResultsResForm->OfficialQuery->Active=false;
   fclose(out);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FkSearchBtnClick(TObject *Sender)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return;
   if (Data->ExamResultsQuery->Active!=true) return;
   try {
      Data->ExamResultsQuery->Locate("ID",FkSearchEdit->Value,p);
      this->ActiveControl=ERExamResultsGrid;
   } catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FkSearchEditKeyPress(TObject *Sender, char &Key)
{
   if (Key=='\r') {
      FkSearchBtnClick(NULL);
      Key='\0';
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
   if (Data->Database1->AliasName.IsEmpty()) {
      // showing OptionsForm if no DSN is set
      ODBC1Click(this);
      OptionsForm->ShowModal();
   }
   if (LoginForm->Visible) {
      LoginForm->SetFocus();
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N41Click(TObject *Sender)
{
 bool includePrefered=false;
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   if (ResultsExamLookup->Text.IsEmpty()) {
      Application->MessageBox("Моля, изберете изпит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      PageControl->ActivePage=ResultTab;
      this->ActiveControl=ResultsExamLookup;
      return;
   }
   ResolveProfileLookupCode(ResultsExamLookup->Text);
   if (ProfileLookupCode!=-1) {      // Даден е изпит
      if (ProfileLookupCode==0) {
         Application->MessageBox("Протокол за изпит НЕ МОЖЕ да се прави за общия изпит!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return;
      }
      switch (Application->MessageBox("Желаете ли да бъде добавена информация за предпочитанието на кандидата?","Протокол за изпит",MB_YESNOCANCEL|MB_APPLMODAL|MB_ICONQUESTION|MB_DEFBUTTON2)) {
         case IDYES:
            includePrefered=true;
         break;
         case IDNO:
            includePrefered=false;
         break;
         default:    return;
      }
      ExamResultsResForm->ExamNameLabel->Caption=ResultsExamLookup->Text;
      ExamResultsResForm->RoomProtocolQuery->Active=false;
      ExamResultsResForm->RoomProtocolQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
      ExamResultsResForm->RoomProtocolQuery->Active=true;

      ExamResultsResForm->inclPrefer=includePrefered;
      if (includePrefered)
         ExamResultsResForm->QRPrefered->Enabled=true;
      else
         ExamResultsResForm->QRPrefered->Enabled=false;

      if (TextPrintCheck->Checked==false)
         ExamResultsResForm->ProtocolExamRes->Preview();
      else
         DoTextPreview(5);
      ExamResultsResForm->RoomProtocolQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N42Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   ReceptionMapForm->PersonQuery->Active=false;
   ReceptionMapForm->PersonQuery->Active=true;

   ReceptionMapForm->WishesQuery->Active=false;
   ReceptionMapForm->WishesQuery->Active=true;

   ReceptionMapForm->ExamsQuery->Active=false;
   ReceptionMapForm->ExamsQuery->Active=true;

   ReceptionMapForm->ClassificateQuery->Active=false;
   ReceptionMapForm->ClassificateQuery->Active=true;

   ReceptionMapForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PRNBtnClick(TObject *Sender)
{
   if (!PRNEveryCheck->Checked) {
      if (Application->MessageBox("Потвърдете, че искате да бъдат напечатани \nизбрания брой разпечатки!","Внимание",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)!=ID_YES)
         return;
   } else {
      if (Application->MessageBox("Потвърдете, че искате да бъдат напечатани \nизбрания брой разпечатки през избрания интервал от време!","Внимание",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)!=ID_YES)
         return;
   }

   PRNTimerTimer(NULL);
   if (PRNEveryCheck->Checked) {
      PRNTimer->Interval=PRNSecondEdit->Value*1000;
      PRNSecondEdit->Enabled=false;
      PRNEveryCheck->Enabled=false;
      PRNTimer->Enabled=true;
      PRNStopBtn->Visible=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBar1Resize(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Width=StatusBar1->Width-250;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShowPRNClick(TObject *Sender)
{
   PRNBtn->Visible=ShowPRN->Down;
   PRNValue->Visible=ShowPRN->Down;
   PRNLabel->Visible=ShowPRN->Down;
   PRNSecondEdit->Visible=ShowPRN->Down;
   PRNEveryCheck->Visible=ShowPRN->Down;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StatusBar1DrawPanel(TStatusBar *StatusBar,
      TStatusPanel *Panel, const TRect &Rect)
{
   StatusBar->Canvas->Font->Color=clBlue;
   StatusBar->Canvas->TextRect(Rect,Rect.Left,Rect.Top,"© 2004 Владимир Лалов (v_lalov@yahoo.com)");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N43Click(TObject *Sender)
{
   N20Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N44Click(TObject *Sender)
{
   N28Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N45Click(TObject *Sender)
{
   N35Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SearchingReceptionExecute(TObject *Sender)
{
   N43Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButton12Click(TObject *Sender)
{
   N42Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N46Click(TObject *Sender)
{
   TableFont->Font=ERExamResultsGrid->Font;
   if (TableFont->Execute()) {
      ERExamResultsGrid->Font=TableFont->Font;
      DBGrid1->Font=TableFont->Font;
      //DBGrid2->Font=TableFont->Font;
      //DBGrid3->Font=TableFont->Font;
      DBRichEdit1->Font=TableFont->Font;
      DBGrid6->Font=TableFont->Font;
      RegisterDBGrid->Font=TableFont->Font;
      DBGrid9->Font=TableFont->Font;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N47Click(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      ConnectToServer1Execute(NULL);
      if (Data->Database1->Connected!=true)
      return;
   }
   
   ResolveProfileLookupCode(ResultsExamLookup->Text);
   if (ProfileLookupCode!=-1) {      // Даден е изпит
      ExamResultsResForm->OfficialQuery->Active=false;

      ExamResultsResForm->OfficialQuery->SQL->Clear();
      if (ProfileLookupCode!=0) {
       // първи изпит
         ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=:SET_EXAM \
WHERE EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=p.ID AND w.GoToExam=1 AND w.Profile_ID=:SET_EXAM) \
AND EXISTS(SELECT * FROM ExamsResults ee WHERE ee.Exam=0 AND ee.Person_ID=p.ID AND ee.Score>=3) \
ORDER BY p.ID");
         ExamResultsResForm->OfficialQuery->ParamByName("SET_EXAM")->AsInteger=ProfileLookupCode;
      } else {
       // първи изпит
         ExamResultsResForm->OfficialQuery->SQL->Add("SELECT p.ID,p.Name,er.ID FK,er.Score,er.points \
FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.Id=er.Person_ID AND er.EXAM=0 \
ORDER BY p.ID");
      }

      ExamResultsResForm->OfficialQuery->Active=true;
      if (ResultsExamLookup->Text=="Общ изпит")
         ExamResultsResForm->ShowExamLabel2->Caption="Математика (общ)";
      else ExamResultsResForm->ShowExamLabel2->Caption=ResultsExamLookup->Text;
      QuickRepEditorForm->SetPageValues(ExamResultsResForm->OfficialQuickRep);
      ExamResultsResForm->OfficialQuickRep->Preview();
      ExamResultsResForm->OfficialQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SMARTCaseToggleClick(TObject *Sender)
{
   NameSMARTCaseBtn->Visible=SMARTCaseToggle->Down;
   AddressSMARTCaseBtn->Visible=SMARTCaseToggle->Down;
   if (SMARTCaseToggle->Down==false) {
      NameSMARTCaseBtn->Down=false;
      AddressSMARTCaseBtn->Down=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyPress(TObject *Sender, char &Key)
{
   if (Key=='\r') {
      AddPerson1Execute(this);
      Key='\0';
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoteAdminServerClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
   mainlog->WriteString("RemoteAdmin :Client "+Socket->RemoteHost+"("+Socket->RemoteAddress+") connected.");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoteAdminServerClientDisconnect(
      TObject *Sender, TCustomWinSocket *Socket)
{
   mainlog->WriteString("RemoteAdmin :Client "+Socket->RemoteHost+"("+Socket->RemoteAddress+") disconnected.");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoteAdminServerClientWrite(TObject *Sender,
      TCustomWinSocket *Socket)
{
 AnsiString text=Socket->ReceiveText();
 FILE *usr;
 char pa[1000];
 AnsiString path;
 bool AuthOK=false;
   mainlog->WriteString("RemoteAdmin("+Socket->RemoteHost+"): "+"Message -"+text);
   GetWindowsDirectory(pa,1000);
   path=StrPas(pa); path=path+"\\temp.file";
   usr=fopen(path.c_str(),"r");
   if (usr==NULL) return;
   while (!feof(usr)) {
      fscanf(usr,"%s",pa);
      path="usrname: "+StrPas(pa)+";";
      if (text.Pos(path)>0) {
         AuthOK=true;
         break;
      }
   }
   fclose(usr);
   if (AuthOK==true) {
      if (text.Pos("setActionIndex=1;")>0) {
       // disconnect from server
         if (Data->Database1->Connected==true) {
            Application->MessageBox(("Текущият потребител ще бъде изключен от базата поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
            DisconnectFromServer1Execute(this);
            Socket->SendText("Disconnected.");
         } else {
            Socket->SendText("Not Connected");
         }
         return;
      }
      if (text.Pos("setActionIndex=10;")>0) {
       // disconnect from server
         if (Data->Database1->Connected==true) {
            //Application->MessageBox(("Текущият потребител ще бъде изключен от базата поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
            DisconnectFromServer1Execute(this);
            Socket->SendText("Disconnected (+force)");
         } else {
            Socket->SendText("Not Connected");
         }
         return;
      }
      if (text.Pos("setActionIndex=2;")>0) {
       // refresh data
         if (Data->Database1->Connected==true) {
            Application->MessageBox(("Данните ще бъдат опреснени поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
            RefreshServer1Execute(this);
            Socket->SendText("Refreshed");
         } else {
            Socket->SendText("Not Connected");
         }
         return;
      }
      if (text.Pos("setActionIndex=21;")>0) {
       // refresh data
         if (Data->Database1->Connected==true) {
            RefreshServer1Execute(this);
            Socket->SendText("Refreshed (+force)");
         } else {
            Socket->SendText("Not Connected");
         }
         return;
      }
      if (text.Pos("setActionIndex=3;")>0) {
         Application->MessageBox(("Програмата ще се затвори поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Good bye!");
         Exit1Execute(this);
         return;
      }
      if (text.Pos("setActionIndex=31;")>0) {
         //Application->MessageBox(("Програмата ще се затвори поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Good bye!");
         Exit1Execute(this);
         return;
      }
      if (text.Pos("setActionIndex=41;")>0) {
       // shutdown + force
         //Application->MessageBox(("Компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Shutting down computer...");
         ExitWindowsEx(EWX_SHUTDOWN|EWX_FORCE,0);
         return;                     
      }
      if (text.Pos("setActionIndex=4;")>0) {
       // shutdown
         Application->MessageBox(("Компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Shutting down computer...");
         ExitWindowsEx(EWX_SHUTDOWN,0);
         return;
      }
      if (text.Pos("setActionIndex=51;")>0) {
       // reboot + force
         //Application->MessageBox(("Компютъра ще бъде рестартиран поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Restarting computer...");
         ExitWindowsEx(EWX_REBOOT|EWX_FORCE,0);
         return;
      }
      if (text.Pos("setActionIndex=5;")>0) {
         Application->MessageBox(("Компютъра ще бъде рестартиран поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Restarting computer...");
         ExitWindowsEx(EWX_REBOOT,0);
         return;
      }
      if (text.Pos("setActionIndex=6;")>0) {
         Application->MessageBox(("Текущия потребител на компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Logging off current user...");
         ExitWindowsEx(EWX_LOGOFF,0);
         return;
      }
      if (text.Pos("setActionIndex=61;")>0) {
         //Application->MessageBox(("Текущия потребител на компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Logging off current user...");
         ExitWindowsEx(EWX_LOGOFF|EWX_FORCE,0);
         return;
      }
      if (text.Pos("setActionIndex=111;")>0) {
         //Application->MessageBox(("Текущия потребител на компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         Socket->SendText("Starting help...");
         Application->HelpCommand(HELP_CONTEXT,Screen->ActiveControl->HelpContext);
         return;
      }
      if (text.Pos("setActionIndex=123;")>0) {
         //Application->MessageBox(("Текущия потребител на компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         if (Data->Database1->Connected==false) {
            ConnectToServer1Execute(this);
            Socket->SendText("Login Form shown...");
         } else {
            Socket->SendText("Currently connected!");
         }
         return;
      }
      if (text.Pos("setActionIndex=321;")>0) {
         //Application->MessageBox(("Текущия потребител на компютъра ще бъде изключен поради изискване на "+Socket->RemoteHost+"!").c_str(),"Отдалечено администриране",MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION);
         if (Data->Database1->Connected==false) {
            AnsiString t;
            t=OptionsForm->DSNEdit->Text;
            OptionsForm->DSNEdit->Text=text.SubString(text.Pos("setActionIndex=321;")+19,text.Length());
            OptionsForm->BitBtn1Click(this);
            Socket->SendText("DSN:"+t+"->"+OptionsForm->DSNEdit->Text);
         } else {
            Socket->SendText("Connected! Cannot change DSN.");
         }
         return;
      }
      if (text.Pos("setActionIndex=11;")>0) {
         if (Data->Database1->Connected==true) {
            Data->NameQuery->Active=true;
            Socket->SendText("User: "+Data->NameQuery->FieldByName("operator")->AsString);
            Data->NameQuery->Active=false;
         } else {
            Socket->SendText("Not Connected");
         }
      }
      if (text.Pos("setActionIndex=1001;")>0) {
         Socket->SendText("Stopping Administration Server...");
         RemoteAdminServer->Active=false;
         return;
      }
   }
   // default action: stop server
   if (text.Pos("usrname: ")==0) {
      RemoteAdminServer->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PRNTimerTimer(TObject *Sender)
{
 AnsiString s;
   if (Data->Database1->Connected!=true) return;
   Data->PersonsQuery->Tag=1;
   for (int i=0;i<PRNValue->Value;i++) {
      if (Data->PersonsQuery->Eof) {
         PRNTimer->Enabled=false;
         PRNStopBtn->Visible=false;
         Application->MessageBox("Край на кандидатите!","Информация",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
         PRNEveryCheck->Enabled=true;
         PRNSecondEdit->Enabled=true;
         break;
      }
      if (TextPrintCheck->Checked) {
         PrintPerson(0);
      } else {
         Print1Execute(this);
      }
      s.printf("Печат на № %d (%d/%d)...",Data->PersonsQuery->FieldByName("ID")->AsInteger,i+1,PRNValue->Value);
      ShowProgress(s,0,0);
      if (Data->PersonsQuery->Eof) break;
      Data->PersonsQuery->Next();
   }
   Data->PersonsQuery->Tag=0;
   Data->PersonsQueryAfterScroll(Data->PersonsQuery);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PRNStopBtnClick(TObject *Sender)
{
   PRNTimer->Enabled=false;
   PRNStopBtn->Visible=false;
   PRNSecondEdit->Enabled=true;
   PRNEveryCheck->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
   StatusBar1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ApplicationEvents1Hint(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Text=Application->Hint;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N50Click(TObject *Sender)
{
 FILE *out;
 char tmp;
   if (Application->MessageBox("Тази функция ще изпечати кодовата таблица на вашия принтер.\n Моля, пригответе печатащото устройство за печат!","Прием на НПМГ - печат",MB_OKCANCEL|MB_APPLMODAL|MB_ICONQUESTION)!=ID_OK)
      return;

   StatusBar1->Panels->Items[0]->Text="Печат на кодовата таблица...";
   out=fopen(OptionsForm->PrintDevice->Text.c_str(),"w");
   if (out==NULL) {
      Application->MessageBox("Грешка при инициализирането на устройството за печат!","Прием на НПМГ - печат",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      //fclose(inp);
      return;
   }
   fprintf(out,"Starting of printer code table...\n\n");
   for (int i=32;i<256;i++) {
        fprintf(out,"%c",i);
        if ((i-32)%30==0) fprintf(out,"\n");
   }
   fprintf(out,"\nEnd of printer code table!\n\n");
   /*
   inp=fopen("PrinterTest.blk","r");
   if (inp==NULL) {
      Application->MessageBox("Файла \'PrinterTest.blk\', съдържащ кодовата таблица не е намерен!","Прием на НПМГ - печат",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return;
   }
   while (!feof(inp)) {
      tmp=fgetc(inp);
      if (tmp==EOF) break;
      fputc(tmp,out);
   }
   fclose(inp);
*/
   fclose(out);
   StatusBar1->Panels->Items[0]->Text="Печата на кодовата таблица е завършен!";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N51Click(TObject *Sender)
{
 FILE *out;
 char tmp;
   if (Application->MessageBox("Тази функция ще изпечати кодовата таблица на вашия принтер.\n Моля, пригответе печатащото устройство за печат!","Прием на НПМГ - печат",MB_OKCANCEL|MB_APPLMODAL|MB_ICONQUESTION)!=ID_OK)
      return;

   StatusBar1->Panels->Items[0]->Text="Печат на кодовата таблица...";
   out=fopen(OptionsForm->PrintDevice->Text.c_str(),"w");
   if (out==NULL) {
      Application->MessageBox("Грешка при инициализирането на устройството за печат!","Прием на НПМГ - печат",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      //fclose(inp);
      return;
   }
//   fprintf(out,"Starting of printer code table...\n\n");
   for (int i=32;i<256;i++) {
        fprintf(out,"%c=%d ",i,i);
        if ((i-32)%10==0) fprintf(out,"\n");
   }
   fprintf(out,"\n\n");
//   fprintf(out,"\nEnd of printer code table!\n\n");
   /*
   inp=fopen("PrinterTest.blk","r");
   if (inp==NULL) {
      Application->MessageBox("Файла \'PrinterTest.blk\', съдържащ кодовата таблица не е намерен!","Прием на НПМГ - печат",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return;
   }
   while (!feof(inp)) {
      tmp=fgetc(inp);
      if (tmp==EOF) break;
      fputc(tmp,out);
   }
   fclose(inp);
*/
   fclose(out);
   StatusBar1->Panels->Items[0]->Text="Печата на кодовата таблица е завършен!";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RegisterDBGridKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
 int offset=0;
   if (Key==' '&&Shift.Contains(ssCtrl)&&!Shift.Contains(ssAlt)) {
      // removing person from classification
      if (delmeQuery->FieldByName("Amount")->AsFloat==delmeQuery->FieldByName("inl_amount")->AsFloat) {
         offset=delmeQuery->FieldByName("notcl")->AsInteger;
      }
      if (delmeQuery->FieldByName("Amount")->AsFloat==RegisterQuery->FieldByName("Amount")->AsFloat&&
          delmeQuery->FieldByName("counter")->AsInteger+offset>1) {
/*
         if (RegisterQuery->FieldByName("Classificated")->AsBoolean!=true) {
            Application->MessageBox("Не можете да изхвърлите този кандидат! Той не е приет в текущия профил!","Прием на НПМГ",MB_OK|MB_APPLMODAL|MB_ICONERROR);
            return;
         }
*/
         if (Data->Database1->Connected!=true) return;
         if (this->ActiveControl!=RegisterDBGrid) return;

         if (RegisterQuery->State!=dsEdit) {
            RegisterQuery->Edit();
         } else {
            RegisterQuery->CommitUpdates();
            RegisterQuery->Edit();
         }
         RegisterQuery->FieldByName("Classificated")->AsBoolean=!RegisterQuery->FieldByName("Classificated")->AsBoolean;
         Key='\0';
      } else {
         Application->MessageBox("Не можете да изхвърлите този кандидат! Няма други кандидати със същия бал!","Прием на НПМГ",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RegisterDBGridKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key==' '&&!Shift.Contains(ssCtrl)) {
      if (Data->Database1->Connected!=true) return;
      if (this->ActiveControl!=RegisterDBGrid) return;
      if (RegisterQuery->FieldByName("Classificated")->AsBoolean!=true) return;
      if (RegisterQuery->State!=dsEdit) {
         RegisterQuery->Edit();
      }
      RegisterQuery->FieldByName("IsIn")->AsBoolean=!RegisterQuery->FieldByName("IsIn")->AsBoolean;
      Key='\0';
   }
}
//---------------------------------------------------------------------------

