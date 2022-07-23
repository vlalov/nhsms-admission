//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExamResultSearcher.h"
#include "DataModule.h"
#include "ExamResultsRes.h"
#include "ExamStatisticsRes.h"
#include "ExamStatsGraph.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "VrEdit"
#pragma resource "*.dfm"
#define max(x,y) (((x)<(y))?(y):(x))
TExamsResultSearcherForm *ExamsResultSearcherForm;
//---------------------------------------------------------------------------
__fastcall TExamsResultSearcherForm::TExamsResultSearcherForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::FormShow(TObject *Sender)
{
 AnsiString temp;
   if (Data->Database1->Connected!=true) return;
   temp=ExamLookup->Text;
   ExamLookup->Items->Clear();
   ExamLookup->Items->Add("Общ изпит");

   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      ExamLookup->Items->Add(Data->ProfilesTable->FieldByName("Name")->AsString);
      Data->ProfilesTable->Next();
   }
   ExamLookup->Text="Общ изпит";
  // ProfileLookupChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::NumCheckClick(TObject *Sender)
{
   NumEdit->Enabled=NumCheck->Checked;
   ExamCheckClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::FkCheckClick(TObject *Sender)
{
   FkEdit->Enabled=FkCheck->Checked;
   ExamCheckClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::PointsCheckClick(TObject *Sender)
{
   PointsFromRadio->Enabled=PointsCheck->Checked;
   PointsFromEdit->Enabled=PointsCheck->Checked&&(PointsFromRadio->Checked||PointsFromToRadio->Checked);
   PointsFromToRadio->Enabled=PointsCheck->Checked;
   PointsToRadio->Enabled=PointsCheck->Checked;
   PointsToEdit->Enabled=PointsCheck->Checked&&(PointsToRadio->Checked||PointsFromToRadio->Checked);
   //PointsFromRadioClick(NULL);

   if (PointsCheck->Checked||ScoreCheck->Checked) {
      ResultTab->Highlighted=true;
   } else ResultTab->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::PointsFromRadioClick(
      TObject *Sender)
{
   PointsFromEdit->Enabled=PointsFromRadio->Checked||PointsFromToRadio->Checked;
   PointsToEdit->Enabled=PointsToRadio->Checked||PointsFromToRadio->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::ScoreCheckClick(TObject *Sender)
{
   ScoreFromRadio->Enabled=ScoreCheck->Checked;
   ScoreFromEdit->Enabled=ScoreCheck->Checked&&(ScoreFromRadio->Checked||ScoreFromToRadio->Checked);
   ScoreFromToRadio->Enabled=ScoreCheck->Checked;
   ScoreToRadio->Enabled=ScoreCheck->Checked;
   ScoreToEdit->Enabled=ScoreCheck->Checked&&(ScoreToRadio->Checked||ScoreFromToRadio->Checked);
   //ScoreFromRadioClick(NULL);

   if (PointsCheck->Checked||ScoreCheck->Checked) {
      ResultTab->Highlighted=true;
   } else ResultTab->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::ScoreFromRadioClick(
      TObject *Sender)
{
   ScoreFromEdit->Enabled=ScoreFromRadio->Checked||ScoreFromToRadio->Checked;
   ScoreToEdit->Enabled=ScoreToRadio->Checked||ScoreFromToRadio->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::ExamLookupChange(
      TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   if (!ExamLookup->Text.IsEmpty()) {
      StatsBtn->Enabled=true;
      ChartBtn->Enabled=true;
      ScoreRadio->Enabled=true;
      PointsRadio->Enabled=true;
   } else {
      StatsBtn->Enabled=false;
      ChartBtn->Enabled=false;
      ScoreRadio->Enabled=false;
      PointsRadio->Enabled=false;
   }
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExamsResultSearcherForm::ResolveProfileLookupCode(int val) {
 AnsiString res;
   if (Data->Database1->Connected!=true) return "Грешка";
   if (val==0) {
      res="Общ изпит";
      return res;
   }
   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      if (val==Data->ProfilesTable->FieldByName("ID")->AsInteger) {
         //ProfileLookupCode=Data->ProfilesTable->FieldByName("ID")->AsInteger;
         res=Data->ProfilesTable->FieldByName("Name")->AsString;
         return res;
      }
      Data->ProfilesTable->Next();
   }
   return "Грешка";
}
int __fastcall TExamsResultSearcherForm::ResolveProfileCode(AnsiString text) {
   if (Data->Database1->Connected!=true) return -1;
   if (text=="Общ изпит") {
      return 0;
   }
   Data->ProfilesTable->First();
   for (int i=0;i<Data->ProfilesTable->RecordCount;i++) {
      if (text==Data->ProfilesTable->FieldByName("Name")->AsString) {
         return Data->ProfilesTable->FieldByName("ID")->AsInteger;
      }
      Data->ProfilesTable->Next();
   }
   return -1;
}

void __fastcall TExamsResultSearcherForm::CancelBtnClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TExamsResultSearcherForm::ResultsQueryCalcFields(
      TDataSet *DataSet)
{
 TLocateOptions p;
 int person_id,profile_id;
   DataSet->FieldByName("Exa")->AsString=ResolveProfileLookupCode(DataSet->FieldByName("Exam")->AsInteger);

   if (search!=true) return;
   person_id=DataSet->FieldByName("Person_ID")->AsInteger;
   profile_id=DataSet->FieldByName("Exam")->AsInteger;
   Data->PersonsQuery->Locate("ID",person_id,p);
   if (Data->PersonsQuery->FieldByName("ID")->AsInteger!=person_id) {
      DataSet->FieldByName("SchoolScore")->Clear();
      DataSet->FieldByName("OlympScore")->Clear();
   } else {
      MainForm->WishesQuery->Locate("Profile_ID",profile_id,p);
      if (MainForm->WishesQuery->FieldByName("Profile_ID")->AsInteger!=profile_id) {
         DataSet->FieldByName("SchoolScore")->Clear();
         DataSet->FieldByName("OlympScore")->Clear();
      } else {
         DataSet->FieldByName("SchoolScore")->AsFloat=MainForm->WishesQuery->FieldByName("Score")->AsFloat;
         if (MainForm->WishesQuery->FieldByName("FromOlymp")->AsBoolean==true) {
            DataSet->FieldByName("OlympScore")->AsFloat=MainForm->WishesQuery->FieldByName("OlympScore")->AsFloat;
         }
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TExamsResultSearcherForm::SearchBtnClick(TObject *Sender)
{
 // Generate PersonsQuery...
 double t;
   if (Data->Database1->Connected!=true) return;
   PersonsQuery->Active=false;
   ResultsQuery->Active=false;
   PersonsQuery->SQL->Clear();
   PersonsQuery->SQL->Add("SELECT DISTINCT p.ID,p.Name,p.PreferedSchool,p.EGN,p.Telephone \
FROM Persons p,ExamsResults er WHERE p.ID=er.Person_ID ");
   if (NumCheck->Checked) {
      PersonsQuery->SQL->Add(" AND p.ID=:SET_PID ");
      PersonsQuery->ParamByName("SET_PID")->AsInteger=NumEdit->Value;
   }
   if (PreferedSchoolCheck->State!=cbGrayed) {
      PersonsQuery->SQL->Add(" AND p.PreferedSchool=:SET_PREFEREDSTATE");
      switch (PreferedSchoolCheck->State) {
         case cbChecked:
            PersonsQuery->ParamByName("SET_PREFEREDSTATE")->AsInteger=1;
         break;
         default:
            PersonsQuery->ParamByName("SET_PREFEREDSTATE")->AsInteger=0;
      }
   }
 // Generate ResultsQuery...
 //  ResultsQuery->SQL->Clear();
 //  ResultsQuery->SQL->Add("SELECT * FROM ExamsResults er WHERE er.Person_ID=:ID ");
   search=true;
   if (ExamCheck->Checked&&!ExamLookup->Text.IsEmpty()) {
      PersonsQuery->SQL->Add(" AND er.Exam=:SET_EXAM ");
      PersonsQuery->ParamByName("SET_EXAM")->AsInteger=ResolveProfileCode(ExamLookup->Text);
   }
   if (FkCheck->Checked) {
      PersonsQuery->SQL->Add(" AND er.ID=:SET_FK ");
      PersonsQuery->ParamByName("SET_FK")->AsInteger=FkEdit->Value;
   }
   if (PointsCheck->Checked) {
      if (PointsFromEdit->Value>PointsToEdit->Value&&PointsFromToRadio->Checked) { // Reverse From and To
         t=PointsFromEdit->Value;
         PointsFromEdit->Value=PointsToEdit->Value;
         PointsToEdit->Value=t;
      }
      if (PointsFromRadio->Checked||PointsFromToRadio->Checked) {// From Statement
         PersonsQuery->SQL->Add(" AND er.Points>=:SET_FROMPT ");
         PersonsQuery->ParamByName("SET_FROMPT")->AsFloat=PointsFromEdit->Value;
      }
      if (PointsToRadio->Checked||PointsFromToRadio->Checked) {                   // To Statement
         PersonsQuery->SQL->Add(" AND er.Points<=:SET_TOPT ");
         PersonsQuery->ParamByName("SET_TOPT")->AsFloat=PointsToEdit->Value;
      }
   }
   if (ScoreCheck->Checked) {
      if (ScoreFromEdit->Value>ScoreToEdit->Value&&ScoreFromToRadio->Checked) { // Reverse From and To
         t=ScoreFromEdit->Value;
         ScoreFromEdit->Value=ScoreToEdit->Value;
         ScoreToEdit->Value=t;
      }
      if (ScoreFromRadio->Checked||ScoreFromToRadio->Checked) {                 // From Statement
         PersonsQuery->SQL->Add(" AND er.Score>=:SET_FROMSC ");
         PersonsQuery->ParamByName("SET_FROMSC")->AsFloat=ScoreFromEdit->Value;
      }
      if (ScoreToRadio->Checked||ScoreFromToRadio->Checked) {                   // To Statement
         PersonsQuery->SQL->Add(" AND er.Score<=:SET_TOSC ");
         PersonsQuery->ParamByName("SET_TOSC")->AsFloat=ScoreToEdit->Value;
      }
   }
   if (HaveWishCheck->Checked&&!ProfileLookup->KeyValue.IsNull()) {
      PersonsQuery->SQL->Add(" AND EXISTS (SELECT * FROM Wishes WHERE Person_ID=p.ID AND Profile_ID=:SET_PROFILE ");
      if (PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull()) {
         PersonsQuery->SQL->Add(" AND Priority=:SET_PRIORITY ");
         PersonsQuery->ParamByName("SET_PRIORITY")->AsInteger=PriorityLookup->KeyValue;
      }
      PersonsQuery->SQL->Add(")");
      PersonsQuery->ParamByName("SET_PROFILE")->AsInteger=ProfileLookup->KeyValue;
   }
   PersonsQuery->SQL->Add(" ORDER BY p.ID ");
   SearchBtn->Enabled=false;
   try {
      PersonsQuery->Active=true;
      ResultsQuery->Active=true;
   } catch (...) {}
   SearchBtn->Enabled=true;
   PrintBtn->Enabled=true;

   if (PersonsQuery->RecordCount>0)
      StatusBar1->SimpleText="Намерени: "+String(PersonsQuery->RecordCount);
   else
      StatusBar1->SimpleText="Намерени: няма";
   if (PersonsQuery->RecordCount==0) PrintBtn->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::PrintBtnClick(TObject *Sender)
{
   search=false;
   ExamResultsResForm->QRSubDetail1->Enabled=ResultsCheck->Checked;
   ExamResultsResForm->ChildBand1->Enabled=ResultsCheck->Checked;
   //ExamResultsResForm->QRBand3->Frame->DrawTop=ResultsCheck->Checked;
   //PersonsQuery->DisableControls();
   ResultsQuery->DisableControls();
   ExamResultsResForm->SearcherQuickRep->Preview();
   search=true;
   //PersonsQuery->EnableControls();
   ResultsQuery->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::StatsBtnClick(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   if (ScoreRadio->Checked) {                      // Statistic by score
      ExamStatsGraphForm->ScoreDecisionCube->DataSet=NULL;

      ExamStatisticsResForm->ParseScoreQuery->Active=false;
      ExamStatisticsResForm->ParseScoreQuery->ParamByName("SET_EXAM")->AsInteger=ResolveProfileCode(ExamLookup->Text);
      ExamStatisticsResForm->ParseScoreQuery->Active=true;
      ExamStatisticsResForm->ScoreQuickRep->Preview();
      ExamStatisticsResForm->ParseScoreQuery->Active=false;
      ExamStatsGraphForm->ScoreDecisionCube->DataSet=ExamStatisticsResForm->ParseScoreQuery;
   } else {
      ExamStatsGraphForm->PointsDecisionGraph->Enabled=false;
      ExamStatsGraphForm->PointsDecisionCube->Active=false;
      try {
         ExamStatisticsResForm->ParsePointsQuery->Active=false;
         ExamStatisticsResForm->ParsePointsQuery->ParamByName("SET_EXAM")->AsInteger=ResolveProfileCode(ExamLookup->Text);
         ExamStatisticsResForm->ParsePointsQuery->Active=true;
      } catch (...) {
         Application->MessageBox("Грешка при генерирането на справката!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      }
      ExamStatisticsResForm->PointsQuickRep->Preview();
      ExamStatisticsResForm->ParsePointsQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::ChartBtnClick(TObject *Sender)
{
if (Data->Database1->Connected!=true) return;
   ExamStatsGraphForm->ScoreTab->TabVisible=false;
   ExamStatsGraphForm->PointsTab->TabVisible=false;
   if (ScoreRadio->Checked) {                      // Statistic by score
      try {
         ExamStatisticsResForm->ParseScoreQuery->Active=false;
         ExamStatisticsResForm->ParseScoreQuery->ParamByName("SET_EXAM")->AsInteger=ResolveProfileCode(ExamLookup->Text);
         ExamStatisticsResForm->ParseScoreQuery->Active=true;
      } catch (...) {
         Application->MessageBox("Грешка при генерирането на справката!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      }

      ExamStatsGraphForm->PointsDecisionGraph->Enabled=false;
      ExamStatsGraphForm->PointsDecisionCube->Active=false;

      ExamStatsGraphForm->ScoreDecisionCube->Active=true;
      ExamStatsGraphForm->PointsDecisionGraph->Enabled=true;
      ExamStatsGraphForm->PageControl->ActivePageIndex=0;
      ExamStatsGraphForm->Show();
      //ExamStatisticsResForm->ParseScoreQuery->Active=false;
   } else {
      try {
         ExamStatisticsResForm->ParsePointsQuery->Active=false;
         ExamStatisticsResForm->ParsePointsQuery->ParamByName("SET_EXAM")->AsInteger=ResolveProfileCode(ExamLookup->Text);
         ExamStatisticsResForm->ParsePointsQuery->Active=true;
      } catch (...) {
         Application->MessageBox("Грешка при генерирането на справката!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      }
      ExamStatsGraphForm->ScoreDecisionCube->Active=false;
      ExamStatsGraphForm->PointsDecisionGraph->Enabled=false;

      ExamStatsGraphForm->PointsDecisionGraph->Enabled=true;
      ExamStatsGraphForm->PointsDecisionCube->Active=true;

      ExamStatsGraphForm->PageControl->ActivePageIndex=1;
      ExamStatsGraphForm->Show();
   }
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::ExamCheckClick(TObject *Sender)
{
   if (ExamCheck->Checked||NumCheck->Checked||FkCheck->Checked||PreferedSchoolCheck->State!=cbGrayed)
      CandidTab->Highlighted=true;
   else CandidTab->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::HaveWishCheckClick(
      TObject *Sender)
{
   ProfileLookup->Enabled=HaveWishCheck->Checked;
   PriorityCheck->Enabled=HaveWishCheck->Checked;
   PriorityLookup->Enabled=HaveWishCheck->Checked&&PriorityCheck->Checked;
   
   WishTab->Highlighted=HaveWishCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TExamsResultSearcherForm::PriorityCheckClick(
      TObject *Sender)
{
   PriorityLookup->Enabled=PriorityCheck->Checked;   
}
//---------------------------------------------------------------------------

