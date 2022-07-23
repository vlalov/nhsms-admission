//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CheckEGN.h"
#include "Library.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCheckEGNForm *CheckEGNForm;
//---------------------------------------------------------------------------
__fastcall TCheckEGNForm::TCheckEGNForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int getSex(char *EGN) {
 char str[12];
 // What's his/her sex?
   strcpy(str,EGN);
   if ((str[8]-'0')%2==0) {
    // Male
      return 1;
   } else {
      // Female
      return 0;
   }
}

void __fastcall TCheckEGNForm::FormActivate(TObject *Sender)
{
 char EGN[12];
 AnsiString str;
 int errors=0;
   if (Data->Database1->Connected!=true) return;
   if (PageControl1->ActivePageIndex==0) {
     if (ListBox->Items->Count!=0) return;
     ListBox->Items->Clear();
     PersonQuery->Active=true;
     PersonQuery->First();
     for (int i=0;i<PersonQuery->RecordCount;i++) {
        strcpy(EGN,PersonQuery->FieldByName("EGN")->AsString.c_str());
        if (CheckEGN(EGN)==false) {
           errors++;
           if (strlen(EGN)==10) {
              if (getSex(EGN)!=PersonQuery->FieldByName("Sex")->AsInteger) {
                 str.printf("Грешно ЕГН: %10s, №: %4d. Пола не е валиден (%s)",EGN,PersonQuery->FieldByName("ID")->AsInteger,(PersonQuery->FieldByName("Sex")->AsInteger==1?"Мъжки":"Женски"));
              } else {
                 str.printf("Грешно ЕГН: %10s, №: %4d.",EGN,PersonQuery->FieldByName("ID")->AsInteger);
              }
           } else {
              str.printf("Грешно ЕГН: %10s, №: %4d.",EGN,PersonQuery->FieldByName("ID")->AsInteger);
           }
           ListBox->Items->Add(str);
        } else {
           if (getSex(EGN)!=PersonQuery->FieldByName("Sex")->AsInteger) {
              errors++;
              str.printf("Пола(%s) Не е валиден! ЕГН: %s, №: %4d.",(PersonQuery->FieldByName("Sex")->AsInteger==1?"Мъжки":"Женски"),EGN,PersonQuery->FieldByName("ID")->AsInteger);
              ListBox->Items->Add(str);
           }
        }
        PersonQuery->Next();
     }
     PersonQuery->Active=false;
     return;
   }
 int id1,id2;
   if (PageControl1->ActivePageIndex==1) {
      if (ListNames->Items->Count!=0) return;
      ListNames->Items->Clear();
      EqualNamesQuery->Active=true;
      EqualNamesQuery->First();
      errors=0;
      for (int i=0;i<EqualNamesQuery->RecordCount;i++) {
         id1=EqualNamesQuery->FieldByName("ID1")->AsInteger;
         id2=EqualNamesQuery->FieldByName("ID2")->AsInteger;
         if (id1<id2) {
            str.printf("Идентични имена на номера %4d и %4d.",id1,id2);
            ListNames->Items->Add(str);
            errors++;
         }
         EqualNamesQuery->Next();
      }
      if (errors==0) ListNames->Items->Add("Няма идентични имена!");
   }
}
//---------------------------------------------------------------------------

void __fastcall TCheckEGNForm::BitBtn1Click(TObject *Sender)
{
   ListBox->Items->Clear();
   ListNames->Items->Clear();
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TCheckEGNForm::PageControl1Change(TObject *Sender)
{
   FormActivate(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TCheckEGNForm::SaveBtnClick(TObject *Sender)
{
   SaveDialog->Execute();
   if (!SaveDialog->FileName.IsEmpty()) {
      switch (PageControl1->ActivePageIndex) {
         case 0:
            ListBox->Items->SaveToFile(SaveDialog->FileName);
         break;
         case 1:
            ListNames->Items->SaveToFile(SaveDialog->FileName);
         break;

      }
   }
}
//---------------------------------------------------------------------------

