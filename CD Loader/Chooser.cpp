//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Chooser.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MSSQL7DE_PATH "SQLServer\\x86\\setup\\SETUPSQL.EXE k=DK"
#define MSSQL7SE_PATH "SQLServer\\x86\\setup\\SETUPSQL.EXE"

#define RECEPTION_PATH "Reception\\Reception_BG.exe"
#define WINRAR_PATH "Accessories\\WinRAR 3.20.exe"
#define FLEXTYPE_PATH "Accessories\\FlexType2k.exe"
#define BDE_PATH "Reception\\BDE.EXE"

TChooserForm *ChooserForm;
//---------------------------------------------------------------------------
__fastcall TChooserForm::TChooserForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChooserForm::TreeView1Change(TObject *Sender,
      TTreeNode *Node)
{
   switch (Node->AbsoluteIndex) {
      case 0:
         Info->Caption="Инсталира Microsoft SQL Server 7.0. Ако този компютър ще се използва като сървър този продукт е задължителен! В противен случай не е необходим.";
      break;
      case 1:
         Info->Caption="Borland Database Engine.Ако на компютъра го няма инсталиран\nинсталацията му е задължителна.\nАко имате инсталиран Borland C++Builder или Borland Delphi този продукт не е необходим.";
      break;
      case 2:
         Info->Caption="Основната част на програмата.\nТози продукт задължително трябва да се инсталира!";
      break;
      case 4:
         Info->Caption="Инсталира WinRAR 3.20. За работата на програмата не е необходим, но може да се окаже полезен при някои обстоятелства.\n\n Лиценз: Shareware (40 дневен пробен период)";
      break;
      case 5:
         Info->Caption="Инсталира Flex Type 2k. В случай, че системата ви не е кирилизирана можете да ползвате този пакет!\n\nV sluchai, che sistemata vi ne e kirilizirana mojete da polzvate tozi paket!\n\n Лиценз: Shareware";
      break;
      default:
         Info->Caption="Моля, изберете продукт!";
   }
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::BitBtn1Click(TObject *Sender)
{
 AnsiString run;
 TTreeNode *Node=TreeView1->Selected;
   if (Node==NULL) {
      Application->MessageBox("Изберете продукт, който да бъде инсталиран!","Информация",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
      return;
   }
   if (Node->Text=="Microsoft SQL Server 7.0") {
      switch (Application->MessageBox("Искате ли да бъде инсталирана Standard версията?\n(само за Windows NT 4.0 Server, Windows 2000 Server)","Desktop или Standard",MB_YESNOCANCEL|MB_DEFBUTTON2|MB_APPLMODAL|MB_ICONQUESTION)) {
         case ID_YES:
            run=MSSQL7SE_PATH;
         break;
         case ID_NO:
            run=MSSQL7DE_PATH;
         break;
         default:
            return;
      }
   }
   if (Node->Text=="Прием на НПМГ") {
      run=RECEPTION_PATH;
   }
   if (Node->Text=="WinRAR 3.20") {
      run=WINRAR_PATH;
   }
   if (Node->Text=="FlexType 2K") {
      run=FLEXTYPE_PATH;
   }
   if (Node->Text=="BDE") {
      run=BDE_PATH;
   }

   if (WinExec(run.c_str(),0)<31) {
      Application->MessageBox("Грешка при стартирането на инсталацията!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TChooserForm::FormShow(TObject *Sender)
{
   Application->MessageBox("Това е инсталационния диск на Приема на НПМГ.\nАвтор: Владимир Лалов (v_lalov@yahoo.com)\nМоля, изберете продуктите, които бихте искали да инсталирате.\n\n\nAko ne mojete da prochetete teksta otgore sistemata Vi ne e kirilizirana!\nMolq, instaliraite kirilizirani shriftove predi da produljite.","Добре дошли в инсталацията на Прием на НПМГ!",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::BitBtn2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::HelpBtnClick(TObject *Sender)
{
   if ((int)ShellExecute(NULL,"open","how to install.txt","","",SW_MAXIMIZE)<32) {
      Application->MessageBox("Грешка при визуализирането на помощния файл! Моля отворете файла \"How to install.txt\" ръчно!","Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------
void __fastcall TChooserForm::runMe(AnsiString command) {
   if ((int)ShellExecute(NULL,"open",command.c_str(),"","",SW_MAXIMIZE)<32) {
      Application->MessageBox(("Грешка при визуализирането на видео файла! Моля отворете "+command+" ръчно!").c_str(),"Грешка",MB_OK|MB_APPLMODAL|MB_ICONERROR);
   }
}
void __fastcall TChooserForm::VideoBtnClick(TObject *Sender)
{
   PopupMenu1->Popup(ChooserForm->Left+VideoBtn->Left,ChooserForm->Top+VideoBtn->Top);
}
//---------------------------------------------------------------------------
void __fastcall TChooserForm::SQLServer1Click(TObject *Sender)
{
   // start "How to install - 1. Install SQL Server.avi"
   runMe("How to install - 1. Install SQL Server.avi");
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::BDE1Click(TObject *Sender)
{
   // start "How to install - 2. Install BDE.avi"
   runMe("How to install - 2. Install BDE.avi");
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::SQL1Click(TObject *Sender)
{
   // start "How to install - 3. Load SQL script.avi"
   runMe("How to install - 3. Load SQL script.avi");
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::N3Click(TObject *Sender)
{
   // start "How to install - 3. Restore DB from backup.avi"
   runMe("How to install - 3. Restore DB from backup.avi");
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::SQLServerQueryAnalyzer1Click(TObject *Sender)
{
   // start "How to install - 3. Install with Query Analyser.avi"
   runMe("How to install - 3. Install with Query Analyser.avi");
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::N1Click(TObject *Sender)
{
   // start "How to install - 4. Install Reception of NHSMS.avi"
   runMe("How to install - 4. Install Reception of NHSMS.avi");
}
//---------------------------------------------------------------------------

