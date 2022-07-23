//---------------------------------------------------------------------------

#include <vcl.h>
#include"Library.h"
#pragma hdrstop

#include "ReceptionRes.h"
#include "DataModule.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReceptionResForm *ReceptionResForm;
//---------------------------------------------------------------------------
__fastcall TReceptionResForm::TReceptionResForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TReceptionResForm::ViewPreview() {
   PlaceQuery->Active=true;
   QuickRep1->ReportTitle="Прием на НПМГ - Текущ кандидат № "+String(Data->PersonsQuery->FieldByName("ID")->AsInteger);
   Initialize();
   QuickRep1->Preview();
   PlaceQuery->Active=false;
}
void __fastcall TReceptionResForm::PrintReport() {
   PlaceQuery->Active=true;
   QuickRep1->ReportTitle="Прием на НПМГ - Текущ кандидат № "+String(Data->PersonsQuery->FieldByName("ID")->AsInteger);
   Initialize();
   QuickRep1->Print();
   PlaceQuery->Active=false;
}
// --- Initialize the Report
void __fastcall TReceptionResForm::Initialize() {
 int id=Data->PersonsQuery->FieldByName("ID")->AsInteger;
 AnsiString temp;
 // Refreshing Persons...
   PersonsQuery->Active=false;
   PersonsQuery->Active=true;
 // Setting filter
   PersonsQuery->Filtered=false;
   PersonsQuery->Filter="ID="+String(id);
   PersonsQuery->Filtered=true;
   if (MainForm->NCD==false) {
      DateShow->Caption=FormatDateTime("ddddd",Now());
   } else {
      DateShow->Caption=FormatDateTime("ddddd",PersonsQuery->FieldByName("EntOn")->AsDateTime);
   }

   MainForm->WishesQuery->Tag=1;

 // Getting static text from the database
   StaticTextQuery->Active=true;

   StaticTextQuery->Filter="ID=1";// Static Text Before
   StaticTextQuery->Filtered=true;
   StaticBeforeText->Caption=StaticTextQuery->FieldByName("value")->AsString;
 // Getting text after datas (ID=2)
   TextsAfter->Caption="";
   StaticTextQuery->Filter="ID=2";// Static Text After
   StaticTextQuery->Filtered=true;
   TextsAfter->Caption=StaticTextQuery->FieldByName("value")->AsString;
 // Append place string from PlaceQuery
   TextsAfter->Caption=TextsAfter->Caption+PlaceQuery->FieldByName("Text")->AsString;
 // Append text after place show
   StaticTextQuery->Filter="ID=3";// Static Text After Place
   StaticTextQuery->Filtered=true;
   TextsAfter->Caption=TextsAfter->Caption+replaceString(StaticTextQuery->FieldByName("value")->AsString,"#operator#",Data->PersonsQuery->FieldByName("EntBy")->AsString);

   QuickRep1->Refresh();
 /* --Reorganizing After Texts (NOT WORKING!)-----------
   PlaceLabel->Top=StaticAfterText->Height+5;
   ShowMessage(StaticAfterText->Height);
   StaticTextAfterPlace->Top=PlaceLabel->Top+PlaceLabel->Height+5;
 */
   PlaceQuery->Active=false;
   StaticTextQuery->Active=false;
}
void __fastcall TReceptionResForm::PersonsQueryCalcFields(
      TDataSet *DataSet)
{
   switch (DataSet->FieldByName("Sex")->AsInteger) {
      case 1:
         PersonsQuerySe->AsString="Мъжки";
      break;
      case 0:
         PersonsQuerySe->AsString="Женски";
      break;
   }
}
//---------------------------------------------------------------------------


