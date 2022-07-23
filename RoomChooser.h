//---------------------------------------------------------------------------

#ifndef RoomChooserH
#define RoomChooserH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TRoomChooserForm : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TDBLookupComboBox *RoomLookup;
   TBitBtn *OKBtn;
   TBitBtn *SaveBtn;
   TDBEdit *DBEdit1;
   TQuery *PlaceQuery;
   TStringField *PlaceQueryCode;
   TStringField *PlaceQueryName;
   TDataSource *PlaceSource;
   TBitBtn *BitBtn1;
   TSaveDialog *SaveDialogCSV;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall BitBtn2Click(TObject *Sender);
   void __fastcall OKBtnClick(TObject *Sender);
   void __fastcall SaveBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TRoomChooserForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRoomChooserForm *RoomChooserForm;
//---------------------------------------------------------------------------
#endif
