//---------------------------------------------------------------------------

#include <vcl.h>
#include "DataModule.h"
#pragma hdrstop

#include "RegisterSearcher.h"
#include "Library.h"
#include "RegisterRes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "VrEdit"
#pragma resource "*.dfm"
TRegisterSearcherForm *RegisterSearcherForm;
//---------------------------------------------------------------------------
__fastcall TRegisterSearcherForm::TRegisterSearcherForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRegisterSearcherForm::FormActivate(TObject *Sender)
{
   RoomQuery->Active=false;
   RoomQuery->Active=true;   
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::RoomCheckClick(TObject *Sender)
{
   RoomLookup->Enabled=RoomCheck->Checked;
   RoomNOT->Enabled=RoomCheck->Checked;
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::TaxTypeCheckClick(TObject *Sender)
{
   TaxTypeLookup->Enabled=TaxTypeCheck->Checked;
   TaxNOT->Enabled=TaxTypeCheck->Checked;
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::IDCheckClick(TObject *Sender)
{
   IDEdit->Enabled=IDCheck->Checked;
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::SexTypeCheckClick(TObject *Sender)
{
   MaleBtn->Enabled=SexTypeCheck->Checked;
   FemaleBtn->Enabled=SexTypeCheck->Checked;
   NameEditChange(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::WishesEntCheckClick(TObject *Sender)
{
   WishesLookup->Enabled=WishesEntCheck->Checked;
   ClassifCheck->Enabled=WishesEntCheck->Checked;
   PriorityCheck->Enabled=WishesEntCheck->Checked;
   PriorityCheckClick(NULL);
   BALCheck->Enabled=WishesEntCheck->Checked;
   BALCheckClick(NULL);
   WishesTab->Highlighted=WishesEntCheck->Checked||IsInCheck->State!=cbGrayed;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::PriorityCheckClick(TObject *Sender)
{
   PriorityLookup->Enabled=PriorityCheck->Checked&&PriorityCheck->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::BALCheckClick(TObject *Sender)
{
   BALFromRadio->Enabled=BALCheck->Checked&&BALCheck->Enabled;
   BALFromToRadio->Enabled=BALCheck->Checked&&BALCheck->Enabled;
   BALToRadio->Enabled=BALCheck->Checked&&BALCheck->Enabled;
   BALFromEdit->Enabled=BALCheck->Checked&&BALCheck->Enabled&&(BALFromRadio->Checked||BALFromToRadio->Checked);
   BALToEdit->Enabled=BALCheck->Checked&&BALCheck->Enabled&&(BALToRadio->Checked||BALFromToRadio->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::NameEditChange(TObject *Sender)
{
   if (!NameEdit->Text.IsEmpty()||!EGNEdit->Text.IsEmpty()||
    (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull())||SexTypeCheck->Checked||
    (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull())||IDCheck->Checked)
      PersonalTab->Highlighted=true;
   else
      PersonalTab->Highlighted=false;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::FormCreate(TObject *Sender)
{
   if (ParseQuery->Active!=true) {
      this->Height=200;
      this->Constraints->MaxHeight=200;
      this->Constraints->MinHeight=200;
      this->Constraints->MaxWidth=this->Width;
      this->Constraints->MinWidth=this->Width;
   }
}
//---------------------------------------------------------------------------
int __fastcall TRegisterSearcherForm::CalcAnds() {
 int ans=0;
 double tmp;
   if (!NameEdit->Text.IsEmpty()) ans++;
   if (IDCheck->Checked) ans++;
   if (!EGNEdit->Text.IsEmpty()) ans++;
   if (TaxTypeCheck->Checked&&!TaxTypeLookup->KeyValue.IsNull()) ans++;
   if (SexTypeCheck->Checked) ans++;
   if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) ans++;

   if (WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull()) {
      ans++;
      if (PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull())
         ans++;
      if (BALCheck->Checked) {
         ans++;
         if (BALFromToRadio->Checked) {
            if (BALFromEdit->Value>BALToEdit->Value) {
               tmp=BALFromEdit->Value;
               BALFromEdit->Value=BALToEdit->Value;
               BALToEdit->Value=tmp;
            }
         }
      }
      if (ClassifCheck->State!=cbGrayed)
         ans++;
   }
   if (IsInCheck->State!=cbGrayed)
      ans++;
   return ans;
}
void __fastcall TRegisterSearcherForm::SearchBtnClick(TObject *Sender)
{
 int ands=0;
 AnsiString name,egn;
   ParseQuery->Active=false;
   ParseQuery->SQL->Clear();
   ParseQuery->SQL->Add("SELECT DISTINCT p.ID,p.Name,p.EGN,p.Sex,p.Tax_ID,p.Room_Code \
FROM Persons p LEFT OUTER JOIN Register r ON p.ID=r.Person_ID,Wishes w \
WHERE w.Person_ID=p.ID AND r.Profile_ID=w.Profile_ID ");
   ands=CalcAnds();
   if (ands>0) ParseQuery->SQL->Add(" AND ");
   if (!NameEdit->Text.IsEmpty()) {
      name=NameEdit->Text;
      ReplaceChars(name);
      if (!NameNOT->Down)
         ParseQuery->SQL->Add(" p.name LIKE '%"+name+"%"+"' ");
      else
         ParseQuery->SQL->Add(" p.name NOT LIKE '%"+name+"%"+"' ");
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
   if (RoomCheck->Checked&&!RoomLookup->KeyValue.IsNull()) {
      if (!RoomNOT->Down)
         ParseQuery->SQL->Add(" p.Room_Code='"+String(RoomLookup->KeyValue)+"' ");
      else
         ParseQuery->SQL->Add(" NOT p.Room_Code='"+String(RoomLookup->KeyValue)+"' ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
 // -------------------------
   if (WishesEntCheck->Checked&&!WishesLookup->KeyValue.IsNull()) {
      ParseQuery->SQL->Add(" w.Profile_ID="+String(WishesLookup->KeyValue)+" ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");

      if (PriorityCheck->Checked&&!PriorityLookup->KeyValue.IsNull()) {
         ParseQuery->SQL->Add(" w.Priority="+String(PriorityLookup->KeyValue)+" ");
         ands--;
         if (ands>0) ParseQuery->SQL->Add(" AND ");
      }
      if (ClassifCheck->State!=cbGrayed) {
         if (ClassifCheck->State==cbChecked)
            ParseQuery->SQL->Add(" r.Classificated=1 ");
         if (ClassifCheck->State==cbUnchecked)
            ParseQuery->SQL->Add(" r.Classificated=0 ");
         ands--;
         if (ands>0) ParseQuery->SQL->Add(" AND ");
      }
      if (BALCheck->Checked) {
         if (BALFromToRadio->Checked) {
            ParseQuery->SQL->Add(" r.Amount>=:SET_MIN AND r.Amount<=:SET_MAX ");
            ParseQuery->ParamByName("SET_MIN")->AsFloat=BALFromEdit->Value;
            ParseQuery->ParamByName("SET_MAX")->AsFloat=BALToEdit->Value;
         }
         if (BALFromRadio->Checked) {
            ParseQuery->SQL->Add(" r.Amount>=:SET_MIN");
            ParseQuery->ParamByName("SET_MIN")->AsFloat=BALFromEdit->Value;
         }
         if (BALToRadio->Checked) {
            ParseQuery->SQL->Add(" r.Amount<=:SET_MAX");
            ParseQuery->ParamByName("SET_MAX")->AsFloat=BALToEdit->Value;
         }
         ands--;
         if (ands>0) ParseQuery->SQL->Add(" AND ");
      }
   }
   if (IsInCheck->State!=cbGrayed) {
      if (IsInCheck->State==cbChecked)
         ParseQuery->SQL->Add(" r.IsIn=1 ");
      if (IsInCheck->State==cbUnchecked)
         ParseQuery->SQL->Add(" r.IsIn=0 ");
      ands--;
      if (ands>0) ParseQuery->SQL->Add(" AND ");
   }
   ParseQuery->SQL->Add(" ORDER BY p.ID");
   //ShowMessage(ParseQuery->SQL->Text);
   if (this->Height==200) {
      this->Constraints->MaxHeight=0;
      this->Constraints->MinHeight=200;
      this->Constraints->MaxWidth=0;
      this->Constraints->MinWidth=0;
      this->Height=500;

      LblKandidates->Visible=true;
      DBGrid1->Visible=true;
      StatusBar1->Visible=true;
      WishesPanel->Visible=true;
      Splitter1->Visible=true;
      LblWishes->Visible=true;
      DBGrid2->Visible=true;

   }

   ParseQuery->Active=true;
   WishesQuery->Active=true;
   if (ParseQuery->RecordCount>0)
      StatusBar1->SimpleText="Намерени: "+String(ParseQuery->RecordCount);
   else
      StatusBar1->SimpleText="Намерени: няма";
   if (ParseQuery->RecordCount==0) PrintBtn->Enabled=false;
   else PrintBtn->Enabled=true;
   SearchBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::CancelBtnClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::ParseQueryCalcFields(
      TDataSet *DataSet)
{
   if (DataSet->FieldByName("Sex")->AsInteger==1) {
      DataSet->FieldByName("Se")->AsString="М";
   } else {
      DataSet->FieldByName("Se")->AsString="Ж";
   }
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::N2Click(TObject *Sender)
{
   N2->Checked=!N2->Checked;
   DBGrid1->Columns->Items[1]->Visible=N2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::N3Click(TObject *Sender)
{
   N3->Checked=!N3->Checked;
   DBGrid1->Columns->Items[2]->Visible=N3->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::N4Click(TObject *Sender)
{
   N4->Checked=!N4->Checked;
   DBGrid1->Columns->Items[3]->Visible=N4->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::N5Click(TObject *Sender)
{
   N5->Checked=!N5->Checked;
   DBGrid1->Columns->Items[4]->Visible=N5->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TRegisterSearcherForm::N6Click(TObject *Sender)
{
   N6->Checked=!N6->Checked;
   DBGrid1->Columns->Items[5]->Visible=N6->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TRegisterSearcherForm::PrintBtnClick(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;

   RegisterResForm->BALLabel->Enabled=BCheck->Checked;
   RegisterResForm->BALShow->Enabled=BCheck->Checked;
   RegisterResForm->ProfileLabel->Enabled=ProfCheck->Checked;
   RegisterResForm->ProfileShow->Enabled=ProfCheck->Checked;
   RegisterResForm->EGNLabel->Enabled=N3->Checked;
   RegisterResForm->EGNShow->Enabled=N3->Checked;

   ParseQuery->Active=true;
   WishesQuery->Active=true;

   RegisterResForm->QuickRep2->Preview();
}
//---------------------------------------------------------------------------

