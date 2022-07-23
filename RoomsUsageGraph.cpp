//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RoomsUsageGraph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRoomsUsageGraphForm *RoomsUsageGraphForm;
//---------------------------------------------------------------------------
__fastcall TRoomsUsageGraphForm::TRoomsUsageGraphForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRoomsUsageGraphForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   RoomsUsageGraphForm->RoomsAllocatedQuery->Active=false;   
}
//---------------------------------------------------------------------------
