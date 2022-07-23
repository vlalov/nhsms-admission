//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <stdio.h>
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsIniData"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
   Database->AliasName=AliasEdit->Text;
   LoginForm->ShowModal();
   if (LoginForm->Tag==-1) {
      return;
   }
   
   try {
      Database->Params->Clear();
      Database->Params->Add("USER NAME="+LoginForm->UserNameEdit->Text);
      Database->Params->Add("PASSWORD="+LoginForm->PasswordEdit->Text);
      
      Database->Connected=true;
   } catch (Exception *E) {
      Application->ShowException(E);
      return;
   }
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT * FROM "+TableEdit->Text);
   Query1->Active=true;
   Query1->GetFieldNames(ListBox->Items);
   for (int i=0;i<ListBox->Items->Count;i++) {
      ListBox->Checked[i]=true;
   }

   Query1->Active=false;
   Database->Connected=false;
   Button2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpeedButton1Click(TObject *Sender)
{
   SaveDialog->FileName=TableEdit->Text+".csv";
   SaveDialog->Execute();
   if (!SaveDialog->FileName.IsEmpty()) {
      PathEdit->Text=SaveDialog->FileName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
 FILE *out=fopen(PathEdit->Text.c_str(),"w");
 bool first=false;
   if (out==NULL) {
      ShowMessage("Error creating file!");
      return;
   }
   Database->Connected=true;
   Query1->Active=true;
   for (int t=0;t<Query1->FieldCount;t++) {
      if (ListBox->Checked[t]!=true) continue;
      if (first) fprintf(out,";");
      fprintf(out,"\"%s\"",ListBox->Items->Strings[t]);
      first=true;
   }
   fprintf(out,"\n");
   Query1->First();
   for (int i=0;i<Query1->RecordCount;i++) {
      first=false;
      for (int j=0;j<Query1->FieldCount;j++) {
         if (ListBox->Checked[j]!=true) continue;
         if (first) fprintf(out,";");
         first=true;
         switch (Query1->FieldByName(ListBox->Items->Strings[j])->DataType) {
            case ftBoolean:
               fprintf(out,"\"%d\"",int(Query1->FieldByName(ListBox->Items->Strings[j])->AsBoolean));
            break;
            case ftDateTime:
               fprintf(out,"\"%s\"",FormatDateTime("c",Query1->FieldByName(ListBox->Items->Strings[j])->AsDateTime));
            break;
            default:
               if (Query1->FieldByName(ListBox->Items->Strings[j])->IsNull)
                  fprintf(out,"");
               else
                  fprintf(out,"\"%s\"",Query1->FieldByName(ListBox->Items->Strings[j])->AsString);
         }
         //fflush(out);
      }
      fprintf(out,"\n");
      Query1->Next();
   }
   fclose(out);
   Query1->Active=false;
   Database->Connected=false;
   ShowMessage("Процеса е завършен успешно!");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TableEditChange(TObject *Sender)
{
   Button2->Enabled=false;   
}
//---------------------------------------------------------------------------
