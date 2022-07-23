//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExamStatsGraph.h"
#include "ExamStatisticsRes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExamStatsGraphForm *ExamStatsGraphForm;
//---------------------------------------------------------------------------
__fastcall TExamStatsGraphForm::TExamStatsGraphForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
