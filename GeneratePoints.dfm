object GeneratePointsForm: TGeneratePointsForm
  Left = 486
  Top = 225
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = #1058#1086#1095#1082#1080'->'#1054#1094#1077#1085#1082#1072
  ClientHeight = 169
  ClientWidth = 168
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 20
    Top = 8
    Width = 57
    Height = 13
    Caption = #1058#1086#1095#1082#1080' '#1079#1072' 3:'
  end
  object Label2: TLabel
    Left = 20
    Top = 36
    Width = 57
    Height = 13
    Caption = #1058#1086#1095#1082#1080' '#1079#1072' 6:'
  end
  object PointsFor2: TVrNumEdit
    Left = 88
    Top = 4
    Width = 53
    Height = 21
    Color = clWindow
    MaxValue = 9000
    Decimals = 2
    RestoreOnEsc = True
    Alignment = taLeftJustify
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = PointsFor2Change
  end
  object PointsFor6: TVrNumEdit
    Left = 88
    Top = 32
    Width = 53
    Height = 21
    Color = clWindow
    MaxValue = 9000
    Decimals = 2
    RestoreOnEsc = True
    Alignment = taLeftJustify
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnChange = PointsFor2Change
  end
  object OKBtn: TBitBtn
    Left = 7
    Top = 124
    Width = 75
    Height = 25
    TabOrder = 3
    OnClick = OKBtnClick
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 87
    Top = 124
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1082#1072#1079
    ModalResult = 2
    TabOrder = 4
    OnClick = BitBtn2Click
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333333333333333333333000033338833333333333333333F333333333333
      0000333911833333983333333388F333333F3333000033391118333911833333
      38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
      911118111118333338F3338F833338F3000033333911111111833333338F3338
      3333F8330000333333911111183333333338F333333F83330000333333311111
      8333333333338F3333383333000033333339111183333333333338F333833333
      00003333339111118333333333333833338F3333000033333911181118333333
      33338333338F333300003333911183911183333333383338F338F33300003333
      9118333911183333338F33838F338F33000033333913333391113333338FF833
      38F338F300003333333333333919333333388333338FFF830000333333333333
      3333333333333333333888330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 60
    Width = 141
    Height = 57
    Caption = #1057#1090#1098#1087#1082#1072
    TabOrder = 2
    object Step: TVrNumEdit
      Left = 80
      Top = 24
      Width = 53
      Height = 21
      Color = clWindow
      MaxValue = 9000
      Decimals = 2
      RestoreOnEsc = True
      Alignment = taLeftJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnChange = PointsFor2Change
    end
    object ByScore: TRadioButton
      Left = 8
      Top = 16
      Width = 57
      Height = 17
      Caption = #1086#1094#1077#1085#1082#1072
      TabOrder = 0
      OnClick = PointsFor2Change
    end
    object ByPoints: TRadioButton
      Left = 8
      Top = 36
      Width = 49
      Height = 17
      Caption = #1090#1086#1095#1082#1080
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = PointsFor2Change
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 150
    Width = 168
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = #1042#1098#1074#1077#1076#1077#1090#1077' '#1076#1072#1085#1085#1080#1090#1077'...'
  end
  object WorkQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    Left = 95
    Top = 35
  end
end
