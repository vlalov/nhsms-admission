//---------------------------------------------------------------------------

#ifndef ChooserH
#define ChooserH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TChooserForm : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *GroupBox1;
   TGroupBox *GroupBox2;
   TTreeView *TreeView1;
   TImageList *ImageList1;
   TLabel *Info;
   TBitBtn *BitBtn1;
   TBitBtn *BitBtn2;
   TBitBtn *HelpBtn;
   TBitBtn *VideoBtn;
   TPopupMenu *PopupMenu1;
   TMenuItem *SQLServer1;
   TMenuItem *BDE1;
   TMenuItem *N1;
   TMenuItem *N2;
   TMenuItem *SQL1;
   TMenuItem *N3;
   TMenuItem *SQLServerQueryAnalyzer1;
   void __fastcall TreeView1Change(TObject *Sender, TTreeNode *Node);
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall BitBtn2Click(TObject *Sender);
   void __fastcall HelpBtnClick(TObject *Sender);
   void __fastcall VideoBtnClick(TObject *Sender);
   void __fastcall SQLServer1Click(TObject *Sender);
   void __fastcall BDE1Click(TObject *Sender);
   void __fastcall SQL1Click(TObject *Sender);
   void __fastcall N3Click(TObject *Sender);
   void __fastcall SQLServerQueryAnalyzer1Click(TObject *Sender);
   void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   void __fastcall runMe(AnsiString command);
   __fastcall TChooserForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChooserForm *ChooserForm;
//---------------------------------------------------------------------------
#endif
