//---------------------------------------------------------------------------

#ifndef CurrentReceptionResH
#define CurrentReceptionResH
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
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TCurrentReceptionResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *PageHeaderBand1;
   TQRBand *ColumnHeaderBand1;
   TQRBand *DetailBand1;
   TQRBand *SummaryBand1;
   TQRBand *PageFooterBand1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel2;
   TQRDBText *QRDBText1;
   TQuery *DataQuery;
   TQRLabel *QRLabel3;
   TIntegerField *DataQueryID;
   TStringField *DataQueryName;
   TStringField *DataQueryEGN;
   TIntegerField *DataQueryTax_id;
   TQRDBText *QRDBText2;
   TQRLabel *QRLabel4;
   TQRDBText *QRDBText3;
   TQRLabel *QRLabel5;
   TQuery *CalcAllTaxQuery;
   TIntegerField *CalcAllTaxQueryid;
   TFloatField *CalcAllTaxQueryAllTax;
   TDataSource *DataSource;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel8;
   TQRSysData *QRSysData2;
   TQRExpr *QRExpr1;
   TQRExpr *QRExpr2;
   TQRLabel *QRLabel9;
   TQRLabel *QRLabel7;
   TQRSysData *QRSysData1;
   TQRLabel *QRLabel10;
   TQRDBText *QRDBText5;
   TStringField *DataQueryoperator;
   TQuery *DeletedWishesQuery;
   TFloatField *DeletedWishesQueryCNT;
   TQRExpr *QRExpr3;
   TDateTimeField *DataQueryEntOn;
   TStringField *DataQueryEntBy;
   TQuickRep *QuickRep2;
   TQRBand *QRBand1;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel12;
   TQRSysData *QRSysData3;
   TQRLabel *QRLabel13;
   TQRBand *QRBand2;
   TQRLabel *QRLabel14;
   TQRLabel *QRLabel15;
   TQRLabel *QRLabel16;
   TQRLabel *QRLabel17;
   TQRBand *QRBand3;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
   TQRDBText *QRDBText8;
   TQRExpr *QRExpr4;
   TQRBand *QRBand4;
   TQRLabel *QRLabel18;
   TQRExpr *QRExpr5;
   TQRExpr *QRExpr6;
   TQRLabel *QRLabel19;
   TQRBand *QRBand5;
   TQRLabel *QRLabel20;
   TQRSysData *QRSysData4;
   TDataSource *DataSource1;
   TQuery *DataQuery2;
   TIntegerField *IntegerField1;
   TStringField *StringField1;
   TStringField *StringField2;
   TIntegerField *IntegerField2;
   TStringField *StringField3;
   TDateTimeField *DateTimeField1;
   TStringField *StringField4;
   TQuery *CalcAllTaxQuery2;
   TIntegerField *IntegerField3;
   TFloatField *FloatField1;
   TQuery *DeletedWishesQuery2;
   TFloatField *FloatField2;
   TQRLabel *OperatorShow;
private:	// User declarations
public:		// User declarations
   __fastcall TCurrentReceptionResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCurrentReceptionResForm *CurrentReceptionResForm;
//---------------------------------------------------------------------------
#endif
