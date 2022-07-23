//---------------------------------------------------------------------------

#include <vcl.h>
#include "DataModule.h"
#pragma hdrstop

#include "RegisterRes.h"
#include "RegisterSearcher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegisterResForm *RegisterResForm;
//---------------------------------------------------------------------------
__fastcall TRegisterResForm::TRegisterResForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TRegisterResForm::Classificated10QueryAfterScroll(
      TDataSet *DataSet)
{
//   ShowMessage(DataSet->FieldByName("Classificated")->AsString);   
}
//---------------------------------------------------------------------------

