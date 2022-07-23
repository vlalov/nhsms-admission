//---------------------------------------------------------------------------

#ifndef RoomUsageAutoH
#define RoomUsageAutoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "CSPIN.h"
#include "CGAUGES.h"
//---------------------------------------------------------------------------
class TRoomUsageAutoForm : public TForm
{
__published:	// IDE-managed Components
   TDBGrid *DBGrid1;
   TQuery *RoomsAllocatedQuery;
   TStringField *RoomsAllocatedQueryCode;
   TIntegerField *RoomsAllocatedQueryCapacity;
   TIntegerField *RoomsAllocatedQueryAllocated;
   TDataSource *RoomSourceSource;
   TPanel *Panel1;
   TStringField *RoomsAllocatedQueryPercent;
   TLabel *Label1;
   TStaticText *AllocatedText;
   TLabel *Label2;
   TStaticText *CapacityText;
   TTimer *Timer;
   TIntegerField *RoomsAllocatedQueryPlace_ID;
   TStringField *RoomsAllocatedQueryPlace;
   TCGauge *PercentGauge;
   void __fastcall TimerTimer(TObject *Sender);
   void __fastcall RoomsAllocatedQueryCalcFields(TDataSet *DataSet);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
   __fastcall TRoomUsageAutoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRoomUsageAutoForm *RoomUsageAutoForm;
//---------------------------------------------------------------------------
#endif
