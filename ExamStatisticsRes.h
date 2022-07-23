//---------------------------------------------------------------------------

#ifndef ExamStatisticsResH
#define ExamStatisticsResH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TExamStatisticsResForm : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *ScoreQuickRep;
   TQRBand *QRBand1;
   TQRLabel *QRLabel9;
   TQRBand *QRBand2;
   TQRLabel *StatTypeLabel;
   TQRLabel *QRLabel12;
   TQRBand *QRBand4;
   TQRLabel *QRLabel15;
   TQRSysData *QRSysData3;
   TQRLabel *QRLabel16;
   TQRSysData *QRSysData4;
   TQRBand *DetailBand1;
   TQRDBText *StatTypeDB;
   TQRDBText *QRDBText2;
   TQuery *ParseScoreQuery;
   TFloatField *ParseScoreQueryScore;
   TIntegerField *ParseScoreQueryPers;
   TQuickRep *PointsQuickRep;
   TQRBand *QRBand3;
   TQRLabel *QRLabel1;
   TQRBand *QRBand5;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRBand *QRBand6;
   TQRLabel *QRLabel4;
   TQRSysData *QRSysData1;
   TQRLabel *QRLabel5;
   TQRSysData *QRSysData2;
   TQRBand *QRBand7;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText3;
   TQuery *ParsePointsQuery;
   TFloatField *ParsePointsQueryPoint;
   TIntegerField *ParsePointsQueryPers;
private:	// User declarations
public:		// User declarations
   __fastcall TExamStatisticsResForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExamStatisticsResForm *ExamStatisticsResForm;
//---------------------------------------------------------------------------
#endif
