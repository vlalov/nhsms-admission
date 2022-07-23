//---------------------------------------------------------------------------

#ifndef ReceptionMapH
#define ReceptionMapH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TReceptionMapForm : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TGroupBox *GroupBox1;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TLabel *Label4;
   TLabel *Label5;
   TLabel *Label6;
   TDBText *DBText1;
   TCSpinEdit *IDEdit;
   TDBEdit *DBEdit1;
   TDBEdit *DBEdit2;
   TDBEdit *DBEdit3;
   TDBEdit *DBEdit4;
   TGroupBox *GroupBox2;
   TDBGrid *WishesGrid;
   TPanel *Panel2;
   TGroupBox *GroupBox3;
   TDBGrid *ExamsGrid;
   TGroupBox *GroupBox4;
   TDBGrid *ClassificateGrid;
   TSplitter *Splitter1;
   TQuery *PersonQuery;
   TDataSource *PersonSource;
   TIntegerField *PersonQueryID;
   TStringField *PersonQueryName;
   TStringField *PersonQueryEGN;
   TStringField *PersonQueryTelephone;
   TStringField *PersonQueryAddress;
   TIntegerField *PersonQuerySex;
   TIntegerField *PersonQueryTax_id;
   TStringField *PersonQueryRoom_Code;
   TDateTimeField *PersonQueryEntOn;
   TStringField *PersonQueryEntBy;
   TStringField *PersonQuerySe;
   TLabel *Label7;
   TDBEdit *DBEdit5;
   TLabel *Label8;
   TDBEdit *DBEdit6;
   TStringField *PersonQueryTax;
   TLabel *Label9;
   TDBEdit *DBEdit7;
   TLabel *Label10;
   TDBEdit *DBEdit8;
   TDBText *DBText2;
   TStringField *PersonQueryValidEGN;
   TQuery *WishesQuery;
   TDataSource *WishesSource;
   TIntegerField *WishesQueryPerson_ID;
   TIntegerField *WishesQueryProfile_ID;
   TIntegerField *WishesQueryPriority;
   TFloatField *WishesQueryScore;
   TBooleanField *WishesQueryFromOlymp;
   TFloatField *WishesQueryOlympScore;
   TBooleanField *WishesQueryGoToExam;
   TDateTimeField *WishesQueryEntOn;
   TStringField *WishesQueryEntBy;
   TStringField *WishesQueryProfile;
   TQuery *ExamsQuery;
   TDataSource *ExamsSource;
   TIntegerField *ExamsQueryID;
   TIntegerField *ExamsQueryExam;
   TFloatField *ExamsQueryPoints;
   TFloatField *ExamsQueryScore;
   TStringField *ExamsQueryExa;
   TQuery *ClassificateQuery;
   TDataSource *ClassificateSource;
   TBooleanField *ClassificateQueryClassificated;
   TIntegerField *ClassificateQueryProfile_ID;
   TFloatField *ClassificateQueryAmount;
   TBooleanField *ClassificateQueryIsIn;
   TIntegerField *ClassificateQueryPriority;
   TStringField *ClassificateQueryStatus;
   TStringField *ClassificateQueryProfile;
   TQuery *HelpQuery;
   TIntegerField *ClassificateQueryPerson_ID;
   TBooleanField *HelpQueryClassificated;
   TIntegerField *HelpQueryProfile_ID;
   TIntegerField *HelpQueryPerson_ID;
   TFloatField *HelpQueryAmount;
   TBooleanField *HelpQueryIsIn;
   TStringField *ClassificateQueryIsInExt;
   TQuery *ClassificationNumberQuery;
   TIntegerField *ClassificationNumberQueryRegisterNumber;
   TDBCheckBox *DBCheckBox1;
   TBooleanField *PersonQueryPreferedSchool;
   void __fastcall IDEditChange(TObject *Sender);
   void __fastcall PersonQueryCalcFields(TDataSet *DataSet);
   void __fastcall ExamsQueryCalcFields(TDataSet *DataSet);
   void __fastcall ClassificateQueryCalcFields(TDataSet *DataSet);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TReceptionMapForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReceptionMapForm *ReceptionMapForm;
//---------------------------------------------------------------------------
#endif
