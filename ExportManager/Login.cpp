//---------------------------------------------------------------------
#include <vcl.h>

#include "Login.h"
#include "main.h"
#pragma hdrstop

//---------------------------------------------------------------------
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TLoginForm *LoginForm;
//---------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------


void __fastcall TLoginForm::FormShow(TObject *Sender)
{
   Tag=0;
   if (UserNameEdit->Text.IsEmpty())
      this->ActiveControl=UserNameEdit;
   else
      this->ActiveControl=PasswordEdit;
   PasswordEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TLoginForm::CancelBtnClick(TObject *Sender)
{
   Tag=-1;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TLoginForm::OKBtnClick(TObject *Sender)
{
   Tag=1;
   flag=false;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if (Tag!=1) Tag=-1;
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   if (flag==true) {
      CanClose=false;
      MessageBeep(MB_ICONASTERISK);
   } else {
      CanClose=true;
   }
}
//---------------------------------------------------------------------------

