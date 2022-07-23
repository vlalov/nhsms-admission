//---------------------------------------------------------------------------

#ifndef ReceptionResH
#define ReceptionResH
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
class TReceptionResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *DetailBand1;
   TQRBand *TitleBand1;
   TQRLabel *StaticBeforeText;
   TQuery *StaticTextQuery;
   TMemoField *StaticTextQueryvalue;
   TQRSubDetail *QRSubDetail1;
   TQRLabel *QRLabel5;
   TQRBand *QRBand1;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRLabel *QRLabel9;
   TQRLabel *QRLabel10;
   TQRLabel *QRLabel14;
   TQRDBText *QRDBText2;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText4;
   TQRDBText *QRDBText5;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
   TQRDBText *QRDBText8;
   TQuery *PersonsQuery;
   TIntegerField *PersonsQueryID;
   TStringField *PersonsQueryName;
   TStringField *PersonsQueryEGN;
   TStringField *PersonsQueryTelephone;
   TStringField *PersonsQueryAddress;
   TIntegerField *PersonsQuerySex;
   TIntegerField *PersonsQueryTax_id;
   TQRCSVFilter *QRCSVFilter1;
   TQRLabel *GoToExamLabel;
   TQRDBText *QRDBText9;
   TDataSource *PersonsSource;
   TIntegerField *StaticTextQueryID;
   TQRLabel *QRLabel15;
   TQRDBText *QRDBText10;
   TQRLabel *QRLabel16;
   TQRDBText *QRDBText11;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel12;
   TQRLabel *QRLabel13;
   TQRLabel *QRLabel17;
   TQRLabel *QRLabel18;
   TQRLabel *QRLabel1;
   TQRDBText *QRDBText12;
   TStringField *PersonsQuerySe;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQuery *PlaceQuery;
   TStringField *PlaceQueryText;
   TQRExpr *QRExpr1;
   TStringField *PersonsQueryRoom_Code;
   TStringField *PersonsQueryEntBy;
   TQRBand *QRBand2;
   TQRLabel *TextsAfter;
   TQRLabel *QRLabel19;
   TQRLabel *QRLabel20;
   TQRLabel *DateShow;
   TDateTimeField *PersonsQueryEntOn;
   void __fastcall PersonsQueryCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
   __fastcall TReceptionResForm(TComponent* Owner);
   void __fastcall ViewPreview();
   void __fastcall PrintReport();
   void __fastcall Initialize();
};
//---------------------------------------------------------------------------
extern PACKAGE TReceptionResForm *ReceptionResForm;
//---------------------------------------------------------------------------
#endif
