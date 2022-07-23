object LoginForm: TLoginForm
  Left = 337
  Top = 210
  HelpContext = 7
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1094#1080#1103
  ClientHeight = 91
  ClientWidth = 237
  Color = clBtnFace
  ParentFont = True
  FormStyle = fsStayOnTop
  OldCreateOrder = True
  Position = poDesktopCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 37
    Width = 41
    Height = 13
    Caption = #1055'&'#1072#1088#1086#1083#1072':'
    FocusControl = PasswordEdit
  end
  object Label2: TLabel
    Left = 4
    Top = 9
    Width = 63
    Height = 13
    Caption = #1055#1086#1090#1088#1077'&'#1073#1080#1090#1077#1083':'
    FocusControl = UserNameEdit
  end
  object PasswordEdit: TEdit
    Left = 72
    Top = 35
    Width = 161
    Height = 21
    HelpContext = 7
    PasswordChar = '*'
    TabOrder = 0
  end
  object OKBtn: TButton
    Left = 78
    Top = 63
    Width = 75
    Height = 25
    HelpContext = 7
    Caption = '&'#1057#1074#1098#1088#1079#1074#1072#1085#1077
    Default = True
    ModalResult = 1
    TabOrder = 1
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 158
    Top = 63
    Width = 75
    Height = 25
    HelpContext = 7
    Cancel = True
    Caption = #1054'&'#1090#1082#1072#1079
    ModalResult = 2
    TabOrder = 2
    OnClick = CancelBtnClick
  end
  object UserNameEdit: TComboBox
    Left = 72
    Top = 8
    Width = 161
    Height = 21
    HelpContext = 7
    ItemHeight = 13
    TabOrder = 3
  end
  object rsPropSaver1: TrsPropSaver
    Storage = MainForm.rsStorage1
    Options = []
    RootSection = 'LoginForm'
    Properties.Strings = (
      'UserNameEdit.Items'
      'UserNameEdit.ItemIndex')
    WhenLoad = wlOnCreate
    WhenSave = wsOnDestroy
    Left = 24
    Top = 56
  end
end
