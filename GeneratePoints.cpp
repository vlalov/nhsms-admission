//---------------------------------------------------------------------------

#include <vcl.h>
#include "Main.h"
#pragma hdrstop

#include "GeneratePoints.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "VrEdit"
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TGeneratePointsForm *GeneratePointsForm;
//---------------------------------------------------------------------------
__fastcall TGeneratePointsForm::TGeneratePointsForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGeneratePointsForm::BitBtn2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
double CalcScore(const double a,const double b,const double p,const int type) {
   if (type==0) return (p-b)/a;
   if (type==1) return a*p+b;
   return 0;
}

void __fastcall TGeneratePointsForm::OKBtnClick(TObject *Sender)
{
 float A,B;
 float x1=PointsFor2->Value,x2=PointsFor6->Value,step=Step->Value,points;
 int profile=this->Tag;
 // Checking datas...
   if (CheckPoints()!=0) {
      Application->MessageBox("Некоректни стойности!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return;
   }
   MainForm->ClearPoints();
   A=3/(x2-x1); B=(3*x2-6*x1)/(x2-x1);

   WorkQuery->SQL->Clear();
   WorkQuery->SQL->Add("INSERT INTO PointsToScore(Profile_ID,Point,Score) VALUES(:SET_PROFILE,ROUND(:SET_POINTS,2),ROUND(:SET_SCORE,2)) ");
   WorkQuery->Prepare();
   if (ByScore->Checked) {
      for (float score=3;score<=6;score+=step) {
         WorkQuery->ParamByName("SET_PROFILE")->AsInteger=profile;
         WorkQuery->ParamByName("SET_POINTS")->AsFloat=CalcScore(A,B,score,0);
         WorkQuery->ParamByName("SET_SCORE")->AsFloat=score;
         WorkQuery->ExecSQL();
      }
   } else {
      for (points=x1;int(points*100)<=int(x2*100);points=points+step) {
         WorkQuery->ParamByName("SET_PROFILE")->AsInteger=profile;
         WorkQuery->ParamByName("SET_POINTS")->AsFloat=points;
         WorkQuery->ParamByName("SET_SCORE")->AsFloat=CalcScore(A,B,points,1);
         WorkQuery->ExecSQL();
         //points=double(int(points*1000))/1000;
      }
   }
   WorkQuery->UnPrepare();
   Application->MessageBox("Процесът е завършен!","Информация",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
   MainForm->ProfileLookupChange(NULL);
   Close();
}
//---------------------------------------------------------------------------
int __fastcall TGeneratePointsForm::CheckPoints() {
   if (PointsFor2->Value>=PointsFor6->Value)              // P1 >= P2
      return 1;
   if (Step->Value>PointsFor6->Value-PointsFor2->Value)  // St > P2 - P1
      return 1;
   return 0;
}
void __fastcall TGeneratePointsForm::PointsFor2Change(TObject *Sender)
{
   try {
      if (Step->Value==0) return;
      if (PointsFor2->Value==0&&PointsFor6->Value==0) return;
      if (ByScore->Checked) {
         StatusBar1->SimpleText="Брой: "+String((int)(3/Step->Value)+1);
      } else {
         StatusBar1->SimpleText="Брой: "+String((int)((PointsFor6->Value-PointsFor2->Value)/Step->Value)+1);
      }
   } catch (...) {
      StatusBar1->SimpleText="";
   }
}
//---------------------------------------------------------------------------

