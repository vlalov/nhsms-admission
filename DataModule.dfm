object Data: TData
  OldCreateOrder = False
  Left = 79
  Top = 22
  Height = 556
  Width = 735
  object Session1: TSession
    Active = True
    SessionName = 'Session1_1'
    Left = 144
  end
  object Database1: TDatabase
    DatabaseName = 'ReceptionDatabase'
    HandleShared = True
    LoginPrompt = False
    Params.Strings = (
      '=')
    SessionName = 'Session1_1'
    Left = 144
    Top = 48
  end
  object TaxesTable: TTable
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    IndexFieldNames = 'ID'
    TableName = 'dbo.Taxes'
    Left = 140
    Top = 96
    object TaxesTableID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object TaxesTableValue: TFloatField
      FieldName = 'Value'
      Required = True
    end
    object TaxesTableName: TStringField
      FieldName = 'Name'
      Required = True
      Size = 50
    end
  end
  object TaxesSource: TDataSource
    DataSet = TaxesTable
    Left = 140
    Top = 140
  end
  object ProfilesSource: TDataSource
    DataSet = ProfilesTable
    Left = 212
    Top = 140
  end
  object PersonsSource: TDataSource
    DataSet = PersonsQuery
    Left = 284
    Top = 140
  end
  object PersonsQuery: TQuery
    CachedUpdates = True
    AfterInsert = PersonsQueryAfterInsert
    BeforePost = PersonsQueryBeforePost
    AfterPost = PersonsQueryAfterPost
    AfterCancel = PersonsQueryAfterCancel
    AfterDelete = PersonsQueryAfterPost
    AfterScroll = PersonsQueryAfterScroll
    OnUpdateError = PersonsQueryUpdateError
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM dbo.Persons ORDER BY ID')
    UpdateObject = PersonsUpdateSQL
    Left = 280
    Top = 96
    object PersonsQueryID: TIntegerField
      AutoGenerateValue = arAutoInc
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE.Persons.ID'
    end
    object PersonsQueryName: TStringField
      FieldName = 'Name'
      Origin = 'RECEPTIONDATABASE.Persons.Name'
      Size = 200
    end
    object PersonsQueryPreferedSchool: TBooleanField
      FieldName = 'PreferedSchool'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".PreferedSchool'
    end
    object PersonsQueryEGN: TStringField
      FieldName = 'EGN'
      Origin = 'RECEPTIONDATABASE.Persons.EGN'
      Size = 10
    end
    object PersonsQueryTelephone: TStringField
      FieldName = 'Telephone'
      Origin = 'RECEPTIONDATABASE.Persons.Telephone'
      Size = 50
    end
    object PersonsQueryAddress: TStringField
      FieldName = 'Address'
      Origin = 'RECEPTIONDATABASE.Persons.Address'
      Size = 200
    end
    object PersonsQuerySex: TIntegerField
      FieldName = 'Sex'
      Origin = 'RECEPTIONDATABASE.Persons.Sex'
    end
    object PersonsQueryTax_id: TIntegerField
      FieldName = 'Tax_id'
      Origin = 'RECEPTIONDATABASE.Persons.Tax_id'
    end
    object PersonsQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".EntOn'
    end
    object PersonsQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".EntBy'
      Size = 50
    end
    object PersonsQueryRoom_Code: TStringField
      FieldName = 'Room_Code'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".Room_Code'
      Size = 10
    end
  end
  object PersonsUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update Persons'
      'set'
      '  Name = :Name,'
      '  PreferedSchool = :PreferedSchool,'
      '  EGN = :EGN,'
      '  Telephone = :Telephone,'
      '  Address = :Address,'
      '  Sex = :Sex,'
      '  Tax_id = :Tax_id,'
      '  Room_Code=:Room_Code'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into Persons'
      
        '  (ID,Name, PreferedSchool, EGN, Telephone, Address, Sex, Tax_id' +
        ',Room_Code)'
      'values'
      
        '  (:ID,:Name, :PreferedSchool, :EGN, :Telephone, :Address, :Sex,' +
        ' '
      ':Tax_id,:Room_Code)')
    DeleteSQL.Strings = (
      'DELETE FROM Wishes WHERE Person_ID=:OLD_ID'
      ''
      'delete from Persons'
      ' where'
      '  ID = :OLD_ID')
    Left = 280
    Top = 52
  end
  object rsPropSaver1: TrsPropSaver
    Storage = MainForm.rsStorage1
    Options = []
    RootSection = 'Server'
    Properties.Strings = (
      'Database1.AliasName')
    WhenLoad = wlOnCreate
    WhenSave = wsOnDestroy
    Left = 336
    Top = 8
  end
  object TextsDataSource: TDataSource
    DataSet = TextsTable
    Left = 60
    Top = 140
  end
  object PlacesTable: TTable
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'Name'
        Attributes = [faRequired]
        DataType = ftString
        Size = 100
      end
      item
        Name = 'Text'
        DataType = ftString
        Size = 100
      end>
    IndexDefs = <
      item
        Name = 'PK_Places'
        Fields = 'ID'
        Options = [ixUnique]
      end>
    IndexFieldNames = 'ID'
    StoreDefs = True
    TableName = 'dbo.Places'
    Left = 368
    Top = 100
    object PlacesTableID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object PlacesTableName: TStringField
      FieldName = 'Name'
      Required = True
      Size = 100
    end
    object PlacesTableText: TStringField
      FieldName = 'Text'
      Size = 100
    end
  end
  object PlacesSource: TDataSource
    DataSet = PlacesTable
    Left = 436
    Top = 100
  end
  object RoomsTable: TTable
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    FieldDefs = <
      item
        Name = 'Place_ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'Capacity'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'Code'
        Attributes = [faRequired]
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Comment'
        DataType = ftString
        Size = 100
      end>
    IndexDefs = <
      item
        Name = 'IX_Rooms_Code'
        Fields = 'Code'
        Options = [ixUnique]
      end>
    IndexFieldNames = 'Place_ID'
    MasterFields = 'ID'
    MasterSource = PlacesSource
    StoreDefs = True
    TableName = 'dbo.Rooms'
    Left = 368
    Top = 144
    object RoomsTablePlace_ID: TIntegerField
      FieldName = 'Place_ID'
      Required = True
    end
    object RoomsTableCapacity: TIntegerField
      FieldName = 'Capacity'
      Required = True
      MaxValue = 2147483647
      MinValue = 1
    end
    object RoomsTableCode: TStringField
      FieldName = 'Code'
      Required = True
      Size = 10
    end
    object RoomsTableComment: TStringField
      FieldName = 'Comment'
      Size = 100
    end
  end
  object RoomsSource: TDataSource
    DataSet = RoomsTable
    Left = 436
    Top = 144
  end
  object CalcFreeRoomsQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT rm.Code,'
      
        '   rm.Capacity-(CASE WHEN subsql.cnt IS NULL THEN 0 ELSE subsql.' +
        'cnt END) CNT'
      'FROM Rooms rm FULL OUTER JOIN '
      #9'(SELECT Room_Code,COUNT(*) cnt '
      #9'FROM Persons p GROUP BY Room_Code) subsql '
      #9'ON rm.Code=subsql.Room_Code')
    Left = 260
    Top = 236
    object CalcFreeRoomsQueryCode: TStringField
      FieldName = 'Code'
      Size = 10
    end
    object CalcFreeRoomsQueryCNT: TIntegerField
      FieldName = 'CNT'
    end
  end
  object TextsTable: TQuery
    CachedUpdates = True
    AfterPost = TextsTableAfterPost
    AfterDelete = TextsTableAfterPost
    AfterScroll = TextsTableAfterScroll
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM dbo.UserTexts')
    UpdateObject = TextsUpdateSQL
    Left = 60
    Top = 96
    object TextsTableID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.UserTexts".ID'
    end
    object TextsTableValue: TMemoField
      FieldName = 'Value'
      Origin = 'RECEPTIONDATABASE."dbo.UserTexts".Value'
      BlobType = ftMemo
      Size = 1
    end
  end
  object TextsUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update dbo.UserTexts'
      'set'
      '  ID = :ID,'
      '  Value = :Value'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into UserTexts'
      '  (ID, Value)'
      'values'
      '  (:ID, :Value)')
    DeleteSQL.Strings = (
      'delete from dbo.UserTexts'
      'where'
      '  ID = :OLD_ID')
    Left = 60
    Top = 44
  end
  object AllRoomsSource: TDataSource
    DataSet = AllRoomsQuery
    Left = 356
    Top = 240
  end
  object AllRoomsQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT Code FROM dbo.Rooms')
    Left = 352
    Top = 196
    object AllRoomsQueryCode: TStringField
      FieldName = 'Code'
      Origin = 'RECEPTIONDATABASE."dbo.Rooms".Code'
      Size = 10
    end
  end
  object ExamResultsQuery: TQuery
    CachedUpdates = True
    AfterInsert = ExamResultsQueryAfterInsert
    BeforePost = ExamResultsQueryBeforePost
    AfterPost = ExamResultsQueryAfterPost
    AfterDelete = ExamResultsQueryAfterPost
    AfterScroll = ExamResultsQueryAfterScroll
    OnUpdateError = ExamResultsQueryUpdateError
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM ExamsResults WHERE Exam=:SET_EXAM'
      'ORDER BY ID')
    UpdateMode = upWhereChanged
    UpdateObject = ExamResultsUpdateSQL
    Left = 56
    Top = 228
    ParamData = <
      item
        DataType = ftInteger
        Name = 'SET_EXAM'
        ParamType = ptUnknown
      end>
    object ExamResultsQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".ID'
    end
    object ExamResultsQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Person_ID'
    end
    object ExamResultsQueryPerson: TStringField
      FieldKind = fkLookup
      FieldName = 'Person'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Person_ID'
      Size = 200
      Lookup = True
    end
    object ExamResultsQueryExam: TIntegerField
      FieldName = 'Exam'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Exam'
    end
    object ExamResultsQueryPoints: TFloatField
      FieldName = 'Points'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Points'
    end
    object ExamResultsQueryScore: TFloatField
      FieldName = 'Score'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Score'
      DisplayFormat = '#0.00'
    end
  end
  object ExamResultsUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update ExamsResults'
      'set'
      '  Person_ID = :Person_ID,'
      '  Points = :Points,'
      '  Score = :Score,'
      '  ID=:ID'
      'where'
      '  ID = :OLD_ID and'
      '  Exam = :SET_EXAM')
    InsertSQL.Strings = (
      'insert ExamsResults'
      '  (ID,Exam,Person_ID, Points, Score)'
      'values'
      '  (:ID, :SET_EXAM,:Person_ID, :Points, :Score)')
    DeleteSQL.Strings = (
      'delete from ExamsResults'
      'where'
      '  ID = :OLD_ID and'
      '  Exam = :SET_EXAM')
    Left = 56
    Top = 184
  end
  object ExamResultsSource: TDataSource
    DataSet = ExamResultsQuery
    Left = 140
    Top = 228
  end
  object CalcFkNextQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT ER.ID LAST'
      'FROM ExamsResults ER,'
      
        #9'(SELECT MAX(x.N)M FROM ExamsResults x WHERE x.Exam=:SET_EXAM) t' +
        'hemax'
      'WHERE ER.N=themax.M')
    Left = 52
    Top = 344
    ParamData = <
      item
        DataType = ftInteger
        Name = 'SET_EXAM'
        ParamType = ptUnknown
      end>
    object CalcFkNextQueryLAST: TIntegerField
      FieldName = 'LAST'
    end
  end
  object ResolveScoresQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT p.ID, p.Name,w.Score SchoolScore,ExamScore='
      '   CASE w.FromOlymp '
      '   WHEN 0 THEN'
      '      er.Score'
      '   WHEN 1 THEN'
      '      CASE w.GoToExam'
      '      WHEN 1 THEN'
      '         CASE WHEN er.Score IS NULL THEN w.OlympScore '
      '              WHEN er.Score<w.OlympScore THEN w.OlympScore'
      '              WHEN er.Score>w.OlympScore THEN er.Score'
      '         END'
      '      WHEN 0 THEN '
      '         w.OlympScore'
      '      END'
      '   END'
      
        'FROM Persons p LEFT OUTER JOIN ExamsResults er ON p.ID=er.Person' +
        '_id AND er.Exam=:SET_PROFILE, Wishes w'
      'WHERE p.id=w.Person_id AND w.Profile_ID=:SET_PROFILE'
      'ORDER BY p.ID')
    Left = 152
    Top = 344
    ParamData = <
      item
        DataType = ftInteger
        Name = 'SET_PROFILE'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'SET_PROFILE'
        ParamType = ptUnknown
      end>
    object ResolveScoresQueryID: TIntegerField
      FieldName = 'ID'
    end
    object ResolveScoresQueryName: TStringField
      FieldName = 'Name'
      Size = 200
    end
    object ResolveScoresQuerySchoolScore: TFloatField
      FieldName = 'SchoolScore'
    end
    object ResolveScoresQueryExamScore: TFloatField
      FieldName = 'ExamScore'
    end
  end
  object RegisterQuery: TQuery
    CachedUpdates = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Register '
      
        'WHERE Classificated=:SET_CLASSIFICATED AND Profile_ID=:SET_PROFI' +
        'LE'
      'ORDER BY Classificated,Profile_ID,Amount DESC,Person_ID')
    Left = 280
    Top = 352
    ParamData = <
      item
        DataType = ftInteger
        Name = 'SET_CLASSIFICATED'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'SET_PROFILE'
        ParamType = ptUnknown
      end>
    object RegisterQueryClassificated: TBooleanField
      FieldName = 'Classificated'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Classificated'
    end
    object RegisterQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Profile_ID'
    end
    object RegisterQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Person_ID'
    end
    object RegisterQueryAmount: TFloatField
      FieldName = 'Amount'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Amount'
      DisplayFormat = '#0.00'
    end
    object RegisterQueryIsIn: TBooleanField
      FieldName = 'IsIn'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".IsIn'
      DisplayValues = #1044#1072';'#1053#1077
    end
    object RegisterQueryPerson: TStringField
      FieldKind = fkLookup
      FieldName = 'Person'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Person_ID'
      Size = 200
      Lookup = True
    end
    object RegisterQuerySex: TIntegerField
      FieldKind = fkLookup
      FieldName = 'Sex'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Sex'
      KeyFields = 'Person_ID'
      Lookup = True
    end
  end
  object RegisterUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update Register'
      'set'
      '  Classificated = :Classificated,'
      '  Profile_ID = :Profile_ID,'
      '  Person_ID = :Person_ID,'
      '  Amount = :Amount,'
      '  IsIn = :IsIn'
      'where'
      '  Profile_ID = :OLD_Profile_ID and'
      '  Person_ID = :OLD_Person_ID')
    InsertSQL.Strings = (
      'insert into Register'
      '  (Classificated, Profile_ID, Person_ID, Amount, IsIn)'
      'values'
      '  (:Classificated, :Profile_ID, :Person_ID, :Amount, :IsIn)')
    DeleteSQL.Strings = (
      'delete from Register'
      'where'
      '  Profile_ID = :OLD_Profile_ID and'
      '  Person_ID = :OLD_Person_ID')
    Left = 280
    Top = 308
  end
  object RegisterSource: TDataSource
    DataSet = RegisterQuery
    Left = 280
    Top = 396
  end
  object SingleQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    Left = 608
    Top = 24
  end
  object NameQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT CONVERT(varchar(50),current_user) operator')
    Left = 56
    Top = 280
    object NameQueryoperator: TStringField
      FieldName = 'operator'
      Size = 50
    end
  end
  object QRTextFilter1: TQRTextFilter
    Left = 580
    Top = 104
  end
  object RegisterNumQuery: TQuery
    CachedUpdates = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM RegisterNum')
    UpdateObject = RegisterNumUpdateSQL
    Left = 504
    Top = 12
    object RegisterNumQueryRegisterNumber: TIntegerField
      FieldName = 'RegisterNumber'
      Origin = 'RECEPTIONDATABASE."dbo.RegisterNum".RegisterNumber'
    end
  end
  object RegisterNumUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update RegisterNum'
      'set'
      '  RegisterNumber = :RegisterNumber'
      'where'
      '  RegisterNumber = :OLD_RegisterNumber')
    InsertSQL.Strings = (
      'insert into RegisterNum'
      '  (RegisterNumber)'
      'values'
      '  (:RegisterNumber)')
    DeleteSQL.Strings = (
      'delete from RegisterNum'
      'where'
      '  RegisterNumber = :OLD_RegisterNumber')
    Left = 508
    Top = 56
  end
  object RegisterDeletedQuery: TQuery
    CachedUpdates = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Register_Deleted')
    UpdateObject = RegisterDeletedUpdateSQL
    Left = 52
    Top = 404
    object RegisterDeletedQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_Deleted".Person_ID'
    end
  end
  object RegisterDeletedUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update Register_Deleted'
      'set'
      '  Person_ID = :Person_ID'
      'where'
      '  Person_ID = :OLD_Person_ID')
    InsertSQL.Strings = (
      'insert into Register_Deleted'
      '  (Person_ID)'
      'values'
      '  (:Person_ID)')
    DeleteSQL.Strings = (
      'delete from Register_Deleted'
      'where'
      '  Person_ID = :OLD_Person_ID')
    Left = 152
    Top = 388
  end
  object CalcBALQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT p.ID,p.Sex, w.Profile_ID,w.Priority, w.Score SchoolScore,' +
        'FirstExam.Score FirstExamScore,ExamQuery.Exam ,'
      '(2*ExamQuery.Exam+FirstExam.Score+w.Score) BAL'
      'FROM Persons p LEFT OUTER JOIN Wishes w ON p.ID=w.Person_ID,'
      
        '   (SELECT ers.* FROM ExamsResults ers WHERE ers.Exam=0) FirstEx' +
        'am,'
      '(SELECT ws.Person_ID,ws.Profile_ID,ws.Score SchoolScore,Exam='
      'CASE ws.FromOlymp'
      '   WHEN 0 THEN er.Score'
      '   WHEN 1 THEN'
      '   CASE ws.GoToExam'
      '      WHEN 1 THEN'
      '         CASE '
      '            WHEN er.Score IS NULL THEN ws.OlympScore'
      '            WHEN er.Score<ws.OlympScore THEN ws.OlympScore'
      '            WHEN er.Score>=ws.OlympScore THEN er.Score'
      '         END'
      '      WHEN 0 THEN ws.OlympScore'
      '   END'
      'END'
      'FROM Wishes ws LEFT OUTER JOIN ExamsResults er '
      
        '   ON ws.Person_ID=er.Person_ID AND ws.Profile_ID=er.Exam) ExamQ' +
        'uery'
      
        'WHERE FirstExam.Person_ID=p.ID AND ExamQuery.Person_ID=p.ID AND ' +
        'ExamQuery.Profile_ID=w.Profile_ID'
      'ORDER BY p.ID,w.Priority')
    Left = 372
    Top = 300
    object CalcBALQueryID: TIntegerField
      FieldName = 'ID'
    end
    object CalcBALQuerySex: TIntegerField
      FieldName = 'Sex'
    end
    object CalcBALQueryPriority: TIntegerField
      FieldName = 'Priority'
    end
    object CalcBALQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
    end
    object CalcBALQuerySchoolScore: TFloatField
      FieldName = 'SchoolScore'
    end
    object CalcBALQueryFirstExamScore: TFloatField
      FieldName = 'FirstExamScore'
    end
    object CalcBALQueryExam: TFloatField
      FieldName = 'Exam'
    end
    object CalcBALQueryBAL: TFloatField
      FieldName = 'BAL'
    end
  end
  object RegisterGradeQuery: TQuery
    AfterScroll = RegisterGradeQueryAfterScroll
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Register_Catalog'
      'ORDER BY Grade')
    UpdateObject = RegisterGradeUpdateSQL
    Left = 536
    Top = 348
    object RegisterGradeQueryGrade: TIntegerField
      FieldName = 'Grade'
      Origin = 'RECEPTIONDATABASE."dbo.Register_Catalog".Grade'
    end
    object RegisterGradeQueryInformation: TStringField
      FieldName = 'Information'
      Origin = 'RECEPTIONDATABASE."dbo.Register_Catalog".Information'
      Size = 50
    end
    object RegisterGradeQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Register_Catalog".EntOn'
    end
    object RegisterGradeQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Register_Catalog".EntBy'
      Size = 50
    end
  end
  object RegisterGradeUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update Register_Catalog'
      'set'
      '  Grade = :Grade,'
      '  Information = :Information'
      'where'
      '  Grade = :OLD_Grade')
    InsertSQL.Strings = (
      'insert into Register_Catalog'
      '  (Grade, Information)'
      'values'
      '  (:Grade, :Information)')
    DeleteSQL.Strings = (
      'delete from Register_Catalog'
      'where'
      '  Grade = :OLD_Grade')
    Left = 456
    Top = 328
  end
  object RegGradeDataSource: TDataSource
    DataSet = RegisterGradeQuery
    Left = 608
    Top = 324
  end
  object RegisterHistoryQuery: TQuery
    AfterOpen = RegisterHistoryQueryAfterOpen
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = RegGradeDataSource
    SQL.Strings = (
      'SELECT * FROM Register_History WHERE Grade=:Grade'
      'ORDER BY Classificated DESC, Amount DESC, Person_ID')
    Left = 536
    Top = 408
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Grade'
        ParamType = ptUnknown
        Size = 4
      end>
    object RegisterHistoryQueryGrade: TIntegerField
      FieldName = 'Grade'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".Grade'
    end
    object RegisterHistoryQueryClassificated: TBooleanField
      FieldName = 'Classificated'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".Classificated'
      DisplayValues = #1044#1072'; '
    end
    object RegisterHistoryQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".Person_ID'
    end
    object RegisterHistoryQueryPerson: TStringField
      FieldKind = fkLookup
      FieldName = 'Person'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Person_ID'
      Size = 150
      Lookup = True
    end
    object RegisterHistoryQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".Profile_ID'
    end
    object RegisterHistoryQueryAmount: TFloatField
      FieldName = 'Amount'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".Amount'
      DisplayFormat = '#0.00'
    end
    object RegisterHistoryQueryIsIn: TBooleanField
      FieldName = 'IsIn'
      Origin = 'RECEPTIONDATABASE."dbo.Register_History".IsIn'
      DisplayValues = #1044#1072';'#1053#1077
    end
  end
  object RegHistoryDataSource: TDataSource
    DataSet = RegisterHistoryQuery
    Left = 540
    Top = 452
  end
  object InitClassifQuery: TQuery
    CachedUpdates = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT r.*,p.Sex,wsh.Priority '
      
        'FROM Register r LEFT OUTER JOIN Persons p ON r.Person_id=p.ID,Wi' +
        'shes wsh'
      'WHERE wsh.Person_id=p.ID AND wsh.Profile_id=r.Profile_ID'
      'ORDER BY Classificated,r.Profile_ID,Amount DESC,r.Person_ID')
    UpdateObject = RegisterUpdateSQL
    Left = 332
    Top = 452
    object BooleanField1: TBooleanField
      FieldName = 'Classificated'
      Origin = 'RECEPTIONDATABASE."dbo.Register".Classificated'
    end
    object IntegerField1: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Profile_ID'
    end
    object IntegerField2: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Person_ID'
    end
    object FloatField1: TFloatField
      FieldName = 'Amount'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".Amount'
      DisplayFormat = '#0.00'
    end
    object BooleanField2: TBooleanField
      FieldName = 'IsIn'
      Origin = 'RECEPTIONDATABASE."dbo.Register_UPPER".IsIn'
      DisplayValues = #1044#1072';'#1053#1077
    end
    object IntegerField3: TIntegerField
      FieldKind = fkLookup
      FieldName = 'Sex'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Sex'
      KeyFields = 'Person_ID'
      Lookup = True
    end
    object InitClassifQueryPriority: TIntegerField
      FieldName = 'Priority'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes".Priority'
    end
  end
  object ProfilesHistoryQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM Profiles_History'
      'WHERE Grade=:SET_GRADE')
    Left = 624
    Top = 428
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'SET_GRADE'
        ParamType = ptUnknown
      end>
    object ProfilesHistoryQueryGrade: TIntegerField
      FieldName = 'Grade'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".Grade'
    end
    object ProfilesHistoryQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".ID'
    end
    object ProfilesHistoryQueryDiffMW: TBooleanField
      FieldName = 'DiffMW'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".DiffMW'
    end
    object ProfilesHistoryQuerySpace: TIntegerField
      FieldName = 'Space'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".Space'
    end
    object ProfilesHistoryQuerySpaceOther: TIntegerField
      FieldName = 'SpaceOther'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".SpaceOther'
    end
  end
  object SearchSwapsQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT p.ID AfterSwap FROM Persons p LEFT OUTER JOIN Persons p2 ' +
        'ON p.ID=p2.ID+1'
      'WHERE p.ID!=1 AND p2.ID IS NULL ')
    Left = 152
    Top = 464
    object SearchSwapsQueryAfterSwap: TIntegerField
      FieldName = 'AfterSwap'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
  end
  object MAXIDQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT MAX(ID) MAXIMUM FROM Persons')
    Left = 72
    Top = 464
    object MAXIDQueryMAXIMUM: TIntegerField
      FieldName = 'MAXIMUM'
      Origin = 'RECEPTIONDATABASE."dbo.Persons".ID'
    end
  end
  object ValidateExamResultsQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM ExamsResults er '
      'WHERE er.Person_ID=:SET_PERSON AND er.Exam=0')
    Left = 56
    ParamData = <
      item
        DataType = ftInteger
        Name = 'SET_PERSON'
        ParamType = ptUnknown
      end>
    object ValidateExamResultsQueryN: TIntegerField
      FieldName = 'N'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".N'
    end
    object ValidateExamResultsQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".ID'
    end
    object ValidateExamResultsQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Person_ID'
    end
    object ValidateExamResultsQueryExam: TIntegerField
      FieldName = 'Exam'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Exam'
    end
    object ValidateExamResultsQueryPoints: TFloatField
      FieldName = 'Points'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Points'
    end
    object ValidateExamResultsQueryScore: TFloatField
      FieldName = 'Score'
      Origin = 'RECEPTIONDATABASE."dbo.ExamsResults".Score'
    end
  end
  object ProfilesHistShowQuery: TQuery
    OnCalcFields = ProfilesHistShowQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = RegGradeDataSource
    SQL.Strings = (
      
        'SELECT ph.*,Allocated.DiffMW,Allocated.male,Allocated.female, Al' +
        'located.male+Allocated.female AllocAll'
      'FROM Profiles_History ph,'
      '(SELECT ID,DiffMW,sex1.cnt male,sex2.cnt female '
      'FROM Profiles_History r,'
      
        #9'(SELECT COUNT(rh.Person_ID) cnt,rh.Profile_ID,p.Sex FROM Regist' +
        'er_History rh,Persons p '
      
        #9' '#9'WHERE p.Id=rh.Person_ID AND Classificated=1 AND p.Sex=1 AND G' +
        'rade=:Grade'
      #9#9'GROUP BY rh.Profile_ID,p.Sex) sex1,'
      
        #9'(SELECT COUNT(rh.Person_ID) cnt,rh.Profile_ID,p.Sex FROM Regist' +
        'er_History rh,Persons p '
      
        #9' '#9'WHERE p.Id=rh.Person_ID AND Classificated=1 AND p.Sex=0 AND G' +
        'rade=:Grade'
      #9#9'GROUP BY rh.Profile_ID,p.Sex) sex2 '
      
        'WHERE r.Grade=:Grade AND sex1.Profile_ID=ID AND sex2.Profile_ID=' +
        'ID) Allocated'
      'WHERE ph.Grade=:Grade AND Allocated.ID=ph.ID'
      'ORDER BY ph.ID')
    Left = 540
    Top = 196
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Grade'
        ParamType = ptUnknown
        Size = 4
      end
      item
        DataType = ftInteger
        Name = 'Grade'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Grade'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Grade'
        ParamType = ptUnknown
      end>
    object ProfilesHistShowQueryGrade: TIntegerField
      FieldName = 'Grade'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".Grade'
    end
    object ProfilesHistShowQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".ID'
    end
    object ProfilesHistShowQueryProfile: TStringField
      FieldKind = fkLookup
      FieldName = 'Profile'
      LookupDataSet = ProfilesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'ID'
      Size = 150
      Lookup = True
    end
    object ProfilesHistShowQueryDiffMW: TBooleanField
      FieldName = 'DiffMW'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".DiffMW'
      DisplayValues = #1044#1072'; '
    end
    object ProfilesHistShowQuerySpace: TIntegerField
      FieldName = 'Space'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".Space'
    end
    object ProfilesHistShowQuerySpaceOther: TIntegerField
      DisplayLabel = 'SpaceMale'
      FieldName = 'SpaceOther'
      Origin = 'RECEPTIONDATABASE."dbo.Profiles_History".SpaceOther'
    end
    object ProfilesHistShowQuerySpaceFemale: TStringField
      FieldKind = fkCalculated
      FieldName = 'SpaceFemale'
      Size = 5
      Calculated = True
    end
    object ProfilesHistShowQueryAllocAll: TIntegerField
      FieldName = 'AllocAll'
    end
    object ProfilesHistShowQuerymale: TIntegerField
      FieldName = 'male'
    end
    object ProfilesHistShowQueryfemale: TIntegerField
      FieldName = 'female'
    end
  end
  object ProfilesHistDataSource: TDataSource
    DataSet = ProfilesHistShowQuery
    Left = 648
    Top = 184
  end
  object ProfilesTable: TQuery
    CachedUpdates = True
    AfterPost = ProfilesTableAfterPost
    AfterDelete = ProfilesTableAfterPost
    OnCalcFields = ProfilesTableCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      
        'SELECT ph.*,Allocated.male+Allocated.female AllocAll,Allocated.m' +
        'ale,Allocated.female'
      'FROM Profiles ph LEFT OUTER JOIN '
      '(SELECT ID,DiffMW,sex1.cnt male,sex2.cnt female '
      'FROM Profiles r,'
      
        #9'(SELECT COUNT(rh.Person_ID) cnt,rh.Profile_ID,p.Sex FROM Regist' +
        'er rh,Persons p '
      #9' '#9'WHERE p.Id=rh.Person_ID AND Classificated=1 AND p.Sex=1'
      #9#9'GROUP BY rh.Profile_ID,p.Sex) sex1,'
      
        #9'(SELECT COUNT(rh.Person_ID) cnt,rh.Profile_ID,p.Sex FROM Regist' +
        'er rh,Persons p '
      #9' '#9'WHERE p.Id=rh.Person_ID AND Classificated=1 AND p.Sex=0'
      #9#9'GROUP BY rh.Profile_ID,p.Sex) sex2 '
      
        'WHERE sex1.Profile_ID=ID AND sex2.Profile_ID=ID) Allocated ON Al' +
        'located.ID=ph.ID'
      'ORDER BY ph.ID')
    UpdateObject = ProfilesUpdateSQL
    Left = 212
    Top = 88
    object ProfilesTableID: TIntegerField
      FieldName = 'ID'
    end
    object ProfilesTableName: TStringField
      FieldName = 'Name'
      Size = 50
    end
    object ProfilesTableDiffMW: TBooleanField
      FieldName = 'DiffMW'
      DisplayValues = #1044#1072';'#1053#1077
    end
    object ProfilesTableSpace: TIntegerField
      FieldName = 'Space'
    end
    object ProfilesTableSpaceOther: TIntegerField
      FieldName = 'SpaceOther'
    end
    object ProfilesTableSpaceW: TStringField
      FieldKind = fkCalculated
      FieldName = 'SpaceW'
      Size = 10
      Calculated = True
    end
    object ProfilesTableAllocAll: TIntegerField
      FieldName = 'AllocAll'
    end
    object ProfilesTablemale: TIntegerField
      FieldName = 'male'
    end
    object ProfilesTablefemale: TIntegerField
      FieldName = 'female'
    end
  end
  object ProfilesUpdateSQL: TUpdateSQL
    ModifySQL.Strings = (
      'update Profiles'
      'set'
      '  ID = :ID,'
      '  Name = :Name,'
      '  DiffMW = :DiffMW,'
      '  Space = :Space,'
      '  SpaceOther = :SpaceOther'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into Profiles'
      '  (ID, Name, DiffMW, Space, SpaceOther)'
      'values'
      '  (:ID, :Name, :DiffMW, :Space, :SpaceOther)')
    DeleteSQL.Strings = (
      'delete from Profiles'
      'where'
      '  ID = :OLD_ID')
    Left = 216
    Top = 16
  end
  object CheckIsInQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    DataSource = ProfilesSource
    SQL.Strings = (
      'SELECT r1.cnt male,r2.cnt female FROM '
      #9'(SELECT COUNT(*) cnt,p.Sex FROM Register r,Persons p'
      
        #9'WHERE r.Person_ID=p.ID AND r.Classificated=1 AND r.IsIn=1 AND P' +
        'rofile_ID=:ID AND p.Sex=1'
      
        #9'GROUP BY p.Sex) r1,(SELECT COUNT(*) cnt,p.Sex FROM Register r,P' +
        'ersons p'
      
        'WHERE r.Person_ID=p.ID AND r.Classificated=1 AND r.IsIn=1 AND Pr' +
        'ofile_ID=:ID AND p.Sex=0'
      'GROUP BY p.Sex) r2')
    Left = 428
    Top = 416
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
      end>
    object CheckIsInQuerymale: TIntegerField
      FieldName = 'male'
    end
    object CheckIsInQueryfemale: TIntegerField
      FieldName = 'female'
    end
  end
end
