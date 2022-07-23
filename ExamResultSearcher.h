//---------------------------------------------------------------------------

#ifndef ExamResultSearcherH
#define ExamResultSearcherH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "VrEdit.hpp"
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TExamsResultSearcherForm : public TForm
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
   TCheckBox *ResultsCheck;
   TPanel *WishesPanel;
   TLabel *LblWishes;
   TDBGrid *DBGrid2;
   TQuery *PersonsQuery;
   TQuery *ResultsQuery;
   TDataSource *PersonsSource;
   TIntegerField *PersonsQueryID;
   TStringField *PersonsQueryName;
   TStringField *PersonsQueryEGN;
   TIntegerField *ResultsQueryID;
   TIntegerField *ResultsQueryPerson_ID;
   TIntegerField *ResultsQueryExam;
   TFloatField *ResultsQueryPoints;
   TFloatField *ResultsQueryScore;
   TDataSource *ResultsSource;
   TStringField *ResultsQueryExa;
   TFloatField *ResultsQuerySchoolScore;
   TFloatField *ResultsQueryOlympScore;
   TPageControl *PageControl1;
   TTabSheet *CandidTab;
   TTabSheet *ResultTab;
   TGroupBox *GroupBox4;
   TCheckBox *PointsCheck;
   TVrNumEdit *PointsFromEdit;
   TVrNumEdit *PointsToEdit;
   TRadioButton *PointsFromRadio;
   TRadioButton *PointsToRadio;
   TRadioButton *PointsFromToRadio;
   TGroupBox *GroupBox5;
   TCheckBox *ScoreCheck;
   TVrNumEdit *ScoreFromEdit;
   TVrNumEdit *ScoreToEdit;
   TRadioButton *ScoreFromRadio;
   TRadioButton *ScoreToRadio;
   TRadioButton *ScoreFromToRadio;
   TGroupBox *GroupBox6;
   TComboBox *ExamLookup;
   TCheckBox *ExamCheck;
   TBitBtn *StatsBtn;
   TBitBtn *ChartBtn;
   TGroupBox *GroupBox1;
   TRadioButton *PointsRadio;
   TRadioButton *ScoreRadio;
   TGroupBox *GroupBox2;
   TCSpinEdit *NumEdit;
   TCheckBox *NumCheck;
   TGroupBox *GroupBox3;
   TCSpinEdit *FkEdit;
   TCheckBox *FkCheck;
   TTabSheet *WishTab;
   TGroupBox *GroupBox7;
   TCheckBox *HaveWishCheck;
   TLabel *Label1;
   TDBLookupComboBox *ProfileLookup;
   TGroupBox *GroupBox8;
   TDBLookupComboBox *PriorityLookup;
   TCheckBox *PriorityCheck;
   TStringField *PersonsQueryTelephone;
   TBooleanField *PersonsQueryPreferedSchool;
   TCheckBox *PreferedSchoolCheck;
   void __fastcall FormShow(TObject *Sender);
   void __fastcall NumCheckClick(TObject *Sender);
   void __fastcall FkCheckClick(TObject *Sender);
   void __fastcall PointsCheckClick(TObject *Sender);
   void __fastcall PointsFromRadioClick(TObject *Sender);
   void __fastcall ScoreCheckClick(TObject *Sender);
   void __fastcall ScoreFromRadioClick(TObject *Sender);
   void __fastcall ExamLookupChange(TObject *Sender);
   void __fastcall CancelBtnClick(TObject *Sender);
   void __fastcall ResultsQueryCalcFields(TDataSet *DataSet);
   void __fastcall SearchBtnClick(TObject *Sender);
   void __fastcall PrintBtnClick(TObject *Sender);
   void __fastcall StatsBtnClick(TObject *Sender);
   void __fastcall ChartBtnClick(TObject *Sender);
   void __fastcall ExamCheckClick(TObject *Sender);
   void __fastcall HaveWishCheckClick(TObject *Sender);
   void __fastcall PriorityCheckClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   bool search;
   __fastcall TExamsResultSearcherForm(TComponent* Owner);
   AnsiString __fastcall ResolveProfileLookupCode(int val);
   int __fastcall ResolveProfileCode(AnsiString text);
};
//---------------------------------------------------------------------------
extern PACKAGE TExamsResultSearcherForm *ExamsResultSearcherForm;
//---------------------------------------------------------------------------
#endif
