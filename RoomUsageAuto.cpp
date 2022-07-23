//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RoomUsageAuto.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TRoomUsageAutoForm *RoomUsageAutoForm;
//---------------------------------------------------------------------------
__fastcall TRoomUsageAutoForm::TRoomUsageAutoForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRoomUsageAutoForm::TimerTimer(TObject *Sender)
{
 AnsiString code;
 int allocatedAll,capacityAll;
 TLocateOptions p;
   if (RoomsAllocatedQuery->Active==true) {
      code=RoomsAllocatedQuery->FieldByName("Code")->AsString;
   } else code="";
   RoomsAllocatedQuery->Active=false;
   RoomsAllocatedQuery->Active=true;
   RoomsAllocatedQuery->First();

   allocatedAll=0;
   capacityAll=0;
   for (int i=0;i<RoomsAllocatedQuery->RecordCount;i++) {
      allocatedAll+=RoomsAllocatedQuery->FieldByName("Allocated")->AsInteger;
      capacityAll+=RoomsAllocatedQuery->FieldByName("Capacity")->AsInteger;
      RoomsAllocatedQuery->Next();
   }
   AllocatedText->Caption=String(allocatedAll);
   CapacityText->Caption=String(capacityAll);
   PercentGauge->Progress=(allocatedAll*100)/capacityAll;
   this->Caption=String(allocatedAll)+"/"+String(capacityAll)+" - Състояние на стаите";

   if (code!="") {
      RoomsAllocatedQuery->Locate("Code",code,p);
   }
}
//---------------------------------------------------------------------------
void __fastcall TRoomUsageAutoForm::RoomsAllocatedQueryCalcFields(
      TDataSet *DataSet)
{
   DataSet->FieldByName("Percent")->AsString=
     String((DataSet->FieldByName("Allocated")->AsInteger*100)/DataSet->FieldByName("Capacity")->AsInteger)+" %";
}
//---------------------------------------------------------------------------
void __fastcall TRoomUsageAutoForm::FormActivate(TObject *Sender)
{
   TimerTimer(Sender);
   Timer->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TRoomUsageAutoForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   Timer->Enabled=false;
   RoomsAllocatedQuery->Active=false;
}
//---------------------------------------------------------------------------
