object ReceptionMapForm: TReceptionMapForm
  Left = 220
  Top = 153
  Width = 694
  Height = 457
  Caption = #1050#1072#1088#1090#1072' '#1085#1072' '#1087#1088#1080#1077#1084#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100001000400280100001600000028000000100000002000
    0000010004000000000080000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    000000000000000000000000000000888888888888000F000000000000800F02
    0020020020800F022222222220800F0F00200FFF20800F02F020F200F0800F02
    F222F22220800F020FFF020020800F020020020020800F022222222220800F00
    0000000000800FFFFFFFFFFFFF0000000000000000000000000000000000FFFF
    0000800100000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000080010000FFFF0000}
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnActivate = FormActivate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 686
    Height = 229
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      686
      229)
    object GroupBox1: TGroupBox
      Left = 4
      Top = 0
      Width = 257
      Height = 225
      Caption = #1044#1072#1085#1085#1080' '#1085#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
      TabOrder = 0
      object Label1: TLabel
        Left = 10
        Top = 20
        Width = 29
        Height = 13
        Caption = #1042#1093'. '#8470
      end
      object Label2: TLabel
        Left = 17
        Top = 43
        Width = 22
        Height = 13
        Caption = #1048#1084#1077
      end
      object Label3: TLabel
        Left = 18
        Top = 88
        Width = 21
        Height = 13
        Caption = #1045#1043#1053
      end
      object Label4: TLabel
        Left = 8
        Top = 134
        Width = 31
        Height = 13
        Caption = #1040#1076#1088#1077#1089
      end
      object Label5: TLabel
        Left = 108
        Top = 20
        Width = 20
        Height = 13
        Caption = #1055#1086#1083
      end
      object Label6: TLabel
        Left = 17
        Top = 159
        Width = 22
        Height = 13
        Caption = #1058#1077#1083'.'
      end
      object DBText1: TDBText
        Left = 136
        Top = 20
        Width = 57
        Height = 17
        DataField = 'Se'
        DataSource = PersonSource
      end
      object Label7: TLabel
        Left = 9
        Top = 183
        Width = 64
        Height = 13
        Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
      end
      object Label8: TLabel
        Left = 137
        Top = 183
        Width = 65
        Height = 13
        Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
      end
      object Label9: TLabel
        Left = 158
        Top = 112
        Width = 24
        Height = 13
        Caption = #1057#1090#1072#1103
      end
      object Label10: TLabel
        Left = 9
        Top = 112
        Width = 31
        Height = 13
        Caption = #1058#1072#1082#1089#1072
      end
      object DBText2: TDBText
        Left = 156
        Top = 88
        Width = 93
        Height = 17
        DataField = 'ValidEGN'
        DataSource = PersonSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object IDEdit: TCSpinEdit
        Left = 44
        Top = 16
        Width = 57
        Height = 22
        MaxValue = 214000
        MinValue = 1
        TabOrder = 0
        Value = 1
        OnChange = IDEditChange
      end
      object DBEdit1: TDBEdit
        Left = 44
        Top = 40
        Width = 205
        Height = 21
        Color = clBtnFace
        DataField = 'Name'
        DataSource = PersonSource
        TabOrder = 1
      end
      object DBEdit2: TDBEdit
        Left = 44
        Top = 84
        Width = 105
        Height = 21
        Color = clBtnFace
        DataField = 'EGN'
        DataSource = PersonSource
        TabOrder = 3
      end
      object DBEdit3: TDBEdit
        Left = 44
        Top = 132
        Width = 205
        Height = 21
        Color = clBtnFace
        DataField = 'Address'
        DataSource = PersonSource
        TabOrder = 6
      end
      object DBEdit4: TDBEdit
        Left = 44
        Top = 156
        Width = 205
        Height = 21
        Color = clBtnFace
        DataField = 'Telephone'
        DataSource = PersonSource
        TabOrder = 7
      end
      object DBEdit5: TDBEdit
        Left = 8
        Top = 200
        Width = 121
        Height = 21
        Color = clBtnFace
        DataField = 'EntBy'
        DataSource = PersonSource
        TabOrder = 8
      end
      object DBEdit6: TDBEdit
        Left = 136
        Top = 200
        Width = 113
        Height = 21
        Color = clBtnFace
        DataField = 'EntOn'
        DataSource = PersonSource
        TabOrder = 9
      end
      object DBEdit7: TDBEdit
        Left = 188
        Top = 108
        Width = 61
        Height = 21
        Color = clBtnFace
        DataField = 'Room_Code'
        DataSource = PersonSource
        TabOrder = 5
      end
      object DBEdit8: TDBEdit
        Left = 44
        Top = 108
        Width = 105
        Height = 21
        Color = clBtnFace
        DataField = 'Tax'
        DataSource = PersonSource
        TabOrder = 4
      end
      object DBCheckBox1: TDBCheckBox
        Left = 44
        Top = 64
        Width = 113
        Height = 17
        Caption = #1087#1088#1077#1076#1087#1086#1095#1080#1090#1072' '#1053#1055#1052#1043
        DataField = 'PreferedSchool'
        DataSource = PersonSource
        ReadOnly = True
        TabOrder = 2
        ValueChecked = 'True'
        ValueUnchecked = 'False'
      end
    end
    object GroupBox2: TGroupBox
      Left = 264
      Top = 0
      Width = 420
      Height = 225
      Anchors = [akLeft, akTop, akRight]
      Caption = #1046#1077#1083#1072#1085#1080#1103
      TabOrder = 1
      object WishesGrid: TDBGrid
        Left = 2
        Top = 15
        Width = 416
        Height = 208
        Align = alClient
        DataSource = WishesSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = [fsBold]
        Columns = <
          item
            Expanded = False
            FieldName = 'Priority'
            Title.Caption = #8470
            Width = 20
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Profile'
            Title.Caption = #1055#1088#1086#1092#1080#1083
            Width = 140
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Score'
            Title.Caption = #1054#1094#1077#1085#1082#1072
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'OlympScore'
            Title.Caption = #1054#1094#1077#1085#1082#1072'('#1086#1083'.)'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'GoToExam'
            Title.Caption = #1053#1072' '#1080#1079#1087'.'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntBy'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
            Width = 130
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntOn'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
            Width = 120
            Visible = True
          end>
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 229
    Width = 686
    Height = 194
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Splitter1: TSplitter
      Left = 329
      Top = 0
      Width = 3
      Height = 194
      Cursor = crHSplit
    end
    object GroupBox3: TGroupBox
      Left = 0
      Top = 0
      Width = 329
      Height = 194
      Align = alLeft
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = #1048#1079#1087#1080#1090#1080
      Constraints.MaxWidth = 329
      TabOrder = 0
      object ExamsGrid: TDBGrid
        Left = 2
        Top = 15
        Width = 325
        Height = 177
        Align = alClient
        Constraints.MaxWidth = 325
        Constraints.MinWidth = 310
        DataSource = ExamsSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = [fsBold]
        Columns = <
          item
            Expanded = False
            FieldName = 'ID'
            Title.Caption = #1060#1082'. '#8470
            Width = 45
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Exa'
            Title.Caption = #1048#1079#1087#1080#1090
            Width = 140
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Score'
            Title.Caption = #1054#1094#1077#1085#1082#1072
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Points'
            Title.Caption = #1058#1086#1095#1082#1080
            Visible = True
          end>
      end
    end
    object GroupBox4: TGroupBox
      Left = 332
      Top = 0
      Width = 354
      Height = 194
      Align = alClient
      Caption = #1050#1083#1072#1089#1080#1088#1072#1085#1077
      TabOrder = 1
      object ClassificateGrid: TDBGrid
        Left = 2
        Top = 15
        Width = 350
        Height = 177
        Align = alClient
        DataSource = ClassificateSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = [fsBold]
        Columns = <
          item
            Expanded = False
            FieldName = 'Priority'
            Title.Caption = #8470
            Width = 20
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'Classificated'
            Title.Caption = #1055#1088#1080#1077#1090
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Status'
            Title.Caption = #1052#1103#1089#1090#1086
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Profile'
            Title.Caption = #1055#1088#1086#1092#1080#1083
            Width = 120
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Amount'
            Title.Caption = #1041#1040#1051
            Width = 40
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'IsInExt'
            Title.Caption = #1047#1072#1087#1080#1089#1072#1085
            Visible = True
          end>
      end
    end
  end
  object PersonQuery: TQuery
    OnCalcFields = PersonQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Persons ORDER BY ID')
    Left = 108
    Top = 52
    object PersonQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
    object PersonQueryName: TStringField
      FieldName = 'Name'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Name'
      Size = 200
    end
    object PersonQueryPreferedSchool: TBooleanField
      FieldName = 'PreferedSchool'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".PreferedSchool'
    end
    object PersonQueryEGN: TStringField
      FieldName = 'EGN'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".EGN'
      Size = 10
    end
    object PersonQueryValidEGN: TStringField
      FieldKind = fkCalculated
      FieldName = 'ValidEGN'
      Calculated = True
    end
    object PersonQueryTelephone: TStringField
      FieldName = 'Telephone'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Telephone'
      Size = 50
    end
    object PersonQueryAddress: TStringField
      FieldName = 'Address'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Address'
      Size = 200
    end
    object PersonQuerySe: TStringField
      FieldKind = fkCalculated
      FieldName = 'Se'
      Size = 10
      Calculated = True
    end
    object PersonQuerySex: TIntegerField
      FieldName = 'Sex'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Sex'
    end
    object PersonQueryTax_id: TIntegerField
      FieldName = 'Tax_id'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Tax_id'
    end
    object PersonQueryTax: TStringField
      FieldKind = fkLookup
      FieldName = 'Tax'
      LookupDataSet = Data.TaxesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Tax_id'
      Size = 50
      Lookup = True
    end
    object PersonQueryRoom_Code: TStringField
      FieldName = 'Room_Code'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Room_Code'
      Size = 10
    end
    object PersonQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".EntOn'
    end
    object PersonQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".EntBy'
      Size = 50
    end
  end
  object PersonSource: TDataSource
    DataSet = PersonQuery
    Left = 108
    Top = 80
  end
  object WishesQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = PersonSource
    SQL.Strings = (
      'SELECT * FROM Wishes w WHERE w.Person_ID=:ID'
      'ORDER BY w.Priority')
    Left = 308
    Top = 68
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end>
    object WishesQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Person_ID'
    end
    object WishesQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Profile_ID'
    end
    object WishesQueryProfile: TStringField
      FieldKind = fkLookup
      FieldName = 'Profile'
      LookupDataSet = Data.ProfilesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Profile_ID'
      Size = 50
      Lookup = True
    end
    object WishesQueryPriority: TIntegerField
      FieldName = 'Priority'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Priority'
    end
    object WishesQueryScore: TFloatField
      FieldName = 'Score'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Score'
      DisplayFormat = '#0.00'
    end
    object WishesQueryFromOlymp: TBooleanField
      FieldName = 'FromOlymp'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".FromOlymp'
      DisplayValues = #1044#1072'; '
    end
    object WishesQueryOlympScore: TFloatField
      FieldName = 'OlympScore'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".OlympScore'
      DisplayFormat = '#0.00'
    end
    object WishesQueryGoToExam: TBooleanField
      FieldName = 'GoToExam'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".GoToExam'
      DisplayValues = #1044#1072';'#1053#1077
    end
    object WishesQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".EntOn'
    end
    object WishesQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".EntBy'
      Size = 50
    end
  end
  object WishesSource: TDataSource
    DataSet = WishesQuery
    Left = 308
    Top = 96
  end
  object ExamsQuery: TQuery
    OnCalcFields = ExamsQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = PersonSource
    SQL.Strings = (
      'SELECT er.* FROM ExamsResults er '
      
        'LEFT OUTER JOIN Wishes w ON w.Person_ID=er.Person_ID AND w.Profi' +
        'le_ID=er.Exam'
      'WHERE er.Person_ID=:ID '
      'ORDER BY w.Priority')
    Left = 116
    Top = 272
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end>
    object ExamsQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".ID'
    end
    object ExamsQueryExam: TIntegerField
      FieldName = 'Exam'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Exam'
    end
    object ExamsQueryExa: TStringField
      FieldKind = fkCalculated
      FieldName = 'Exa'
      Size = 50
      Calculated = True
    end
    object ExamsQueryScore: TFloatField
      FieldName = 'Score'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Score'
      DisplayFormat = '#0.00'
    end
    object ExamsQueryPoints: TFloatField
      FieldName = 'Points'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Points'
    end
  end
  object ExamsSource: TDataSource
    DataSet = ExamsQuery
    Left = 116
    Top = 300
  end
  object ClassificateQuery: TQuery
    OnCalcFields = ClassificateQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = PersonSource
    SQL.Strings = (
      
        'SELECT r.Classificated,r.Profile_ID,r.Amount,r.IsIn,r.Person_ID,' +
        'w.Priority '
      
        'FROM Register r LEFT OUTER JOIN Wishes w ON r.Person_ID=w.Person' +
        '_ID AND r.Profile_ID=w.Profile_ID'
      'WHERE r.Person_ID=:ID'
      'ORDER BY w.Priority')
    Left = 364
    Top = 272
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID'
        ParamType = ptUnknown
        Size = 4
      end>
    object ClassificateQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Person_ID'
    end
    object ClassificateQueryClassificated: TBooleanField
      FieldName = 'Classificated'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Classificated'
      DisplayValues = #1044#1072'; '
    end
    object ClassificateQueryPriority: TIntegerField
      FieldName = 'Priority'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Priority'
    end
    object ClassificateQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Profile_ID'
    end
    object ClassificateQueryProfile: TStringField
      FieldKind = fkLookup
      FieldName = 'Profile'
      LookupDataSet = Data.ProfilesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Profile_ID'
      Size = 50
      Lookup = True
    end
    object ClassificateQueryAmount: TFloatField
      FieldName = 'Amount'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Amount'
      DisplayFormat = '#0.00'
    end
    object ClassificateQueryIsIn: TBooleanField
      FieldName = 'IsIn'
      Origin = 'RECEPTIONDATABASE."dbo.Register".IsIn'
    end
    object ClassificateQueryIsInExt: TStringField
      FieldKind = fkCalculated
      FieldName = 'IsInExt'
      Size = 5
      Calculated = True
    end
    object ClassificateQueryStatus: TStringField
      FieldKind = fkCalculated
      FieldName = 'Status'
      Calculated = True
    end
  end
  object ClassificateSource: TDataSource
    DataSet = ClassificateQuery
    Left = 364
    Top = 300
  end
  object HelpQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT * FROM Register r LEFT OUTER JOIN Persons p ON r.Person_I' +
        'D=p.ID'
      
        'WHERE (r.Amount>:Amount OR (r.Amount=:Amount AND r.Person_ID<:Pe' +
        'rson_ID)) AND Profile_ID=:Profile_ID'
      'AND (p.Sex=:SET_SEX1 OR p.Sex=:SET_SEX2)'
      'ORDER BY r.Amount DESC,r.Person_ID')
    Left = 284
    Top = 292
    ParamData = <
      item
        DataType = ftFloat
        Name = 'Amount'
        ParamType = ptUnknown
        Size = 8
      end
      item
        DataType = ftFloat
        Name = 'Amount'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Person_ID'
        ParamType = ptUnknown
        Size = 4
      end
      item
        DataType = ftInteger
        Name = 'Profile_ID'
        ParamType = ptUnknown
        Size = 4
      end
      item
        DataType = ftUnknown
        Name = 'SET_SEX1'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'SET_SEX2'
        ParamType = ptUnknown
      end>
    object HelpQueryClassificated: TBooleanField
      FieldName = 'Classificated'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Classificated'
    end
    object HelpQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Profile_ID'
    end
    object HelpQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Person_ID'
    end
    object HelpQueryAmount: TFloatField
      FieldName = 'Amount'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Amount'
    end
    object HelpQueryIsIn: TBooleanField
      FieldName = 'IsIn'
      Origin = 'RECEPTIONDATABASE."dbo.Register".IsIn'
    end
  end
  object ClassificationNumberQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM RegisterNum')
    Left = 400
    Top = 208
    object ClassificationNumberQueryRegisterNumber: TIntegerField
      FieldName = 'RegisterNumber'
      Origin = 'RECEPTIONDATABASE.RegisterNum.RegisterNumber'
    end
  end
end
