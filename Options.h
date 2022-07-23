//---------------------------------------------------------------------------

#ifndef OptionsH
#define OptionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TOptionsForm : public TForm
{
__published:	// IDE-managed Components
   TrsPropSaver *rsPropSaver1;
   TLabel *Label1;
   TEdit *DSNEdit;
   TBitBtn *BitBtn1;
   TGroupBox *GroupBox1;
   TCheckBox *AutoLogOnCheck;
   TOpenDialog *CodeTable;
   TGroupBox *GroupBox2;
   TLabeledEdit *CodeTableLabel;
   TSpeedButton *SpeedButton1;
   TLabel *Label2;
   TComboBox *PrintDevice;
   TButton *TestBtn;
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall SpeedButton1Click(TObject *Sender);
   void __fastcall TestBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TOptionsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsForm *OptionsForm;
//---------------------------------------------------------------------------
#endif
