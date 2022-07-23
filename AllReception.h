//---------------------------------------------------------------------------

#ifndef AllReceptionH
#define AllReceptionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TAllReceptionForm : public TForm
{
__published:	// IDE-managed Components
   TQuery *OperatorsQuery;
   TStringField *OperatorsQueryentby;
   TQuery *ParseQuery;
   TDataSource *DataSource1;
   TDBGrid *DBGrid1;
   TIntegerField *ParseQueryID;
   TStringField *ParseQueryName;
   TStringField *ParseQueryEGN;
   TStringField *ParseQueryTelephone;
   TStringField *ParseQueryAddress;
   TIntegerField *ParseQuerySex;
   TIntegerField *ParseQueryTax_id;
   TDateTimeField *ParseQueryEntOn;
   TStringField *ParseQueryEntBy;
   TStatusBar *StatusBar1;
   TPanel *Panel2;
   TPanel *Panel1;
   TBitBtn *SearchBtn;
   TBitBtn *CancelBtn;
   TPageControl *PageControl1;
   TTabSheet *Tab1;
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
   TTabSheet *Tab2;
   TGroupBox *GroupBox2;
   TLabel *Label4;
   TCheckBox *OperatorNameCheck;
   TComboBox *OperatorNameCombo;
   TGroupBox *GroupBox3;
   TLabel *Label5;
   TLabel *Label6;
   TCheckBox *DateEntered;
   TDateTimePicker *StartDateTime;
   TDateTimePicker *EndDateTime;
   TBitBtn *PrintBtn;
   TStringField *ParseQueryTax;
   TQuery *WishesQuery;
   TIntegerField *WishesQueryPerson_ID;
   TIntegerField *WishesQueryProfile_ID;
   TStringField *WishesQueryProfile;
   TIntegerField *WishesQueryPriority;
   TFloatField *WishesQueryScore;
   TFloatField *WishesQueryOlympScore;
   TBooleanField *WishesQueryFromOlymp;
   TBooleanField *WishesQueryGoToExam;
   TDataSource *DataSource2;
   TStringField *WishesQueryGoToE;
   TStringField *WishesQueryFromOlym;
   TSplitter *Splitter1;
   TStringField *ParseQuerySe;
   TCheckBox *TaxesCheck;
   TLabel *LblKandidates;
   TPanel *WishesPanel;
   TLabel *LblWishes;
   TDBGrid *DBGrid2;
   TCheckBox *WishesCheck;
   TGroupBox *GroupBox5;
   TCheckBox *RoomCheck;
   TDBLookupComboBox *RoomLookup;
   TStringField *ParseQueryRoom_Code;
   TTabSheet *WishesTab;
   TGroupBox *GroupBox6;
   TDBLookupComboBox *WishesLookup;
   TCheckBox *WishesEntCheck;
   TGroupBox *GroupBox7;
   TDBLookupComboBox *PriorityLookup;
   TCheckBox *PriorityCheck;
   TLabel *Label3;
   TBitBtn *StatsBtn;
   TCheckBox *OlympCheck;
   TDateTimeField *WishesQueryEntOn;
   TStringField *WishesQueryEntBy;
   TQuery *RoomQuery;
   TIntegerField *RoomQueryCapacity;
   TStringField *RoomQueryCode;
   TDataSource *RoomSource;
   TGroupBox *GroupBox8;
   TCheckBox *IDCheck;
   TCSpinEdit *IDEdit;
   TPopupMenu *PersonsPopupMenu;
   TMenuItem *N1;
   TMenuItem *N2;
   TMenuItem *N3;
   TMenuItem *N4;
   TMenuItem *N5;
   TMenuItem *N6;
   TMenuItem *N7;
   TMenuItem *N8;
   TMenuItem *N9;
   TMenuItem *N10;
   TPopupMenu *WishesPopupMenu;
   TMenuItem *N11;
   TMenuItem *N12;
   TMenuItem *N13;
   TMenuItem *N14;
   TMenuItem *N15;
   TMenuItem *N16;
   TMenuItem *N17;
   TMenuItem *N18;
   TLabel *Label7;
   TEdit *AddressEdit;
   TSpeedButton *NameNOT;
   TSpeedButton *EGNNOT;
   TSpeedButton *AddressNOT;
   TSpeedButton *TaxNOT;
   TSpeedButton *RoomNOT;
   TBooleanField *ParseQueryPreferedSchool;
   void __fastcall OperatorNameCheckClick(TObject *Sender);
   void __fastcall DateEnteredClick(TObject *Sender);
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall SexTypeCheckClick(TObject *Sender);
   void __fastcall TaxTypeCheckClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall SearchBtnClick(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall WishesQueryCalcFields(TDataSet *DataSet);
   void __fastcall ParseQueryCalcFields(TDataSet *DataSet);
   void __fastcall PrintBtnClick(TObject *Sender);
   void __fastcall NameEditChange(TObject *Sender);
   void __fastcall TaxTypeLookupClick(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall RoomCheckClick(TObject *Sender);
   void __fastcall WishesEntCheckClick(TObject *Sender);
   void __fastcall PriorityCheckClick(TObject *Sender);
   void __fastcall StatsBtnClick(TObject *Sender);
   void __fastcall OlympCheckClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall IDCheckClick(TObject *Sender);
   void __fastcall N2Click(TObject *Sender);
   void __fastcall N3Click(TObject *Sender);
   void __fastcall N4Click(TObject *Sender);
   void __fastcall N5Click(TObject *Sender);
   void __fastcall N6Click(TObject *Sender);
   void __fastcall N7Click(TObject *Sender);
   void __fastcall N8Click(TObject *Sender);
   void __fastcall N9Click(TObject *Sender);
   void __fastcall N10Click(TObject *Sender);
   void __fastcall N12Click(TObject *Sender);
   void __fastcall N13Click(TObject *Sender);
   void __fastcall N14Click(TObject *Sender);
   void __fastcall N15Click(TObject *Sender);
   void __fastcall N16Click(TObject *Sender);
   void __fastcall N17Click(TObject *Sender);
   void __fastcall N18Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TAllReceptionForm(TComponent* Owner);
   int __fastcall CalcAnds();
   void __fastcall Hiligh();
};
//---------------------------------------------------------------------------
extern PACKAGE TAllReceptionForm *AllReceptionForm;
//---------------------------------------------------------------------------
#endif
