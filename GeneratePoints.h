//---------------------------------------------------------------------------

#ifndef GeneratePointsH
#define GeneratePointsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include "VrEdit.hpp"
#include <Buttons.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include <DB.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TGeneratePointsForm : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TLabel *Label2;
   TVrNumEdit *PointsFor2;
   TVrNumEdit *PointsFor6;
   TBitBtn *OKBtn;
   TBitBtn *BitBtn2;
   TQuery *WorkQuery;
   TGroupBox *GroupBox1;
   TVrNumEdit *Step;
   TRadioButton *ByScore;
   TRadioButton *ByPoints;
   TStatusBar *StatusBar1;
   void __fastcall BitBtn2Click(TObject *Sender);
   void __fastcall OKBtnClick(TObject *Sender);
   void __fastcall PointsFor2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TGeneratePointsForm(TComponent* Owner);
   int __fastcall CheckPoints();
};
//---------------------------------------------------------------------------
extern PACKAGE TGeneratePointsForm *GeneratePointsForm;
//---------------------------------------------------------------------------
#endif
