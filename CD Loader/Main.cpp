//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Chooser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDControl"
#pragma link "LMDFill"
#pragma link "LMDGraphicControl"
#pragma resource "*.dfm"
TBannerForm *BannerForm;
//---------------------------------------------------------------------------
__fastcall TBannerForm::TBannerForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBannerForm::FormActivate(TObject *Sender)
{
   this->WindowState=wsMaximized;
   this->Repaint();
   ChooserForm->ShowModal();
   //MessageBeep(0xFFFFFFFF);
}
//---------------------------------------------------------------------------

