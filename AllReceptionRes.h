//---------------------------------------------------------------------------

#ifndef AllReceptionResH
#define AllReceptionResH
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
#include <QRExport.hpp>
//---------------------------------------------------------------------------
class TAllReceptionResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *DetailBand1;
   TQRDBText *QRDBText2;
   TQRBand *PageHeaderBand1;
   TQRLabel *QRLabel1;
   TQRSubDetail *QRSubDetail1;
   TQRDBText *QRDBText5;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText8;
   TQRBand *QRBand1;
   TQRLabel *QRLabel14;
   TQRDBText *QRDBText9;
   TQRLabel *QRLabel15;
   TQRDBText *QRDBText10;
   TQRLabel *QRLabel16;
   TQRDBText *QRDBText11;
   TQRBand *SummaryBand1;
   TQuery *CalcAllTaxQuery;
   TIntegerField *CalcAllTaxQueryid;
   TFloatField *CalcAllTaxQueryAllTax;
   TIntegerField *CalcAllTaxQuerycnt;
   TFloatField *CalcAllTaxQuerytheTAX;
   TQRExpr *QRExpr1;
   TQRLabel *QRLabel17;
   TQRDBText *QRDBText13;
        TQRLabel *QRLabel18;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel11;
        TQRLabel *QRLabel12;
private:	// User declarations
public:		// User declarations
   __fastcall TAllReceptionResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAllReceptionResForm *AllReceptionResForm;
//---------------------------------------------------------------------------
#endif
