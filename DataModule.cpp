//---------------------------------------------------------------------------

#include <vcl.h>
#include "Main.h"
#include<stdlib.h>
#pragma hdrstop

#include "DataModule.h"
#include "Library.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TData *Data;
extern bool DEBUG;
//---------------------------------------------------------------------------
__fastcall TData::TData(TComponent* Owner)
   : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TData::SetWishes(bool toState) {
   MainForm->WishesDBNavigator->Enabled=toState;
   MainForm->WishesPriorityLookup->Enabled=toState;
   MainForm->WishesProfileLookup->Enabled=toState;
   MainForm->WishesScoreEdit->Enabled=toState;
   MainForm->OlympCheck->Enabled=toState;
   MainForm->OlympScoreEdit->Enabled=toState;
   MainForm->GoToExamCheck->Enabled=toState;
   MainForm->WishesDBGrid->Enabled=toState;
//   MainForm->WishesPageControl->Enabled=toState;
//   MainForm->DBNavigator5->Enabled=toState;
   MainForm->OlympCheckClick(NULL);
}

void __fastcall TData::SetDataSets(bool toState) {
   if (Database1->Connected!=true) return;
// Refreshing DataSets...
   RegisterHistoryQuery->Active=false;
   TaxesTable->Active=toState;
   ProfilesTable->Active=toState;
   PersonsQuery->Active=toState;
   MainForm->WishesQuery->Active=toState;
   TextsTable->Active=toState;
   PlacesTable->Active=toState;
   RoomsTable->Active=toState;
   AllRoomsQuery->Active=toState;
   MainForm->AllTaxQuery->Active=toState;

   if (toState==true) {
      //AllocatedSpaceQuery->Active=toState;
      ProfilesHistShowQuery->Active=toState;
      RegisterGradeQuery->Active=toState;
   } else {
      RegisterGradeQuery->Active=toState;
      ProfilesHistShowQuery->Active=toState;
      //AllocatedSpaceQuery->Active=toState;
   }

   if (toState==true)
   MainForm->RegisterPersSearchBtnClick(NULL);
   else MainForm->RegisterQuery->Active=false;
/*
   if (toState==true)
      MainForm->ClassifProfileLookupClick(NULL);
   else
      RegisterUpperQuery->Active=toState;
*/
   //ExamsResultsQuery->Active=toState;
}
AnsiString __fastcall TData::GenerateRoomCode() {
 AnsiString Room;
 long free,rnd;
   CalcFreeRoomsQuery->Active=true;
   CalcFreeRoomsQuery->First();
   free=0;
   for (int i=0;i<CalcFreeRoomsQuery->RecordCount;i++) {
      if (CalcFreeRoomsQueryCNT->AsInteger>0)
         free+=CalcFreeRoomsQueryCNT->AsInteger;
      CalcFreeRoomsQuery->Next();
   }
   randomize();
   rnd=random(free)+1;
   CalcFreeRoomsQuery->First();
   for (int j=0;j<CalcFreeRoomsQuery->RecordCount;j++) {
      if (CalcFreeRoomsQueryCNT->AsInteger<=0) {
         CalcFreeRoomsQuery->Next();
         continue;
      }

      if (rnd>CalcFreeRoomsQueryCNT->AsInteger) {
         rnd-=CalcFreeRoomsQueryCNT->AsInteger;
         CalcFreeRoomsQuery->Next();
         continue;
      } else {
         Room=CalcFreeRoomsQueryCode->AsString;
         break;
      }
   }
   CalcFreeRoomsQuery->Active=false;
   if (Room.IsEmpty()) {
      Application->MessageBox("Няма повече места!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
   }
   return Room;
}

void __fastcall TData::CommitPersonsChanges() {
 AnsiString EGN;
 TLocateOptions p;
 bool flag=false;
   try {
      EGN=PersonsQuery->FieldByName("EGN")->AsString;
      PersonsQuery->CommitUpdates();
   } catch (Exception *E) {
      PersonsQuery->CancelUpdates();
      flag=true;
      MainForm->mainlog->WriteException(E->Message);
   }
   if (flag!=true) {
     PersonsQuery->Active=false;
     PersonsQuery->Active=true;
     PersonsQuery->Locate("EGN",EGN,p);
   }
      //PersonsQuery->Last();
  // } catch (...) {};
   if (MainForm->PageControl->ActivePage->Caption=="Reception")
      MainForm->StatusBar1->Panels->Items[0]->Text="Въведени :"+String(PersonsQuery->RecordCount);

}

void __fastcall TData::PersonsQueryAfterPost(TDataSet *DataSet)
{
   CommitPersonsChanges();
   SetWishes(true);
}
//---------------------------------------------------------------------------
void __fastcall TData::PersonsQueryAfterScroll(TDataSet *DataSet)
{

   if (PersonsQuery->Tag==0&&MainForm->PageControl->ActivePage->Caption=="Reception")
      MainForm->StatusBar1->Panels->Items[0]->Text="Въведени :"+String(PersonsQuery->RecordCount);

   if (MainForm->WishesQuery->Active==true)
      MainForm->WishesCountLabel->Caption="Желания: "+String(MainForm->WishesQuery->RecordCount);

   if (CheckEGN(MainForm->PersEGNEdit->Text.c_str())!=true&&!MainForm->PersEGNEdit->Text.IsEmpty()) {
      MainForm->PersEGNEdit->Font->Color=clRed;
   } else {
      MainForm->PersEGNEdit->Font->Color=clWindowText;
   }
   MainForm->TaxShower->Font->Color=clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TData::PersonsQueryAfterInsert(TDataSet *DataSet)
{
   SetWishes(false);
   //ShowMessage("After Insert");
//   PersonsQuery->FieldByName("Room_Code")->AsString=GenerateRoomCode();
   if (MainForm->PageControl->ActivePage->Caption=="Reception") {
      Data->PersonsQuery->FieldByName("Tax_id")->AsInteger=1;
      PersonsQueryPreferedSchool->AsBoolean=true; // default value
   }
}
//---------------------------------------------------------------------------
void __fastcall TData::PersonsQueryAfterCancel(TDataSet *DataSet)
{
   SetWishes(true);
}
//---------------------------------------------------------------------------
void __fastcall TData::TextsTableAfterPost(TDataSet *DataSet)
{
 TQuery *pQuery;
   if (Database1->Connected!=true) return;
   TextsTable->CommitUpdates();
}
//---------------------------------------------------------------------------

void __fastcall TData::TextsTableAfterScroll(TDataSet *DataSet)
{
   MainForm->DescriptionMemo->Lines->Clear();
   switch (DataSet->FieldByName("ID")->AsInteger) {
      case 1:
         MainForm->DescriptionMemo->Lines->Add("Появява се над Report-а за текущия кандидат");
      break;
      case 2:
         MainForm->DescriptionMemo->Lines->Add("Появява се под желанията в Report-а за текущия кандидат");
      break;
      case 3:
         MainForm->DescriptionMemo->Lines->Add("Появява се под мястото за провеждане на изпита по математика в Report-а за текущия кандидат. Поддържа се променлива #operator#, която се замества със оператора, въвел кандидата.");
      break;
      case 4:
         MainForm->DescriptionMemo->Lines->Add("Важи само за печат във текстов режим!\nПротокол за кандидат.\nЗа повече информация погледнете файла \"Person Blank.variables\"");
      break;
      case 5:
         MainForm->DescriptionMemo->Lines->Add("Важи само за печат във текстов режим!\nПротокол за зала.\nЗа повече информация погледнете файла \"Room Blank.variables\"");
      break;
      case 6:
         MainForm->DescriptionMemo->Lines->Add("Важи само за печат във текстов режим!\nТакси на текущия или избран оператор.\nЗа повече информация погледнете файла \"Taxes Blank.variables\"");
      break;
      case 7:
         MainForm->DescriptionMemo->Lines->Add("Важи само за печат във текстов режим!\nПротокол за изпит.\nЗа повече информация погледнете файла \"Exam Blank.variables\"");
      break;

      default:
         MainForm->DescriptionMemo->Lines->Add("--- Няма никаква роля! ---");
   }
}
//---------------------------------------------------------------------------
void __fastcall TData::ResolvePointsToScore() {
 TLocateOptions p;
 double first,last,t;
   if (ExamResultsQuery->FieldByName("Points")->IsNull) return;
   MainForm->ResolveProfileLookupCode(MainForm->ResultsExamLookup->Text);
   MainForm->PointsToScoreQuery->Active=false;
   MainForm->PointsToScoreQuery->ParamByName("SET_PROF")->AsInteger=MainForm->ProfileLookupCode;
   MainForm->PointsToScoreQuery->Active=true;
 // Checking range of points
   MainForm->PointsToScoreQuery->First();
   first=MainForm->PointsToScoreQuery->FieldByName("Point")->AsFloat;
   MainForm->PointsToScoreQuery->Last();
   last=MainForm->PointsToScoreQuery->FieldByName("Point")->AsFloat;

   if (first>last) {t=first; first=last; last=t;}
   if (ExamResultsQuery->FieldByName("Points")->AsFloat>last) {
      Application->MessageBox("Невалидни точки!","Внимание!",MB_OK|MB_APPLMODAL|MB_ICONWARNING);
   }
   if (ExamResultsQuery->FieldByName("Points")->AsFloat<first) {
      ExamResultsQuery->FieldByName("Score")->AsFloat=2;
   } else {
   // ---
     MainForm->PointsToScoreQuery->Locate("Point",ExamResultsQuery->FieldByName("Points")->AsFloat,p);
     if (MainForm->PointsToScoreQuery->FieldByName("Score")->AsFloat<3.0)
        ExamResultsQuery->FieldByName("Score")->AsFloat=2;
     else
        ExamResultsQuery->FieldByName("Score")->AsFloat=MainForm->PointsToScoreQuery->FieldByName("Score")->AsFloat;
   }
}

void __fastcall TData::ExamResultsQueryAfterPost(TDataSet *DataSet)
{
 TQuery *pQuery;
 int person;
 TLocateOptions p;
   if (Database1->Connected!=true) return;
   if (MainForm->ResultsExamLookup->Text.IsEmpty()) {
      ExamResultsQuery->CancelUpdates();
      return;
   }
   MainForm->ResolveProfileLookupCode(MainForm->ResultsExamLookup->Text);
   if (MainForm->ProfileLookupCode<0)  {
      ExamResultsQuery->CancelUpdates();
      return;
   }
   ValidateExamResultsQuery->Active=false;
   ValidateExamResultsQuery->ParamByName("SET_PERSON")->AsInteger=DataSet->FieldByName("Person_ID")->AsInteger;
   ValidateExamResultsQuery->Active=true;
   if (ExamResultsQuery->FieldByName("Exam")->AsInteger!=0) {
     // current exam isn't the first exam
      if (ValidateExamResultsQuery->RecordCount==0) {
         Application->MessageBox("Кандидатът не се е явил на първия изпит!","Внимание",MB_OK|MB_APPLMODAL|MB_ICONWARNING);
      } else {
         if (ValidateExamResultsQuery->FieldByName("Score")->AsFloat<3) {
            Application->MessageBox("Кандидатът има слаба оценка на първия изпит!","Внимание",MB_OK|MB_APPLMODAL|MB_ICONWARNING);
         }
      }
   }
   ValidateExamResultsQuery->Active=false;
   pQuery=ExamResultsUpdateSQL->Query[ukInsert];
   pQuery->ParamByName("SET_EXAM")->AsInteger=MainForm->ProfileLookupCode;
   pQuery=ExamResultsUpdateSQL->Query[ukModify];
   pQuery->ParamByName("SET_EXAM")->AsInteger=MainForm->ProfileLookupCode;
   pQuery=ExamResultsUpdateSQL->Query[ukDelete];
   pQuery->ParamByName("SET_EXAM")->AsInteger=MainForm->ProfileLookupCode;

   try {
      ExamResultsQuery->CommitUpdates();
      person=ExamResultsQuery->FieldByName("Person_ID")->AsInteger;

      ExamResultsQuery->Active=false;
      MainForm->ResolveProfileLookupCode(MainForm->ResultsExamLookup->Text);
      ExamResultsQuery->ParamByName("SET_EXAM")->AsInteger=MainForm->ProfileLookupCode;
      ExamResultsQuery->Active=true;
      ExamResultsQuery->Locate("Person_ID",person,p);
   } catch(...) {
      ExamResultsQuery->CancelUpdates();
   }
}
//---------------------------------------------------------------------------

void __fastcall TData::ExamResultsQueryBeforePost(TDataSet *DataSet)
{
   if (!ExamResultsQuery->FieldByName("Points")->IsNull)
   ResolvePointsToScore();
}
//---------------------------------------------------------------------------

void __fastcall TData::ExamResultsQueryAfterInsert(TDataSet *DataSet)
{
 // Setting Fk Number for inserting the record in the database
   //ExamResultsQuery->FieldByName("ID")->AsInteger=ExamResultsQuery->RecordCount+1;

   CalcFkNextQuery->Active=false;
   MainForm->ResolveProfileLookupCode(MainForm->ResultsExamLookup->Text);
   CalcFkNextQuery->ParamByName("SET_EXAM")->AsInteger=MainForm->ProfileLookupCode;
   CalcFkNextQuery->Active=true;
   ExamResultsQuery->FieldByName("ID")->AsInteger=CalcFkNextQuery->FieldByName("LAST")->AsInteger+1;
   CalcFkNextQuery->Active=false;
}
//---------------------------------------------------------------------------


void __fastcall TData::RegisterQueryAfterPost(TDataSet *DataSet)
{
/*
 TQuery *pQuery;
   if (Database1->Connected!=true) return;
   RegisterQuery->CommitUpdates();
*/
/*
   if (MainForm->ClassifProfileLookup->KeyValue.IsNull()) return;
   pQuery=RegisterUpperUpdateSQL->Query[ukDelete];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=MainForm->ClassifProfileLookup->KeyValue;
   pQuery=RegisterUpperUpdateSQL->Query[ukInsert];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=MainForm->ClassifProfileLookup->KeyValue;
   pQuery=RegisterUpperUpdateSQL->Query[ukModify];
   pQuery->ParamByName("SET_PROFILE")->AsInteger=MainForm->ClassifProfileLookup->KeyValue;
   try {

   } catch(...) {
      RegisterUpperQuery->CancelUpdates();
   }
*/
}
//---------------------------------------------------------------------------

void __fastcall TData::ProfilesTableCalcFields(TDataSet *DataSet)
{
 int val;
   if (DataSet->FieldByName("DiffMW")->AsBoolean==true) {
      val=DataSet->FieldByName("Space")->AsInteger-DataSet->FieldByName("SpaceOther")->AsInteger;
      if (val>0)
         DataSet->FieldByName("SpaceW")->AsString=String(val);
      else DataSet->FieldByName("SpaceW")->AsString=String(DataSet->FieldByName("SpaceOther")->AsInteger);
   } else {
      DataSet->FieldByName("SpaceW")->AsString="---";
   }
}
//---------------------------------------------------------------------------
void __fastcall TData::PersonsQueryUpdateError(TDataSet *DataSet,
      EDatabaseError *E, TUpdateKind UpdateKind,
      TUpdateAction &UpdateAction)
{
  if (!DEBUG) {
    if (dynamic_cast<EDBEngineError*>(E) != 0) {
       if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind!=ukDelete) {
          Application->MessageBox("Грешка при записването на данните.\nВероятно повтарящо се ЕГН или липсващи данни!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
          return;
       }
       if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind==ukDelete) {
          Application->MessageBox("Грешка при записването на данните.\nЗаписа не може да бъде изтрит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
          return;
       }
    }
  } else Application->ShowException(E);
  MainForm->mainlog->WriteException(E->Message);
}
//---------------------------------------------------------------------------
void __fastcall TData::RegisterHistoryQueryAfterOpen(TDataSet *DataSet)
{
  MainForm->ShowProgress("Кандидати: "+String(Data->RegisterHistoryQuery->RecordCount),0,0);
}
//---------------------------------------------------------------------------

void __fastcall TData::RegisterGradeQueryAfterScroll(TDataSet *DataSet)
{
   MainForm->ClassifProfileLookupClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TData::PersonsQueryBeforePost(TDataSet *DataSet)
{
   if (PersonsQuery->State==dsInsert) {
      PersonsQuery->FieldByName("Room_Code")->AsString=GenerateRoomCode();
      //-----
      SearchSwapsQuery->Active=false;
      SearchSwapsQuery->Active=true;
      if (SearchSwapsQuery->RecordCount!=0&&MainForm->NOFillHoles==false) { // fill holes if available and allowed
         PersonsQuery->FieldByName("ID")->AsInteger=SearchSwapsQuery->FieldByName("AfterSwap")->AsInteger-1;
      } else {
         MAXIDQuery->Active=false;
         MAXIDQuery->Active=true;
         if (MAXIDQuery->RecordCount!=0) {
            PersonsQuery->FieldByName("ID")->AsInteger=MAXIDQuery->FieldByName("MAXIMUM")->AsInteger+1+MainForm->startIndex;
         } else PersonsQuery->FieldByName("ID")->AsInteger=1;
      }
      SearchSwapsQuery->Active=false;
      MAXIDQuery->Active=false;
   }
}
//---------------------------------------------------------------------------


void __fastcall TData::ExamResultsQueryUpdateError(TDataSet *DataSet,
      EDatabaseError *E, TUpdateKind UpdateKind,
      TUpdateAction &UpdateAction)
{
  MainForm->mainlog->WriteException(E->Message);
  if (!DEBUG) {
     UpdateAction=uaAbort;
     if (E->Message.AnsiPos("Кандидатът не е пожелал такъв изпит!")>0) {
         Application->MessageBox("Кандидата не е пожелал такова желание или няма да ходи на изпит!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return;
     }
     if (E->Message.AnsiPos("Кандидатът няма въведен първи изпит!")>0) {
         Application->MessageBox("Кандидатът няма въведен първи изпит!\nВъвеждането на следващи изпити е НЕВЪЗМОЖНО!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return;
     }
     if (E->Message.AnsiPos("Кандидатът има слаба оценка на първия изпит!")>0) {
         Application->MessageBox("Кандидатът има слаба оценка на първия изпит!\nВъвеждането на следващи изпити е НЕВЪЗМОЖНО!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return;
     }
     if (dynamic_cast<EDBEngineError*>(E) != 0) {
        if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind!=ukDelete) {
           Application->MessageBox("Грешка при записването на данните.\nВероятно повтарящ се входен номер или липсващи данни!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
           return;
        }
        if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol&&UpdateKind==ukDelete) {
           Application->MessageBox("Грешка при записването на данните.\nЗаписа не може да бъде изтрит!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
           return;
        }
     }
  }
  UpdateAction=uaFail;
  Application->ShowException(E);
}
//---------------------------------------------------------------------------

void __fastcall TData::ExamResultsQueryAfterScroll(TDataSet *DataSet)
{
   if (ExamResultsQuery->Active==true)
      MainForm->ShowProgress("Въведени резултати по "+MainForm->ResultsExamLookup->Text+": "+String(ExamResultsQuery->RecordCount),0,0);
}
//---------------------------------------------------------------------------

void __fastcall TData::ProfilesHistShowQueryCalcFields(TDataSet *DataSet)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return;

   switch (DataSet->FieldByName("DiffMW")->AsBoolean) {
      case false:
         DataSet->FieldByName("SpaceFemale")->AsString="";
      break;
      case true:
         DataSet->FieldByName("SpaceFemale")->AsString=String(DataSet->FieldByName("Space")->AsInteger-DataSet->FieldByName("SpaceOther")->AsInteger);
      break;
   }
}
//---------------------------------------------------------------------------

void __fastcall TData::ProfilesTableAfterPost(TDataSet *DataSet)
{
   ProfilesTable->CommitUpdates();   
}
//---------------------------------------------------------------------------

