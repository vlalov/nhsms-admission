//---------------------------------------------------------------------------

#ifndef QuickRepPageH
#define QuickRepPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VrEdit.hpp"
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <ComCtrls.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include <Dialogs.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQuickRepEditorForm : public TForm
{
__published:	// IDE-managed Components
   TComboBox *PaperTypeCombo;
   TLabel *Label1;
   TComboBox *OrientationCombo;
   TLabel *Label4;
   TGroupBox *GroupBox1;
   TLabel *Label5;
   TVrNumEdit *TopMarginEdit;
   TLabel *Label6;
   TVrNumEdit *ButtomMarginEdit;
   TVrNumEdit *LeftMarginEdit;
   TLabel *Label7;
   TVrNumEdit *RigthMarginEdit;
   TLabel *Label8;
   TLabel *Label2;
   TVrNumEdit *WidthEdit;
   TLabel *Label3;
   TVrNumEdit *LengthEdit;
   TButton *CancelBtn;
   TButton *OKBtn;
   TGroupBox *GroupBox;
   TQuickRep *QuickRep1;
   TTrackBar *TrackPersent;
   TrsPropSaver *rsPropSaver1;
   TButton *FontBtn;
   TFontDialog *FontDialog;
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall PaperTypeComboChange(TObject *Sender);
   void __fastcall OrientationComboChange(TObject *Sender);
   void __fastcall LengthEditChange(TObject *Sender);
   void __fastcall TrackPersentChange(TObject *Sender);
   void __fastcall LeftMarginEditChange(TObject *Sender);
   void __fastcall OKBtnClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall FontBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TQuickRepEditorForm(TComponent* Owner);
   void __fastcall SetPageValues(TQuickRep *Dest,TQRCompositeReport *composite=NULL);
   void __fastcall ApplyToAll();
};
//---------------------------------------------------------------------------
extern PACKAGE TQuickRepEditorForm *QuickRepEditorForm;
//---------------------------------------------------------------------------
#endif
