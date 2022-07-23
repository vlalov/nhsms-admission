object OptionsForm: TOptionsForm
  Left = 284
  Top = 133
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1080
  ClientHeight = 178
  ClientWidth = 322
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 8
    Width = 23
    Height = 13
    Caption = 'DSN'
  end
  object DSNEdit: TEdit
    Left = 36
    Top = 5
    Width = 189
    Height = 21
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 232
    Top = 24
    Width = 75
    Height = 25
    TabOrder = 1
    OnClick = BitBtn1Click
    Kind = bkOK
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 32
    Width = 221
    Height = 41
    TabOrder = 2
    object AutoLogOnCheck: TCheckBox
      Left = 8
      Top = 12
      Width = 209
      Height = 17
      Caption = #1057#1074#1098#1088#1079#1074#1072#1085#1077' '#1087#1088#1080' '#1089#1090#1072#1088#1090#1080#1088#1072#1085#1077' '#1085#1072' '#1087#1088#1086#1075#1088'.'
      TabOrder = 0
    end
  end
  object GroupBox2: TGroupBox
    Left = 4
    Top = 80
    Width = 317
    Height = 92
    Caption = #1058#1077#1082#1089#1090#1086#1074' '#1087#1077#1095#1072#1090
    TabOrder = 3
    object SpeedButton1: TSpeedButton
      Left = 288
      Top = 31
      Width = 23
      Height = 22
      Caption = '...'
      Flat = True
      OnClick = SpeedButton1Click
    end
    object Label2: TLabel
      Left = 8
      Top = 68
      Width = 63
      Height = 13
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086':'
    end
    object CodeTableLabel: TLabeledEdit
      Left = 8
      Top = 32
      Width = 277
      Height = 21
      EditLabel.Width = 84
      EditLabel.Height = 13
      EditLabel.Caption = #1050#1086#1076#1086#1074#1072' '#1090#1072#1073#1083#1080#1094#1072':'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object PrintDevice: TComboBox
      Left = 76
      Top = 64
      Width = 77
      Height = 21
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 1
      Text = 'LPT1'
      Items.Strings = (
        'LPT1'
        'LPT2'
        'LPT3')
    end
    object TestBtn: TButton
      Left = 212
      Top = 60
      Width = 75
      Height = 25
      Caption = #1058#1077#1089#1090'...'
      TabOrder = 2
      OnClick = TestBtnClick
    end
  end
  object rsPropSaver1: TrsPropSaver
    Storage = MainForm.rsStorage1
    RootSection = 'OptionsForm'
    Properties.Strings = (
      'AutoLogOnCheck.Checked'
      'CodeTableLabel.Text'
      'PrintDevice.Text')
    WhenLoad = wlOnCreate
    WhenSave = wsOnHide
    Left = 236
    Top = 12
  end
  object CodeTable: TOpenDialog
    DefaultExt = 'prt'
    Filter = #1050#1086#1076#1086#1074#1080' '#1090#1072#1073#1083#1080#1094#1080' (*.prt)|*.prt|'#1042#1089#1080#1095#1082#1080' '#1092#1072#1081#1083#1086#1074#1077' (*.*)|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = #1048#1079#1073#1077#1088#1077#1090#1077' '#1082#1086#1076#1086#1074#1072' '#1090#1072#1073#1083#1080#1094#1072
    Left = 236
    Top = 52
  end
end
