//---------------------------------------------------------------------------

#include <vcl.h>
#include "DataModule.h"
#pragma hdrstop

#include "RoomChooser.h"
#include "RoomProtocolRes.h"
#include<stdio.h>
#include "Main.h"
#include "PrintBlanks.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRoomChooserForm *RoomChooserForm;
//---------------------------------------------------------------------------
__fastcall TRoomChooserForm::TRoomChooserForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRoomChooserForm::FormShow(TObject *Sender)
{
   PlaceQuery->Active=true;
   if (PlaceQuery->RecordCount>1) RoomLookup->KeyValue=PlaceQuery->FieldByName("Code")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TRoomChooserForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   PlaceQuery->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TRoomChooserForm::BitBtn2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TRoomChooserForm::OKBtnClick(TObject *Sender)
{
   PlaceQuery->Active=true;
   if (MainForm->TextPrintCheck->Checked) {
      if (Application->MessageBox("Предпечат?","Печат в текстов режим",MB_YESNO|MB_APPLMODAL|MB_ICONQUESTION)==ID_YES) {
         DoTextPreview();
      } else {
         DoTextPrint();
      }
   } else {
      RoomProtocolResForm->PersonsQuery->Active=true;
      RoomProtocolResForm->QuickRep1->Preview();
      RoomProtocolResForm->PersonsQuery->Active=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TRoomChooserForm::SaveBtnClick(TObject *Sender)
{
 FILE *out;
 AnsiString text;
   if (Data->Database1->Connected!=true) {
      return;
   }
   if (SaveDialogCSV->Execute()) {
      out=fopen(SaveDialogCSV->FileName.c_str(),"w");
      if (out==NULL) { ShowMessage("Грешка при отварянето на файла!"); return; }
      PlaceQuery->Active=true;
      RoomProtocolResForm->PersonsQuery->Active=false;
      RoomProtocolResForm->PersonsQuery->Active=true;
      text="Протокол за провеждане на изпит";
      text="\""+text+"\"\n";
      text=text+"\"Зала: "+PlaceQuery->FieldByName("Code")->AsString+"   "+PlaceQuery->FieldByName("Name")->AsString;
      text=text+"\"\n";
      fprintf(out,text.c_str());
      fprintf(out,"\"№\",\"Име\",\"Подпис\"\n");
      RoomProtocolResForm->PersonsQuery->First();

      for (int i=0;i<RoomProtocolResForm->PersonsQuery->RecordCount;i++) {
         fprintf(out,"\"%d\",\"%s\"\n",
 RoomProtocolResForm->PersonsQuery->FieldByName("ID")->AsInteger,RoomProtocolResForm->PersonsQuery->FieldByName("Name")->AsString.c_str());
         RoomProtocolResForm->PersonsQuery->Next();
      }
      text.printf("\"Общ брой: %d\"\n",RoomProtocolResForm->PersonsQuery->RecordCount);
      fprintf(out,text.c_str());
      fprintf(out,"Квестори:\n");
      RoomProtocolResForm->PersonsQuery->Active=false;
      fclose(out);
   }
}
//---------------------------------------------------------------------------

