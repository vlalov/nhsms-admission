//---------------------------------------------------------------------------

#ifndef HelpShowH
#define HelpShowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include "lmdcont.hpp"
#include "LMDCustomComponent.hpp"
//---------------------------------------------------------------------------
class THelpShowForm : public TForm
{
__published:	// IDE-managed Components
   TMemo *Text;
   TrsPropSaver *rsPropSaver1;
   TLMDStringList *LMDStringList1;
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall THelpShowForm(TComponent* Owner);
   void __fastcall SetText(int type);
};
//---------------------------------------------------------------------------
extern PACKAGE THelpShowForm *HelpShowForm;
//---------------------------------------------------------------------------
#endif
