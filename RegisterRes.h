//---------------------------------------------------------------------------

#ifndef RegisterResH
#define RegisterResH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
//---------------------------------------------------------------------------
class TRegisterResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *ColumnHeaderBand1;
   TQuery *ClassificatedQuery;
   TQuickRep *QuickRep2;
   TQRBand *QRBand1;
   TQRLabel *QRLabel5;
   TQRBand *QRBand2;
   TQRLabel *QRLabel7;
   TQRLabel *BALLabel;
   TQRLabel *QRLabel9;
   TQRBand *QRBand3;
   TQRDBText *QRDBText4;
   TQRDBText *BALShow;
   TQRDBText *QRDBText6;
   TQRLabel *ProfileLabel;
   TQRDBText *ProfileShow;
   TQRLabel *EGNLabel;
   TQRDBText *EGNShow;
   TQRBand *QRProtocolDetailBand;
   TQuery *Classificated10Query;
   TQRSubDetail *QRSubDetail1;
   TDataSource *DataSource10;
   TDataSource *DataSource;
   TIntegerField *ClassificatedQueryPerson_ID;
   TIntegerField *ClassificatedQuerySex;
   TIntegerField *ClassificatedQueryProfile_ID;
   TFloatField *ClassificatedQuerySchoolScore;
   TFloatField *ClassificatedQueryFirstExamScore;
   TFloatField *ClassificatedQueryExamScore;
   TFloatField *ClassificatedQueryBAL;
   TStringField *ClassificatedQueryName;
   TQRLabel *PageHeaderText;
   TQRShape *QRShape2;
   TQRExpr *QRExpr1;
   TQRShape *QRShape1;
   TQRDBText *QRDBText8;
   TQRShape *QRShape3;
   TQRDBText *QRDBText5;
   TQRShape *QRShape4;
   TQRDBText *QRDBText3;
   TQRShape *QRShape6;
   TQRDBText *QRDBText1;
   TQRShape *QRShape7;
   TQRDBText *QRDBText2;
   TQRShape *QRShape5;
   TQRDBText *QRDBText7;
   TQRShape *QRShape8;
   TQRLabel *QRLabel1;
   TQRShape *QRShape9;
   TQRLabel *QRLabel4;
   TQRShape *QRShape10;
   TQRLabel *QRLabel2;
   TQRShape *QRShape11;
   TQRLabel *QRLabel10;
   TQRShape *QRShape12;
   TQRLabel *QRLabel6;
   TQRShape *QRShape13;
   TQRLabel *QRLabel8;
   TQRShape *QRShape14;
   TQRLabel *QRLabel3;
   TQRBand *SummaryBand2;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel12;
   TQRDBText *QRPrefered;
   TBooleanField *ClassificatedQueryPreferedSchool;
   TBooleanField *Classificated10QueryClassif;
   void __fastcall Classificated10QueryAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
   __fastcall TRegisterResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegisterResForm *RegisterResForm;
//---------------------------------------------------------------------------
#endif
