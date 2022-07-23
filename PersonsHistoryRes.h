//---------------------------------------------------------------------------

#ifndef PersonsHistoryResH
#define PersonsHistoryResH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TPersonsHistoryResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *TitleBand1;
   TQRBand *ColumnHeaderBand1;
   TQRBand *DetailBand1;
   TQRBand *SummaryBand1;
   TQRBand *PageFooterBand1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel5;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText4;
   TQRDBText *QRDBText5;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
   TQRLabel *QRLabel9;
   TQRLabel *QRLabel10;
   TQRSysData *QRSysData1;
   TQRSysData *QRSysData2;
   TQRSysData *QRSysData3;
   TQRLabel *QRLabel11;
private:	// User declarations
public:		// User declarations
   __fastcall TPersonsHistoryResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPersonsHistoryResForm *PersonsHistoryResForm;
//---------------------------------------------------------------------------
#endif
