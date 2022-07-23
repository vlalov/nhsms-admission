object CurrentReceptionResForm: TCurrentReceptionResForm
  Left = 86
  Top = 40
  Width = 734
  Height = 519
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object QuickRep1: TQuickRep
    Left = 0
    Top = 0
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    DataSet = DataQuery
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
    Page.Columns = 2
    Page.Orientation = poPortrait
    Page.PaperSize = A4
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
    ReportTitle = #1055#1088#1080#1077#1084' '#1085#1072' '#1053#1055#1052#1043' - '#1074#1098#1074#1077#1076#1077#1085#1080' '#1082#1072#1085#1076#1080#1076#1072#1090#1080
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object PageHeaderBand1: TQRBand
      Left = 38
      Top = 38
      Width = 718
      Height = 59
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        156.104166666667
        1899.70833333333)
      BandType = rbPageHeader
      object QRLabel1: TQRLabel
        Left = 10
        Top = 8
        Width = 698
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          50.2708333333333
          26.4583333333333
          21.1666666666667
          1846.79166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = False
        AutoStretch = False
        Caption = #1055#1088#1080#1077#1084' '#1085#1072' '#1053#1055#1052#1043' - '#1057#1087#1088#1072#1074#1082#1072' '#1079#1072' '#1090#1077#1082#1091#1097#1080#1090#1077' '#1090#1072#1082#1089#1080
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 12
      end
      object QRLabel7: TQRLabel
        Left = 8
        Top = 36
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          21.1666666666667
          95.25
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1044#1072#1090#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRSysData1: TQRSysData
        Left = 44
        Top = 36
        Width = 36
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          116.416666666667
          95.25
          95.25)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsDate
        Transparent = False
        FontSize = 10
      end
      object QRLabel10: TQRLabel
        Left = 156
        Top = 36
        Width = 58
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          412.75
          95.25
          153.458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1054#1087#1077#1088#1072#1090#1086#1088
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText5: TQRDBText
        Left = 220
        Top = 36
        Width = 48
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          582.083333333333
          95.25
          127)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery
        DataField = 'operator'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object ColumnHeaderBand1: TQRBand
      Left = 38
      Top = 97
      Width = 359
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = True
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        105.833333333333
        949.854166666667)
      BandType = rbColumnHeader
      object QRLabel2: TQRLabel
        Left = 27
        Top = 16
        Width = 15
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          71.4375
          42.3333333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #8470
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel3: TQRLabel
        Left = 48
        Top = 16
        Width = 26
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          127
          42.3333333333333
          68.7916666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1048#1084#1077
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel4: TQRLabel
        Left = 216
        Top = 16
        Width = 26
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          571.5
          42.3333333333333
          68.7916666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'E'#1043#1053
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel5: TQRLabel
        Left = 304
        Top = 16
        Width = 35
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          804.333333333333
          42.3333333333333
          92.6041666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1058#1072#1082#1089#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand1: TQRBand
      Left = 38
      Top = 137
      Width = 359
      Height = 24
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        63.5
        949.854166666667)
      BandType = rbDetail
      object QRDBText1: TQRDBText
        Left = 0
        Top = 4
        Width = 41
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          0
          10.5833333333333
          108.479166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery
        DataField = 'ID'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText2: TQRDBText
        Left = 48
        Top = 4
        Width = 35
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          127
          10.5833333333333
          92.6041666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery
        DataField = 'Name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText3: TQRDBText
        Left = 216
        Top = 4
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          571.5
          10.5833333333333
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery
        DataField = 'EGN'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr3: TQRExpr
        Left = 304
        Top = 4
        Width = 302
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          804.333333333333
          10.5833333333333
          799.041666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        Master = QuickRep1
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'CalcAllTaxQuery.AllTax - DeletedWishesQuery.CNT'
        FontSize = 10
      end
    end
    object SummaryBand1: TQRBand
      Left = 38
      Top = 161
      Width = 718
      Height = 32
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        84.6666666666667
        1899.70833333333)
      BandType = rbSummary
      object QRLabel6: TQRLabel
        Left = 4
        Top = 8
        Width = 41
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          10.5833333333333
          21.1666666666667
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1054#1073#1097#1086':'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr1: TQRExpr
        Left = 304
        Top = 8
        Width = 339
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          804.333333333333
          21.1666666666667
          896.9375)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        Master = QuickRep1
        ResetAfterPrint = False
        Transparent = False
        WordWrap = True
        Expression = 'SUM(CalcAllTaxQuery.AllTax - DeletedWishesQuery.CNT)'
        FontSize = 10
      end
      object QRExpr2: TQRExpr
        Left = 48
        Top = 8
        Width = 45
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          127
          21.1666666666667
          119.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'COUNT'
        FontSize = 10
      end
      object QRLabel9: TQRLabel
        Left = 264
        Top = 8
        Width = 37
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          698.5
          21.1666666666667
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1057#1091#1084#1072':'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object PageFooterBand1: TQRBand
      Left = 38
      Top = 193
      Width = 718
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        105.833333333333
        1899.70833333333)
      BandType = rbPageFooter
      object QRLabel8: TQRLabel
        Left = 616
        Top = 8
        Width = 57
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1629.83333333333
          21.1666666666667
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1057#1090#1088#1072#1085#1080#1094#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRSysData2: TQRSysData
        Left = 680
        Top = 8
        Width = 46
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1799.16666666667
          21.1666666666667
          121.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsPageNumber
        Transparent = False
        FontSize = 10
      end
    end
  end
  object QuickRep2: TQuickRep
    Left = 0
    Top = 1128
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    DataSet = DataQuery2
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
    Page.Columns = 2
    Page.Orientation = poPortrait
    Page.PaperSize = A4
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
    ReportTitle = #1055#1088#1080#1077#1084' '#1085#1072' '#1053#1055#1052#1043' - '#1074#1098#1074#1077#1076#1077#1085#1080' '#1082#1072#1085#1076#1080#1076#1072#1090#1080
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object QRBand1: TQRBand
      Left = 38
      Top = 38
      Width = 718
      Height = 59
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        156.104166666667
        1899.70833333333)
      BandType = rbPageHeader
      object QRLabel11: TQRLabel
        Left = 10
        Top = 8
        Width = 698
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          50.2708333333333
          26.4583333333333
          21.1666666666667
          1846.79166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = False
        AutoStretch = False
        Caption = #1055#1088#1080#1077#1084' '#1085#1072' '#1053#1055#1052#1043' - '#1057#1087#1088#1072#1074#1082#1072' '#1079#1072' '#1090#1072#1082#1089#1080#1090#1077' '#1085#1072' '#1086#1087#1077#1088#1072#1090#1086#1088
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 12
      end
      object QRLabel12: TQRLabel
        Left = 8
        Top = 36
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          21.1666666666667
          95.25
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1044#1072#1090#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRSysData3: TQRSysData
        Left = 44
        Top = 36
        Width = 36
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          116.416666666667
          95.25
          95.25)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsDate
        Transparent = False
        FontSize = 10
      end
      object QRLabel13: TQRLabel
        Left = 156
        Top = 36
        Width = 58
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          412.75
          95.25
          153.458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1054#1087#1077#1088#1072#1090#1086#1088
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object OperatorShow: TQRLabel
        Left = 220
        Top = 36
        Width = 122
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          582.083333333333
          95.25
          322.791666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '< error in operation >'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRBand2: TQRBand
      Left = 38
      Top = 97
      Width = 359
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = True
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        105.833333333333
        949.854166666667)
      BandType = rbColumnHeader
      object QRLabel14: TQRLabel
        Left = 23
        Top = 16
        Width = 15
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          60.8541666666667
          42.3333333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #8470
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel15: TQRLabel
        Left = 44
        Top = 16
        Width = 26
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          116.416666666667
          42.3333333333333
          68.7916666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1048#1084#1077
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel16: TQRLabel
        Left = 224
        Top = 16
        Width = 26
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          592.666666666667
          42.3333333333333
          68.7916666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'E'#1043#1053
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel17: TQRLabel
        Left = 312
        Top = 16
        Width = 35
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          825.5
          42.3333333333333
          92.6041666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1058#1072#1082#1089#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRBand3: TQRBand
      Left = 38
      Top = 137
      Width = 359
      Height = 24
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        63.5
        949.854166666667)
      BandType = rbDetail
      object QRDBText6: TQRDBText
        Left = 0
        Top = 4
        Width = 37
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          0
          10.5833333333333
          97.8958333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery2
        DataField = 'ID'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText7: TQRDBText
        Left = 44
        Top = 4
        Width = 35
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          116.416666666667
          10.5833333333333
          92.6041666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery2
        DataField = 'Name'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText8: TQRDBText
        Left = 224
        Top = 4
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          592.666666666667
          10.5833333333333
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = DataQuery2
        DataField = 'EGN'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr4: TQRExpr
        Left = 312
        Top = 4
        Width = 316
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          825.5
          10.5833333333333
          836.083333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        Master = QuickRep2
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'CalcAllTaxQuery2.AllTax - DeletedWishesQuery2.CNT'
        FontSize = 10
      end
    end
    object QRBand4: TQRBand
      Left = 38
      Top = 161
      Width = 718
      Height = 32
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        84.6666666666667
        1899.70833333333)
      BandType = rbSummary
      object QRLabel18: TQRLabel
        Left = 4
        Top = 8
        Width = 41
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          10.5833333333333
          21.1666666666667
          108.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1054#1073#1097#1086':'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr5: TQRExpr
        Left = 304
        Top = 8
        Width = 353
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          804.333333333333
          21.1666666666667
          933.979166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        Master = QuickRep2
        ResetAfterPrint = False
        Transparent = False
        WordWrap = True
        Expression = 'SUM(CalcAllTaxQuery2.AllTax - DeletedWishesQuery2.CNT)'
        FontSize = 10
      end
      object QRExpr6: TQRExpr
        Left = 48
        Top = 8
        Width = 45
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          127
          21.1666666666667
          119.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'COUNT'
        FontSize = 10
      end
      object QRLabel19: TQRLabel
        Left = 264
        Top = 8
        Width = 37
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          698.5
          21.1666666666667
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1057#1091#1084#1072':'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRBand5: TQRBand
      Left = 38
      Top = 193
      Width = 718
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        105.833333333333
        1899.70833333333)
      BandType = rbPageFooter
      object QRLabel20: TQRLabel
        Left = 616
        Top = 8
        Width = 57
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1629.83333333333
          21.1666666666667
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #1057#1090#1088#1072#1085#1080#1094#1072
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRSysData4: TQRSysData
        Left = 680
        Top = 8
        Width = 8
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1799.16666666667
          21.1666666666667
          21.1666666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsPageNumber
        Transparent = False
        FontSize = 10
      end
    end
  end
  object DataQuery: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT p.*,CONVERT(varchar(50),current_user) operator '
      'FROM persons p FULL OUTER JOIN Wishes w ON p.id=w.person_id'
      
        'WHERE (DATEDIFF(d,p.EntOn,getdate())=0 AND p.EntBy=user_name()) ' +
        'OR'
      #9'(DATEDIFF(d,w.EntOn,getdate())=0 AND w.EntBy=user_name()) OR'
      'EXISTS (SELECT * FROM Wishes_Deleted wd '
      #9'WHERE wd.Person_ID=p.ID AND DATEDIFF(d,wd.DelOn,getdate())=0 '
      #9#9'AND DelBy=user_name() AND wd.GoToExam=1)')
    Left = 12
    Top = 292
    object DataQueryID: TIntegerField
      FieldName = 'ID'
    end
    object DataQueryName: TStringField
      FieldName = 'Name'
      Size = 200
    end
    object DataQueryEGN: TStringField
      FieldName = 'EGN'
      Size = 10
    end
    object DataQueryTax_id: TIntegerField
      FieldName = 'Tax_id'
    end
    object DataQueryoperator: TStringField
      FieldName = 'operator'
      Size = 255
    end
    object DataQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
    end
    object DataQueryEntBy: TStringField
      FieldName = 'EntBy'
      Size = 50
    end
  end
  object CalcAllTaxQuery: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = DataSource
    SQL.Strings = (
      'SELECT p.id,AllTax='
      '    CASE '
      
        '      WHEN DATEDIFF(d,p.EntOn,getdate())=0 AND p.EntBy=user_name' +
        '()'
      '      THEN (count(w.priority)+1)*tax.value'
      '      ELSE (count(w.priority))*tax.value'
      '    END'
      
        'FROM persons p FULL OUTER JOIN wishes w ON p.id=w.person_id AND ' +
        'DATEDIFF(d,w.EntOn,getdate())=0 AND w.EntBy=user_name()'
      #9'AND w.GoToExam=1,taxes tax'
      'WHERE p.tax_id=tax.id AND p.id=:ID'
      'GROUP BY p.id,tax.value,p.EntOn,p.EntBy')
    Left = 116
    Top = 292
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        ParamType = ptUnknown
      end>
    object CalcAllTaxQueryid: TIntegerField
      FieldName = 'id'
    end
    object CalcAllTaxQueryAllTax: TFloatField
      FieldName = 'AllTax'
    end
  end
  object DataSource: TDataSource
    DataSet = DataQuery
    Left = 12
    Top = 260
  end
  object DeletedWishesQuery: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = DataSource
    SQL.Strings = (
      'SELECT COUNT(*)*tax.value CNT FROM Wishes_Deleted wd,'
      
        #9'(SELECT p.id,taxes.value FROM Persons p,Taxes taxes WHERE p.tax' +
        '_id=taxes.id AND p.id=:ID) tax  '
      'WHERE wd.Person_ID=:ID AND wd.GoToExam=1 '
      ' '#9'AND DATEDIFF(d,wd.DelOn,getdate())=0 AND wd.DelBy=user_name() '
      #9'AND NOT(wd.DelBy=:EntBy AND DATEDIFF(d,wd.DelOn,:EntOn)=0)'
      'GROUP BY tax.value')
    Left = 152
    Top = 292
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EntBy'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EntOn'
        ParamType = ptUnknown
      end>
    object DeletedWishesQueryCNT: TFloatField
      FieldName = 'CNT'
    end
  end
  object DataSource1: TDataSource
    DataSet = DataQuery2
    Left = 8
    Top = 376
  end
  object DataQuery2: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT p.*,CONVERT(varchar(50),:SET_USERNAME) operator '
      'FROM persons p FULL OUTER JOIN Wishes w ON p.id=w.person_id'
      
        'WHERE (DATEDIFF(d,p.EntOn,:SET_DATE)=0 AND p.EntBy=:SET_USERNAME' +
        ') OR'
      #9'(DATEDIFF(d,w.EntOn,:SET_DATE)=0 AND w.EntBy=:SET_USERNAME) OR'
      'EXISTS (SELECT * FROM Wishes_Deleted wd '
      #9'WHERE wd.Person_ID=p.ID AND DATEDIFF(d,wd.DelOn,:SET_DATE)=0 '
      #9#9'AND DelBy=:SET_USERNAME AND wd.GoToExam=1)')
    Left = 8
    Top = 408
    ParamData = <
      item
        DataType = ftString
        Name = 'SET_USERNAME'
        ParamType = ptUnknown
        Value = 'dbo'
      end
      item
        DataType = ftDateTime
        Name = 'SET_DATE'
        ParamType = ptUnknown
        Value = 37801d
      end
      item
        DataType = ftString
        Name = 'SET_USERNAME'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'SET_DATE'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SET_USERNAME'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'SET_DATE'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SET_USERNAME'
        ParamType = ptUnknown
      end>
    object IntegerField1: TIntegerField
      FieldName = 'ID'
    end
    object StringField1: TStringField
      FieldName = 'Name'
      Size = 200
    end
    object StringField2: TStringField
      FieldName = 'EGN'
      Size = 10
    end
    object IntegerField2: TIntegerField
      FieldName = 'Tax_id'
    end
    object StringField3: TStringField
      FieldName = 'operator'
      Size = 255
    end
    object DateTimeField1: TDateTimeField
      FieldName = 'EntOn'
    end
    object StringField4: TStringField
      FieldName = 'EntBy'
      Size = 50
    end
  end
  object CalcAllTaxQuery2: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = DataSource1
    SQL.Strings = (
      'SELECT p.id,AllTax='
      '    CASE '
      
        '      WHEN DATEDIFF(d,p.EntOn,:SET_DATETIME)=0 AND p.EntBy=:SET_' +
        'USER'
      '      THEN (count(w.priority)+1)*tax.value'
      '      ELSE (count(w.priority))*tax.value'
      '    END'
      
        'FROM persons p FULL OUTER JOIN wishes w ON p.id=w.person_id AND ' +
        'DATEDIFF(d,w.EntOn,:SET_DATETIME)=0 AND w.EntBy=:SET_USER'
      #9'AND w.GoToExam=1,taxes tax'
      'WHERE p.tax_id=tax.id AND p.id=:ID'
      'GROUP BY p.id,tax.value,p.EntOn,p.EntBy')
    Left = 112
    Top = 408
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'SET_DATETIME'
        ParamType = ptUnknown
        Value = 37801d
      end
      item
        DataType = ftString
        Name = 'SET_USER'
        ParamType = ptUnknown
        Value = 'dbo'
      end
      item
        DataType = ftDateTime
        Name = 'SET_DATETIME'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SET_USER'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end>
    object IntegerField3: TIntegerField
      FieldName = 'id'
    end
    object FloatField1: TFloatField
      FieldName = 'AllTax'
    end
  end
  object DeletedWishesQuery2: TQuery
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = DataSource1
    SQL.Strings = (
      'SELECT COUNT(*)*tax.value CNT FROM Wishes_Deleted wd,'
      
        #9'(SELECT p.id,taxes.value FROM Persons p,Taxes taxes WHERE p.tax' +
        '_id=taxes.id AND p.id=:ID) tax  '
      'WHERE wd.Person_ID=:ID AND wd.GoToExam=1 '
      ' '#9'AND DATEDIFF(d,wd.DelOn,:SET_DATE)=0 AND wd.DelBy=:SET_USER'
      #9'AND NOT(wd.DelBy=:EntBy AND DATEDIFF(d,wd.DelOn,:EntOn)=0)'
      'GROUP BY tax.value')
    Left = 152
    Top = 408
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'SET_DATE'
        ParamType = ptUnknown
        Value = 37801d
      end
      item
        DataType = ftString
        Name = 'SET_USER'
        ParamType = ptUnknown
        Value = 'dbo'
      end
      item
        DataType = ftUnknown
        Name = 'EntBy'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EntOn'
        ParamType = ptUnknown
      end>
    object FloatField2: TFloatField
      FieldName = 'CNT'
    end
  end
end
