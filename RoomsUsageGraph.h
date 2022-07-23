//---------------------------------------------------------------------------

#ifndef RoomsUsageGraphH
#define RoomsUsageGraphH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MXDB.hpp>
#include <Mxstore.hpp>
#include <Chart.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <MXGRAPH.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TRoomsUsageGraphForm : public TForm
{
__published:	// IDE-managed Components
   TQuery *RoomsAllocatedQuery;
   TStringField *RoomsAllocatedQueryCode;
   TIntegerField *RoomsAllocatedQueryPersent;
   TDecisionCube *DecisionCube1;
   TDecisionSource *DecisionSource1;
   TDecisionGraph *DecisionGraph1;
   TBarSeries *Series1;
   TBarSeries *Series2;
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
   __fastcall TRoomsUsageGraphForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRoomsUsageGraphForm *RoomsUsageGraphForm;
//---------------------------------------------------------------------------
#endif
