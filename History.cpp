//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "History.h"
#include "Library.h"
#include "DataModule.h"
#include "PersonsHistoryRes.h"
#include "WishesHistoryRes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
THistoryForm *HistoryForm;
//---------------------------------------------------------------------------
__fastcall THistoryForm::THistoryForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THistoryForm::BitBtn1Click(TObject *Sender)
{
   Close();   
}
//---------------------------------------------------------------------------
void __fastcall THistoryForm::FormCreate(TObject *Sender)
{
   StartChangedDateTime->Date=Now();
   EndChangedDateTime->Date=Now();
   StartEntDateTime->Date=Now();
   EndEntDateTime->Date=Now();

   StartEntWishDateTime->Date=Now();
   EndEntWishDateTime->Date=Now();
   
   StartChangedWishDateTime->Date=Now();
   EndChangedWishDateTime->Date=Now();
}
//---------------------------------------------------------------------------
void __fastcall THistoryForm::HighLightOper() {
   if (ChangedOperCheck->Checked||ChangedDateCheck->Checked||
    EntOperatorCheck->Checked||EntDateCheck->Checked)
      OperTab->Highlighted=true;
   else
      OperTab->Highlighted=false;
}

void __fastcall THistoryForm::ChangedOperCheckClick(TObject *Sender)
{
   ChangedOperCombo->Enabled=ChangedOperCheck->Checked;
   HighLightOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::EntOperatorCheckClick(TObject *Sender)
{
   EntOperatorCombo->Enabled=EntOperatorCheck->Checked;
   HighLightOper();   
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::ChangedDateCheckClick(TObject *Sender)
{
   StartChangedDateTime->Enabled=ChangedDateCheck->Checked;
   EndChangedDateTime->Enabled=ChangedDateCheck->Checked;
   HighLightOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::EntDateCheckClick(TObject *Sender)
{
   StartEntDateTime->Enabled=EntDateCheck->Checked;
   EndEntDateTime->Enabled=EntDateCheck->Checked;
   HighLightOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::TaxTypeCheckClick(TObject *Sender)
{
   TaxTypeLookup->Enabled=TaxTypeCheck->Checked;
   NameEditChange(NULL);   
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::SexTypeCheckClick(TObject *Sender)
{
   MaleBtn->Enabled=SexTypeCheck->Checked;
   FemaleBtn->Enabled=SexTypeCheck->Checked;
   NameEditChange(NULL);   
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::NameEditChange(TObject *Sender)
{
   if (!NameEdit->Text.IsEmpty()||!EGNEdit->Text.IsEmpty()||
    (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull())||
    SexTypeCheck->Checked||IDCheck->Checked||
    (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()))
      OwnTab->Highlighted=true;
   else
      OwnTab->Highlighted=false;
}
//---------------------------------------------------------------------------
int __fastcall THistoryForm::CalcPersAnds() {
 int ans=0;
   if (ChangedOperCheck->Checked) ans++;
   if (EntOperatorCheck->Checked) ans++;
   if (ChangedDateCheck->Checked) ans++;
   if (EntDateCheck->Checked) ans++;

   if (!NameEdit->Text.IsEmpty()) ans++;
   if (!EGNEdit->Text.IsEmpty()) ans++;
   if (IDCheck->Checked) ans++;
   if (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull()) ans++;
   if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) ans++;
   if (SexTypeCheck->Checked) ans++;   
   return ans;
}

void __fastcall THistoryForm::SearchBtnClick(TObject *Sender)
{
 int ands;
 TDateTime tmp;
 AnsiString name,egn;
   if (PageControl->ActivePageIndex==0) {
    // Кандидати
      PersonsHistoryQuery->Active=false;
      PersonsHistoryQuery->SQL->Clear();
      PersonsHistoryQuery->SQL->Add("SELECT * FROM persons_history ");
      ands=CalcPersAnds();
      if (ands>0) PersonsHistoryQuery->SQL->Add(" WHERE ");
      if (ChangedOperCheck->Checked) {
         PersonsHistoryQuery->SQL->Add(" changedby='"+ChangedOperCombo->Text+"' ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (ChangedDateCheck->Checked) {
         PersonsHistoryQuery->SQL->Add(" (DATEDIFF(d,datechanged,:SET_STARTDATE)<=0 AND DATEDIFF(d,datechanged,:SET_ENDDATE)>=0) ");
         if (StartChangedDateTime->DateTime>EndChangedDateTime->DateTime) {
            tmp=StartChangedDateTime->DateTime;
            StartChangedDateTime->DateTime=EndChangedDateTime->DateTime;
            EndChangedDateTime->DateTime=tmp;
         }
         PersonsHistoryQuery->ParamByName("SET_STARTDATE")->AsDateTime=StartChangedDateTime->DateTime;
         PersonsHistoryQuery->ParamByName("SET_ENDDATE")->AsDateTime=EndChangedDateTime->DateTime;
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
    //-------
      if (EntOperatorCheck->Checked) {
         PersonsHistoryQuery->SQL->Add(" entby='"+EntOperatorCombo->Text+"' ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (EntDateCheck->Checked) {
         PersonsHistoryQuery->SQL->Add(" (DATEDIFF(d,datechanged,:SET_STARTTDATE)<=0 AND DATEDIFF(d,datechanged,:SET_ENDTDATE)>=0) ");
         if (StartEntDateTime->DateTime>EndEntDateTime->DateTime) {
            tmp=StartEntDateTime->DateTime;
            StartEntDateTime->DateTime=EndEntDateTime->DateTime;
            EndEntDateTime->DateTime=tmp;
         }
         PersonsHistoryQuery->ParamByName("SET_STARTTDATE")->AsDateTime=StartEntDateTime->DateTime;
         PersonsHistoryQuery->ParamByName("SET_ENDTDATE")->AsDateTime=EndEntDateTime->DateTime;
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (!NameEdit->Text.IsEmpty()) {
         name=NameEdit->Text;
         ReplaceChars(name);
         PersonsHistoryQuery->SQL->Add(" name LIKE '"+name+"%' ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (IDCheck->Checked) {
         PersonsHistoryQuery->SQL->Add(" ID="+String(IDEdit->Value)+" ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (!EGNEdit->Text.IsEmpty()) {
         egn=EGNEdit->Text;
         ReplaceChars(egn);
         PersonsHistoryQuery->SQL->Add(" EGN LIKE '"+egn+"%' ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (SexTypeCheck->Checked) {
         if (MaleBtn->Checked)
            PersonsHistoryQuery->SQL->Add(" sex=1 ");
         else
            PersonsHistoryQuery->SQL->Add(" sex=0 ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull()) {
         PersonsHistoryQuery->SQL->Add(" tax_id="+String(TaxTypeLookup->KeyValue)+" ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) {
         PersonsHistoryQuery->SQL->Add(" Room_Code='"+String(RoomLookup->KeyValue)+"' ");
         ands--;
         if (ands>0) PersonsHistoryQuery->SQL->Add(" AND ");
      }
      PersonsHistoryQuery->SQL->Add(" ORDER BY DateChanged DESC ");
      //ShowMessage(PersonsHistoryQuery->SQL->Text);
      PersonsHistoryQuery->Active=true;
      if (PersonsHistoryQuery->RecordCount>0)
         FoundLabel->Caption="Намерени: "+String(PersonsHistoryQuery->RecordCount);
      else
         FoundLabel->Caption="Намерени: няма";
   } else {
    // Желания
      WishesQuery->Active=false;
      WishesQuery->SQL->Clear();
      WishesQuery->SQL->Add("SELECT * FROM wishes_history ");
      ands=CalcWishAnds();
      if (ands>0) WishesQuery->SQL->Add(" WHERE ");

      if (ChangedWishCheck->Checked) {
         WishesQuery->SQL->Add(" changedby='"+ChangedWishOperCombo->Text+"' ");
         ands--;
         if (ands>0) WishesQuery->SQL->Add(" AND ");
      }
      if (ChangedWishDateCheck->Checked) {
         WishesQuery->SQL->Add(" (DATEDIFF(d,datechanged,:SET_STARTTDATE)<=0 AND DATEDIFF(d,datechanged,:SET_ENDTDATE)>=0) ");
         if (StartChangedWishDateTime->DateTime>EndChangedWishDateTime->DateTime) {
            tmp=StartChangedWishDateTime->DateTime;
            StartChangedWishDateTime->DateTime=EndChangedWishDateTime->DateTime;
            EndChangedWishDateTime->DateTime=tmp;
         }
         WishesQuery->ParamByName("SET_STARTTDATE")->AsDateTime=StartChangedWishDateTime->DateTime;
         WishesQuery->ParamByName("SET_ENDTDATE")->AsDateTime=EndChangedWishDateTime->DateTime;

         ands--;
         if (ands>0) WishesQuery->SQL->Add(" AND ");
      }

      if (EntWishOperCheck->Checked) {
         WishesQuery->SQL->Add(" Entby='"+EntWishOperCombo->Text+"' ");
         ands--;
         if (ands>0) WishesQuery->SQL->Add(" AND ");
      }
      if (EntWishDateCheck->Checked) {
         WishesQuery->SQL->Add(" (DATEDIFF(d,EntOn,:SET_STARTEDATE)<=0 AND DATEDIFF(d,EntOn,:SET_ENDEDATE)>=0) ");
         if (StartEntWishDateTime->DateTime>EndEntWishDateTime->DateTime) {
            tmp=StartEntWishDateTime->DateTime;
            StartEntWishDateTime->DateTime=EndEntWishDateTime->DateTime;
            EndEntWishDateTime->DateTime=tmp;
         }
         WishesQuery->ParamByName("SET_STARTEDATE")->AsDateTime=StartEntWishDateTime->DateTime;
         WishesQuery->ParamByName("SET_ENDEDATE")->AsDateTime=EndEntWishDateTime->DateTime;

         ands--;
         if (ands>0) WishesQuery->SQL->Add(" AND ");
      }

      ///
      if (CandidWishCheck->Checked) {
         WishesQuery->SQL->Add(" Person_ID="+String(CandidNumEdit->Value)+" ");
      }
      WishesQuery->SQL->Add(" ORDER BY datechanged DESC");
      //ShowMessage(WishesQuery->SQL->Text);
      WishesQuery->Active=true;
      if (WishesQuery->RecordCount>0)
         FoundLabel->Caption="Намерени желания: "+String(WishesQuery->RecordCount);
      else
         FoundLabel->Caption="Намерени желания: няма";
   }
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::PersonsHistoryQueryCalcFields(
      TDataSet *DataSet)
{
   switch (DataSet->FieldByName("Sex")->AsInteger) {
      case 1:
         PersonsHistoryQuerySe->AsString="М";
      break;
      case 0:
         PersonsHistoryQuerySe->AsString="Ж";
      break;
   }
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::IDCheckClick(TObject *Sender)
{
   IDEdit->Enabled=IDCheck->Checked;
   NameEditChange(NULL);   
}
//---------------------------------------------------------------------------

//===========================================================================
//--------- Желания ---------------------------------------------------------
//===========================================================================
int __fastcall THistoryForm::CalcWishAnds() {
 int ans=0;
   if (ChangedWishCheck->Checked) ans++;
   if (ChangedWishDateCheck->Checked) ans++;
   if (EntWishOperCheck->Checked) ans++;
   if (EntWishDateCheck->Checked) ans++;
   if (CandidWishCheck->Checked) ans++;
   return ans;
}
void __fastcall THistoryForm::HighLightWishOper() {
   if (ChangedWishCheck->Checked||ChangedWishDateCheck->Checked
    ||EntWishOperCheck->Checked||EntWishDateCheck->Checked)
      WishOperTab->Highlighted=true;
   else
      WishOperTab->Highlighted=false;
}
void __fastcall THistoryForm::CandidWishCheckClick(TObject *Sender)
{
   CandidNumEdit->Enabled=CandidWishCheck->Checked;
   CandidWishNameLookup->Enabled=CandidWishCheck->Checked;
   if (CandidWishCheck->Checked)
      WishOwnTab->Highlighted=true;
   else
      WishOwnTab->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::ChangedWishCheckClick(TObject *Sender)
{
   ChangedWishOperCombo->Enabled=ChangedWishCheck->Checked;
   HighLightWishOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::ChangedWishDateCheckClick(TObject *Sender)
{
   StartChangedWishDateTime->Enabled=ChangedWishDateCheck->Checked;
   EndChangedWishDateTime->Enabled=ChangedWishDateCheck->Checked;
   HighLightWishOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::FormShow(TObject *Sender)
{
   PersonsQuery->Active=true;
   Tag=0;
   try {
      EntByQuery->Active=true;
      EntOperatorCombo->Items->Clear();
      for (int i=0;i<EntByQuery->RecordCount;i++) {
         EntOperatorCombo->Items->Add(EntByQuery->FieldByName("entby")->AsString);
         EntByQuery->Next();
      }
      EntByQuery->Active=false;

      EntByWishQuery->Active=true;
      EntWishOperCombo->Items->Clear();
      for (int i=0;i<EntByWishQuery->RecordCount;i++) {
         EntWishOperCombo->Items->Add(EntByWishQuery->FieldByName("entby")->AsString);
         EntByWishQuery->Next();
      }
      EntByWishQuery->Active=false;

      ChangedByQuery->Active=true;
      ChangedOperCombo->Items->Clear();
      for (int j=0;j<ChangedByQuery->RecordCount;j++) {
         ChangedOperCombo->Items->Add(ChangedByQuery->FieldByName("changedby")->AsString);
         ChangedByQuery->Next();
      }
      ChangedByQuery->Active=false;

      ChangedWishQuery->Active=true;
      ChangedWishOperCombo->Items->Clear();
      for (int z=0;z<ChangedWishQuery->RecordCount;z++) {
         ChangedWishOperCombo->Items->Add(ChangedWishQuery->FieldByName("changedby")->AsString);
         ChangedWishQuery->Next();
      }
      ChangedWishQuery->Active=false;
   } catch (...) {
      Application->MessageBox("Нямате права за достъп до историята!","Грешка",MB_OK|MB_ICONERROR|MB_APPLMODAL);
      Tag=1;
      return;

   }
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   PersonsQuery->Active=false;
   EntByQuery->Active=false;
   ChangedByQuery->Active=false;
   ChangedWishQuery->Active=false;
   EntByWishQuery->Active=false;
   WishesQuery->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::WishesQueryCalcFields(TDataSet *DataSet)
{
   switch (DataSet->FieldByName("GoToExam")->AsBoolean) {
      case true:
         if (DataSet->FieldByName("FromOlymp")->AsBoolean==true)
            DataSet->FieldByName("GoToE")->AsString="Да";
         else
            DataSet->FieldByName("GoToE")->AsString="";
      break;
      case false:
         if (DataSet->FieldByName("FromOlymp")->AsBoolean==true)
            DataSet->FieldByName("GoToE")->AsString="Не";
         else
            DataSet->FieldByName("GoToE")->AsString="";
      break;
   }
   switch (DataSet->FieldByName("FromOlymp")->AsBoolean) {
      case true:
         DataSet->FieldByName("FromOlym")->AsString="Да";
      break;
      case false:
         DataSet->FieldByName("FromOlym")->AsString="Не";
      break;
   }
}
//---------------------------------------------------------------------------


void __fastcall THistoryForm::CandidNumEditChange(TObject *Sender)
{
   CandidWishNameLookup->KeyValue=CandidNumEdit->Value;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::PageControlChange(TObject *Sender)
{
   switch (PageControl->ActivePageIndex) {
      case 0:
         if (PersonsHistoryQuery->Active==true)
         if (PersonsHistoryQuery->RecordCount>0)
            FoundLabel->Caption="Намерени: "+String(PersonsHistoryQuery->RecordCount);
         else
            FoundLabel->Caption="Намерени: няма";
      break;
      case 1:
         if (WishesQuery->Active==true)
         if (WishesQuery->RecordCount>0)
            FoundLabel->Caption="Намерени желания: "+String(WishesQuery->RecordCount);
         else
            FoundLabel->Caption="Намерени желания: няма";
      break;
   }
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::PrintBtnClick(TObject *Sender)
{
   switch (PageControl->ActivePageIndex) {
      case 0:
         PersonsHistoryResForm->QuickRep1->Preview();
      break;
      case 1:
         WishesHistoryResForm->QuickRep1->Preview();
      break;
   }
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::FormPaint(TObject *Sender)
{
   if (Tag==1) Close();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::RoomCheckClick(TObject *Sender)
{
   RoomLookup->Enabled=RoomCheck->Checked;
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::EntWishOperCheckClick(TObject *Sender)
{
   EntWishOperCombo->Enabled=EntWishOperCheck->Checked;
   HighLightWishOper();
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::EntWishDateCheckClick(TObject *Sender)
{
   StartEntWishDateTime->Enabled=EntWishDateCheck->Checked;
   EndEntWishDateTime->Enabled=EntWishDateCheck->Checked;
   HighLightWishOper();
}
//---------------------------------------------------------------------------


void __fastcall THistoryForm::CandidWishNameLookupCloseUp(TObject *Sender)
{
   if (CandidWishNameLookup->KeyValue.IsNull()||Data->Database1->Connected!=true) return;
   CandidNumEdit->Value=CandidWishNameLookup->KeyValue;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N2Click(TObject *Sender)
{
   DBGrid1->Columns->Items[1]->Visible=N2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N3Click(TObject *Sender)
{
   DBGrid1->Columns->Items[2]->Visible=N3->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N4Click(TObject *Sender)
{
   DBGrid1->Columns->Items[3]->Visible=N4->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N5Click(TObject *Sender)
{
   DBGrid1->Columns->Items[4]->Visible=N5->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N6Click(TObject *Sender)
{
   DBGrid1->Columns->Items[5]->Visible=N6->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N7Click(TObject *Sender)
{
   DBGrid1->Columns->Items[6]->Visible=N7->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N8Click(TObject *Sender)
{
   DBGrid1->Columns->Items[7]->Visible=N8->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N9Click(TObject *Sender)
{
   DBGrid1->Columns->Items[8]->Visible=N9->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N10Click(TObject *Sender)
{
   DBGrid1->Columns->Items[9]->Visible=N10->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N11Click(TObject *Sender)
{
   DBGrid1->Columns->Items[10]->Visible=N11->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N12Click(TObject *Sender)
{
   DBGrid1->Columns->Items[11]->Visible=N12->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::N13Click(TObject *Sender)
{
   DBGrid1->Columns->Items[12]->Visible=N13->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::NAllClick(TObject *Sender)
{
   DBGrid1->Columns->Items[1]->Visible=true;
   DBGrid1->Columns->Items[2]->Visible=true;
   DBGrid1->Columns->Items[3]->Visible=true;
   DBGrid1->Columns->Items[4]->Visible=true;
   DBGrid1->Columns->Items[5]->Visible=true;
   DBGrid1->Columns->Items[6]->Visible=true;
   DBGrid1->Columns->Items[7]->Visible=true;
   DBGrid1->Columns->Items[8]->Visible=true;
   DBGrid1->Columns->Items[9]->Visible=true;
   DBGrid1->Columns->Items[10]->Visible=true;
   DBGrid1->Columns->Items[11]->Visible=true;
   DBGrid1->Columns->Items[12]->Visible=true;

   N2->Checked=true;
   N3->Checked=true;
   N4->Checked=true;
   N5->Checked=true;
   N6->Checked=true;
   N7->Checked=true;
   N8->Checked=true;
   N9->Checked=true;
   N10->Checked=true;
   N11->Checked=true;
   N12->Checked=true;
   N13->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem4Click(TObject *Sender)
{
   DBGrid2->Columns->Items[1]->Visible=MenuItem4->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem5Click(TObject *Sender)
{
   DBGrid2->Columns->Items[2]->Visible=MenuItem5->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem6Click(TObject *Sender)
{
   DBGrid2->Columns->Items[3]->Visible=MenuItem6->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem7Click(TObject *Sender)
{
   DBGrid2->Columns->Items[4]->Visible=MenuItem7->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem8Click(TObject *Sender)
{
   DBGrid2->Columns->Items[5]->Visible=MenuItem8->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem9Click(TObject *Sender)
{
   DBGrid2->Columns->Items[6]->Visible=MenuItem9->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem10Click(TObject *Sender)
{
   DBGrid2->Columns->Items[7]->Visible=MenuItem10->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem11Click(TObject *Sender)
{
   DBGrid2->Columns->Items[8]->Visible=MenuItem11->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem12Click(TObject *Sender)
{
   DBGrid2->Columns->Items[9]->Visible=MenuItem12->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem13Click(TObject *Sender)
{
   DBGrid2->Columns->Items[10]->Visible=MenuItem13->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem14Click(TObject *Sender)
{
   DBGrid2->Columns->Items[11]->Visible=MenuItem14->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem15Click(TObject *Sender)
{
   DBGrid2->Columns->Items[12]->Visible=MenuItem15->Checked;
}
//---------------------------------------------------------------------------

void __fastcall THistoryForm::MenuItem1Click(TObject *Sender)
{
   DBGrid2->Columns->Items[1]->Visible=true;
   DBGrid2->Columns->Items[2]->Visible=true;
   DBGrid2->Columns->Items[3]->Visible=true;
   DBGrid2->Columns->Items[4]->Visible=true;
   DBGrid2->Columns->Items[5]->Visible=true;
   DBGrid2->Columns->Items[6]->Visible=true;
   DBGrid2->Columns->Items[7]->Visible=true;
   DBGrid2->Columns->Items[8]->Visible=true;
   DBGrid2->Columns->Items[9]->Visible=true;
   DBGrid2->Columns->Items[10]->Visible=true;
   DBGrid2->Columns->Items[11]->Visible=true;
   DBGrid2->Columns->Items[12]->Visible=true;

   MenuItem4->Checked=true;
   MenuItem5->Checked=true;
   MenuItem6->Checked=true;
   MenuItem7->Checked=true;
   MenuItem8->Checked=true;
   MenuItem9->Checked=true;
   MenuItem10->Checked=true;
   MenuItem11->Checked=true;
   MenuItem12->Checked=true;
   MenuItem13->Checked=true;
   MenuItem14->Checked=true;
   MenuItem15->Checked=true;

}
//---------------------------------------------------------------------------

