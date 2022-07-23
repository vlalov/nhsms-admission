//---------------------------------------------------------------------------

#ifndef DataModuleH
#define DataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include <QRExport.hpp>
//---------------------------------------------------------------------------
const int eKeyViol = 9729;
const int eRequiredFieldMissing = 9732;
const int eForeignKey = 9733;
const int eDetailsExist = 9734;

class TData : public TDataModule
{
__published:	// IDE-managed Components
   TSession *Session1;
   TDatabase *Database1;
   TTable *TaxesTable;
   TFloatField *TaxesTableValue;
   TStringField *TaxesTableName;
   TDataSource *TaxesSource;
   TIntegerField *TaxesTableID;
   TDataSource *ProfilesSource;
   TDataSource *PersonsSource;
   TQuery *PersonsQuery;
   TUpdateSQL *PersonsUpdateSQL;
   TIntegerField *PersonsQueryID;
   TStringField *PersonsQueryName;
   TStringField *PersonsQueryEGN;
   TStringField *PersonsQueryTelephone;
   TStringField *PersonsQueryAddress;
   TIntegerField *PersonsQuerySex;
   TIntegerField *PersonsQueryTax_id;
   TrsPropSaver *rsPropSaver1;
   TDataSource *TextsDataSource;
   TDateTimeField *PersonsQueryEntOn;
   TStringField *PersonsQueryEntBy;
   TTable *PlacesTable;
   TIntegerField *PlacesTableID;
   TStringField *PlacesTableName;
   TStringField *PlacesTableText;
   TDataSource *PlacesSource;
   TTable *RoomsTable;
   TDataSource *RoomsSource;
   TIntegerField *RoomsTablePlace_ID;
   TIntegerField *RoomsTableCapacity;
   TStringField *RoomsTableCode;
   TQuery *CalcFreeRoomsQuery;
   TStringField *CalcFreeRoomsQueryCode;
   TIntegerField *CalcFreeRoomsQueryCNT;
   TStringField *PersonsQueryRoom_Code;
   TQuery *TextsTable;
   TUpdateSQL *TextsUpdateSQL;
   TIntegerField *TextsTableID;
   TMemoField *TextsTableValue;
   TDataSource *AllRoomsSource;
   TQuery *AllRoomsQuery;
   TStringField *AllRoomsQueryCode;
   TQuery *ExamResultsQuery;
   TIntegerField *ExamResultsQueryID;
   TIntegerField *ExamResultsQueryPerson_ID;
   TIntegerField *ExamResultsQueryExam;
   TUpdateSQL *ExamResultsUpdateSQL;
   TDataSource *ExamResultsSource;
   TStringField *ExamResultsQueryPerson;
   TFloatField *ExamResultsQueryPoints;
   TFloatField *ExamResultsQueryScore;
   TStringField *RoomsTableComment;
   TQuery *CalcFkNextQuery;
   TIntegerField *CalcFkNextQueryLAST;
   TQuery *ResolveScoresQuery;
   TIntegerField *ResolveScoresQueryID;
   TStringField *ResolveScoresQueryName;
   TFloatField *ResolveScoresQuerySchoolScore;
   TFloatField *ResolveScoresQueryExamScore;
   TQuery *RegisterQuery;
   TUpdateSQL *RegisterUpdateSQL;
   TIntegerField *RegisterQueryProfile_ID;
   TIntegerField *RegisterQueryPerson_ID;
   TFloatField *RegisterQueryAmount;
   TBooleanField *RegisterQueryIsIn;
   TDataSource *RegisterSource;
   TStringField *RegisterQueryPerson;
   TBooleanField *RegisterQueryClassificated;
   TQuery *SingleQuery;
   TIntegerField *RegisterQuerySex;
   TQuery *NameQuery;
   TStringField *NameQueryoperator;
   TQRTextFilter *QRTextFilter1;
   TQuery *RegisterNumQuery;
   TIntegerField *RegisterNumQueryRegisterNumber;
   TUpdateSQL *RegisterNumUpdateSQL;
   TQuery *RegisterDeletedQuery;
   TUpdateSQL *RegisterDeletedUpdateSQL;
   TIntegerField *RegisterDeletedQueryPerson_ID;
   TQuery *CalcBALQuery;
   TIntegerField *CalcBALQueryID;
   TIntegerField *CalcBALQueryProfile_ID;
   TFloatField *CalcBALQuerySchoolScore;
   TFloatField *CalcBALQueryFirstExamScore;
   TFloatField *CalcBALQueryExam;
   TFloatField *CalcBALQueryBAL;
   TIntegerField *CalcBALQueryPriority;
   TIntegerField *CalcBALQuerySex;
   TQuery *RegisterGradeQuery;
   TUpdateSQL *RegisterGradeUpdateSQL;
   TIntegerField *RegisterGradeQueryGrade;
   TStringField *RegisterGradeQueryInformation;
   TDateTimeField *RegisterGradeQueryEntOn;
   TStringField *RegisterGradeQueryEntBy;
   TDataSource *RegGradeDataSource;
   TQuery *RegisterHistoryQuery;
   TDataSource *RegHistoryDataSource;
   TIntegerField *RegisterHistoryQueryGrade;
   TBooleanField *RegisterHistoryQueryClassificated;
   TIntegerField *RegisterHistoryQueryPerson_ID;
   TIntegerField *RegisterHistoryQueryProfile_ID;
   TFloatField *RegisterHistoryQueryAmount;
   TStringField *RegisterHistoryQueryPerson;
   TQuery *InitClassifQuery;
   TBooleanField *BooleanField1;
   TIntegerField *IntegerField1;
   TIntegerField *IntegerField2;
   TFloatField *FloatField1;
   TBooleanField *BooleanField2;
   TIntegerField *IntegerField3;
   TIntegerField *InitClassifQueryPriority;
   TBooleanField *RegisterHistoryQueryIsIn;
   TQuery *ProfilesHistoryQuery;
   TIntegerField *ProfilesHistoryQueryGrade;
   TIntegerField *ProfilesHistoryQueryID;
   TBooleanField *ProfilesHistoryQueryDiffMW;
   TIntegerField *ProfilesHistoryQuerySpace;
   TIntegerField *ProfilesHistoryQuerySpaceOther;
   TQuery *SearchSwapsQuery;
   TIntegerField *SearchSwapsQueryAfterSwap;
   TQuery *MAXIDQuery;
   TIntegerField *MAXIDQueryMAXIMUM;
   TQuery *ValidateExamResultsQuery;
   TIntegerField *ValidateExamResultsQueryN;
   TIntegerField *ValidateExamResultsQueryID;
   TIntegerField *ValidateExamResultsQueryPerson_ID;
   TIntegerField *ValidateExamResultsQueryExam;
   TFloatField *ValidateExamResultsQueryPoints;
   TFloatField *ValidateExamResultsQueryScore;
   TQuery *ProfilesHistShowQuery;
   TIntegerField *ProfilesHistShowQueryGrade;
   TIntegerField *ProfilesHistShowQueryID;
   TBooleanField *ProfilesHistShowQueryDiffMW;
   TIntegerField *ProfilesHistShowQuerySpace;
   TIntegerField *ProfilesHistShowQuerySpaceOther;
   TStringField *ProfilesHistShowQuerySpaceFemale;
   TDataSource *ProfilesHistDataSource;
   TStringField *ProfilesHistShowQueryProfile;
   TIntegerField *ProfilesHistShowQuerymale;
   TIntegerField *ProfilesHistShowQueryfemale;
   TIntegerField *ProfilesHistShowQueryAllocAll;
   TQuery *ProfilesTable;
   TUpdateSQL *ProfilesUpdateSQL;
   TIntegerField *ProfilesTableID;
   TStringField *ProfilesTableName;
   TBooleanField *ProfilesTableDiffMW;
   TIntegerField *ProfilesTableSpace;
   TIntegerField *ProfilesTableSpaceOther;
   TIntegerField *ProfilesTableAllocAll;
   TIntegerField *ProfilesTablemale;
   TIntegerField *ProfilesTablefemale;
   TStringField *ProfilesTableSpaceW;
   TQuery *CheckIsInQuery;
   TIntegerField *CheckIsInQuerymale;
   TIntegerField *CheckIsInQueryfemale;
   TBooleanField *PersonsQueryPreferedSchool;
   void __fastcall PersonsQueryAfterPost(TDataSet *DataSet);
   void __fastcall PersonsQueryAfterScroll(TDataSet *DataSet);
   void __fastcall PersonsQueryAfterInsert(TDataSet *DataSet);
   void __fastcall PersonsQueryAfterCancel(TDataSet *DataSet);
   void __fastcall TextsTableAfterPost(TDataSet *DataSet);
   void __fastcall TextsTableAfterScroll(TDataSet *DataSet);
   void __fastcall ExamResultsQueryAfterPost(TDataSet *DataSet);
   void __fastcall ExamResultsQueryBeforePost(TDataSet *DataSet);
   void __fastcall ExamResultsQueryAfterInsert(TDataSet *DataSet);
   void __fastcall RegisterQueryAfterPost(TDataSet *DataSet);
   void __fastcall ProfilesTableCalcFields(TDataSet *DataSet);
   void __fastcall PersonsQueryUpdateError(TDataSet *DataSet,
          EDatabaseError *E, TUpdateKind UpdateKind,
          TUpdateAction &UpdateAction);
   void __fastcall RegisterHistoryQueryAfterOpen(TDataSet *DataSet);
   void __fastcall RegisterGradeQueryAfterScroll(TDataSet *DataSet);
        void __fastcall PersonsQueryBeforePost(TDataSet *DataSet);
   void __fastcall ExamResultsQueryUpdateError(TDataSet *DataSet,
          EDatabaseError *E, TUpdateKind UpdateKind,
          TUpdateAction &UpdateAction);
   void __fastcall ExamResultsQueryAfterScroll(TDataSet *DataSet);
   void __fastcall ProfilesHistShowQueryCalcFields(TDataSet *DataSet);
   void __fastcall ProfilesTableAfterPost(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
   __fastcall TData(TComponent* Owner);
   void __fastcall SetDataSets(bool toState);
   void __fastcall CommitPersonsChanges();
   void __fastcall SetWishes(bool toState);
   AnsiString __fastcall GenerateRoomCode();
   void __fastcall ResolvePointsToScore();
};
//---------------------------------------------------------------------------
extern PACKAGE TData *Data;
//---------------------------------------------------------------------------
#endif
