object RoomsUsageGraphForm: TRoomsUsageGraphForm
  Left = 240
  Top = 103
  Width = 508
  Height = 342
  Caption = #1057#1098#1089#1090#1086#1103#1085#1080#1077' '#1085#1072' '#1089#1090#1072#1080#1090#1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object DecisionGraph1: TDecisionGraph
    Left = 0
    Top = 0
    Width = 500
    Height = 315
    DecisionSource = DecisionSource1
    Title.Text.Strings = (
      #1057#1098#1089#1090#1086#1103#1085#1080#1077' '#1085#1072' '#1089#1090#1072#1080#1090#1077)
    Align = alClient
    TabOrder = 0
    object Series1: TBarSeries
      Active = False
      Marks.ArrowLength = 20
      Marks.Visible = False
      SeriesColor = clRed
      Title = 'Template: '#1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Bar'
      YValues.Multiplier = 1
      YValues.Order = loNone
      Identifier = 'Template: '#1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
      Style = 61
    end
    object Series2: TBarSeries
      Active = False
      ColorEachPoint = True
      Marks.ArrowLength = 20
      Marks.Visible = False
      SeriesColor = clRed
      Title = '1D Template: '#1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Bar'
      YValues.Multiplier = 1
      YValues.Order = loNone
      Identifier = '1D Template: '#1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
      Style = 40
    end
  end
  object RoomsAllocatedQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT rm.Code,(rm.Capacity-COUNT(pr.ID)) Persent '
      'FROM Rooms rm LEFT JOIN Persons pr ON rm.Code=pr.Room_Code'
      'GROUP BY rm.Code,rm.Capacity')
    Left = 48
    Top = 172
    object RoomsAllocatedQueryCode: TStringField
      FieldName = 'Code'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Code'
      Size = 10
    end
    object RoomsAllocatedQueryPersent: TIntegerField
      FieldName = 'Persent'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Capacity'
    end
  end
  object DecisionCube1: TDecisionCube
    DataSet = RoomsAllocatedQuery
    DimensionMap = <
      item
        ActiveFlag = diAsNeeded
        FieldType = ftString
        Fieldname = 'Code'
        BaseName = 'rm.Code'
        Name = #1050#1086#1076' '#1085#1072' '#1089#1090#1072#1103#1090#1072
        DerivedFrom = -1
        DimensionType = dimDimension
        BinType = binNone
        ValueCount = 0
        Active = True
      end
      item
        ActiveFlag = diAsNeeded
        FieldType = ftInteger
        Fieldname = 'Persent'
        BaseName = ' (Capacity - COUNT( ID )) '
        Name = #1057#1074#1086#1073#1086#1076#1085#1080' '#1084#1077#1089#1090#1072
        DerivedFrom = -1
        DimensionType = dimGenericAgg
        BinType = binNone
        ValueCount = -1
        Active = True
      end>
    ShowProgressDialog = False
    MaxDimensions = 5
    MaxSummaries = 10
    MaxCells = 0
    Left = 116
    Top = 144
  end
  object DecisionSource1: TDecisionSource
    DecisionCube = DecisionCube1
    ControlType = xtCheck
    SparseRows = False
    SparseCols = False
    Left = 116
    Top = 176
    DimensionCount = 1
    SummaryCount = 1
    CurrentSummary = 0
    SparseRows = False
    SparseCols = False
    DimensionInfo = (
      2
      0
      1
      0
      -1)
  end
end
