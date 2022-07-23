//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
#include <CheckLst.hpp>
#include "rsIniData.hpp"
#include "rsStorage.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TEdit *PathEdit;
   TButton *Button1;
   TSpeedButton *SpeedButton1;
   TComboBox *TableEdit;
   TDatabase *Database;
   TQuery *Query1;
   TSaveDialog *SaveDialog;
   TCheckListBox *ListBox;
   TButton *Button2;
   TComboBox *AliasEdit;
   TrsIniData *rsIniData1;
   TrsStorage *rsStorage1;
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall SpeedButton1Click(TObject *Sender);
   void __fastcall Button2Click(TObject *Sender);
   void __fastcall TableEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
