//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AllReceptionProfilesRes.h"
#include "AllReception.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAllReceptionProfilesResForm *AllReceptionProfilesResForm;
//---------------------------------------------------------------------------
__fastcall TAllReceptionProfilesResForm::TAllReceptionProfilesResForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAllReceptionProfilesResForm::MaleQueryCalcFields(
      TDataSet *DataSet)
{
   switch (DataSet->FieldByName("sex")->AsInteger) {
      case 1:
         DataSet->FieldByName("Se")->AsString="Ì";
      break;
      case 0:
         DataSet->FieldByName("Se")->AsString="Æ";
      break;
   }
}
//---------------------------------------------------------------------------

