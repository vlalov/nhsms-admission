//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include<stdio.h>
#include "Login.h"

#define TOKEN "GO"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsIniData"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TInitMainForm *InitMainForm;
//---------------------------------------------------------------------------
__fastcall TInitMainForm::TInitMainForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInitMainForm::SpeedButton1Click(TObject *Sender)
{
   if (!ScriptFile->Text.IsEmpty()) OpenDialog1->FileName=ScriptFile->Text;
   if (OpenDialog1->Execute()) {
      ScriptFile->Text=OpenDialog1->FileName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TInitMainForm::CreateBtnClick(TObject *Sender)
{
 FILE *script;
   if (DSNEdit->Text.IsEmpty()||ScriptFile->Text.IsEmpty()||!FileExists(ScriptFile->Text)) {
      Application->MessageBox("Моля, въведете валиден път до SQL скрипт и съществуващ DSN!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      return;
   }
   // starting the process
   // first ask for username and password
   LoginForm->ShowModal();
   if (LoginForm->Tag==-1) {
      return;
   }
   try {
      long count=0;
      char buff[50000];
      AnsiString buffer,tmp;
      script=fopen(ScriptFile->Text.c_str(),"r");

      while (!feof(script)) {
         buff[count]=fgetc(script);
         count++;
      }

      Database1->Params->Clear();
      Database1->Params->Add("USER NAME="+LoginForm->UserNameEdit->Text);
      Database1->Params->Add("PASSWORD="+LoginForm->PasswordEdit->Text);

      Session1->Active=true;
      Database1->AliasName=DSNEdit->Text;
      Database1->Connected=true;

      int index;
      buffer=StrPas(buff);
      do {
         index=buffer.AnsiPos(TOKEN);
         if (index>0) {
            tmp=buffer.SubString(0,index-1);
         } else break; // token not found
         Query1->SQL->Clear();
         Query1->SQL->Add(tmp);
         Query1->ExecSQL();
         buffer=buffer.SubString(index+2,buffer.Length());
      } while (index!=0);

      Application->MessageBox("Процесът е завършен успешно!","Прием на НПМГ",MB_ICONINFORMATION|MB_APPLMODAL|MB_OK);
   } catch (Exception &e) {
      Application->MessageBox("Възникна грешка при изпълнението на процеса!\nМоля, проверете името и паролата. Възможна е и грешка в скрипта!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
      //Application->MessageBox(e.Message.c_str(),"Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
   }
   // all went ok, then clear the memory and staff
   fclose(script);
   Database1->Connected=false;
   Session1->Active=false;

}
//---------------------------------------------------------------------------
void __fastcall TInitMainForm::BitBtn2Click(TObject *Sender)
{
 char dir[1000];
   GetSystemDirectory(dir,1000);
   strcat(dir,"\\ODBCAD32.exe");
   if (WinExec(dir,0)<31) {
      Application->MessageBox("Грешка при стартирането на ODBC Администратора!","Грешка",MB_ICONERROR|MB_APPLMODAL|MB_OK);
   }
}
//---------------------------------------------------------------------------

