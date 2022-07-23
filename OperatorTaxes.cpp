//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OperatorTaxes.h"
#include "DataModule.h"
#include "CurrentReceptionRes.h"
#include "Main.h"
#include "PrintBlanks.h"
#include "PreviewText.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOperatorTaxesForm *OperatorTaxesForm;
//---------------------------------------------------------------------------
__fastcall TOperatorTaxesForm::TOperatorTaxesForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOperatorTaxesForm::FormActivate(TObject *Sender)
{
   if (Data->Database1->Connected!=true) return;
   OperatorsQuery->Active=true;
//   RoomQuery->Active=false;
//   RoomQuery->Active=true;
   OperatorNameCombo->Items->Clear();
   for (int i=0;i<OperatorsQuery->RecordCount;i++) {
      OperatorNameCombo->Items->Add(OperatorsQuery->FieldByName("entby")->AsString);
      OperatorsQuery->Next();
   }
   OperatorsQuery->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TOperatorTaxesForm::FormCreate(TObject *Sender)
{
   StartDateTime->DateTime=Now();
}
//---------------------------------------------------------------------------
void __fastcall TOperatorTaxesForm::CancelBtnClick(TObject *Sender)
{
   Close();   
}
//---------------------------------------------------------------------------
void __fastcall TOperatorTaxesForm::SearchBtnClick(TObject *Sender)
{
   if (Data->Database1->Connected!=true) {
      return;
   }
   CurrentReceptionResForm->DataQuery2->Active=false;
   CurrentReceptionResForm->DataQuery2->ParamByName("SET_USERNAME")->AsString=OperatorNameCombo->Text;
   CurrentReceptionResForm->DataQuery2->ParamByName("SET_DATE")->AsDateTime=StartDateTime->DateTime;
   CurrentReceptionResForm->DataQuery2->Active=true;

   CurrentReceptionResForm->CalcAllTaxQuery2->Active=false;
   CurrentReceptionResForm->CalcAllTaxQuery2->ParamByName("SET_USER")->AsString=OperatorNameCombo->Text;
   CurrentReceptionResForm->CalcAllTaxQuery2->ParamByName("SET_DATETIME")->AsDateTime=StartDateTime->DateTime;
   CurrentReceptionResForm->CalcAllTaxQuery2->Active=true;

   CurrentReceptionResForm->DeletedWishesQuery2->Active=false;
   CurrentReceptionResForm->DeletedWishesQuery2->ParamByName("SET_USER")->AsString=OperatorNameCombo->Text;
   CurrentReceptionResForm->DeletedWishesQuery2->ParamByName("SET_DATE")->AsDateTime=StartDateTime->DateTime;
   CurrentReceptionResForm->DeletedWishesQuery2->Active=true;
   if (MainForm->TextPrintCheck->Checked) {
      DoTextPreview(2);
   } else {
      CurrentReceptionResForm->OperatorShow->Caption=CurrentReceptionResForm->DataQuery2->FieldByName("operator")->AsString+" ("+FormatDateTime("ddddd",StartDateTime->DateTime)+")";
      CurrentReceptionResForm->QuickRep2->Preview();
   }
   CurrentReceptionResForm->CalcAllTaxQuery2->Active=false;
   CurrentReceptionResForm->DeletedWishesQuery2->Active=false;
   CurrentReceptionResForm->DataQuery2->Active=false;
}
//---------------------------------------------------------------------------
