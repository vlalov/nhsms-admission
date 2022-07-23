object QuickRepEditorForm: TQuickRepEditorForm
  Left = 224
  Top = 155
  BorderStyle = bsDialog
  Caption = 'General Report Editor'
  ClientHeight = 269
  ClientWidth = 489
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 55
    Height = 13
    Caption = 'Paper Type'
  end
  object Label4: TLabel
    Left = 8
    Top = 68
    Width = 51
    Height = 13
    Caption = 'Orientation'
  end
  object Label2: TLabel
    Left = 32
    Top = 40
    Width = 28
    Height = 13
    Caption = 'Width'
  end
  object Label3: TLabel
    Left = 140
    Top = 40
    Width = 33
    Height = 13
    Caption = 'Length'
  end
  object PaperTypeCombo: TComboBox
    Left = 68
    Top = 8
    Width = 169
    Height = 21
    Style = csDropDownList
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ItemIndex = 3
    ParentFont = False
    TabOrder = 0
    Text = '210,0 x 297,0 A4'
    OnChange = PaperTypeComboChange
    Items.Strings = (
      '254,0 x 355,6 10x14 in'
      '279,40 x 431,80 11x17 in'
      '297,0 x 420,0 A3'
      '210,0 x 297,0 A4'
      '148,0 x 210,0 A5'
      '250,0 x 354,0 B4'
      '182,0 x 257,0 B5'
      '100,0 x 100,0 C size'
      '104,8 x 241,3 Envelope #10'
      '114,3 x 263,5 Envelope #11'
      '101,6 x 279,4 Envelope #12'
      '127,0 x 292,1 Envelope #14'
      '98,43 x 225,4 Envelope #9'
      '190,5 x 254,0 Executive 7'
      '215,9 x 279,0 Note'
      '431,8 x 279,4 Ledger'
      '139,7 x 215,9 Statement 5'
      '279,4 x 431,8 Tabloid'
      'Custom...')
  end
  object OrientationCombo: TComboBox
    Left = 68
    Top = 64
    Width = 97
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 3
    Text = 'Portrait'
    OnChange = OrientationComboChange
    Items.Strings = (
      'Portrait'
      'Landscape')
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 96
    Width = 233
    Height = 133
    Caption = 'Margins'
    TabOrder = 4
    object Label5: TLabel
      Left = 100
      Top = 12
      Width = 19
      Height = 13
      Caption = 'Top'
    end
    object Label6: TLabel
      Left = 96
      Top = 112
      Width = 33
      Height = 13
      Caption = 'Buttom'
    end
    object Label7: TLabel
      Left = 8
      Top = 60
      Width = 18
      Height = 13
      Caption = 'Left'
    end
    object Label8: TLabel
      Left = 200
      Top = 60
      Width = 25
      Height = 13
      Caption = 'Right'
    end
    object TopMarginEdit: TVrNumEdit
      Left = 92
      Top = 28
      Width = 41
      Height = 21
      Color = clWindow
      MaxValue = 9999
      MinValue = 1
      Decimals = 2
      Value = 10
      Alignment = taLeftJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = LeftMarginEditChange
    end
    object ButtomMarginEdit: TVrNumEdit
      Left = 92
      Top = 84
      Width = 41
      Height = 21
      Color = clWindow
      MaxValue = 9999
      MinValue = 1
      Decimals = 2
      Value = 10
      Alignment = taLeftJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnChange = LeftMarginEditChange
    end
    object LeftMarginEdit: TVrNumEdit
      Left = 32
      Top = 56
      Width = 41
      Height = 21
      Color = clWindow
      MaxValue = 9999
      MinValue = 1
      Decimals = 2
      Value = 10
      Alignment = taLeftJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnChange = LeftMarginEditChange
    end
    object RigthMarginEdit: TVrNumEdit
      Left = 152
      Top = 56
      Width = 41
      Height = 21
      Color = clWindow
      MaxValue = 9999
      MinValue = 1
      Decimals = 2
      Value = 10
      Alignment = taLeftJustify
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnChange = LeftMarginEditChange
    end
  end
  object WidthEdit: TVrNumEdit
    Left = 68
    Top = 36
    Width = 57
    Height = 21
    Color = clWindow
    MaxValue = 9999
    MinValue = 50
    Decimals = 1
    Value = 210
    Alignment = taLeftJustify
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnChange = LengthEditChange
  end
  object LengthEdit: TVrNumEdit
    Left = 180
    Top = 36
    Width = 57
    Height = 21
    Color = clWindow
    MaxValue = 9999
    MinValue = 50
    Decimals = 1
    Value = 297
    Alignment = taLeftJustify
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnChange = LengthEditChange
  end
  object CancelBtn: TButton
    Left = 288
    Top = 240
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 8
    OnClick = CancelBtnClick
  end
  object OKBtn: TButton
    Left = 128
    Top = 240
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 7
    OnClick = OKBtnClick
  end
  object GroupBox: TGroupBox
    Left = 248
    Top = 4
    Width = 237
    Height = 205
    Caption = 'Preview - 10%'
    TabOrder = 5
    object QuickRep1: TQuickRep
      Left = 7
      Top = 16
      Width = 79
      Height = 112
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = []
      Functions.Strings = (
        'PAGENUMBER'
        'COLUMNNUMBER'
        'REPORTTITLE')
      Functions.DATA = (
        '0'
        '0'
        #39#39)
      Options = [FirstPageHeader, LastPageFooter]
      Page.Columns = 1
      Page.Orientation = poPortrait
      Page.PaperSize = A4
      Page.Ruler = False
      Page.Values = (
        100
        2970
        100
        2100
        100
        100
        0)
      PrinterSettings.Copies = 1
      PrinterSettings.Duplex = False
      PrinterSettings.FirstPage = 0
      PrinterSettings.LastPage = 0
      PrinterSettings.OutputBin = Auto
      PrintIfEmpty = True
      ShowProgress = False
      SnapToGrid = False
      Units = MM
      Zoom = 10
    end
  end
  object TrackPersent: TTrackBar
    Left = 248
    Top = 212
    Width = 237
    Height = 25
    Max = 100
    Orientation = trHorizontal
    Frequency = 5
    Position = 10
    SelEnd = 0
    SelStart = 0
    TabOrder = 6
    ThumbLength = 10
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = TrackPersentChange
  end
  object FontBtn: TButton
    Left = 208
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Font'
    TabOrder = 9
    OnClick = FontBtnClick
  end
  object rsPropSaver1: TrsPropSaver
    Storage = MainForm.rsStorage1
    RootSection = 'QuickRepEditorForm'
    Properties.Strings = (
      'OrientationCombo.ItemIndex'
      'PaperTypeCombo.ItemIndex'
      'ButtomMarginEdit.Value'
      'LeftMarginEdit.Value'
      'LengthEdit.Value'
      'RigthMarginEdit.Value'
      'TopMarginEdit.Value'
      'WidthEdit.Value'
      'TrackPersent.Position'
      'QuickRep1.Zoom'
      'FontDialog.Font.Charset'
      'FontDialog.Font.Color'
      'FontDialog.Font.Height'
      'FontDialog.Font.Name'
      'FontDialog.Font.Pitch'
      'FontDialog.Font.Size'
      'FontDialog.Font.Style'
      'QuickRep1.Page.BottomMargin'
      'QuickRep1.Page.LeftMargin'
      'QuickRep1.Page.Length'
      'QuickRep1.Page.RightMargin'
      'QuickRep1.Page.TopMargin'
      'QuickRep1.Page.Width'
      'QuickRep1.Page.Orientation')
    WhenLoad = wlOnCreate
    WhenSave = wsManual
    Left = 188
    Top = 112
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Options = []
    Left = 156
    Top = 112
  end
end
