//---------------------------------------------------------------------------

#ifndef OperatorTaxesH
#define OperatorTaxesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TOperatorTaxesForm : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label4;
   TComboBox *OperatorNameCombo;
   TQuery *OperatorsQuery;
   TStringField *OperatorsQueryentby;
   TBitBtn *SearchBtn;
   TBitBtn *CancelBtn;
   TLabel *Label5;
   TDateTimePicker *StartDateTime;
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall SearchBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TOperatorTaxesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOperatorTaxesForm *OperatorTaxesForm;
//---------------------------------------------------------------------------
#endif
