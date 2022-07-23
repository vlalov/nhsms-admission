//---------------------------------------------------------------------------

#ifndef RegisterSearcherH
#define RegisterSearcherH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "VrEdit.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TRegisterSearcherForm : public TForm
{
__published:	// IDE-managed Components
   TSplitter *Splitter1;
   TLabel *LblKandidates;
   TDBGrid *DBGrid1;
   TStatusBar *StatusBar1;
   TPanel *Panel2;
   TPanel *Panel1;
   TBitBtn *SearchBtn;
   TBitBtn *CancelBtn;
   TBitBtn *PrintBtn;
   TCheckBox *BCheck;
   TPageControl *PageControl1;
   TTabSheet *PersonalTab;
   TLabel *Label1;
   TLabel *Label2;
   TEdit *NameEdit;
   TEdit *EGNEdit;
   TGroupBox *GroupBox1;
   TCheckBox *SexTypeCheck;
   TRadioButton *MaleBtn;
   TRadioButton *FemaleBtn;
   TGroupBox *GroupBox4;
   TDBLookupComboBox *TaxTypeLookup;
   TCheckBox *TaxTypeCheck;
   TGroupBox *GroupBox5;
   TCheckBox *RoomCheck;
   TDBLookupComboBox *RoomLookup;
   TGroupBox *GroupBox8;
   TCheckBox *IDCheck;
   TCSpinEdit *IDEdit;
   TTabSheet *WishesTab;
   TGroupBox *GroupBox6;
   TDBLookupComboBox *WishesLookup;
   TCheckBox *WishesEntCheck;
   TGroupBox *GroupBox7;
   TDBLookupComboBox *PriorityLookup;
   TCheckBox *PriorityCheck;
   TPanel *WishesPanel;
   TLabel *LblWishes;
   TDBGrid *DBGrid2;
   TQuery *ParseQuery;
   TDataSource *DataSource1;
   TQuery *WishesQuery;
   TDataSource *DataSource2;
   TQuery *RoomQuery;
   TStringField *RoomQueryCode;
   TIntegerField *RoomQueryCapacity;
   TDataSource *RoomSource;
   TGroupBox *GroupBox2;
   TVrNumEdit *BALFromEdit;
   TVrNumEdit *BALToEdit;
   TRadioButton *BALFromRadio;
   TRadioButton *BALToRadio;
   TRadioButton *BALFromToRadio;
   TCheckBox *BALCheck;
   TIntegerField *ParseQueryID;
   TStringField *ParseQueryName;
   TStringField *ParseQueryEGN;
   TIntegerField *ParseQuerySex;
   TIntegerField *ParseQueryTax_ID;
   TStringField *ParseQueryRoom_Code;
   TBooleanField *WishesQueryClassificated;
   TIntegerField *WishesQueryProfile_ID;
   TFloatField *WishesQueryAmount;
   TBooleanField *WishesQueryIsIn;
   TStringField *WishesQueryProfile;
   TIntegerField *WishesQueryPerson_ID;
   TStringField *ParseQueryTax;
   TStringField *ParseQuerySe;
   TPopupMenu *CandidatesPopupMenu;
   TMenuItem *N1;
   TMenuItem *N2;
   TMenuItem *N3;
   TMenuItem *N4;
   TMenuItem *N5;
   TMenuItem *N6;
   TCheckBox *ProfCheck;
   TCheckBox *ClassifCheck;
   TIntegerField *WishesQueryPriority;
   TCheckBox *IsInCheck;
   TSpeedButton *NameNOT;
   TSpeedButton *EGNNOT;
   TSpeedButton *TaxNOT;
   TSpeedButton *RoomNOT;
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall RoomCheckClick(TObject *Sender);
   void __fastcall TaxTypeCheckClick(TObject *Sender);
   void __fastcall IDCheckClick(TObject *Sender);
   void __fastcall SexTypeCheckClick(TObject *Sender);
   void __fastcall WishesEntCheckClick(TObject *Sender);
   void __fastcall PriorityCheckClick(TObject *Sender);
   void __fastcall BALCheckClick(TObject *Sender);
   void __fastcall NameEditChange(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall SearchBtnClick(TObject *Sender);
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall ParseQueryCalcFields(TDataSet *DataSet);
   void __fastcall N2Click(TObject *Sender);
   void __fastcall N3Click(TObject *Sender);
   void __fastcall N4Click(TObject *Sender);
   void __fastcall N5Click(TObject *Sender);
   void __fastcall N6Click(TObject *Sender);
   void __fastcall PrintBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TRegisterSearcherForm(TComponent* Owner);
   int __fastcall CalcAnds();
};
//---------------------------------------------------------------------------
extern PACKAGE TRegisterSearcherForm *RegisterSearcherForm;
//---------------------------------------------------------------------------
#endif
