//---------------------------------------------------------------------------

#ifndef CheckEGNH
#define CheckEGNH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TCheckEGNForm : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TBitBtn *SaveBtn;
   TQuery *PersonQuery;
   TIntegerField *PersonQueryID;
   TStringField *PersonQueryName;
   TStringField *PersonQueryEGN;
   TStringField *PersonQueryTelephone;
   TStringField *PersonQueryAddress;
   TIntegerField *PersonQuerySex;
   TIntegerField *PersonQueryTax_id;
   TStringField *PersonQueryRoom_Code;
   TDateTimeField *PersonQueryEntOn;
   TStringField *PersonQueryEntBy;
   TPageControl *PageControl1;
   TTabSheet *TabSheet1;
   TTabSheet *TabSheet2;
   TListBox *ListBox;
   TListBox *ListNames;
   TQuery *EqualNamesQuery;
   TIntegerField *EqualNamesQueryID1;
   TIntegerField *EqualNamesQueryID2;
   TBitBtn *BitBtn2;
   TSaveDialog *SaveDialog;
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall PageControl1Change(TObject *Sender);
   void __fastcall SaveBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TCheckEGNForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheckEGNForm *CheckEGNForm;
//---------------------------------------------------------------------------
#endif
