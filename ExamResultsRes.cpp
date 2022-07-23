//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExamResultsRes.h"
#include "ExamResultSearcher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExamResultsResForm *ExamResultsResForm;
//---------------------------------------------------------------------------
__fastcall TExamResultsResForm::TExamResultsResForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TExamResultsResForm::OfficialQueryCalcFields(
      TDataSet *DataSet)
{
 AnsiString text;
 float score=DataSet->FieldByName("Score")->AsFloat;
   if (score>=2&&score<3)     text="Слаб";
   if (score>=3&&score<3.5)   text="Среден";
   if (score>=3.5&&score<4.5) text="Добър";
   if (score>=4.5&&score<5.5) text="Мн. добър";
   if (score>=5.5&&score<=6)  text="Отличен";
   if (score==0) text="Неявил се";
   DataSet->FieldByName("ScoreLabel")->AsString=text;
   if (score!=6) {
      if (score!=0) DataSet->FieldByName("ScoreString")->AsString=FormatFloat("#0.00",score);
   } else DataSet->FieldByName("ScoreString")->AsString="6";
}
//---------------------------------------------------------------------------

