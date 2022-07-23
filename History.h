//---------------------------------------------------------------------------

#ifndef HistoryH
#define HistoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include "CSPIN.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class THistoryForm : public TForm
{
__published:	// IDE-managed Components
   TPageControl *PageControl;
   TPanel *Panel1;
   TTabSheet *TabSheet1;
   TTabSheet *TabSheet2;
   TBitBtn *BitBtn1;
   TPanel *Panel2;
   TPageControl *PageControl2;
   TTabSheet *OperTab;
   TTabSheet *OwnTab;
   TGroupBox *GroupBox1;
   TLabel *Label1;
   TCheckBox *ChangedOperCheck;
   TComboBox *ChangedOperCombo;
   TGroupBox *GroupBox3;
   TLabel *Label2;
   TLabel *Label3;
   TCheckBox *ChangedDateCheck;
   TDateTimePicker *StartChangedDateTime;
   TDateTimePicker *EndChangedDateTime;
   TGroupBox *GroupBox2;
   TLabel *Label4;
   TCheckBox *EntOperatorCheck;
   TComboBox *EntOperatorCombo;
   TGroupBox *GroupBox4;
   TLabel *Label5;
   TLabel *Label6;
   TCheckBox *EntDateCheck;
   TDateTimePicker *StartEntDateTime;
   TDateTimePicker *EndEntDateTime;
   TDBGrid *DBGrid1;
   TEdit *NameEdit;
   TLabel *Label7;
   TLabel *Label8;
   TEdit *EGNEdit;
   TGroupBox *GroupBox5;
   TDBLookupComboBox *TaxTypeLookup;
   TCheckBox *TaxTypeCheck;
   TGroupBox *GroupBox6;
   TCheckBox *SexTypeCheck;
   TRadioButton *MaleBtn;
   TRadioButton *FemaleBtn;
   TQuery *PersonsHistoryQuery;
   TQuery *EntByQuery;
   TStringField *EntByQueryentby;
   TQuery *ChangedByQuery;
   TStringField *ChangedByQuerychangedby;
   TBitBtn *SearchBtn;
   TGroupBox *GroupBox7;
   TCheckBox *IDCheck;
   TCSpinEdit *IDEdit;
   TDateTimeField *PersonsHistoryQueryDateChanged;
   TStringField *PersonsHistoryQueryChangedBy;
   TStringField *PersonsHistoryQueryComment;
   TIntegerField *PersonsHistoryQueryID;
   TStringField *PersonsHistoryQueryName;
   TStringField *PersonsHistoryQueryEGN;
   TStringField *PersonsHistoryQueryTelephone;
   TStringField *PersonsHistoryQueryAddress;
   TIntegerField *PersonsHistoryQuerySex;
   TIntegerField *PersonsHistoryQueryTax_id;
   TDateTimeField *PersonsHistoryQueryEntOn;
   TStringField *PersonsHistoryQueryEntBy;
   TDataSource *PersHistSource;
   TStringField *PersonsHistoryQuerySe;
   TStringField *PersonsHistoryQueryTax;
   TLabel *FoundLabel;
   TPanel *Panel3;
   TPageControl *PageControl1;
   TTabSheet *WishOperTab;
   TGroupBox *GroupBox8;
   TLabel *Label9;
   TCheckBox *ChangedWishCheck;
   TComboBox *ChangedWishOperCombo;
   TGroupBox *GroupBox9;
   TLabel *Label10;
   TLabel *Label11;
   TCheckBox *ChangedWishDateCheck;
   TDateTimePicker *StartChangedWishDateTime;
   TDateTimePicker *EndChangedWishDateTime;
   TTabSheet *WishOwnTab;
   TGroupBox *GroupBox14;
   TCheckBox *CandidWishCheck;
   TCSpinEdit *CandidNumEdit;
   TDBGrid *DBGrid2;
   TLabel *Label15;
   TDBLookupComboBox *CandidWishNameLookup;
   TLabel *Label12;
   TQuery *PersonsQuery;
   TIntegerField *PersonsQueryID;
   TStringField *PersonsQueryName;
   TStringField *PersonsQueryEGN;
   TStringField *PersonsQueryTelephone;
   TStringField *PersonsQueryAddress;
   TIntegerField *PersonsQuerySex;
   TIntegerField *PersonsQueryTax_id;
   TDateTimeField *PersonsQueryEntOn;
   TStringField *PersonsQueryEntBy;
   TDataSource *PersonsSource;
   TQuery *ChangedWishQuery;
   TStringField *StringField1;
   TQuery *WishesQuery;
   TDataSource *WishesSource;
   TDateTimeField *WishesQueryDateChanged;
   TStringField *WishesQueryChangedBy;
   TStringField *WishesQueryComment;
   TIntegerField *WishesQueryPerson_ID;
   TIntegerField *WishesQueryProfile_ID;
   TIntegerField *WishesQueryPriority;
   TFloatField *WishesQueryScore;
   TBooleanField *WishesQueryFromOlymp;
   TFloatField *WishesQueryOlympScore;
   TBooleanField *WishesQueryGoToExam;
   TStringField *WishesQueryPerson;
   TStringField *WishesQueryProfile;
   TStringField *WishesQueryGoToExa;
   TStringField *WishesQueryFromOlym;
   TBitBtn *PrintBtn;
   TGroupBox *GroupBox10;
   TCheckBox *RoomCheck;
   TDBLookupComboBox *RoomLookup;
   TStringField *PersonsHistoryQueryRoom_Code;
   TGroupBox *GroupBox11;
   TLabel *Label13;
   TCheckBox *EntWishOperCheck;
   TComboBox *EntWishOperCombo;
   TGroupBox *GroupBox12;
   TLabel *Label14;
   TLabel *Label16;
   TCheckBox *EntWishDateCheck;
   TDateTimePicker *StartEntWishDateTime;
   TDateTimePicker *EndEntWishDateTime;
   TQuery *EntByWishQuery;
   TStringField *StringField2;
   TDateTimeField *WishesQueryEntOn;
   TStringField *WishesQueryEntBy;
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
   TMenuItem *N11;
   TMenuItem *N12;
   TMenuItem *N13;
   TMenuItem *N14;
   TMenuItem *NAll;
   TPopupMenu *WishesPopupMenu;
   TMenuItem *MenuItem1;
   TMenuItem *MenuItem2;
   TMenuItem *MenuItem3;
   TMenuItem *MenuItem4;
   TMenuItem *MenuItem5;
   TMenuItem *MenuItem6;
   TMenuItem *MenuItem7;
   TMenuItem *MenuItem8;
   TMenuItem *MenuItem9;
   TMenuItem *MenuItem10;
   TMenuItem *MenuItem11;
   TMenuItem *MenuItem12;
   TMenuItem *MenuItem13;
   TMenuItem *MenuItem14;
   TMenuItem *MenuItem15;
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall ChangedOperCheckClick(TObject *Sender);
   void __fastcall EntOperatorCheckClick(TObject *Sender);
   void __fastcall ChangedDateCheckClick(TObject *Sender);
   void __fastcall EntDateCheckClick(TObject *Sender);
   void __fastcall TaxTypeCheckClick(TObject *Sender);
   void __fastcall SexTypeCheckClick(TObject *Sender);
   void __fastcall NameEditChange(TObject *Sender);
   void __fastcall SearchBtnClick(TObject *Sender);
   void __fastcall PersonsHistoryQueryCalcFields(TDataSet *DataSet);
   void __fastcall IDCheckClick(TObject *Sender);
   void __fastcall CandidWishCheckClick(TObject *Sender);
   void __fastcall ChangedWishCheckClick(TObject *Sender);
   void __fastcall ChangedWishDateCheckClick(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall WishesQueryCalcFields(TDataSet *DataSet);
   void __fastcall CandidNumEditChange(TObject *Sender);
   void __fastcall PageControlChange(TObject *Sender);
   void __fastcall PrintBtnClick(TObject *Sender);
   void __fastcall FormPaint(TObject *Sender);
   void __fastcall RoomCheckClick(TObject *Sender);
   void __fastcall EntWishOperCheckClick(TObject *Sender);
   void __fastcall EntWishDateCheckClick(TObject *Sender);
   void __fastcall CandidWishNameLookupCloseUp(TObject *Sender);
   void __fastcall N2Click(TObject *Sender);
   void __fastcall N3Click(TObject *Sender);
   void __fastcall N4Click(TObject *Sender);
   void __fastcall N5Click(TObject *Sender);
   void __fastcall N6Click(TObject *Sender);
   void __fastcall N7Click(TObject *Sender);
   void __fastcall N8Click(TObject *Sender);
   void __fastcall N9Click(TObject *Sender);
   void __fastcall N10Click(TObject *Sender);
   void __fastcall N11Click(TObject *Sender);
   void __fastcall N12Click(TObject *Sender);
   void __fastcall N13Click(TObject *Sender);
   void __fastcall NAllClick(TObject *Sender);
   void __fastcall MenuItem4Click(TObject *Sender);
   void __fastcall MenuItem5Click(TObject *Sender);
   void __fastcall MenuItem6Click(TObject *Sender);
   void __fastcall MenuItem7Click(TObject *Sender);
   void __fastcall MenuItem8Click(TObject *Sender);
   void __fastcall MenuItem9Click(TObject *Sender);
   void __fastcall MenuItem10Click(TObject *Sender);
   void __fastcall MenuItem11Click(TObject *Sender);
   void __fastcall MenuItem12Click(TObject *Sender);
   void __fastcall MenuItem13Click(TObject *Sender);
   void __fastcall MenuItem14Click(TObject *Sender);
   void __fastcall MenuItem15Click(TObject *Sender);
   void __fastcall MenuItem1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall THistoryForm(TComponent* Owner);
   void __fastcall HighLightOper();
   void __fastcall HighLightOwn();
   void __fastcall HighLightWishOper();
   int __fastcall CalcPersAnds();
   int __fastcall CalcWishAnds();
};
//---------------------------------------------------------------------------
extern PACKAGE THistoryForm *HistoryForm;
//---------------------------------------------------------------------------
#endif
