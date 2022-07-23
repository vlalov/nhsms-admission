//---------------------------------------------------------------------------

#include <vcl.h>
#include "PrintBlanks.h"
#include "DataModule.h"
#include "Main.h"
#include "ReceptionRes.h"
#include "QuickRepPage.h"
#include "BlankLoad.h"
#include "PreviewText.h"
#include "Options.h"
#include "RoomChooser.h"
#include "RoomProtocolRes.h"
#include "CurrentReceptionRes.h"
#include "OperatorTaxes.h"
#include "ExamResultsRes.h"
#pragma hdrstop

//---------------------------------------------------------------------------
extern int DEBUG;
#pragma package(smart_init)
AnsiString PrintPerson(int returntype=0) {
 AnsiString txt;
 BlankLoader *persons;
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return 0;
   Data->TextsTable->Locate("ID",4,p);
   if (Data->TextsTable->FieldByName("ID")->AsInteger!=4||Data->TextsTable->FieldByName("Value")->AsString.IsEmpty()) {
      if (FileExists("Person Blank.blk"))
         persons=new BlankLoader("Person Blank.blk");
      else {
         Application->MessageBox("Не е намерен текст № 4!\nФайлът \"Person Blank.blk\" не е намерен!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return 0;
      }
   } else {
      persons=new BlankLoader(Data->TextsTable->FieldByName("Value")->AsString,0);
   }
 // some tasks for preparation
   MainForm->CalcAllTaxQuery->Active=false;
   if (Data->PersonsQuery->State==dsEdit||Data->PersonsQuery->State==dsInsert)
     Data->PersonsQuery->Post();
   if (MainForm->WishesQuery->State==dsEdit||MainForm->WishesQuery->State==dsInsert)
     MainForm->WishesQuery->Post();
   MainForm->TextTaxQuery->Active=true;
   MainForm->PlaceQuery->Active=true;
 // end of preparation... now initialize the variables
   persons->DoRepetition(MainForm->WishesQuery->RecordCount,"#/","\\#",true);

   if (MainForm->NCD==false) {
      persons->replace("#1",FormatDateTime("ddddd",Now()));
   } else {
      persons->replace("#1",FormatDateTime("ddddd",Data->PersonsQuery->FieldByName("EntOn")->AsDateTime));
   }
   persons->replace("#2",Data->PersonsQuery->FieldByName("Room_Code")->AsString+"-"+
      Data->PersonsQuery->FieldByName("ID")->AsString);

   persons->replace("#3",Data->PersonsQuery->FieldByName("Name")->AsString);
   persons->replace("#4",Data->PersonsQuery->FieldByName("EGN")->AsString);
   persons->replace("#5",(Data->PersonsQuery->FieldByName("Sex")->AsInteger==1)?"Мъжки":"Женски");
   persons->replace("#6",Data->PersonsQuery->FieldByName("Address")->AsString);
   persons->replace("#7",Data->PersonsQuery->FieldByName("Telephone")->AsString);

   persons->replace("#N",String(MainForm->TextTaxQuery->FieldByName("cnt")->AsInteger));
   persons->replace("#T",String(MainForm->TextTaxQuery->FieldByName("theTAX")->AsFloat));
   persons->replace("#X",String(MainForm->TextTaxQuery->FieldByName("AllTAX")->AsFloat));

   persons->replace("#operator#",Data->PersonsQuery->FieldByName("EntBy")->AsString);
   persons->replace("#Z",MainForm->PlaceQuery->FieldByName("Text")->AsString);


   MainForm->WishesQuery->First();
   if (MainForm->WishesQuery->RecordCount==0) {
      Application->MessageBox("Няма записи!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return "";
   }
   for (int i=0;i<MainForm->WishesQuery->RecordCount;i++) {
      txt.printf("%2d",MainForm->WishesQuery->FieldByName("Priority")->AsInteger);
      persons->overwriteFirst("#8",txt);

      persons->overwriteFirst("#9",MainForm->WishesQuery->FieldByName("Profile")->AsString);

      txt=FormatFloat("#0.00",MainForm->WishesQuery->FieldByName("Score")->AsFloat);
      persons->overwriteFirst("#0",txt);

      if (MainForm->WishesQuery->FieldByName("FromOlymp")->AsBoolean) {
         txt=FormatFloat("#0.00",MainForm->WishesQuery->FieldByName("OlympScore")->AsFloat);
         persons->overwriteFirst("#A",txt);
         persons->overwriteFirst("#B",(MainForm->WishesQuery->FieldByName("GoToExam")->AsBoolean)==true?"Да":"Не");
      } else {
         persons->overwriteFirst("#A","    ");
         persons->overwriteFirst("#B","  ");
      }
      MainForm->WishesQuery->Next();
   }
   MainForm->TextTaxQuery->Active=false;
   MainForm->PlaceQuery->Active=false;
/*
   QuickRepEditorForm->SetPageValues(ReceptionResForm->QuickRep1);

//   ReceptionResForm->PrintReport();
//   WishesQuery->Tag=0;
//   CalcAllTaxQuery->Active=false;
*/
   persons->AppendInitials();
   if (returntype==0) {
      persons->decode(OptionsForm->CodeTableLabel->Text);
      if (DEBUG)
         persons->SaveToFile("preview.persons");
      persons->Print(OptionsForm->PrintDevice->Text);
      delete persons;
      return "";
   }
   txt=persons->getFormatted();
   delete persons;
   return txt;
}
//========================================================================
AnsiString PrintRoomReport(int state) {
 AnsiString txt;
 BlankLoader *room;
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return "";
   Data->TextsTable->Locate("ID",5,p);
   if (Data->TextsTable->FieldByName("ID")->AsInteger!=5||Data->TextsTable->FieldByName("Value")->AsString.IsEmpty()) {
      if (FileExists("Room Blank.blk"))
         room=new BlankLoader("Room Blank.blk");
      else {
         Application->MessageBox("Не е намерен текст № 5!\nФайлът \"Room Blank.blk\" не е намерен!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return 0;
      }
   } else {
      room=new BlankLoader(Data->TextsTable->FieldByName("Value")->AsString,0);
   }
   RoomProtocolResForm->PersonsQuery->Active=true;
   room->DoRepetition(RoomProtocolResForm->PersonsQuery->RecordCount,"#/","\\#");

   room->replace("#1",FormatDateTime("ddddd",Now()));
   room->replace("#2",RoomChooserForm->PlaceQuery->FieldByName("Code")->AsString);
   room->replace("#3",RoomChooserForm->PlaceQuery->FieldByName("Name")->AsString);
   room->replace("#7",RoomProtocolResForm->PersonsQuery->RecordCount);


   RoomProtocolResForm->PersonsQuery->First();
   if (RoomProtocolResForm->PersonsQuery->RecordCount==0) {
      Application->MessageBox("Няма записи!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return "";
   }
   for (int i=0;i<RoomProtocolResForm->PersonsQuery->RecordCount;i++) {
      txt.printf("%4d",RoomProtocolResForm->PersonsQuery->FieldByName("ID")->AsInteger);
      room->overwriteFirst("#4",txt);

      room->overwriteFirst("#5",RoomProtocolResForm->PersonsQuery->FieldByName("Name")->AsString);
      room->replaceFirst("#6",RoomProtocolResForm->PersonsQuery->FieldByName("EGN")->AsString);

      RoomProtocolResForm->PersonsQuery->Next();
   }
   RoomProtocolResForm->PersonsQuery->Active=false;

   room->AppendInitials(1);
   if (state==0) {
      room->decode(OptionsForm->CodeTableLabel->Text);
      if (DEBUG)
         room->SaveToFile("preview.Room");
      room->Print(OptionsForm->PrintDevice->Text);
      delete room;
      return "";
   }
   txt=room->getFormatted();
   delete room;
   return txt;
}
AnsiString PrintExamReport(int state) {
 AnsiString txt;
 BlankLoader *exam;
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return "";
   Data->TextsTable->Locate("ID",7,p);
   if (Data->TextsTable->FieldByName("ID")->AsInteger!=7||Data->TextsTable->FieldByName("Value")->AsString.IsEmpty()) {
      if (FileExists("Exam Blank.blk"))
         exam=new BlankLoader("Exam Blank.blk");
      else {
         Application->MessageBox("Не е намерен текст № 7!\nФайлът \"Exam Blank.blk\" не е намерен!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return 0;
      }
   } else {
      exam=new BlankLoader(Data->TextsTable->FieldByName("Value")->AsString,0);
   }
   if (ExamResultsResForm->RoomProtocolQuery->Active==false)
      ExamResultsResForm->RoomProtocolQuery->Active=true;

   exam->DoRepetition(ExamResultsResForm->RoomProtocolQuery->RecordCount,"#/","\\#");

   exam->replace("#1",FormatDateTime("ddddd",Now()));
   exam->replace("#2",ExamResultsResForm->ExamNameLabel->Caption);
   exam->replace("#6",ExamResultsResForm->RoomProtocolQuery->RecordCount);

   ExamResultsResForm->RoomProtocolQuery->First();
   if (ExamResultsResForm->RoomProtocolQuery->RecordCount==0) {
      Application->MessageBox("Няма записи!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
      return "";
   }
   for (int i=0;i<ExamResultsResForm->RoomProtocolQuery->RecordCount;i++) {
      txt.printf("%4d",ExamResultsResForm->RoomProtocolQuery->FieldByName("ID")->AsInteger);
      exam->overwriteFirst("#3",txt);

      exam->overwriteFirst("#4",ExamResultsResForm->RoomProtocolQuery->FieldByName("Name")->AsString);
      exam->replaceFirst("#5",ExamResultsResForm->RoomProtocolQuery->FieldByName("EGN")->AsString);
      // dealing with PreferedSchool flag
      if (ExamResultsResForm->inclPrefer==true) {
         exam->replaceFirst("#p",ExamResultsResForm->RoomProtocolQueryPreferedSchool->AsString+" ");
      } else {
         exam->replaceFirst("#p","  ");
      }
      
      ExamResultsResForm->RoomProtocolQuery->Next();
   }
   ExamResultsResForm->RoomProtocolQuery->Active=false;

   exam->AppendInitials(1);
   if (state==0) {
      exam->decode(OptionsForm->CodeTableLabel->Text);
      if (DEBUG)
         exam->SaveToFile("preview.Exam");
      exam->Print(OptionsForm->PrintDevice->Text);
      delete exam;
      return "";
   }
   txt=exam->getFormatted();
   delete exam;
   return txt;
}
AnsiString PrintCurrentTaxes(int state) {
 AnsiString txt;
 BlankLoader *taxes;
 TLocateOptions p;
 double theTax=0,tax;
   if (Data->Database1->Connected!=true) return "";
   Data->TextsTable->Locate("ID",6,p);
   if (Data->TextsTable->FieldByName("ID")->AsInteger!=6||Data->TextsTable->FieldByName("Value")->AsString.IsEmpty()) {
      if (FileExists("Taxes Blank.blk"))
         taxes=new BlankLoader("Taxes Blank.blk");
      else {
         Application->MessageBox("Не е намерен текст № 6!\nФайлът \"Taxes Blank.blk\" не е намерен!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return 0;
      }
   } else {
      taxes=new BlankLoader(Data->TextsTable->FieldByName("Value")->AsString,0);
   }
   if (state==0||state==1) { // current operator and date
      if (CurrentReceptionResForm->DataQuery->Active==false)
         CurrentReceptionResForm->DataQuery->Active=true;
      if (CurrentReceptionResForm->CalcAllTaxQuery->Active==false)
         CurrentReceptionResForm->CalcAllTaxQuery->Active=true;
      if (CurrentReceptionResForm->DeletedWishesQuery->Active==false)
         CurrentReceptionResForm->DeletedWishesQuery->Active=true;
      taxes->DoRepetition(CurrentReceptionResForm->DataQuery->RecordCount,"#/","\\#");

      taxes->replace("#1",FormatDateTime("ddddd",Now()));
      taxes->replace("#2",CurrentReceptionResForm->DataQuery->FieldByName("operator")->AsString);

      CurrentReceptionResForm->DataQuery->First();
      if (CurrentReceptionResForm->DataQuery->RecordCount==0) {
         Application->MessageBox("Няма записи!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return "";
      }
      for (int i=0;i<CurrentReceptionResForm->DataQuery->RecordCount;i++) {
         txt.printf("%4d",CurrentReceptionResForm->DataQuery->FieldByName("ID")->AsInteger);
         taxes->overwriteFirst("#3",txt);
         taxes->overwriteFirst("#4",CurrentReceptionResForm->DataQuery->FieldByName("Name")->AsString);
         taxes->overwriteFirst("#5",CurrentReceptionResForm->DataQuery->FieldByName("EGN")->AsString);
         //CalcAllTaxQuery.AllTax - DeletedWishesQuery.CNT
         tax=CurrentReceptionResForm->CalcAllTaxQuery->FieldByName("AllTax")->AsFloat-
                                         CurrentReceptionResForm->DeletedWishesQuery->FieldByName("CNT")->AsFloat;
         taxes->replaceFirst("#6",String(tax));
         theTax+=tax;

         CurrentReceptionResForm->DataQuery->Next();
      }
      taxes->replace("#7",CurrentReceptionResForm->DataQuery->RecordCount);
      taxes->replace("#8",theTax);
   } else { // custom operator and date: state==11 or state==10
      if (CurrentReceptionResForm->DataQuery2->Active==false)
         CurrentReceptionResForm->DataQuery2->Active=true;
      if (CurrentReceptionResForm->CalcAllTaxQuery2->Active==false)
         CurrentReceptionResForm->CalcAllTaxQuery2->Active=true;
      if (CurrentReceptionResForm->DeletedWishesQuery2->Active==false)
         CurrentReceptionResForm->DeletedWishesQuery2->Active=true;

      taxes->DoRepetition(CurrentReceptionResForm->DataQuery2->RecordCount,"#/","\\#");

      taxes->replace("#1",FormatDateTime("ddddd",Now()));
      taxes->replace("#2",CurrentReceptionResForm->DataQuery2->FieldByName("operator")->AsString+" ("+
            FormatDateTime("ddddd",OperatorTaxesForm->StartDateTime->DateTime)+")");

      CurrentReceptionResForm->DataQuery2->First();
      if (CurrentReceptionResForm->DataQuery2->RecordCount==0) {
         Application->MessageBox("Няма записи!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
         return "";
      }
      for (int i=0;i<CurrentReceptionResForm->DataQuery2->RecordCount;i++) {
         txt.printf("%4d",CurrentReceptionResForm->DataQuery2->FieldByName("ID")->AsInteger);
         taxes->overwriteFirst("#3",txt);

         taxes->overwriteFirst("#4",CurrentReceptionResForm->DataQuery2->FieldByName("Name")->AsString);
         taxes->overwriteFirst("#5",CurrentReceptionResForm->DataQuery2->FieldByName("EGN")->AsString);
         //CalcAllTaxQuery.AllTax - DeletedWishesQuery.CNT
         tax=CurrentReceptionResForm->CalcAllTaxQuery2->FieldByName("AllTax")->AsFloat-
                                         CurrentReceptionResForm->DeletedWishesQuery2->FieldByName("CNT")->AsFloat;
         taxes->replaceFirst("#6",String(tax));
         theTax+=tax;

         CurrentReceptionResForm->DataQuery2->Next();
      }
      taxes->replace("#7",CurrentReceptionResForm->DataQuery2->RecordCount);
      taxes->replace("#8",theTax);
   }
   taxes->AppendInitials();
   if (state==0||state==10) {
      taxes->decode(OptionsForm->CodeTableLabel->Text);
      if (DEBUG)
         taxes->SaveToFile("preview.CurrentTaxes");
      taxes->Print(OptionsForm->PrintDevice->Text);
      delete taxes;
      return "";
   }
   txt=taxes->getFormatted();
   delete taxes;
   return txt;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int DoTextPrint(int type) {
   if (Data->Database1->Connected!=true) return 0;
   if (MainForm->PageControl->ActivePage==MainForm->ReceptionTab&&MainForm->Active) {
      PrintPerson(0);
      return 1;
   }
   if (RoomChooserForm->Active) {
      PrintRoomReport(0);
      return 1;
   }
   if (type==1) {
      PrintCurrentTaxes(0);
      return 1;
   }
   if (type==5) {
      PrintExamReport(0);
      return 1;
   }
   if (type==11) {
      PrintCurrentTaxes(10);
      return 1;
   }
   return 0;
}
int DoTextPreview(int type) {
   if (Data->Database1->Connected!=true) return 0;
   if (type==1) { // current operator taxes
      PreviewTextForm->Text->Lines->Text=PrintCurrentTaxes(1);
      PreviewTextForm->Tag=1;
      PreviewTextForm->Show();
      return 1;
   }
   if (type==2) { // custom taxes and date
      PreviewTextForm->Text->Lines->Text=PrintCurrentTaxes(11);
      PreviewTextForm->Tag=11;
      PreviewTextForm->Show();
      return 1;
   }
   if (type==5) { // exam report
      PreviewTextForm->Text->Lines->Text=PrintExamReport(1);
      PreviewTextForm->Tag=5;
      PreviewTextForm->Show();
      return 1;
   }
   if (RoomChooserForm->Active) {
      PreviewTextForm->Text->Lines->Text=PrintRoomReport(1);
      PreviewTextForm->Tag=2;
      PreviewTextForm->Show();
      return 1;
   }
   if (MainForm->PageControl->ActivePage==MainForm->ReceptionTab&&MainForm->Active) {
      PreviewTextForm->Text->Lines->Text=PrintPerson(1);
      PreviewTextForm->Tag=3;
      PreviewTextForm->Show();
      return 1;
   }
   return 0;
}
