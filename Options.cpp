//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Options.h"
#include "Main.h"
#include "DataModule.h"
#include "BlankLoad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TOptionsForm *OptionsForm;
//---------------------------------------------------------------------------
__fastcall TOptionsForm::TOptionsForm(TComponent* Owner)
   : TForm(Owner)
{
   OptionsForm->Font=MainForm->Font;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::BitBtn1Click(TObject *Sender)
{
   if (Data->Database1->AliasName!=DSNEdit->Text&&Data->Database1->Connected==true) {
      Application->MessageBox("Първо изключете връзката със сървъра!","Грешка",MB_OK|MB_ICONERROR|MB_APPLMODAL);
      return;
   } else
      if (Data->Database1->Connected!=true)
         Data->Database1->AliasName=DSNEdit->Text;
   
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::FormActivate(TObject *Sender)
{
   DSNEdit->Text=Data->Database1->AliasName;
   if (Data->Database1->Connected==true)
      DSNEdit->Enabled=false;
   else
      DSNEdit->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::SpeedButton1Click(TObject *Sender)
{
   CodeTable->FileName=CodeTableLabel->Text;
   if (CodeTable->Execute()) {
      CodeTableLabel->Text=CodeTable->FileName;
   }
}
//---------------------------------------------------------------------------


void __fastcall TOptionsForm::TestBtnClick(TObject *Sender)
{
 AnsiString text=
"\n\
Triabva da se vijda cialata bulgarska azbuka\n\
purvo golemite posle i malkite bukvi:\n\
\n\
АБВГДЕЖЗИЙКЛМНО\n\
ПРСТУФХЦЧШЩЪЬЮЯ\n\
абвгдежзийклмно\n\
прстуфхцчшщъьюя\n\n\n\
";
   if (Application->MessageBox("Тази функция ще изпечати българската азбука\nна принтера.","Потвърдете",MB_APPLMODAL|MB_ICONQUESTION|MB_YESNO)!=ID_YES)
      return;
   if (Application->MessageBox("Моля, пригответе принтера за печат!","Прием на НПМГ - печат",MB_APPLMODAL|MB_ICONQUESTION|MB_OKCANCEL)!=ID_OK)
      return;
 BlankLoader *test=new BlankLoader(text,false);
   test->decode(CodeTableLabel->Text);
   test->Print(PrintDevice->Text);
   delete test;
}
//---------------------------------------------------------------------------

