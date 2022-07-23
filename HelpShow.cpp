//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HelpShow.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma link "lmdcont"
#pragma link "LMDCustomComponent"
#pragma resource "*.dfm"
THelpShowForm *HelpShowForm;
//---------------------------------------------------------------------------
__fastcall THelpShowForm::THelpShowForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THelpShowForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   MainForm->Online1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall THelpShowForm::FormActivate(TObject *Sender)
{
   MainForm->Online1->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall THelpShowForm::SetText(int type) {
   Text->Lines->Text=LMDStringList1->Items[type]->Items->Text;
}
