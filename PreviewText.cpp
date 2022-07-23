//---------------------------------------------------------------------------

#include <vcl.h>
#include "PrintBlanks.h"
#pragma hdrstop

#include "PreviewText.h"
#include "BlankLoad.h"
#include "Options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPreviewTextForm *PreviewTextForm;
//---------------------------------------------------------------------------
__fastcall TPreviewTextForm::TPreviewTextForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::PrintBtnClick(TObject *Sender)
{
   switch (this->Tag) {
      case 3:
         PrintPerson(0);
      break;
      case 11:
         PrintCurrentTaxes(10);
      break;
      case 2:
         PrintRoomReport(0);
      break;
      case 1:
         PrintCurrentTaxes(0);
      break;
      case 5:
         PrintExamReport(0);
      break;
      default:
         ShowMessage("Fatal Exception: Internal Error!");
   }
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::EncodeBtnClick(TObject *Sender)
{
 CustomCodeTable *table=new CustomCodeTable(OptionsForm->CodeTableLabel->Text);
 TPoint p;
   EncodeBtn->Enabled=false;
   save=Text->Lines->Text;
   Text->Lines->Text=table->decodeString(Text->Lines->Text);

   p.x=0;
   p.y=0;
   Text->CaretPos=p;

   DecodeBtn->Enabled=true;
   delete table;
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::DecodeBtnClick(TObject *Sender)
{
 TPoint p;
   DecodeBtn->Enabled=false;
   Text->Lines->Text=save;
   EncodeBtn->Enabled=true;
   p.x=0;
   p.y=0;
   Text->CaretPos=p;
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   EncodeBtn->Enabled=true;
   DecodeBtn->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::FormActivate(TObject *Sender)
{
   EncodeBtn->Hint="Кодиране на текста.\nКодова таблица: "+OptionsForm->CodeTableLabel->Text+"\nВъзможно е кодирания текст да не се чете!";
   PrintBtn->Hint="Печат на текста.\nУстройство: "+OptionsForm->PrintDevice->Text;

   StatusBar1->Panels->Items[0]->Text="Редове: "+String(Text->Lines->Count);
 TPoint p;
   p.x=0;
   p.y=0;
   Text->CaretPos=p;
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::StatusBar1Resize(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Width=StatusBar1->Width-250;
}
//---------------------------------------------------------------------------

void __fastcall TPreviewTextForm::StatusBar1DrawPanel(
      TStatusBar *StatusBar, TStatusPanel *Panel, const TRect &Rect)
{
   StatusBar->Canvas->Font->Color=clBlue;
   StatusBar->Canvas->TextRect(Rect,Rect.Left,Rect.Top,"© 2004 Владимир Лалов (v_lalov@yahoo.com)");
}
//---------------------------------------------------------------------------

