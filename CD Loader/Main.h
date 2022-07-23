//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDControl.hpp"
#include "LMDFill.hpp"
#include "LMDGraphicControl.hpp"
//---------------------------------------------------------------------------
class TBannerForm : public TForm
{
__published:	// IDE-managed Components
   TLMDFill *LMDFill1;
   TImage *Image1;
   TLabel *Label1;
   void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TBannerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBannerForm *BannerForm;
//---------------------------------------------------------------------------
#endif
