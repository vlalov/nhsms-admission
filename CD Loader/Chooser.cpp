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
         Info->Caption="��������� Microsoft SQL Server 7.0. ��� ���� �������� �� �� �������� ���� ������ ���� ������� � ������������! � �������� ������ �� � ���������.";
      break;
      case 1:
         Info->Caption="Borland Database Engine.��� �� ��������� �� ���� ����������\n������������ �� � ������������.\n��� ����� ���������� Borland C++Builder ��� Borland Delphi ���� ������� �� � ���������.";
      break;
      case 2:
         Info->Caption="��������� ���� �� ����������.\n���� ������� ������������ ������ �� �� ���������!";
      break;
      case 4:
         Info->Caption="��������� WinRAR 3.20. �� �������� �� ���������� �� � ���������, �� ���� �� �� ����� ������� ��� ����� �������������.\n\n ������: Shareware (40 ������ ������ ������)";
      break;
      case 5:
         Info->Caption="��������� Flex Type 2k. � ������, �� ��������� �� �� � ������������ ������ �� �������� ���� �����!\n\nV sluchai, che sistemata vi ne e kirilizirana mojete da polzvate tozi paket!\n\n ������: Shareware";
      break;
      default:
         Info->Caption="����, �������� �������!";
   }
}
//---------------------------------------------------------------------------

void __fastcall TChooserForm::BitBtn1Click(TObject *Sender)
{
 AnsiString run;
 TTreeNode *Node=TreeView1->Selected;
   if (Node==NULL) {
      Application->MessageBox("�������� �������, ����� �� ���� ����������!","����������",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
      return;
   }
   if (Node->Text=="Microsoft SQL Server 7.0") {
      switch (Application->MessageBox("������ �� �� ���� ����������� Standard ��������?\n(���� �� Windows NT 4.0 Server, Windows 2000 Server)","Desktop ��� Standard",MB_YESNOCANCEL|MB_DEFBUTTON2|MB_APPLMODAL|MB_ICONQUESTION)) {
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
   if (Node->Text=="����� �� ����") {
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
      Application->MessageBox("������ ��� ������������ �� ������������!","������",MB_OK|MB_APPLMODAL|MB_ICONERROR);
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
   Application->MessageBox("���� � �������������� ���� �� ������ �� ����.\n�����: �������� ����� (v_lalov@yahoo.com)\n����, �������� ����������, ����� ����� ������ �� �����������.\n\n\nAko ne mojete da prochetete teksta otgore sistemata Vi ne e kirilizirana!\nMolq, instaliraite kirilizirani shriftove predi da produljite.","����� ����� � ������������ �� ����� �� ����!",MB_OK|MB_APPLMODAL|MB_ICONINFORMATION);
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
      Application->MessageBox("������ ��� ��������������� �� �������� ����! ���� �������� ����� \"How to install.txt\" �����!","������",MB_OK|MB_APPLMODAL|MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------
void __fastcall TChooserForm::runMe(AnsiString command) {
   if ((int)ShellExecute(NULL,"open",command.c_str(),"","",SW_MAXIMIZE)<32) {
      Application->MessageBox(("������ ��� ��������������� �� ����� �����! ���� �������� "+command+" �����!").c_str(),"������",MB_OK|MB_APPLMODAL|MB_ICONERROR);
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

