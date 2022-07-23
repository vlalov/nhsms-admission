//----------------------------------------------------------------------------
#ifndef LoginH
#define LoginH
//----------------------------------------------------------------------------
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
//----------------------------------------------------------------------------
class TLoginForm : public TForm
{
__published:
	TLabel *Label1;
   TEdit *PasswordEdit;
	TButton *OKBtn;
	TButton *CancelBtn;
   TLabel *Label2;
   TComboBox *UserNameEdit;
   TrsPropSaver *rsPropSaver1;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall OKBtnClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
public:
	virtual __fastcall TLoginForm(TComponent* AOwner);
   bool flag;
};
//----------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//----------------------------------------------------------------------------
#endif    
