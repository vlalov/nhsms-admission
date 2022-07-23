//---------------------------------------------------------------------------

#ifndef AllReceptionProfilesResH
#define AllReceptionProfilesResH
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
class TAllReceptionProfilesResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *TitleBand1;
   TQRBand *ColumnHeaderBand1;
   TQRBand *DetailBand1;
   TQRBand *SummaryBand1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel18;
   TQRLabel *QRLabel2;
   TQuery *MaleQuery;
   TQRLabel *ProfileLabel;
   TQRDBText *QRDBText1;
   TQRBand *QRBand1;
   TQuery *ProfilesQuery;
   TDataSource *PrioritySource;
   TIntegerField *ProfilesQuerypriority;
   TQuery *TotalQuery;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel5;
   TQuery *FemaleQuery;
   TQRDBText *QRDBText3;
   TIntegerField *MaleQuerymale;
   TQRDBText *QRDBText4;
   TQRExpr *QRExpr1;
   TIntegerField *FemaleQueryfemale;
   TQRDBText *QRDBText2;
   TQRLabel *QRLabel13;
   TIntegerField *TotalQuerytotal;
   TQRLabel *QRLabel6;
   TQRExpr *QRExpr2;
   TQRExpr *QRExpr3;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRSysData *QRSysData1;
   TQRLabel *QRLabel9;
   TQRSysData *QRSysData2;
   void __fastcall MaleQueryCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
   __fastcall TAllReceptionProfilesResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAllReceptionProfilesResForm *AllReceptionProfilesResForm;
//---------------------------------------------------------------------------
#endif
