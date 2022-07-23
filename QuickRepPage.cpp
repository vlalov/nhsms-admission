//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QuickRepPage.h"
#include "ReceptionRes.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VrEdit"
#pragma link "rsPropSaver"
#pragma link "rsStorage"
#pragma resource "*.dfm"
TQuickRepEditorForm *QuickRepEditorForm;
//---------------------------------------------------------------------------
__fastcall TQuickRepEditorForm::TQuickRepEditorForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQuickRepEditorForm::CancelBtnClick(TObject *Sender)
{
   Close();   
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::PaperTypeComboChange(TObject *Sender)
{
/*
254,0 x 355,6 10x14 in
279,40 x 431,80 11x17 in
297,0 x 420,0 A3
210,0 x 297,0 A4
148,0 x 210,0 A5
250,0 x 354,0 B4
182,0 x 257,0 B5
100,0 x 100,0 C size
104,8 x 241,3 Envelope #10
114,8 x 263,5 Envelope #11
114,8 x 263,5 Envelope #12
127,0 x 292,1 Envelope #14
98,43 x 225,4 Envelope #9
190,5 x 254,0 Executive 7
215,9 x 330,2 Note
431,8 x 279,4 Ledger
139,7 x 215,9 Statement 5
279,4 x 431,8 Tabloid
Custom...
*/
   if (PaperTypeCombo->Text=="Custom...") {
      WidthEdit->Enabled=true;
      LengthEdit->Enabled=true;
      OrientationCombo->Enabled=false;
      QuickRep1->Page->PaperSize=Custom;
      QuickRep1->Page->Orientation=poPortrait;
      OrientationCombo->ItemIndex=0;

      WidthEdit->Value=QuickRep1->Page->Width;
      LengthEdit->Value=QuickRep1->Page->Length;

      return;
   }
   WidthEdit->Enabled=false;
   LengthEdit->Enabled=false;

   if (PaperTypeCombo->Text=="254,0 x 355,6 10x14 in") {
      QuickRep1->Page->PaperSize=qr10X14;
   }
   if (PaperTypeCombo->Text=="279,40 x 431,80 11x17 in") {
      QuickRep1->Page->PaperSize=qr11X17;
   }

   if (PaperTypeCombo->Text=="297,0 x 420,0 A3") {
      QuickRep1->Page->PaperSize=A3;
   }

   if (PaperTypeCombo->Text=="210,0 x 297,0 A4") {
      QuickRep1->Page->PaperSize=A4;
   }

   if (PaperTypeCombo->Text=="148,0 x 210,0 A5") {
      QuickRep1->Page->PaperSize=A5;
   }

   if (PaperTypeCombo->Text=="250,0 x 354,0 B4") {
      QuickRep1->Page->PaperSize=B4;
   }
   if (PaperTypeCombo->Text=="182,0 x 257,0 B5") {
      QuickRep1->Page->PaperSize=B5;
   }
   if (PaperTypeCombo->Text=="100,0 x 100,0 C size") {
      QuickRep1->Page->PaperSize=CSheet;
   }
   if (PaperTypeCombo->Text=="104,8 x 241,3 Envelope #10") {
      QuickRep1->Page->PaperSize=Env10;
   }
   if (PaperTypeCombo->Text=="114,3 x 263,5 Envelope #11") {
      QuickRep1->Page->PaperSize=Env11;
   }
   if (PaperTypeCombo->Text=="101,6 x 279,4 Envelope #12") {
      QuickRep1->Page->PaperSize=Env12;
   }
   if (PaperTypeCombo->Text=="127,0 x 292,1 Envelope #14") {
      QuickRep1->Page->PaperSize=Env14;
   }
   if (PaperTypeCombo->Text=="98,43 x 225,4 Envelope #9") {
      QuickRep1->Page->PaperSize=Env9;
   }
   if (PaperTypeCombo->Text=="190,5 x 254,0 Executive 7") {
      QuickRep1->Page->PaperSize=Executive;
   }
   if (PaperTypeCombo->Text=="215,9 x 279,0 Note") {
      QuickRep1->Page->PaperSize=Note;
   }
   if (PaperTypeCombo->Text=="431,8 x 279,4 Ledger") {
      QuickRep1->Page->PaperSize=Ledger;
   }
   if (PaperTypeCombo->Text=="139,7 x 215,9 Statement 5") {
      QuickRep1->Page->PaperSize=Statement;
   }
   if (PaperTypeCombo->Text=="279,4 x 431,8 Tabloid") {
      QuickRep1->Page->PaperSize=Tabloid;
   }
   WidthEdit->Value=QuickRep1->Page->Width;
   LengthEdit->Value=QuickRep1->Page->Length;
   OrientationCombo->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::OrientationComboChange(TObject *Sender)
{
   if (OrientationCombo->Text=="Portrait") QuickRep1->Page->Orientation=poPortrait;
   else QuickRep1->Page->Orientation=poLandscape;

   WidthEdit->Value=QuickRep1->Page->Width;
   LengthEdit->Value=QuickRep1->Page->Length;
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::LengthEditChange(TObject *Sender)
{
   try {
      QuickRep1->Page->Width=WidthEdit->Value;
      QuickRep1->Page->Length=LengthEdit->Value;
   } catch(...) {
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::TrackPersentChange(TObject *Sender)
{
   QuickRep1->Zoom=TrackPersent->Position;
   GroupBox->Caption="Preview - "+String(TrackPersent->Position)+"%";
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::LeftMarginEditChange(TObject *Sender)
{
   try {
      QuickRep1->Page->LeftMargin=LeftMarginEdit->Value;
      QuickRep1->Page->RightMargin=RigthMarginEdit->Value;
      QuickRep1->Page->TopMargin=TopMarginEdit->Value;
      QuickRep1->Page->BottomMargin=ButtomMarginEdit->Value;
   } catch(...) {
   }
}
//---------------------------------------------------------------------------
void __fastcall TQuickRepEditorForm::SetPageValues(TQuickRep *Dest,TQRCompositeReport *composite) {
   PaperTypeComboChange(this);
   if (Dest!=NULL) {
      Dest->Page->PaperSize=QuickRep1->Page->PaperSize;
      Dest->Page->Width=QuickRep1->Page->Width;
      Dest->Page->Length=QuickRep1->Page->Length;
      Dest->Page->Orientation=QuickRep1->Page->Orientation;

      Dest->Page->LeftMargin=LeftMarginEdit->Value;
      Dest->Page->RightMargin=RigthMarginEdit->Value;
      Dest->Page->TopMargin=TopMarginEdit->Value;
      Dest->Page->BottomMargin=ButtomMarginEdit->Value;

      Dest->Font=QuickRep1->Font;
   }
   if (composite!=NULL) {
      composite->PrinterSettings->PaperSize=QuickRep1->Page->PaperSize;
      composite->PrinterSettings->Orientation=QuickRep1->Page->Orientation;
      
   }
}

void __fastcall TQuickRepEditorForm::OKBtnClick(TObject *Sender)
{
   MainForm->ApplyToAll();
   rsPropSaver1->SaveValues();
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::FormActivate(TObject *Sender)
{
   rsPropSaver1->LoadValues();
   PaperTypeComboChange(this);
/*
   switch (QuickRep1->Page->PaperSize) {
      case qr10X14:
         PaperTypeCombo->ItemIndex=0;
      break;
      case qr11X17:
         PaperTypeCombo->ItemIndex=1;
      break;
      case A3:
         PaperTypeCombo->ItemIndex=2;
      break;
      case A4:
         PaperTypeCombo->ItemIndex=3;
      break;
      case A5:
         PaperTypeCombo->ItemIndex=4;
      break;
      case B4:
         PaperTypeCombo->ItemIndex=5;
      break;
      case B5:
         PaperTypeCombo->ItemIndex=6;
      break;
      case CSheet:
         PaperTypeCombo->ItemIndex=7;
      break;
      case Env10:
         PaperTypeCombo->ItemIndex=8;
      break;
      case Env11:
         PaperTypeCombo->ItemIndex=9;
      break;
      case Env12:
         PaperTypeCombo->ItemIndex=10;
      break;
      case Env14:
         PaperTypeCombo->ItemIndex=11;
      break;
      case Env9:
         PaperTypeCombo->ItemIndex=12;
      break;
      case Executive:
         PaperTypeCombo->ItemIndex=13;
      break;
      case Note:
         PaperTypeCombo->ItemIndex=14;
      break;
      case Ledger:
         PaperTypeCombo->ItemIndex=15;
      break;
      case Statement:
         PaperTypeCombo->ItemIndex=16;
      break;
      case Tabloid:
         PaperTypeCombo->ItemIndex=17;
      break;
      case Custom:
         PaperTypeCombo->ItemIndex=18;
      break;
   }

//------------------------------------------------------------------------------
   QuickRep1->Page->PaperSize=ReceptionResForm->QuickRep1->Page->PaperSize;
   QuickRep1->Page->Width=ReceptionResForm->QuickRep1->Page->Width;
   QuickRep1->Page->Length=ReceptionResForm->QuickRep1->Page->Length;
   QuickRep1->Page->Orientation=ReceptionResForm->QuickRep1->Page->Orientation;

   LengthEdit->Value=QuickRep1->Page->Length;
   WidthEdit->Value=QuickRep1->Page->Width;
   OrientationCombo->ItemIndex=QuickRep1->Page->Orientation==poPortrait?0:1;

   LeftMarginEdit->Value=ReceptionResForm->QuickRep1->Page->LeftMargin;
   RigthMarginEdit->Value=ReceptionResForm->QuickRep1->Page->RightMargin;
   TopMarginEdit->Value=ReceptionResForm->QuickRep1->Page->TopMargin;
   ButtomMarginEdit->Value=ReceptionResForm->QuickRep1->Page->BottomMargin;
*/
}
//---------------------------------------------------------------------------

void __fastcall TQuickRepEditorForm::FontBtnClick(TObject *Sender)
{
   if (!FontDialog->Execute()) return;
   QuickRep1->Font=FontDialog->Font;
}
//---------------------------------------------------------------------------

