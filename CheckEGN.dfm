object CheckEGNForm: TCheckEGNForm
  Left = 211
  Top = 107
  Width = 431
  Height = 248
  Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1079#1072' '#1075#1088#1077#1096#1082#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000009999999999999990990000090000099099000099900009909900
    0999900009909900999999000990990999999900099099999999999009909909
    9990999009909900990009990990990000000099000099000000000990009999
    999999909900999999999990099000000000000000090000000000000000FFFF
    0000000100003EF900003C790000387900003039000020390000001900002119
    0000338900003FCF00003FE700000013000000190000FFFE0000FFFF0000}
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 192
    Width = 423
    Height = 29
    HelpContext = 13
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      423
      29)
    object SaveBtn: TBitBtn
      Left = 132
      Top = 2
      Width = 76
      Height = 26
      HelpContext = 13
      Anchors = []
      Caption = #1047#1072#1087#1080#1089
      ModalResult = 8
      TabOrder = 0
      OnClick = SaveBtnClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFF00000000000000FF03300000088030FF03300000088030FF03300000088
        030FF03300000000030FF03333333333330FF03300000000330FF03088888888
        030FF03088888888030FF03088888888030FF03088888888030FF03088888888
        000FF03088888888080FF00000000000000FFFFFFFFFFFFFFFFF}
    end
    object BitBtn2: TBitBtn
      Left = 212
      Top = 2
      Width = 76
      Height = 26
      HelpContext = 13
      Anchors = []
      Cancel = True
      Caption = #1054#1090#1082#1072#1079
      Default = True
      ModalResult = 2
      TabOrder = 1
      OnClick = BitBtn1Click
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
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 423
    Height = 192
    HelpContext = 13
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 1
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #1043#1088#1077#1096#1085#1086' '#1045#1043#1053
      object ListBox: TListBox
        Left = 0
        Top = 0
        Width = 415
        Height = 164
        HelpContext = 13
        AutoComplete = False
        Align = alClient
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 14
        MultiSelect = True
        ParentFont = False
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1086#1074#1090#1072#1088#1103#1097#1086' '#1089#1077' '#1080#1084#1077
      ImageIndex = 1
      object ListNames: TListBox
        Left = 0
        Top = 0
        Width = 415
        Height = 164
        HelpContext = 13
        AutoComplete = False
        Align = alClient
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 14
        MultiSelect = True
        ParentFont = False
        TabOrder = 0
      end
    end
  end
  object PersonQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Persons ORDER BY ID')
    Left = 144
    Top = 64
    object PersonQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'CHECKEGNDATABASE.Persons.ID'
    end
    object PersonQueryName: TStringField
      FieldName = 'Name'
      Origin = 'CHECKEGNDATABASE.Persons.Name'
      Size = 200
    end
    object PersonQueryEGN: TStringField
      FieldName = 'EGN'
      Origin = 'CHECKEGNDATABASE.Persons.EGN'
      Size = 10
    end
    object PersonQueryTelephone: TStringField
      FieldName = 'Telephone'
      Origin = 'CHECKEGNDATABASE.Persons.Telephone'
      Size = 50
    end
    object PersonQueryAddress: TStringField
      FieldName = 'Address'
      Origin = 'CHECKEGNDATABASE.Persons.Address'
      Size = 200
    end
    object PersonQuerySex: TIntegerField
      FieldName = 'Sex'
      Origin = 'CHECKEGNDATABASE.Persons.Sex'
    end
    object PersonQueryTax_id: TIntegerField
      FieldName = 'Tax_id'
      Origin = 'CHECKEGNDATABASE.Persons.Tax_id'
    end
    object PersonQueryRoom_Code: TStringField
      FieldName = 'Room_Code'
      Origin = 'CHECKEGNDATABASE.Persons.Room_Code'
      Size = 10
    end
    object PersonQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'CHECKEGNDATABASE.Persons.EntOn'
    end
    object PersonQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'CHECKEGNDATABASE.Persons.EntBy'
      Size = 50
    end
  end
  object EqualNamesQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT p1.ID ID1,p2.ID ID2 FROM Persons p1 LEFT OUTER JOIN Perso' +
        'ns p2'
      'ON p1.Name=p2.Name WHERE p1.ID!=p2.ID')
    Left = 36
    Top = 124
    object EqualNamesQueryID1: TIntegerField
      FieldName = 'ID1'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
    object EqualNamesQueryID2: TIntegerField
      FieldName = 'ID2'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1080' '#1092#1072#1081#1083#1086#1074#1077'(*.txt)|*.txt|'#1042#1089#1080#1095#1082#1080' '#1092#1072#1081#1083#1086#1074#1077'(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 144
    Top = 108
  end
end
