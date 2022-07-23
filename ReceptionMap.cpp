//---------------------------------------------------------------------------

#include <vcl.h>
#include "DataModule.h"
#include "Library.h"
#include "Main.h"
#pragma hdrstop

#include "ReceptionMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TReceptionMapForm *ReceptionMapForm;
//---------------------------------------------------------------------------
__fastcall TReceptionMapForm::TReceptionMapForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TReceptionMapForm::IDEditChange(TObject *Sender)
{
 TLocateOptions p;
   if (IDEdit->Text.IsEmpty()) return;
   try {
      PersonQuery->Locate("ID",IDEdit->Value,p);
   } catch (...) {
   }
}
//---------------------------------------------------------------------------
void __fastcall TReceptionMapForm::PersonQueryCalcFields(TDataSet *DataSet)
{
   switch (DataSet->FieldByName("Sex")->AsInteger) {
      case 1:
         DataSet->FieldByName("Se")->AsString="Мъжки";
      break;
      case 0:
         DataSet->FieldByName("Se")->AsString="Женски";
      break;
   }
    char str[12];
 // What's his/her sex?
   strcpy(str,DataSet->FieldByName("EGN")->AsString.c_str());
   if ((str[8]-'0')%2==0) {
    // Male
       if (DataSet->FieldByName("Sex")->AsInteger!=1)
          DataSet->FieldByName("Se")->AsString=DataSet->FieldByName("Se")->AsString+" (!)";
   } else {
      // Female
      if (DataSet->FieldByName("Sex")->AsInteger!=0)
         DataSet->FieldByName("Se")->AsString=DataSet->FieldByName("Se")->AsString+" (!)";
   }

   if (CheckEGN(DataSet->FieldByName("EGN")->AsString.c_str())==true) {
      DataSet->FieldByName("ValidEGN")->AsString="";
   } else {
      DataSet->FieldByName("ValidEGN")->AsString="Невалидно";
   }
}
//---------------------------------------------------------------------------

void __fastcall TReceptionMapForm::ExamsQueryCalcFields(TDataSet *DataSet)
{
 TLocateOptions p;
   if (DataSet->FieldByName("Exam")->AsInteger==0) {
      DataSet->FieldByName("Exa")->AsString="Общ изпит";
   } else {
      Data->ProfilesTable->Locate("ID",DataSet->FieldByName("Exam")->AsInteger,p);
      if (Data->ProfilesTable->FieldByName("ID")->AsInteger==DataSet->FieldByName("Exam")->AsInteger) {
         DataSet->FieldByName("Exa")->AsString=Data->ProfilesTable->FieldByName("Name")->AsString;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TReceptionMapForm::ClassificateQueryCalcFields(
      TDataSet *DataSet)
{
 TLocateOptions p;
   if (Data->Database1->Connected!=true) return;
   if (DataSet->Active!=true)
      DataSet->Active=true;
   HelpQuery->Active=false;
   HelpQuery->ParamByName("Amount")->AsFloat=DataSet->FieldByName("Amount")->AsFloat;
   HelpQuery->ParamByName("Profile_ID")->AsInteger=DataSet->FieldByName("Profile_ID")->AsInteger;
   HelpQuery->ParamByName("Person_ID")->AsInteger=DataSet->FieldByName("Person_ID")->AsInteger;
   Data->ProfilesTable->Locate("ID",DataSet->FieldByName("Profile_ID")->AsInteger,p);
   if (Data->ProfilesTable->FieldByName("DiffMW")->AsBoolean==true) {
      HelpQuery->ParamByName("SET_SEX1")->AsInteger=PersonQuery->FieldByName("Sex")->AsInteger;
      HelpQuery->ParamByName("SET_SEX2")->AsInteger=PersonQuery->FieldByName("Sex")->AsInteger;
   } else {
      HelpQuery->ParamByName("SET_SEX1")->AsInteger=1;
      HelpQuery->ParamByName("SET_SEX2")->AsInteger=0;
   }
   HelpQuery->Active=true;

   DataSet->FieldByName("Status")->AsString=String(HelpQuery->RecordCount+1);
 //---
   if (DataSet->FieldByName("Classificated")->AsBoolean==true) {
      switch (DataSet->FieldByName("IsIn")->AsBoolean) {
         case true:
            DataSet->FieldByName("IsInExt")->AsString="Да";
         break;
         case false:
            DataSet->FieldByName("IsInExt")->AsString=" ";
         break;
      }
   } else {
      switch (DataSet->FieldByName("IsIn")->AsBoolean) {
         case true:
            DataSet->FieldByName("IsInExt")->AsString="-!-";
         break;
         case false:
            DataSet->FieldByName("IsInExt")->AsString="---";
         break;
      }
   }

}
//---------------------------------------------------------------------------
void __fastcall TReceptionMapForm::FormActivate(TObject *Sender)
{
 AnsiString text;
   ClassificateQuery->Active=false;
   ExamsQuery->Active=false;
   WishesQuery->Active=false;
   PersonQuery->Active=false;

   PersonQuery->Active=true;
   WishesQuery->Active=true;
   ExamsQuery->Active=true;
   ClassificateQuery->Active=true;

   if (MainForm->PageControl->ActivePage==MainForm->ReceptionTab&&IDEdit->Value==1) {
      IDEdit->Value=Data->PersonsQuery->FieldByName("ID")->AsInteger;
   }
   IDEditChange(NULL);
   this->ActiveControl=IDEdit;
 //-------------------
   ClassificationNumberQuery->Active=true;
   switch (ClassificationNumberQuery->FieldByName("RegisterNumber")->AsInteger) {
      case 1: text="Първо"; break;
      case 2: text="Второ"; break;
      case 3: text="Трето"; break;
      case 4: text="Четвърто"; break;
      case 5: text="Пето"; break;
      default: text=String(ClassificationNumberQuery->FieldByName("RegisterNumber")->AsInteger)+"-то";
   }
   GroupBox4->Caption=text+" класиране";
   ClassificationNumberQuery->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TReceptionMapForm::FormDestroy(TObject *Sender)
{
   ClassificateQuery->Active=false;
   ExamsQuery->Active=false;
   WishesQuery->Active=false;
   PersonQuery->Active=false;
}
//---------------------------------------------------------------------------

