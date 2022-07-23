object ExamStatsGraphForm: TExamStatsGraphForm
  Left = 238
  Top = 106
  Width = 696
  Height = 556
  Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1079#1072' '#1088#1077#1079#1091#1083#1090#1072#1090#1080' '#1086#1090' '#1080#1079#1087#1080#1090#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 688
    Height = 529
    ActivePage = ScoreTab
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object ScoreTab: TTabSheet
      Caption = 'ScoreTab'
      object ScoreDecisionGraph: TDecisionGraph
        Left = 0
        Top = 0
        Width = 680
        Height = 501
        DecisionSource = ScoreDecisionSource
        Title.Text.Strings = (
          #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1079#1072' '#1088#1077#1079#1091#1083#1090#1072#1090#1080' '#1086#1090' '#1080#1079#1087#1080#1090#1080' ('#1054#1094#1077#1085#1082#1072')')
        Legend.Font.Charset = DEFAULT_CHARSET
        Legend.Font.Color = clBlack
        Legend.Font.Height = -9
        Legend.Font.Name = 'Arial'
        Legend.Font.Style = []
        Legend.ShadowSize = 2
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        object Series1: TBarSeries
          Active = False
          Marks.ArrowLength = 20
          Marks.Style = smsLabelValue
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Template: '#1054#1094#1077#1085#1082#1072
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
          Identifier = 'Template: '#1054#1094#1077#1085#1082#1072
          Style = 61
        end
        object Series2: TBarSeries
          Active = False
          ColorEachPoint = True
          Marks.ArrowLength = 20
          Marks.Style = smsLabelValue
          Marks.Visible = False
          SeriesColor = clRed
          Title = '1D Template: '#1054#1094#1077#1085#1082#1072
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
          Identifier = '1D Template: '#1054#1094#1077#1085#1082#1072
          Style = 40
        end
      end
    end
    object PointsTab: TTabSheet
      Caption = 'PointsTab'
      ImageIndex = 1
      object PointsDecisionGraph: TDecisionGraph
        Left = 0
        Top = 0
        Width = 680
        Height = 501
        DecisionSource = PoinsDecisionSource
        Title.Text.Strings = (
          #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1079#1072' '#1088#1077#1079#1091#1083#1090#1072#1090#1080' '#1086#1090' '#1080#1079#1087#1080#1090#1080' ('#1058#1086#1095#1082#1080')')
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        object BarSeries1: TBarSeries
          Active = False
          Marks.ArrowLength = 20
          Marks.Style = smsLabelValue
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Template: '#1054#1094#1077#1085#1082#1072
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
          Identifier = 'Template: '#1054#1094#1077#1085#1082#1072
          Style = 61
        end
        object BarSeries2: TBarSeries
          Active = False
          ColorEachPoint = True
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clRed
          Title = '1D Template: '#1054#1094#1077#1085#1082#1072
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
          Identifier = '1D Template: '#1054#1094#1077#1085#1082#1072
          Style = 40
        end
      end
    end
  end
  object ScoreDecisionSource: TDecisionSource
    DecisionCube = ScoreDecisionCube
    ControlType = xtCheck
    SparseRows = False
    SparseCols = False
    Left = 168
    Top = 84
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
  object ScoreDecisionCube: TDecisionCube
    DataSet = ExamStatisticsResForm.ParseScoreQuery
    DimensionMap = <
      item
        ActiveFlag = diAsNeeded
        FieldType = ftFloat
        Fieldname = 'Score'
        BaseName = 'pts.Score'
        Name = #1054#1094#1077#1085#1082#1072
        DerivedFrom = -1
        DimensionType = dimDimension
        BinType = binNone
        ValueCount = 61
        Active = True
      end
      item
        ActiveFlag = diAsNeeded
        FieldType = ftInteger
        Fieldname = 'Pers'
        BaseName = 'er.ID'
        Name = #1041#1088#1086#1081
        DerivedFrom = -1
        DimensionType = dimCount
        BinType = binNone
        ValueCount = -1
        Active = True
      end>
    ShowProgressDialog = True
    MaxDimensions = 5
    MaxSummaries = 10
    MaxCells = 0
    Left = 168
    Top = 52
  end
  object PointsDecisionCube: TDecisionCube
    DataSet = ExamStatisticsResForm.ParsePointsQuery
    DimensionMap = <
      item
        ActiveFlag = diAsNeeded
        FieldType = ftFloat
        Fieldname = 'Point'
        BaseName = 'pts.Point'
        Name = #1058#1086#1095#1082#1080
        DerivedFrom = -1
        DimensionType = dimDimension
        BinType = binNone
        ValueCount = -1
        Active = True
      end
      item
        ActiveFlag = diAsNeeded
        FieldType = ftInteger
        Fieldname = 'Pers'
        BaseName = 'er.ID'
        Name = #1041#1088#1086#1081
        DerivedFrom = -1
        DimensionType = dimCount
        BinType = binNone
        ValueCount = -1
        Active = True
      end>
    ShowProgressDialog = True
    MaxDimensions = 5
    MaxSummaries = 10
    MaxCells = 0
    Left = 248
    Top = 56
  end
  object PoinsDecisionSource: TDecisionSource
    DecisionCube = PointsDecisionCube
    ControlType = xtCheck
    SparseRows = False
    SparseCols = False
    Left = 248
    Top = 84
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
