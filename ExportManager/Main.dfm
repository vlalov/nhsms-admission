object MainForm: TMainForm
  Left = 263
  Top = 320
  BorderStyle = bsDialog
  Caption = #1045#1082#1089#1087#1086#1088#1090' '#1085#1072' '#1090#1072#1073#1083#1080#1094#1072' '#1074' CSV'
  ClientHeight = 203
  ClientWidth = 350
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 12
    Width = 22
    Height = 13
    Caption = 'Alias'
  end
  object Label2: TLabel
    Left = 172
    Top = 12
    Width = 43
    Height = 13
    Caption = #1058#1072#1073#1083#1080#1094#1072
  end
  object Label3: TLabel
    Left = 16
    Top = 44
    Width = 21
    Height = 13
    Caption = 'CSV'
  end
  object SpeedButton1: TSpeedButton
    Left = 308
    Top = 40
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = SpeedButton1Click
  end
  object PathEdit: TEdit
    Left = 44
    Top = 40
    Width = 261
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 97
    Top = 68
    Width = 75
    Height = 25
    Caption = #1048#1079#1087#1098#1083#1085#1080
    TabOrder = 3
    OnClick = Button1Click
  end
  object TableEdit: TComboBox
    Left = 218
    Top = 8
    Width = 125
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    OnChange = TableEditChange
    Items.Strings = (
      'Persons'
      'Wishes'
      'ExamsResults'
      'Profiles'
      'Register'
      'Taxes'
      'Places'
      'Rooms'
      'UserTexts')
  end
  object ListBox: TCheckListBox
    Left = 4
    Top = 100
    Width = 342
    Height = 97
    ItemHeight = 13
    TabOrder = 5
  end
  object Button2: TButton
    Left = 173
    Top = 68
    Width = 75
    Height = 25
    Caption = #1045#1082#1089#1087#1086#1088#1090
    Enabled = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object AliasEdit: TComboBox
    Left = 44
    Top = 8
    Width = 125
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'base2002'
    OnChange = TableEditChange
    Items.Strings = (
      'base2002'
      'base2001'
      'base2000'
      'base1999'
      'SQLServer')
  end
  object Database: TDatabase
    DatabaseName = 'DatabaseExport'
    LoginPrompt = False
    SessionName = 'Default'
    Left = 240
    Top = 16
  end
  object Query1: TQuery
    DatabaseName = 'DatabaseExport'
    Left = 240
    Top = 48
  end
  object SaveDialog: TSaveDialog
    Filter = 
      'Comma Separated Values(*.csv)|*.csv|Text Files(*.txt)|*.txt|All ' +
      'Files(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Title = 'Select output file'
    Left = 272
    Top = 48
  end
  object rsIniData1: TrsIniData
    FileName = 'Reception.ini'
    Options = []
    Left = 60
    Top = 70
  end
  object rsStorage1: TrsStorage
    Active = True
    EncryptId = 1886286367
    StorageData = rsIniData1
    Left = 30
    Top = 70
  end
end
