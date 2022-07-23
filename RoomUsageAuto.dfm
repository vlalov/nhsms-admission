object RoomUsageAutoForm: TRoomUsageAutoForm
  Left = 303
  Top = 187
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1098#1089#1090#1086#1103#1085#1080#1077' '#1085#1072' '#1089#1090#1072#1080#1090#1077
  ClientHeight = 363
  ClientWidth = 394
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  Icon.Data = {
    0000010001001010100001000400280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000008FFFFFFFFFFF00008AAAAAAAAAAF00008A
    AAAAAAAAAF00008AAAAAAAAAAF00008AAAAAAAAAAF00008AAAAAAAAAAF00008A
    AAAAAAAAAF00008AAAAAAAAAAF00008AAAAAAAAAAF00008AAAAAAAAAAF000082
    222222222F000080202020202F000088888888888F000000000000000000FFFF
    0000FFFF0000C0030000C0030000C0030000C0030000C0030000C0030000C003
    0000C0030000C0030000C0030000C0030000C0030000C0030000FFFF0000}
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 394
    Height = 332
    Align = alClient
    DataSource = RoomSourceSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgCancelOnExit]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Place'
        Title.Caption = #1057#1075#1088#1072#1076#1072
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Code'
        Title.Caption = #1050#1086#1076
        Width = 40
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Capacity'
        Title.Caption = #1050#1072#1087#1072#1094#1080#1090#1077#1090
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Allocated'
        Title.Caption = #1053#1072#1089#1090#1072#1085#1077#1085#1080
        Width = 60
        Visible = True
      end
      item
        Alignment = taRightJustify
        Expanded = False
        FieldName = 'Percent'
        Title.Alignment = taRightJustify
        Title.Caption = '%'
        Width = 35
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 332
    Width = 394
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 3
      Top = 8
      Width = 58
      Height = 13
      Caption = #1053#1072#1089#1090#1072#1085#1077#1085#1080':'
    end
    object Label2: TLabel
      Left = 107
      Top = 9
      Width = 56
      Height = 13
      Caption = #1050#1072#1087#1072#1094#1080#1090#1077#1090':'
    end
    object PercentGauge: TCGauge
      Left = 212
      Top = 8
      Width = 173
      Height = 17
      Progress = 97
    end
    object AllocatedText: TStaticText
      Left = 64
      Top = 8
      Width = 37
      Height = 17
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 0
    end
    object CapacityText: TStaticText
      Left = 168
      Top = 8
      Width = 37
      Height = 17
      AutoSize = False
      BorderStyle = sbsSunken
      TabOrder = 1
    end
  end
  object RoomsAllocatedQuery: TQuery
    OnCalcFields = RoomsAllocatedQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT rm.Place_ID,rm.Code,rm.Capacity,COUNT(pr.ID) Allocated FR' +
        'OM Rooms rm LEFT JOIN Persons pr ON rm.Code=pr.Room_Code'
      'GROUP BY rm.Place_ID,rm.Code,rm.Capacity'
      'ORDER BY rm.Place_ID')
    Left = 52
    Top = 172
    object RoomsAllocatedQueryPlace_ID: TIntegerField
      FieldName = 'Place_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Place_ID'
    end
    object RoomsAllocatedQueryPlace: TStringField
      FieldKind = fkLookup
      FieldName = 'Place'
      LookupDataSet = Data.PlacesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Place_ID'
      Size = 50
      Lookup = True
    end
    object RoomsAllocatedQueryCode: TStringField
      FieldName = 'Code'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Code'
      Size = 10
    end
    object RoomsAllocatedQueryCapacity: TIntegerField
      FieldName = 'Capacity'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Capacity'
    end
    object RoomsAllocatedQueryAllocated: TIntegerField
      FieldName = 'Allocated'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
    object RoomsAllocatedQueryPercent: TStringField
      FieldKind = fkCalculated
      FieldName = 'Percent'
      Size = 10
      Calculated = True
    end
  end
  object RoomSourceSource: TDataSource
    DataSet = RoomsAllocatedQuery
    Left = 52
    Top = 140
  end
  object Timer: TTimer
    Enabled = False
    Interval = 30000
    OnTimer = TimerTimer
    Left = 108
    Top = 140
  end
end
