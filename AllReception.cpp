//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AllReception.h"
#include "DataModule.h"
#include "Library.h"
#include "AllReceptionRes.h"
#include "AllReceptionProfilesRes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TAllReceptionForm *AllReceptionForm;
//---------------------------------------------------------------------------
__fastcall TAllReceptionForm::TAllReceptionForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAllReceptionForm::Hiligh() {
   if (OperatorNameCheck->Checked||DateEntered->Checked)
      Tab2->Highlighted=true;
   else
      Tab2->Highlighted=false;
}

void __fastcall TAllReceptionForm::OperatorNameCheckClick(TObject *Sender)
{
   OperatorNameCombo->Enabled=OperatorNameCheck->Checked;
   Hiligh();
}
//---------------------------------------------------------------------------
void __fastcall TAllReceptionForm::DateEnteredClick(TObject *Sender)
{
   StartDateTime->Enabled=DateEntered->Checked;
   EndDateTime->Enabled=DateEntered->Checked;
   Hiligh();
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::CancelBtnClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::SexTypeCheckClick(TObject *Sender)
{
   NameEditChange(NULL);
   MaleBtn->Enabled=SexTypeCheck->Checked;
   FemaleBtn->Enabled=SexTypeCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::TaxTypeCheckClick(TObject *Sender)
{
   NameEditChange(NULL);
   TaxTypeLookup->Enabled=TaxTypeCheck->Checked;
   TaxNOT->Enabled=TaxTypeCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::FormActivate(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   OperatorsQuery->Active=true;
   RoomQuery->Active=false;
   RoomQuery->Active=true;
   OperatorNameCombo->Items->Clear();
   for (int i=0;i<OperatorsQuery->RecordCount;i++) {
      OperatorNameCombo->Items->Add(OperatorsQuery->FieldByName("entby")->AsString);
      OperatorsQuery->Next();
   }
   OperatorsQuery->Active=false;
}
//---------------------------------------------------------------------------
int __fastcall TAllReceptionForm::CalcAnds() {
 int ans=0;
   if (!NameEdit->Text.IsEmpty()) ans++;
   if (IDCheck->Checked) ans++;
   if (!EGNEdit->Text.IsEmpty()) ans++;
   if (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull()) ans++;
   if (SexTypeCheck->Checked) ans++;
   if (OperatorNameCheck->Checked) ans++;
   if (DateEntered->Checked) ans++;
   if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) ans++;

   if (OlympCheck->Checked||(WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull())) ans++;
   if (!AddressEdit->Text.IsEmpty()) ans++;
   //if (WishesEntCheck->Checked&&PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull()) ans++;

   //if (OlympCheck->Checked) ans++;
   return ans;
}
int WishCheck() {
 int res=0;
   if (AllReceptionForm->OlympCheck->Checked) res++;
   if (AllReceptionForm->WishesEntCheck->Checked&&!AllReceptionForm->WishesLookup->KeyValue.IsNull()) res++;
   if (AllReceptionForm->PriorityCheck->Checked&&!AllReceptionForm->PriorityLookup->KeyValue.IsNull()) res++;
   return res;
}

void __fastcall TAllReceptionForm::SearchBtnClick(TObject *Sender)
{
 AnsiString name,egn;
 int ands=0;
 TDateTime tmp;
 int wantAND=0;
   if (Data->Database1->Connected!=true) return;
   ParseQuery->Active=false;
   WishesQuery->Active=false;
   ParseQuery->SQL->Clear();
   ParseQuery->SQL->Add("SELECT p.ID,p.Name,p.PreferedSchool,p.EGN,p.Telephone,p.Address,p.Sex,p.Tax_id,p.Room_Code,p.EntOn,p.EntBy \
FROM persons p ");
   ands=CalcAnds();
   if (ands>0) ParseQuery->SQL->Add(" WHERE ");
 //--- Checking Wishes Tab---------------------
   if (OlympCheck->Checked||(WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull())) {
      wantAND=WishCheck();
      ParseQuery->SQL->Add(" EXISTS (SELECT * FROM Wishes w WHERE p.ID=w.Person_ID AND ");
      if (OlympCheck->Checked) {
         ParseQuery->SQL->Add(" w.FromOlymp=1 ");
         wantAND--;
         if (wantAND>0) ParseQuery->SQL->Add(" AND ");
      }
      if (WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull()) {
         ParseQuery->SQL->Add(" w.Profile_ID="+String(WishesLookup->KeyValue)+" ");
         wantAND--;
         if (wantAND>0) ParseQuery->SQL->Add(" AND ");
      }
      if (PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull()) {
         ParseQuery->SQL->Add(" w.Priority="+String(PriorityLookup->KeyValue)+" ");
      }
      ParseQuery->SQL->Add(") ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
 //--- Wishes Tab DONE!
   if (!NameEdit->Text.IsEmpty()) {
      name=NameEdit->Text;
      ReplaceChars(name);
      if (!NameNOT->Down)
         ParseQuery->SQL->Add(" p.name LIKE '%"+name+"%' ");
      else
         ParseQuery->SQL->Add(" p.name NOT LIKE '%"+name+"%' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (IDCheck->Checked) {
      ParseQuery->SQL->Add(" p.ID="+String(IDEdit->Value));
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (!EGNEdit->Text.IsEmpty()) {
      egn=EGNEdit->Text;
      ReplaceChars(egn);
      if (!EGNNOT->Down)
         ParseQuery->SQL->Add(" p.egn LIKE '"+egn+"%"+"' ");
      else
         ParseQuery->SQL->Add(" p.egn NOT LIKE '"+egn+"%"+"' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (!AddressEdit->Text.IsEmpty()) {
      egn=AddressEdit->Text;
      ReplaceChars(egn);
      if (!AddressNOT->Down)
         ParseQuery->SQL->Add(" p.Address LIKE '%"+egn+"%' ");
      else
         ParseQuery->SQL->Add(" p.Address NOT LIKE '%"+egn+"%' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull()) {
      if (!TaxNOT->Down)
         ParseQuery->SQL->Add(" p.tax_id="+String(TaxTypeLookup->KeyValue)+" ");
      else
         ParseQuery->SQL->Add(" NOT p.tax_id="+String(TaxTypeLookup->KeyValue)+" ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (SexTypeCheck->Checked) {
      if (MaleBtn->Checked)
         ParseQuery->SQL->Add(" p.Sex=1 ");
      else
         ParseQuery->SQL->Add(" p.Sex=0 ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }

   if (OperatorNameCheck->Checked) {
      ParseQuery->SQL->Add(" p.EntBy='"+OperatorNameCombo->Text+"' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   if (DateEntered->Checked) {
      ParseQuery->SQL->Add(" (DATEDIFF(d,p.enton,:SET_START)<=0 AND DATEDIFF(d,p.enton,:SET_END)>=0) ");
      if (StartDateTime->DateTime>EndDateTime->DateTime) {
         tmp=StartDateTime->DateTime;
         StartDateTime->DateTime=EndDateTime->DateTime;
         EndDateTime->DateTime=tmp;
      }
      ParseQuery->ParamByName("SET_START")->AsDateTime=StartDateTime->DateTime;
      ParseQuery->ParamByName("SET_END")->AsDateTime=EndDateTime->DateTime;
   }
   if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) {
      if (!RoomNOT->Down)
         ParseQuery->SQL->Add(" p.Room_Code='"+String(RoomLookup->KeyValue)+"' ");
      else
         ParseQuery->SQL->Add(" NOT p.Room_Code='"+String(RoomLookup->KeyValue)+"' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   WishesQuery->SQL->Clear();
   if (!OlympCheck->Checked)
      WishesQuery->SQL->Add("SELECT * FROM dbo.wishes wh WHERE wh.person_id=:ID ORDER BY wh.Priority");
   else
      WishesQuery->SQL->Add("SELECT * FROM dbo.wishes wh WHERE \
wh.person_id=:ID AND wh.FromOlymp=1 ORDER BY wh.Priority");

//--- Order By clause
/*   if (WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull())
      ParseQuery->SQL->Add(" ORDER BY w.Priority ");
   else */
   ParseQuery->SQL->Add(" ORDER BY ID ");
 //-- Done Generating the Query. Starting...
   ParseQuery->Active=true;
   WishesQuery->Active=true;

   LblKandidates->Visible=true;
   DBGrid1->Visible=true;
   //LblWishes->Visible=true;
   //DBGrid2->Visible=true;
   WishesPanel->Visible=true;
   StatusBar1->Visible=true;
   if (this->Height<=220) this->Height=550;
   ParseQuery->Active=true;

   if (ParseQuery->RecordCount>0)
      StatusBar1->SimpleText="Намерени: "+String(ParseQuery->RecordCount);
   else
      StatusBar1->SimpleText="Намерени: няма";
   if (ParseQuery->RecordCount==0) PrintBtn->Enabled=false;
   else PrintBtn->Enabled=true;
   SearchBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::FormShow(TObject *Sender)
{
   if (ParseQuery->Active==false) {
      AllReceptionForm->WindowState=wsNormal;
      LblKandidates->Visible=false;
      DBGrid1->Visible=false;
      //LblWishes->Visible=false;
      //DBGrid2->Visible=false;
      WishesPanel->Visible=false;
      StatusBar1->Visible=false;
      AllReceptionForm->Height=220;
      PrintBtn->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::WishesQueryCalcFields(TDataSet *DataSet)
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

void __fastcall TAllReceptionForm::ParseQueryCalcFields(TDataSet *DataSet)
{
   switch (DataSet->FieldByName("Sex")->AsInteger) {
      case 1:
         DataSet->FieldByName("Se")->AsString="М";
      break;
      case 0:
         DataSet->FieldByName("Se")->AsString="Ж";
      break;
   }

}
//---------------------------------------------------------------------------
void __fastcall TAllReceptionForm::PrintBtnClick(TObject *Sender)
{
   AllReceptionResForm->SummaryBand1->Enabled=TaxesCheck->Checked;
   AllReceptionResForm->QRBand1->Enabled=TaxesCheck->Checked;

   //AllReceptionResForm->ChildBand1->Enabled=WishesCheck->Checked;
   AllReceptionResForm->QRSubDetail1->Enabled=WishesCheck->Checked;


   AllReceptionResForm->CalcAllTaxQuery->Active=true;
   AllReceptionResForm->QuickRep1->Preview();
   AllReceptionResForm->CalcAllTaxQuery->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::NameEditChange(TObject *Sender)
{
   if (!NameEdit->Text.IsEmpty()||!EGNEdit->Text.IsEmpty()||
    (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull())||SexTypeCheck->Checked||
    (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull())||IDCheck->Checked||!AddressEdit->Text.IsEmpty())
      Tab1->Highlighted=true;
   else
      Tab1->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::TaxTypeLookupClick(TObject *Sender)
{
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::FormCreate(TObject *Sender)
{
   StartDateTime->DateTime=Now();
   EndDateTime->DateTime=Now();
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::RoomCheckClick(TObject *Sender)
{
   NameEditChange(NULL);
   RoomLookup->Enabled=RoomCheck->Checked;
   RoomNOT->Enabled=RoomCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::WishesEntCheckClick(TObject *Sender)
{
   if (WishesEntCheck->Checked||OlympCheck->Checked) {
      WishesTab->Highlighted=true;
   } else WishesTab->Highlighted=false;
   WishesLookup->Enabled=WishesEntCheck->Checked;
   PriorityCheck->Enabled=WishesEntCheck->Checked;
   StatsBtn->Enabled=WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull();
   PriorityLookup->Enabled=WishesEntCheck->Checked&&PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull();
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::PriorityCheckClick(TObject *Sender)
{
   PriorityLookup->Enabled=PriorityCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::StatsBtnClick(TObject *Sender)
{
   AllReceptionProfilesResForm->TotalQuery->Active=true;
   AllReceptionProfilesResForm->ProfilesQuery->Active=false;
   AllReceptionProfilesResForm->ProfilesQuery->ParamByName("SET_PROFILE_ID")->AsInteger=WishesLookup->KeyValue;
   AllReceptionProfilesResForm->ProfilesQuery->Active=true;

   AllReceptionProfilesResForm->MaleQuery->Active=false;
   AllReceptionProfilesResForm->MaleQuery->ParamByName("SET_PROFILE_ID")->AsInteger=WishesLookup->KeyValue;
   AllReceptionProfilesResForm->MaleQuery->Active=true;

   AllReceptionProfilesResForm->FemaleQuery->Active=false;
   AllReceptionProfilesResForm->FemaleQuery->ParamByName("SET_PROFILE_ID")->AsInteger=WishesLookup->KeyValue;
   AllReceptionProfilesResForm->FemaleQuery->Active=true;

   AllReceptionProfilesResForm->TotalQuery->Active=false;
   AllReceptionProfilesResForm->TotalQuery->ParamByName("SET_PROFILE_ID")->AsInteger=WishesLookup->KeyValue;
   AllReceptionProfilesResForm->TotalQuery->Active=true;

   AllReceptionProfilesResForm->ProfileLabel->Caption=WishesLookup->Text;
   //AllReceptionProfilesResForm->
   AllReceptionProfilesResForm->QuickRep1->Preview();
   AllReceptionProfilesResForm->MaleQuery->Active=false;
   AllReceptionProfilesResForm->FemaleQuery->Active=false;
   AllReceptionProfilesResForm->TotalQuery->Active=false;
   AllReceptionProfilesResForm->ProfilesQuery->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::OlympCheckClick(TObject *Sender)
{
   WishesTab->Highlighted=OlympCheck->Checked||WishesEntCheck->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TAllReceptionForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   RoomQuery->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::IDCheckClick(TObject *Sender)
{
   NameEditChange(NULL);
   IDEdit->Enabled=IDCheck->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N2Click(TObject *Sender)
{
 // name
   N2->Checked=!N2->Checked;
   DBGrid1->Columns->Items[1]->Visible=N2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N3Click(TObject *Sender)
{
 // EGN
   N3->Checked=!N3->Checked;
   DBGrid1->Columns->Items[2]->Visible=N3->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N4Click(TObject *Sender)
{
 // sex
   N4->Checked=!N4->Checked;
   DBGrid1->Columns->Items[3]->Visible=N4->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N5Click(TObject *Sender)
{
 // telephone
   N5->Checked=!N5->Checked;
   DBGrid1->Columns->Items[4]->Visible=N5->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N6Click(TObject *Sender)
{
 // address
   N6->Checked=!N6->Checked;
   DBGrid1->Columns->Items[5]->Visible=N6->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N7Click(TObject *Sender)
{
 // tax
   N7->Checked=!N7->Checked;
   DBGrid1->Columns->Items[6]->Visible=N7->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N8Click(TObject *Sender)
{
 // room
   N8->Checked=!N8->Checked;
   DBGrid1->Columns->Items[7]->Visible=N8->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N9Click(TObject *Sender)
{
 // EntOn
   N9->Checked=!N9->Checked;
   DBGrid1->Columns->Items[8]->Visible=N9->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N10Click(TObject *Sender)
{
 // EntBy
   N10->Checked=!N10->Checked;
   DBGrid1->Columns->Items[9]->Visible=N10->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N12Click(TObject *Sender)
{
 // Priority
   N12->Checked=!N12->Checked;
   DBGrid2->Columns->Items[1]->Visible=N12->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N13Click(TObject *Sender)
{
 // Score
   N13->Checked=!N13->Checked;
   DBGrid2->Columns->Items[2]->Visible=N13->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N14Click(TObject *Sender)
{
 // FromOlymp
   N14->Checked=!N14->Checked;
   DBGrid2->Columns->Items[3]->Visible=N14->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N15Click(TObject *Sender)
{
 // OlympScore
   N15->Checked=!N15->Checked;
   DBGrid2->Columns->Items[4]->Visible=N15->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N16Click(TObject *Sender)
{
 // GoToExam
   N16->Checked=!N16->Checked;
   DBGrid2->Columns->Items[5]->Visible=N16->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N17Click(TObject *Sender)
{
 // EntOn
   N17->Checked=!N17->Checked;
   DBGrid2->Columns->Items[6]->Visible=N17->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionForm::N18Click(TObject *Sender)
{
 // EntBy
   N18->Checked=!N18->Checked;
   DBGrid2->Columns->Items[7]->Visible=N18->Checked;
}
//---------------------------------------------------------------------------

