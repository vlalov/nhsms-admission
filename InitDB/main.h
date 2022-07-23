//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include "rsIniData.hpp"
#include "rsStorage.hpp"
//---------------------------------------------------------------------------
class TInitMainForm : public TForm
{
__published:	// IDE-managed Components
   TSession *Session1;
   TDatabase *Database1;
   TLabel *Label1;
   TEdit *DSNEdit;
   TLabel *Label2;
   TEdit *ScriptFile;
   TSpeedButton *SpeedButton1;
   TOpenDialog *OpenDialog1;
   TBitBtn *CreateBtn;
   TBitBtn *BitBtn2;
   TQuery *Query1;
   TrsIniData *rsIniData1;
   TrsStorage *rsStorage1;
   void __fastcall SpeedButton1Click(TObject *Sender);
   void __fastcall CreateBtnClick(TObject *Sender);
   void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TInitMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInitMainForm *InitMainForm;
//---------------------------------------------------------------------------
#endif
