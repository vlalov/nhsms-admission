object RoomChooserForm: TRoomChooserForm
  Left = 306
  Top = 255
  HelpContext = 17
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1088#1086#1090#1086#1082#1086#1083' '#1079#1072' '#1089#1090#1072#1103
  ClientHeight = 93
  ClientWidth = 274
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
    0000000000000788888888888000078080808888800007F888888888800007F0
    F0888888800007FFFF888888800007F0F0808080800007FFFFFF8888800007F0
    F0F0F888800007FFFFFFFF88800007F0F0F0F088800007FFFFFFFFF8800007F0
    F0F0FF00000007FFFFFFFF7F000007FFFFFFFF70000007777777777000008003
    0000800300008003000080030000800300008003000080030000800300008003
    00008003000080030000800300008003000080070000800F0000801F0000}
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 8
    Width = 71
    Height = 13
    Caption = #1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
  end
  object RoomLookup: TDBLookupComboBox
    Left = 80
    Top = 5
    Width = 65
    Height = 21
    HelpContext = 17
    KeyField = 'Code'
    ListField = 'Code'
    ListSource = PlaceSource
    TabOrder = 0
  end
  object OKBtn: TBitBtn
    Left = 195
    Top = 4
    Width = 75
    Height = 25
    HelpContext = 17
    TabOrder = 1
    OnClick = OKBtnClick
    Kind = bkOK
  end
  object SaveBtn: TBitBtn
    Left = 195
    Top = 32
    Width = 75
    Height = 25
    HelpContext = 17
    Cancel = True
    Caption = #1047#1072#1087#1080#1089
    ModalResult = 2
    TabOrder = 2
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
  object DBEdit1: TDBEdit
    Left = 4
    Top = 36
    Width = 185
    Height = 21
    HelpContext = 17
    Color = clBtnFace
    DataField = 'Name'
    DataSource = PlaceSource
    ReadOnly = True
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 195
    Top = 60
    Width = 75
    Height = 25
    HelpContext = 17
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
  object PlaceQuery: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT rm.Code,Pl.Name FROM Rooms rm,Places Pl WHERE Pl.ID=rm.Pl' +
        'ace_ID')
    Left = 124
    Top = 28
    object PlaceQueryCode: TStringField
      FieldName = 'Code'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Code'
      Size = 10
    end
    object PlaceQueryName: TStringField
      FieldName = 'Name'
      Origin = 'RECEPTIONDATABASE."dbo.Places".Name'
      Size = 100
    end
  end
  object PlaceSource: TDataSource
    DataSet = PlaceQuery
    Left = 124
    Top = 56
  end
  object SaveDialogCSV: TSaveDialog
    DefaultExt = 'csv'
    Filter = 
      'CSV '#1092#1072#1081#1083#1086#1074#1077'(*.CSV)|*.CSV|TXT '#1092#1072#1081#1083#1086#1074#1077'(*.TXT)|*.TXT|'#1042#1089#1080#1095#1082#1080' '#1092#1072#1081#1083#1086#1074#1077 +
      '(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 8
    Top = 8
  end
end
