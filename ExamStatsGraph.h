//---------------------------------------------------------------------------

#ifndef ExamStatsGraphH
#define ExamStatsGraphH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <MXDB.hpp>
#include <MXGRAPH.hpp>
#include <Mxstore.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TExamStatsGraphForm : public TForm
{
__published:	// IDE-managed Components
   TDecisionSource *ScoreDecisionSource;
   TDecisionCube *ScoreDecisionCube;
   TDecisionCube *PointsDecisionCube;
   TDecisionSource *PoinsDecisionSource;
   TPageControl *PageControl;
   TTabSheet *ScoreTab;
   TTabSheet *PointsTab;
   TDecisionGraph *PointsDecisionGraph;
   TBarSeries *BarSeries1;
   TBarSeries *BarSeries2;
   TDecisionGraph *ScoreDecisionGraph;
   TBarSeries *Series1;
   TBarSeries *Series2;
private:	// User declarations
public:		// User declarations
   __fastcall TExamStatsGraphForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExamStatsGraphForm *ExamStatsGraphForm;
//---------------------------------------------------------------------------
#endif
