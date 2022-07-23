//---------------------------------------------------------------------------

#ifndef WishesHistoryResH
#define WishesHistoryResH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TWishesHistoryResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *TitleBand1;
   TQRLabel *QRLabel1;
   TQRBand *ColumnHeaderBand1;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel5;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRBand *DetailBand1;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText4;
   TQRDBText *QRDBText5;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
   TQRBand *SummaryBand1;
   TQRLabel *QRLabel9;
   TQRSysData *QRSysData1;
   TQRBand *PageFooterBand1;
   TQRLabel *QRLabel10;
   TQRSysData *QRSysData2;
   TQRSysData *QRSysData3;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel12;
   TQRDBText *QRDBText8;
private:	// User declarations
public:		// User declarations
   __fastcall TWishesHistoryResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWishesHistoryResForm *WishesHistoryResForm;
//---------------------------------------------------------------------------
#endif
