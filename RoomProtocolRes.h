//---------------------------------------------------------------------------

#ifndef RoomProtocolResH
#define RoomProtocolResH
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
class TRoomProtocolResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *TitleBand1;
   TQRBand *DetailBand1;
   TQRBand *PageFooterBand1;
   TQRLabel *QRLabel1;
   TQRDBText *QRDBText13;
   TQuery *PersonsQuery;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText4;
   TQRBand *SummaryBand1;
   TQRLabel *QRLabel3;
   TQRSysData *QRSysData1;
   TQRLabel *QRLabel5;
   TQRSysData *QRSysData2;
   TQRLabel *QRLabel6;
   TQRBand *ColumnHeaderBand1;
   TQRLabel *QRLabel18;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel7;
   TQRSysData *QRSysData3;
   TIntegerField *PersonsQueryID;
   TStringField *PersonsQueryName;
   TStringField *PersonsQueryEGN;
   TStringField *PersonsQueryTelephone;
   TStringField *PersonsQueryAddress;
   TIntegerField *PersonsQuerySex;
   TIntegerField *PersonsQueryTax_id;
   TStringField *PersonsQueryRoom_Code;
   TDateTimeField *PersonsQueryEntOn;
   TStringField *PersonsQueryEntBy;
   TQRLabel *QRLabel8;
   TQRShape *QRShape1;
   TQRShape *QRShape2;
   TQRLabel *QRLabel2;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TQRLabel *QRLabel9;
   TQRSysData *QRSysData4;
   TQRLabel *QRLabel10;
   TQRSysData *QRSysData5;
private:	// User declarations
public:		// User declarations
   __fastcall TRoomProtocolResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRoomProtocolResForm *RoomProtocolResForm;
//---------------------------------------------------------------------------
#endif
