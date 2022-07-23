//---------------------------------------------------------------------------

#ifndef PreviewTextH
#define PreviewTextH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPreviewTextForm : public TForm
{
__published:	// IDE-managed Components
   TRichEdit *Text;
   TPanel *Panel1;
   TSpeedButton *PrintBtn;
   TSpeedButton *EncodeBtn;
   TSpeedButton *DecodeBtn;
   TStatusBar *StatusBar1;
   void __fastcall PrintBtnClick(TObject *Sender);
   void __fastcall EncodeBtnClick(TObject *Sender);
   void __fastcall DecodeBtnClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall StatusBar1Resize(TObject *Sender);
   void __fastcall StatusBar1DrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
private:	// User declarations
public:		// User declarations
   __fastcall TPreviewTextForm(TComponent* Owner);
   AnsiString save;
};
//---------------------------------------------------------------------------
extern PACKAGE TPreviewTextForm *PreviewTextForm;
//---------------------------------------------------------------------------
#endif
