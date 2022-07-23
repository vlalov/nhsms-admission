//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include "rsPropSaver.hpp"
#include "rsStorage.hpp"
#include "rsXmlData.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <dbcgrids.hpp>
#include <Buttons.hpp>
#include "LMDBaseDialog.hpp"
#include "LMDContainerComponent.hpp"
#include "LMDCustomComponent.hpp"
#include "LMDWindowListDlg.hpp"
#include <Tabs.hpp>
#include <Graphics.hpp>
#include "CSPIN.h"

#include "LogGenerator.h"
#include "LMDAboutDlg.hpp"
#include <AppEvnts.hpp>
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDControl.hpp"
#include "LMDFill.hpp"
#include "LMDGraphicControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomStatusBar.hpp"
#include "LMDStatusBar.hpp"
#include <ScktComp.hpp>
#include "rsIniData.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
   TMainMenu *MainMenu1;
   TMenuItem *N1;
   TMenuItem *N2;
   TMenuItem *N3;
   TMenuItem *N4;
   TMenuItem *N5;
   TMenuItem *N6;
   TMenuItem *N7;
   TMenuItem *N8;
   TMenuItem *N9;
   TMenuItem *N10;
   TImageList *ImageList1;
   TMenuItem *N11;
   TMenuItem *N12;
   TrsPropSaver *rsPropSaver1;
   TrsStorage *rsStorage1;
   TTreeView *TreeView;
   TPanel *MainPanel;
   TSplitter *Splitter1;
   TToolBar *ToolBar1;
   TToolButton *ToolButton1;
   TToolButton *ToolButton2;
   TToolButton *ToolButton3;
   TToolButton *ToolButton4;
   TActionList *ActionList1;
   TAction *ConnectToServer1;
   TAction *DisconnectFromServer1;
   TAction *RefreshServer1;
   TAction *Exit1;
   TToolButton *ToolButton5;
   TPageControl *PageControl;
   TTabSheet *TaxesTab;
   TTabSheet *ProfilesTab;
   TDBNavigator *DBNavigator1;
   TDBGrid *DBGrid1;
   TDBGrid *DBGrid2;
   TDBNavigator *ProfilesNavig;
   TTabSheet *WelcomeTab;
   TTabSheet *ReceptionTab;
   TDBNavigator *PersDBNavigator;
   TGroupBox *GroupBox1;
   TLabel *Label2;
   TDBEdit *PersNameEdit;
   TLabel *Label3;
   TDBEdit *PersEGNEdit;
   TLabel *Label4;
   TDBEdit *PersTelEdit;
   TLabel *Label5;
   TDBEdit *PersAddrEdit;
   TDBRadioGroup *PersSexEdit;
   TLabel *Label6;
   TDBLookupComboBox *PersTaxEdit;
   TAction *AddPerson1;
   TAction *CancelUpdate1;
   TUpdateSQL *WishesUpdateSQL;
   TDataSource *WishesSource;
   TQuery *WishesQuery;
   TTimer *Timer1;
   TMenuItem *N13;
   TIntegerField *WishesQueryPerson_ID;
   TIntegerField *WishesQueryProfile_ID;
   TIntegerField *WishesQueryPriority;
   TFloatField *WishesQueryScore;
   TFloatField *WishesQueryOlympScore;
   TBooleanField *WishesQueryFromOlymp;
   TAction *AddWish1;
   TPrinterSetupDialog *PrinterSetupDialog;
   TAction *Print1;
   TStringField *WishesQueryProfile;
   TTabSheet *TextsTab;
   TDBNavigator *DBNavigator4;
   TDBGrid *DBGrid3;
   TQuery *CalcAllTaxQuery;
   TIntegerField *CalcAllTaxQueryid;
   TFloatField *CalcAllTaxQueryAllTax;
   TSplitter *Splitter2;
   TPanel *Panel2;
   TSplitter *Splitter3;
   TLabel *Label11;
   TLabel *Label12;
   TDBRichEdit *DBRichEdit1;
   TToolButton *ToolButton6;
   TToolButton *ToolButton8;
   TAction *Preview1;
   TMenuItem *N14;
   TMenuItem *N15;
   TMenuItem *N16;
   TMenuItem *N17;
   TMenuItem *N18;
   TMenuItem *N19;
   TMenuItem *N20;
   TIntegerField *CalcAllTaxQuerycnt;
   TFloatField *CalcAllTaxQuerytheTAX;
   TMenuItem *N21;
   TLMDWindowListDlg *LMDWindowListDlg1;
   TMenuItem *N22;
   TTabSheet *PlacesTab;
   TDBNavigator *DBNavigator2;
   TDBGrid *DBGrid4;
   TSplitter *Splitter4;
   TDBGrid *DBGrid5;
   TDBNavigator *DBNavigator3;
   TLabel *Label14;
   TLabel *Label15;
   TDBEdit *DBEdit1;
   TPanel *Panel1;
   TRichEdit *DescriptionMemo;
   TLabel *Label16;
   TLabel *Label17;
   TLabel *Label18;
   TLabel *Label19;
   TQuery *ExchangeQuery;
   TLabel *Label24;
   TMenuItem *N23;
   TMenuItem *N24;
   TMenuItem *N25;
   TMenuItem *N26;
   TTabSheet *PointsScoreTab;
   TLabel *Label25;
   TPanel *Panel3;
   TLabel *Label26;
   TDBGrid *DBGrid6;
   TButton *GenerateBtn;
   TButton *ClearPointsBtn;
   TQuery *PointsToScoreQuery;
   TIntegerField *PointsToScoreQueryProfile_ID;
   TFloatField *PointsToScoreQueryScore;
   TDataSource *PointToScoreSource;
   TDBNavigator *DBNavigator6;
   TUpdateSQL *PointsToScoreUpdateSQL;
   TComboBox *ProfileLookup;
   TQuery *WorkQuery;
   TTabSheet *ResultTab;
   TLabel *Label28;
   TDBGrid *ERExamResultsGrid;
   TPanel *Panel4;
   TDBNavigator *DBNavigator7;
   TFloatField *PointsToScoreQueryPoint;
   TLabel *Label27;
   TComboBox *ResultsExamLookup;
   TMenuItem *N27;
   TMenuItem *N30;
   TAction *PrevRecord;
   TAction *NextRecord;
   TAction *FirstRecord;
   TAction *LastRecord;
   TAction *DeleteRecord;
   TAction *SaveChanges;
   TDBEdit *PersRoomView;
   TCSpinEdit *PersIDSearchEdit;
   TSpeedButton *PersSearchBtn;
   TPanel *Panel5;
   TLabel *Label13;
   TDBText *DBText1;
   TMenuItem *N28;
   TMenuItem *N29;
   TMenuItem *N31;
   TAction *SearchPersonID;
   TTabSheet *RegisterTab;
   TPanel *Panel6;
   TLabel *Label1;
   TLabel *Label29;
   TDBLookupComboBox *RegisterProfileCombo;
   TLabel *Label30;
   TPanel *Panel7;
   TRadioButton *RegisterMaleRadio;
   TRadioButton *RegisterFemaleRadio;
   TPanel *Panel9;
   TLabel *Label32;
   TDBGrid *RegisterDBGrid;
   TTabSheet *ClassificateTab;
   TLabel *Label35;
   TQuery *RegisterQuery;
   TUpdateSQL *RegisterUpdateSQL;
   TBooleanField *RegisterQueryClassificated;
   TIntegerField *RegisterQueryProfile_ID;
   TIntegerField *RegisterQueryPerson_ID;
   TFloatField *RegisterQueryAmount;
   TBooleanField *RegisterQueryIsIn;
   TDataSource *RegisterSource;
   TPanel *Panel8;
   TDBNavigator *DBNavigator8;
   TCSpinEdit *RegisterPersIDSearch;
   TSpeedButton *RegisterPersSearchBtn;
   TStringField *RegisterQueryPerson;
   TMenuItem *N32;
   TMenuItem *ODBC1;
   TSpeedButton *SexTypeBtn;
   TMenuItem *N33;
   TMenuItem *N34;
   TMenuItem *N35;
   TMenuItem *N36;
   TMenuItem *N37;
   TMenuItem *N38;
   TBooleanField *WishesQueryGoToExam;
   TPanel *Panel10;
   TBitBtn *ClassificateBtn;
   TBitBtn *ClassificateClearBtn;
   TBitBtn *ScndClassificateBtn;
   TPanel *Panel11;
   TLabel *Label34;
   TDBGrid *DBGrid8;
   TButton *AddGradeBtn;
   TButton *RemoveGradeBtn;
   TButton *ActivateGradeBtn;
   TCSpinEdit *ResultPIDEdit;
   TSpeedButton *ResultsPIDBtn;
   TLabel *Label7;
   TDBNavigator *WishesDBNavigator;
   TDBLookupComboBox *WishesPriorityLookup;
   TSpeedButton *WishUpBtn;
   TSpeedButton *WishDownBtn;
   TDBGrid *WishesDBGrid;
   TDBEdit *WishesScoreEdit;
   TLabel *Label9;
   TDBLookupComboBox *WishesProfileLookup;
   TLabel *Label8;
   TGroupBox *GroupBox3;
   TLabel *Label10;
   TDBCheckBox *OlympCheck;
   TDBEdit *OlympScoreEdit;
   TDBCheckBox *GoToExamCheck;
   TLabel *WishesCountLabel;
   TDBEdit *WishesPriorityView;
   TLMDAboutDlg *LMDAboutDlg1;
   TMenuItem *Online1;
   TApplicationEvents *ApplicationEvents1;
   TDBEdit *TaxShower;
   TDataSource *AllTaxDataSource;
   TLabel *Label20;
   TLabel *Label21;
   TQuery *AllTaxQuery;
   TIntegerField *IntegerField1;
   TFloatField *FloatField1;
   TIntegerField *IntegerField2;
   TFloatField *FloatField2;
   TSpeedButton *NameSMARTCaseBtn;
   TSpeedButton *AddressSMARTCaseBtn;
   TMenuItem *N39;
   TMenuItem *N40;
   TButton *SaveBtn;
   TSaveDialog *SaveDialogCSV;
   TQuery *ClassificatedQuery;
   TIntegerField *ClassificatedQueryPerson_ID;
   TStringField *ClassificatedQueryName;
   TIntegerField *ClassificatedQuerySex;
   TIntegerField *ClassificatedQueryProfile_ID;
   TFloatField *ClassificatedQuerySchoolScore;
   TFloatField *ClassificatedQueryFirstExamScore;
   TFloatField *ClassificatedQueryExamScore;
   TFloatField *ClassificatedQueryBAL;
   TToolButton *ToolButton7;
   TToolButton *ToolButton9;
   TToolButton *ToolButton11;
   TButton *SaveBtn2;
   TSpeedButton *FkSearchBtn;
   TCSpinEdit *FkSearchEdit;
   TMenuItem *N41;
   TMenuItem *N42;
   TImage *Image1;
   TOpenDialog *OpenDialog1;
   TCSpinEdit *PRNValue;
   TButton *PRNBtn;
   TStatusBar *StatusBar1;
   TSpeedButton *ShowPRN;
   TToolButton *ToolButton12;
   TToolButton *ToolButton13;
   TToolButton *ToolButton14;
   TPopupMenu *PopupMenu1;
   TMenuItem *N43;
   TMenuItem *N44;
   TMenuItem *N45;
   TAction *SearchingReception;
   TMenuItem *N46;
   TFontDialog *TableFont;
   TMenuItem *N47;
   TSpeedButton *SMARTCaseToggle;
   TServerSocket *RemoteAdminServer;
   TPageControl *PageControl1;
   TTabSheet *ClassifTab;
   TTabSheet *ProfilesHistoryTab;
   TPanel *Panel13;
   TDBGrid *DBGrid9;
   TLabel *Label31;
   TDBLookupComboBox *ClassifProfileLookup;
   TLabel *Label33;
   TPanel *Panel12;
   TRadioButton *ClassMaleRadio;
   TRadioButton *ClassFemaleRadio;
   TCSpinEdit *ClassifPIDEdit;
   TSpeedButton *ClassifPIDBtn;
   TCheckBox *AcceptedCheck;
   TDBGrid *DBGrid7;
   TMenuItem *TextPrintCheck;
   TQuery *TextTaxQuery;
   TIntegerField *IntegerField3;
   TFloatField *FloatField3;
   TIntegerField *IntegerField4;
   TFloatField *FloatField4;
   TQuery *PlaceQuery;
   TStringField *PlaceQueryText;
   TCheckBox *PRNEveryCheck;
   TLabel *PRNLabel;
   TCSpinEdit *PRNSecondEdit;
   TTimer *PRNTimer;
   TBitBtn *PRNStopBtn;
   TMenuItem *N48;
   TMenuItem *N49;
   TImageList *ImageListHOT;
   TDBCheckBox *PersPreferedSchoolCheckBox;
   TrsIniData *rsIniData1;
        TMenuItem *N50;
        TMenuItem *N51;
   TQuery *delmeQuery;
   void __fastcall ConnectToServer1Execute(TObject *Sender);
   void __fastcall DisconnectFromServer1Execute(TObject *Sender);
   void __fastcall RefreshServer1Execute(TObject *Sender);
   void __fastcall Exit1Execute(TObject *Sender);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
   void __fastcall TreeViewChange(TObject *Sender, TTreeNode *Node);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall AddPerson1Execute(TObject *Sender);
   void __fastcall CancelUpdate1Execute(TObject *Sender);
   void __fastcall PersEGNEditExit(TObject *Sender);
   void __fastcall WishesQueryAfterPost(TDataSet *DataSet);
   void __fastcall N13Click(TObject *Sender);
   void __fastcall Timer1Timer(TObject *Sender);
   void __fastcall OlympCheckClick(TObject *Sender);
   void __fastcall WishesQueryAfterScroll(TDataSet *DataSet);
   void __fastcall WishesQueryAfterInsert(TDataSet *DataSet);
   void __fastcall AddWish1Execute(TObject *Sender);
   void __fastcall Preview1Execute(TObject *Sender);
   void __fastcall Print1Execute(TObject *Sender);
   void __fastcall N19Click(TObject *Sender);
   void __fastcall N21Click(TObject *Sender);
   void __fastcall N22Click(TObject *Sender);
   void __fastcall N23Click(TObject *Sender);
   void __fastcall N25Click(TObject *Sender);
   void __fastcall N26Click(TObject *Sender);
   void __fastcall PointsToScoreQueryAfterPost(TDataSet *DataSet);
   void __fastcall ProfileLookupChange(TObject *Sender);
   void __fastcall ClearPointsBtnClick(TObject *Sender);
   void __fastcall GenerateBtnClick(TObject *Sender);
   void __fastcall ProfileLookupDropDown(TObject *Sender);
   void __fastcall ResultsExamLookupChange(TObject *Sender);
   void __fastcall ResultsExamLookupDropDown(TObject *Sender);
   void __fastcall PrevRecordExecute(TObject *Sender);
   void __fastcall NextRecordExecute(TObject *Sender);
   void __fastcall FirstRecordExecute(TObject *Sender);
   void __fastcall LastRecordExecute(TObject *Sender);
   void __fastcall DeleteRecordExecute(TObject *Sender);
   void __fastcall SaveChangesExecute(TObject *Sender);
   void __fastcall ERExamResultsGridColExit(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall PersSearchBtnClick(TObject *Sender);
   void __fastcall WishesQueryAfterEdit(TDataSet *DataSet);
   void __fastcall N20Click(TObject *Sender);
   void __fastcall PersIDSearchEditKeyPress(TObject *Sender, char &Key);
   void __fastcall WishesDBGridColExit(TObject *Sender);
   void __fastcall N28Click(TObject *Sender);
   void __fastcall N29Click(TObject *Sender);
   void __fastcall N31Click(TObject *Sender);
   void __fastcall SearchPersonIDExecute(TObject *Sender);
   void __fastcall ClassificateClearBtnClick(TObject *Sender);
   void __fastcall ClassificateBtnClick(TObject *Sender);
   void __fastcall RegisterProfileComboCloseUp(TObject *Sender);
   void __fastcall RegisterPersSearchBtnClick(TObject *Sender);
   void __fastcall RegisterPersIDSearchKeyPress(TObject *Sender,
          char &Key);
   void __fastcall RegisterQueryAfterPost(TDataSet *DataSet);
   void __fastcall ScndClassificateBtnClick(TObject *Sender);
   void __fastcall N11Click(TObject *Sender);
   void __fastcall ODBC1Click(TObject *Sender);
   void __fastcall SexTypeBtnClick(TObject *Sender);
   void __fastcall N34Click(TObject *Sender);
   void __fastcall N35Click(TObject *Sender);
   void __fastcall N10Click(TObject *Sender);
   void __fastcall ResultsPIDBtnClick(TObject *Sender);
   void __fastcall ResultPIDEditKeyPress(TObject *Sender, char &Key);
   void __fastcall PersNameEditKeyPress(TObject *Sender, char &Key);
   void __fastcall AddGradeBtnClick(TObject *Sender);
   void __fastcall RemoveGradeBtnClick(TObject *Sender);
   void __fastcall ClassifProfileLookupClick(TObject *Sender);
   void __fastcall ClassifPIDBtnClick(TObject *Sender);
   void __fastcall ClassifPIDEditKeyPress(TObject *Sender, char &Key);
   void __fastcall ActivateGradeBtnClick(TObject *Sender);
   void __fastcall WishUpBtnClick(TObject *Sender);
   void __fastcall WishDownBtnClick(TObject *Sender);
   void __fastcall WishesQueryUpdateError(TDataSet *DataSet,
          EDatabaseError *E, TUpdateKind UpdateKind,
          TUpdateAction &UpdateAction);
   void __fastcall PersEGNEditKeyPress(TObject *Sender, char &Key);
   void __fastcall N8Click(TObject *Sender);
   void __fastcall Online1Click(TObject *Sender);
   void __fastcall rsPropSaver1AfterLoad(TObject *Sender);
   void __fastcall GroupBox1Enter(TObject *Sender);
   void __fastcall Panel1Enter(TObject *Sender);
   void __fastcall PersSexEditExit(TObject *Sender);
   void __fastcall PersNameEditEnter(TObject *Sender);
   void __fastcall PersAddrEditEnter(TObject *Sender);
   void __fastcall PersAddrEditKeyPress(TObject *Sender, char &Key);
   void __fastcall N39Click(TObject *Sender);
   void __fastcall N40Click(TObject *Sender);
   void __fastcall SaveBtnClick(TObject *Sender);
   void __fastcall SaveBtn2Click(TObject *Sender);
   void __fastcall FkSearchBtnClick(TObject *Sender);
   void __fastcall FkSearchEditKeyPress(TObject *Sender, char &Key);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall N41Click(TObject *Sender);
   void __fastcall N42Click(TObject *Sender);
   void __fastcall PRNBtnClick(TObject *Sender);
   void __fastcall StatusBar1Resize(TObject *Sender);
   void __fastcall ShowPRNClick(TObject *Sender);
   void __fastcall StatusBar1DrawPanel(TStatusBar *StatusBar,
          TStatusPanel *Panel, const TRect &Rect);
   void __fastcall N43Click(TObject *Sender);
   void __fastcall N44Click(TObject *Sender);
   void __fastcall N45Click(TObject *Sender);
   void __fastcall SearchingReceptionExecute(TObject *Sender);
   void __fastcall ToolButton12Click(TObject *Sender);
   void __fastcall N46Click(TObject *Sender);
   void __fastcall N47Click(TObject *Sender);
   void __fastcall SMARTCaseToggleClick(TObject *Sender);
   void __fastcall FormKeyPress(TObject *Sender, char &Key);
   void __fastcall RemoteAdminServerClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
   void __fastcall RemoteAdminServerClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
   void __fastcall RemoteAdminServerClientWrite(TObject *Sender,
          TCustomWinSocket *Socket);
   void __fastcall PRNTimerTimer(TObject *Sender);
   void __fastcall PRNStopBtnClick(TObject *Sender);
   void __fastcall FormResize(TObject *Sender);
   void __fastcall ApplicationEvents1Hint(TObject *Sender);
        void __fastcall N50Click(TObject *Sender);
        void __fastcall N51Click(TObject *Sender);
   void __fastcall RegisterDBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall RegisterDBGridKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
   int ProfileLookupCode;
   AnsiString Arg;
   TLog *mainlog;
   int index;
   bool NOFillHoles;
   bool NCD;
   
   __fastcall TMainForm(TComponent* Owner);
   void __fastcall RefreshExamsLookup();
   void __fastcall ResolveProfileLookupCode(AnsiString text);
   void __fastcall InitializeTabs();
   void __fastcall SetFont(TFont* Font);
   void __fastcall ClearPoints();
   void __fastcall RefreshResultsLookup();
   void __fastcall MoveInDataSets(int movetype);
   void __fastcall ApplyToAll();
   void __fastcall ShowProgress(AnsiString message,int current,int total);
   bool __fastcall CheckKey(bool state,char &key) {
    AnsiString t;
      if (strchr(" ,./-=?><|\\+;",key)!=NULL) return true;
      if (state==true&&strchr("1234567890=_+!@#$%^&*(){}[]:;<>?/,.|§~`",key)==NULL) {
       // Must be Upper and it is an alpha
         t=String(key);
         key=t.UpperCase().c_str()[0];
         return false;
      }
      if (state==false&&strchr("1234567890=_+!@#$%^&*(){}[]:;<>?/,.|§~`",key)==NULL) {
       // Must be lower and it is an alpha
         t=String(key);
         key=t.LowerCase().c_str()[0];
         return false;
      }
      if (strchr("1234567890=_+!@#$%^&*(){}[]:;<>?/,.|§~`",key)!=NULL) {
         state=true;
      }
      return false;
    }
    bool MustBeUpper;
    int startIndex;
 // Register
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
