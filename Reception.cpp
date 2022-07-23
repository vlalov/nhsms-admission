//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("WishesHistoryRes.cpp", WishesHistoryResForm);
USEFORM("AllReceptionProfilesRes.cpp", AllReceptionProfilesResForm);
USEFORM("AllReceptionRes.cpp", AllReceptionResForm);
USEFORM("CurrentReceptionRes.cpp", CurrentReceptionResForm);
USEFORM("DataModule.cpp", Data); /* TDataModule: File Type */
USEFORM("ExamResultSearcher.cpp", ExamsResultSearcherForm);
USEFORM("ExamResultsRes.cpp", ExamResultsResForm);
USEFORM("ExamStatisticsRes.cpp", ExamStatisticsResForm);
USEFORM("ExamStatsGraph.cpp", ExamStatsGraphForm);
USEFORM("GeneratePoints.cpp", GeneratePointsForm);
USEFORM("History.cpp", HistoryForm);
USEFORM("Login.cpp", LoginForm);
USEFORM("Main.cpp", MainForm);
USEFORM("Options.cpp", OptionsForm);
USEFORM("PersonsHistoryRes.cpp", PersonsHistoryResForm);
USEFORM("ReceptionRes.cpp", ReceptionResForm);
USEFORM("RoomChooser.cpp", RoomChooserForm);
USEFORM("RoomProtocolRes.cpp", RoomProtocolResForm);
USEFORM("RoomsUsage.cpp", RoomsUsageForm);
USEFORM("RoomsUsageGraph.cpp", RoomsUsageGraphForm);
USEFORM("AllReception.cpp", AllReceptionForm);
USEFORM("RegisterRes.cpp", RegisterResForm);
USEFORM("RegisterSearcher.cpp", RegisterSearcherForm);
USEFORM("QuickRepPage.cpp", QuickRepEditorForm);
USEFORM("HelpShow.cpp", HelpShowForm);
USEFORM("OperatorTaxes.cpp", OperatorTaxesForm);
USEFORM("CheckEGN.cpp", CheckEGNForm);
USEFORM("ReceptionMap.cpp", ReceptionMapForm);
USEFORM("PreviewText.cpp", PreviewTextForm);
USEFORM("RoomUsageAuto.cpp", RoomUsageAutoForm);
//---------------------------------------------------------------------------
AnsiString Arguments;
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE p, HINSTANCE t, LPSTR ar, int)
{
   try
   {
       Application->Initialize();
       Arguments=StrPas(ar);
       Application->Title = "Ïðèåì íà ÍÏÌÃ";
       Application->HelpFile = "RECEPTION.HLP";
       Application->CreateForm(__classid(TMainForm), &MainForm);
       Application->CreateForm(__classid(TData), &Data);
       Application->CreateForm(__classid(TCurrentReceptionResForm), &CurrentReceptionResForm);
       Application->CreateForm(__classid(TExamResultsResForm), &ExamResultsResForm);
       Application->CreateForm(__classid(TExamStatisticsResForm), &ExamStatisticsResForm);
       Application->CreateForm(__classid(TLoginForm), &LoginForm);
       Application->CreateForm(__classid(TOptionsForm), &OptionsForm);
       Application->CreateForm(__classid(TReceptionResForm), &ReceptionResForm);
       Application->CreateForm(__classid(TQuickRepEditorForm), &QuickRepEditorForm);
       Application->CreateForm(__classid(THelpShowForm), &HelpShowForm);
       Application->CreateForm(__classid(THistoryForm), &HistoryForm);
       Application->CreateForm(__classid(TPersonsHistoryResForm), &PersonsHistoryResForm);
       Application->CreateForm(__classid(TWishesHistoryResForm), &WishesHistoryResForm);
       Application->CreateForm(__classid(TAllReceptionForm), &AllReceptionForm);
       Application->CreateForm(__classid(TAllReceptionProfilesResForm), &AllReceptionProfilesResForm);
       Application->CreateForm(__classid(TAllReceptionResForm), &AllReceptionResForm);
       Application->CreateForm(__classid(TOperatorTaxesForm), &OperatorTaxesForm);
       Application->CreateForm(__classid(TCheckEGNForm), &CheckEGNForm);
       Application->CreateForm(__classid(TExamsResultSearcherForm), &ExamsResultSearcherForm);
       Application->CreateForm(__classid(TExamStatsGraphForm), &ExamStatsGraphForm);
       Application->CreateForm(__classid(TGeneratePointsForm), &GeneratePointsForm);
       Application->CreateForm(__classid(TRoomChooserForm), &RoomChooserForm);
       Application->CreateForm(__classid(TRoomProtocolResForm), &RoomProtocolResForm);
       Application->CreateForm(__classid(TRoomsUsageForm), &RoomsUsageForm);
       Application->CreateForm(__classid(TRoomsUsageGraphForm), &RoomsUsageGraphForm);
       Application->CreateForm(__classid(TRegisterResForm), &RegisterResForm);
       Application->CreateForm(__classid(TRegisterSearcherForm), &RegisterSearcherForm);
       Application->CreateForm(__classid(TReceptionMapForm), &ReceptionMapForm);
       Application->CreateForm(__classid(TPreviewTextForm), &PreviewTextForm);
       Application->CreateForm(__classid(TRoomUsageAutoForm), &RoomUsageAutoForm);
       Application->Run();
   }
   catch (Exception &exception)
   {
       //Application->ShowException(&exception);
   }
   catch (...)
   {
       try
       {
          throw Exception("");
       }
       catch (Exception &exception)
       {
          //Application->ShowException(&exception);
       }
   }
   return 0;
}
//---------------------------------------------------------------------------
