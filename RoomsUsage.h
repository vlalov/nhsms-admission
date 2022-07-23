//---------------------------------------------------------------------------

#ifndef RoomsUsageH
#define RoomsUsageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TRoomsUsageForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *PageHeaderBand1;
   TQRBand *DetailBand1;
   TQRBand *ColumnHeaderBand1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel18;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQuery *RoomsAllocatedQuery;
   TStringField *RoomsAllocatedQueryCode;
   TIntegerField *RoomsAllocatedQueryAllocated;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TIntegerField *RoomsAllocatedQueryCapacity;
   TQRDBText *QRDBText3;
   TQRExpr *QRExpr1;
   TQRBand *SummaryBand1;
   TQRLabel *QRLabel5;
   TQRExpr *QRExpr2;
   TQRExpr *QRExpr3;
   TQRExpr *QRExpr4;
   TQRExpr *QRExpr5;
private:	// User declarations
public:		// User declarations
   __fastcall TRoomsUsageForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRoomsUsageForm *RoomsUsageForm;
//---------------------------------------------------------------------------
#endif
