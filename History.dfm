object HistoryForm: THistoryForm
  Left = 211
  Top = 134
  Width = 584
  Height = 421
  Caption = #1048#1089#1090#1086#1088#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010000001000800680500001600000028000000100000002000
    0000010008000000000000010000000000000000000000010000000100000000
    0000000080000080000000808000800000008000800080800000C0C0C000C0DC
    C000F0CAA60000003E0000005D0000007C0000009B000000BA000000D9000000
    F0002424FF004848FF006C6CFF009090FF00B4B4FF0000143E00001E5D000028
    7C0000329B00003CBA000046D9000055F000246DFF004885FF006C9DFF0090B5
    FF00B4CDFF00002A3E00003F5D0000547C0000699B00007EBA000093D90000AA
    F00024B6FF0048C2FF006CCEFF0090DAFF00B4E6FF00003E3E00005D5D00007C
    7C00009B9B0000BABA0000D9D90000F0F00024FFFF0048FFFF006CFFFF0090FF
    FF00B4FFFF00003E2A00005D3F00007C5400009B690000BA7E0000D9930000F0
    AA0024FFB60048FFC2006CFFCE0090FFDA00B4FFE600003E1400005D1E00007C
    2800009B320000BA3C0000D9460000F0550024FF6D0048FF85006CFF9D0090FF
    B500B4FFCD00003E0000005D0000007C0000009B000000BA000000D9000000F0
    000024FF240048FF48006CFF6C0090FF9000B4FFB400143E00001E5D0000287C
    0000329B00003CBA000046D9000055F000006DFF240085FF48009DFF6C00B5FF
    9000CDFFB4002A3E00003F5D0000547C0000699B00007EBA000093D90000AAF0
    0000B6FF2400C2FF4800CEFF6C00DAFF9000E6FFB4003E3E00005D5D00007C7C
    00009B9B0000BABA0000D9D90000F0F00000FFFF2400FFFF4800FFFF6C00FFFF
    9000FFFFB4003E2A00005D3F00007C5400009B690000BA7E0000D9930000F0AA
    0000FFB62400FFC24800FFCE6C00FFDA9000FFE6B4003E1400005D1E00007C28
    00009B320000BA3C0000D9460000F0550000FF6D2400FF854800FF9D6C00FFB5
    9000FFCDB4003E0000005D0000007C0000009B000000BA000000D9000000F000
    0000FF242400FF484800FF6C6C00FF909000FFB4B4003E0014005D001E007C00
    28009B003200BA003C00D9004600F0005500FF246D00FF488500FF6C9D00FF90
    B500FFB4CD003E002A005D003F007C0054009B006900BA007E00D9009300F000
    AA00FF24B600FF48C200FF6CCE00FF90DA00FFB4E6003E003E005D005D007C00
    7C009B009B00BA00BA00D900D900F000F000FF24FF00FF48FF00FF6CFF00FF90
    FF00FFB4FF002A003E003F005D0054007C0069009B007E00BA009300D900AA00
    F000B624FF00C248FF00CE6CFF00DA90FF00E6B4FF0014003E001E005D002800
    7C0032009B003C00BA004600D9005500F0006D24FF008548FF009D6CFF00B590
    FF00CDB4FF0006060600121212001F1F1F002C2C2C0039393900454545005252
    52005F5F5F006C6C6C007878780085858500929292009F9F9F00ABABAB00B8B8
    B800C5C5C500D2D2D200DEDEDE00EBEBEB00F8F8F800F0FBFF00A4A0A0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    000000E2E2E2E2E2E20000000000000000E2E227ECEC252525E2E20000000000
    E22727E2E2E2E2E2E22525E2000000EC2725252828E2272727E2E225E20000EC
    2523280728E227072727E2E2E200EC25383825380728072727E22525E8E2ECF4
    383838073807280725252525E8E2ECECEC39383807382525252525E2E2E2ECFF
    393939383807E8E2E825252525E2ECF4FF393939382539E8E2E2E8E8E8E200EC
    FFFFEC3938382539E8E2E2E2E20000ECF4ECFF393939382539E8E2E2E2000000
    ECF4FFFFFF2739382539E8E2E200000000ECECF4FF273938382539E8E2000000
    000000ECECECECECEC002539E80000000000000000000000000000250000F81F
    0000E0070000C003000080010000800100000000000000000000000000000000
    0000000000008001000080010000C0010000E0010000F8110000FFFB0000}
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnClose = FormClose
  OnCreate = FormCreate
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 576
    Height = 365
    HelpContext = 21
    ActivePage = TabSheet1
    Align = alClient
    HotTrack = True
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControlChange
    object TabSheet1: TTabSheet
      Caption = #1050#1072#1085#1076#1080#1076#1072#1090#1080
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 568
        Height = 141
        HelpContext = 21
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object PageControl2: TPageControl
          Left = 0
          Top = 0
          Width = 568
          Height = 141
          HelpContext = 21
          ActivePage = OwnTab
          Align = alClient
          HotTrack = True
          TabIndex = 0
          TabOrder = 0
          object OwnTab: TTabSheet
            Caption = #1044#1072#1085#1085#1080' '#1079#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
            ImageIndex = 1
            object Label7: TLabel
              Left = 4
              Top = 8
              Width = 22
              Height = 13
              HelpContext = 21
              Caption = #1048#1084#1077
            end
            object Label8: TLabel
              Left = 4
              Top = 32
              Width = 21
              Height = 13
              HelpContext = 21
              Caption = #1045#1043#1053
            end
            object NameEdit: TEdit
              Left = 32
              Top = 5
              Width = 253
              Height = 21
              HelpContext = 21
              TabOrder = 0
              OnChange = NameEditChange
            end
            object EGNEdit: TEdit
              Left = 32
              Top = 29
              Width = 157
              Height = 21
              HelpContext = 21
              MaxLength = 10
              TabOrder = 1
              OnChange = NameEditChange
            end
            object GroupBox5: TGroupBox
              Left = 4
              Top = 56
              Width = 185
              Height = 53
              HelpContext = 21
              TabOrder = 2
              object TaxTypeLookup: TDBLookupComboBox
                Left = 20
                Top = 24
                Width = 141
                Height = 21
                HelpContext = 21
                Enabled = False
                KeyField = 'ID'
                ListField = 'Name'
                ListSource = Data.TaxesSource
                TabOrder = 0
              end
              object TaxTypeCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 73
                Height = 17
                HelpContext = 21
                Caption = #1042#1080#1076' '#1090#1072#1082#1089#1072
                TabOrder = 1
                OnClick = TaxTypeCheckClick
              end
            end
            object GroupBox6: TGroupBox
              Left = 196
              Top = 48
              Width = 77
              Height = 61
              HelpContext = 21
              TabOrder = 3
              object SexTypeCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 39
                Height = 17
                HelpContext = 21
                Caption = #1055#1086#1083
                TabOrder = 0
                OnClick = SexTypeCheckClick
              end
              object MaleBtn: TRadioButton
                Left = 12
                Top = 20
                Width = 43
                Height = 17
                HelpContext = 21
                Caption = #1052#1098#1078
                Checked = True
                Enabled = False
                TabOrder = 1
                TabStop = True
              end
              object FemaleBtn: TRadioButton
                Left = 12
                Top = 40
                Width = 49
                Height = 17
                HelpContext = 21
                Caption = #1046#1077#1085#1072
                Enabled = False
                TabOrder = 2
              end
            end
            object GroupBox7: TGroupBox
              Left = 292
              Top = 0
              Width = 109
              Height = 45
              HelpContext = 21
              TabOrder = 4
              object IDCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 94
                Height = 17
                HelpContext = 21
                Caption = #1042#1093#1086#1076#1103#1097' '#1085#1086#1084#1077#1088
                TabOrder = 0
                OnClick = IDCheckClick
              end
              object IDEdit: TCSpinEdit
                Left = 36
                Top = 17
                Width = 53
                Height = 22
                HelpContext = 21
                Enabled = False
                MaxValue = 200000000
                MinValue = 1
                TabOrder = 1
                Value = 1
              end
            end
            object GroupBox10: TGroupBox
              Left = 292
              Top = 48
              Width = 141
              Height = 53
              HelpContext = 21
              TabOrder = 5
              object RoomCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 45
                Height = 17
                HelpContext = 21
                Caption = #1057#1090#1072#1103
                TabOrder = 0
                OnClick = RoomCheckClick
              end
              object RoomLookup: TDBLookupComboBox
                Left = 16
                Top = 24
                Width = 121
                Height = 21
                HelpContext = 21
                Enabled = False
                KeyField = 'Code'
                ListField = 'Code'
                ListSource = Data.RoomsSource
                TabOrder = 1
                OnClick = NameEditChange
              end
            end
          end
          object OperTab: TTabSheet
            Caption = #1054#1087#1077#1088#1072#1090#1086#1088
            object GroupBox1: TGroupBox
              Left = 4
              Top = 0
              Width = 277
              Height = 53
              HelpContext = 21
              TabOrder = 0
              object Label1: TLabel
                Left = 8
                Top = 24
                Width = 22
                Height = 13
                HelpContext = 21
                Caption = #1048#1084#1077
              end
              object ChangedOperCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 88
                Height = 17
                HelpContext = 21
                Caption = #1055#1088#1086#1084#1077#1085#1077#1085' '#1086#1090
                TabOrder = 0
                OnClick = ChangedOperCheckClick
              end
              object ChangedOperCombo: TComboBox
                Left = 36
                Top = 20
                Width = 233
                Height = 21
                HelpContext = 21
                AutoDropDown = True
                Enabled = False
                ItemHeight = 13
                Sorted = True
                TabOrder = 1
              end
            end
            object GroupBox3: TGroupBox
              Left = 4
              Top = 56
              Width = 277
              Height = 53
              HelpContext = 21
              TabOrder = 2
              object Label2: TLabel
                Left = 8
                Top = 24
                Width = 13
                Height = 13
                HelpContext = 21
                Caption = #1054#1090
              end
              object Label3: TLabel
                Left = 144
                Top = 24
                Width = 12
                Height = 13
                HelpContext = 21
                Caption = #1076#1086
              end
              object ChangedDateCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 109
                Height = 17
                HelpContext = 21
                Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
                TabOrder = 0
                OnClick = ChangedDateCheckClick
              end
              object StartChangedDateTime: TDateTimePicker
                Left = 28
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614
                Time = 37614
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 1
              end
              object EndChangedDateTime: TDateTimePicker
                Left = 164
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614.9999884259
                Time = 37614.9999884259
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 2
              end
            end
            object GroupBox2: TGroupBox
              Left = 284
              Top = 0
              Width = 273
              Height = 53
              HelpContext = 21
              TabOrder = 1
              object Label4: TLabel
                Left = 8
                Top = 24
                Width = 22
                Height = 13
                HelpContext = 21
                Caption = #1048#1084#1077
              end
              object EntOperatorCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 81
                Height = 17
                HelpContext = 21
                Caption = #1042#1098#1074#1077#1076#1077#1085' '#1086#1090
                TabOrder = 0
                OnClick = EntOperatorCheckClick
              end
              object EntOperatorCombo: TComboBox
                Left = 36
                Top = 20
                Width = 233
                Height = 21
                HelpContext = 21
                AutoDropDown = True
                Enabled = False
                ItemHeight = 13
                Sorted = True
                TabOrder = 1
              end
            end
            object GroupBox4: TGroupBox
              Left = 284
              Top = 56
              Width = 273
              Height = 53
              HelpContext = 21
              TabOrder = 3
              object Label5: TLabel
                Left = 8
                Top = 24
                Width = 13
                Height = 13
                HelpContext = 21
                Caption = #1054#1090
              end
              object Label6: TLabel
                Left = 144
                Top = 24
                Width = 12
                Height = 13
                HelpContext = 21
                Caption = #1076#1086
              end
              object EntDateCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 121
                Height = 17
                HelpContext = 21
                Caption = #1044#1072#1090#1072' '#1085#1072' '#1074#1098#1074#1077#1078#1076#1072#1085#1077
                TabOrder = 0
                OnClick = EntDateCheckClick
              end
              object StartEntDateTime: TDateTimePicker
                Left = 28
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614
                Time = 37614
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 1
              end
              object EndEntDateTime: TDateTimePicker
                Left = 164
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614.9999884259
                Time = 37614.9999884259
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 2
              end
            end
          end
        end
      end
      object DBGrid1: TDBGrid
        Left = 0
        Top = 141
        Width = 568
        Height = 196
        HelpContext = 21
        Align = alClient
        DataSource = PersHistSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        PopupMenu = PersonsPopupMenu
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = [fsBold]
        Columns = <
          item
            Expanded = False
            FieldName = 'Comment'
            Title.Caption = #1050#1086#1084#1077#1085#1090#1072#1088
            Width = 100
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'DateChanged'
            Title.Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
            Width = 120
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'ChangedBy'
            Title.Caption = #1055#1088#1086#1084#1077#1085#1077#1085#1086' '#1086#1090
            Width = 100
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'ID'
            Title.Caption = #1042#1093'. '#8470
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Name'
            Title.Caption = #1048#1084#1077' '#1085#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
            Width = 200
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EGN'
            Title.Caption = #1045#1043#1053
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Se'
            Title.Caption = #1055#1086#1083
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Tax'
            Title.Caption = #1058#1072#1082#1089#1072
            Width = 100
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Telephone'
            Title.Caption = #1058#1077#1083#1077#1092#1086#1085
            Width = 150
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Address'
            Title.Caption = #1040#1076#1088#1077#1089
            Width = 200
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Room_Code'
            Title.Caption = #1057#1090#1072#1103
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntOn'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
            Width = 120
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntBy'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
            Width = 200
            Visible = True
          end>
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1046#1077#1083#1072#1085#1080#1103
      ImageIndex = 1
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 568
        Height = 141
        HelpContext = 21
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object PageControl1: TPageControl
          Left = 0
          Top = 0
          Width = 568
          Height = 141
          HelpContext = 21
          ActivePage = WishOwnTab
          Align = alClient
          HotTrack = True
          TabIndex = 0
          TabOrder = 0
          object WishOwnTab: TTabSheet
            Caption = #1044#1072#1085#1085#1080' '#1079#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
            ImageIndex = 1
            object GroupBox14: TGroupBox
              Left = 4
              Top = 0
              Width = 293
              Height = 77
              HelpContext = 21
              TabOrder = 0
              object Label15: TLabel
                Left = 68
                Top = 52
                Width = 22
                Height = 13
                HelpContext = 21
                Caption = #1048#1084#1077
              end
              object Label12: TLabel
                Left = 16
                Top = 20
                Width = 74
                Height = 13
                HelpContext = 21
                Caption = #1042#1093#1086#1076#1103#1097' '#1085#1086#1084#1077#1088
              end
              object CandidWishCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 69
                Height = 17
                HelpContext = 21
                Caption = #1050#1072#1085#1076#1080#1076#1072#1090
                TabOrder = 0
                OnClick = CandidWishCheckClick
              end
              object CandidNumEdit: TCSpinEdit
                Left = 96
                Top = 17
                Width = 53
                Height = 22
                HelpContext = 21
                Enabled = False
                MaxValue = 200000000
                MinValue = 1
                TabOrder = 1
                Value = 1
                OnChange = CandidNumEditChange
              end
              object CandidWishNameLookup: TDBLookupComboBox
                Left = 96
                Top = 48
                Width = 189
                Height = 21
                HelpContext = 21
                Enabled = False
                KeyField = 'ID'
                ListField = 'Name'
                ListSource = PersonsSource
                TabOrder = 2
                OnCloseUp = CandidWishNameLookupCloseUp
              end
            end
          end
          object WishOperTab: TTabSheet
            Caption = #1054#1087#1077#1088#1072#1090#1086#1088
            object GroupBox8: TGroupBox
              Left = 4
              Top = 0
              Width = 277
              Height = 53
              HelpContext = 21
              TabOrder = 0
              object Label9: TLabel
                Left = 8
                Top = 24
                Width = 22
                Height = 13
                HelpContext = 21
                Caption = #1048#1084#1077
              end
              object ChangedWishCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 88
                Height = 17
                HelpContext = 21
                Caption = #1055#1088#1086#1084#1077#1085#1077#1085' '#1086#1090
                TabOrder = 0
                OnClick = ChangedWishCheckClick
              end
              object ChangedWishOperCombo: TComboBox
                Left = 36
                Top = 20
                Width = 233
                Height = 21
                HelpContext = 21
                AutoDropDown = True
                Enabled = False
                ItemHeight = 13
                Sorted = True
                TabOrder = 1
              end
            end
            object GroupBox9: TGroupBox
              Left = 4
              Top = 56
              Width = 277
              Height = 53
              HelpContext = 21
              TabOrder = 1
              object Label10: TLabel
                Left = 8
                Top = 24
                Width = 13
                Height = 13
                HelpContext = 21
                Caption = #1054#1090
              end
              object Label11: TLabel
                Left = 144
                Top = 24
                Width = 12
                Height = 13
                HelpContext = 21
                Caption = #1076#1086
              end
              object ChangedWishDateCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 109
                Height = 17
                HelpContext = 21
                Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
                TabOrder = 0
                OnClick = ChangedWishDateCheckClick
              end
              object StartChangedWishDateTime: TDateTimePicker
                Left = 28
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614
                Time = 37614
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 1
              end
              object EndChangedWishDateTime: TDateTimePicker
                Left = 164
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614.9999884259
                Time = 37614.9999884259
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 2
              end
            end
            object GroupBox11: TGroupBox
              Left = 284
              Top = 0
              Width = 273
              Height = 53
              HelpContext = 21
              TabOrder = 2
              object Label13: TLabel
                Left = 8
                Top = 24
                Width = 22
                Height = 13
                HelpContext = 21
                Caption = #1048#1084#1077
              end
              object EntWishOperCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 81
                Height = 17
                HelpContext = 21
                Caption = #1042#1098#1074#1077#1076#1077#1085' '#1086#1090
                TabOrder = 0
                OnClick = EntWishOperCheckClick
              end
              object EntWishOperCombo: TComboBox
                Left = 36
                Top = 20
                Width = 233
                Height = 21
                HelpContext = 21
                AutoDropDown = True
                Enabled = False
                ItemHeight = 13
                Sorted = True
                TabOrder = 1
              end
            end
            object GroupBox12: TGroupBox
              Left = 284
              Top = 56
              Width = 273
              Height = 53
              HelpContext = 21
              TabOrder = 3
              object Label14: TLabel
                Left = 8
                Top = 24
                Width = 13
                Height = 13
                HelpContext = 21
                Caption = #1054#1090
              end
              object Label16: TLabel
                Left = 144
                Top = 24
                Width = 12
                Height = 13
                HelpContext = 21
                Caption = #1076#1086
              end
              object EntWishDateCheck: TCheckBox
                Left = 8
                Top = 0
                Width = 121
                Height = 17
                HelpContext = 21
                Caption = #1044#1072#1090#1072' '#1085#1072' '#1074#1098#1074#1077#1078#1076#1072#1085#1077
                TabOrder = 0
                OnClick = EntWishDateCheckClick
              end
              object StartEntWishDateTime: TDateTimePicker
                Left = 28
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614
                Time = 37614
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 1
              end
              object EndEntWishDateTime: TDateTimePicker
                Left = 164
                Top = 20
                Width = 105
                Height = 21
                HelpContext = 21
                CalAlignment = dtaLeft
                Date = 37614.9999884259
                Time = 37614.9999884259
                DateFormat = dfShort
                DateMode = dmComboBox
                Enabled = False
                Kind = dtkDate
                ParseInput = False
                TabOrder = 2
              end
            end
          end
        end
      end
      object DBGrid2: TDBGrid
        Left = 0
        Top = 141
        Width = 568
        Height = 196
        HelpContext = 21
        Align = alClient
        DataSource = WishesSource
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ParentFont = False
        PopupMenu = WishesPopupMenu
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = [fsBold]
        Columns = <
          item
            Expanded = False
            FieldName = 'Comment'
            Title.Caption = #1050#1086#1084#1077#1085#1090#1072#1088
            Width = 100
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'DateChanged'
            Title.Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
            Width = 120
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'ChangedBy'
            Title.Caption = #1055#1088#1086#1084#1077#1085#1077#1085#1086' '#1086#1090
            Width = 100
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Person_ID'
            Title.Caption = #1042#1093'. '#8470
            Width = 50
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Person'
            Title.Caption = #1048#1084#1077' '#1085#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
            Width = 200
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Profile'
            Title.Caption = #1055#1088#1086#1092#1080#1083
            Width = 150
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Priority'
            Title.Caption = #1055#1088#1080#1086#1088'.'
            Width = 40
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
            FieldName = 'FromOlym'
            Title.Caption = #1054#1090' '#1086#1083#1080#1084#1087'.'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'OlympScore'
            Title.Caption = #1054#1083#1080#1084'. '#1054#1094'.'
            Width = 65
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'GoToE'
            Title.Caption = #1053#1072' '#1080#1079#1087'.'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntOn'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
            Width = 120
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'EntBy'
            Title.Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
            Width = 200
            Visible = True
          end>
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 365
    Width = 576
    Height = 29
    HelpContext = 21
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      576
      29)
    object FoundLabel: TLabel
      Left = 4
      Top = 8
      Width = 55
      Height = 13
      HelpContext = 21
      Caption = #1053#1072#1084#1077#1088#1077#1085#1080':'
    end
    object BitBtn1: TBitBtn
      Left = 500
      Top = 3
      Width = 75
      Height = 25
      HelpContext = 21
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = #1047#1072#1090#1074#1086#1088#1080
      ModalResult = 2
      TabOrder = 0
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
    object SearchBtn: TBitBtn
      Left = 340
      Top = 3
      Width = 75
      Height = 25
      HelpContext = 21
      Anchors = [akRight, akBottom]
      Caption = #1058#1098#1088#1089#1077#1085#1077
      Default = True
      TabOrder = 1
      OnClick = SearchBtnClick
      Glyph.Data = {
        36050000424D360500000000000036040000280000000E000000100000000100
        08000000000000010000120B0000120B00000001000000010000000000008400
        0000FF000000FFFF000084848400C6C6C600CED6D600FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00060606060606
        0606060600000606000006060606060606060601030200060000060600000000
        0000010302020000000006060405050505010302020505000000060604070707
        0103020205070500000006060400000405020205070705000000060405030500
        0404050707070500000004070305030500050707070705000000040307030503
        0005070707070500000004070307030500050707070705000000060407030700
        0507070707070500000006060404000507070707070705000000060604070707
        0707070700000000000006060407070707070707050704060000060604070707
        0707070705040606000006060404040404040404040606060000}
    end
    object PrintBtn: TBitBtn
      Left = 420
      Top = 3
      Width = 75
      Height = 25
      HelpContext = 21
      Anchors = [akRight, akBottom]
      Caption = #1055#1077#1095#1072#1090
      TabOrder = 2
      OnClick = PrintBtnClick
      Glyph.Data = {
        16050000424D16050000000000003604000028000000100000000E0000000100
        080000000000E0000000120B0000120B00000001000000010000000000008484
        8400C6C6C600CED6D60000FFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00030300000000
        0000000000000003030303000202020202020202020002000303000000000000
        0000000000000002000300020202020202040404020200000003000202020202
        0201010102020002000300000000000000000000000000020200000202020202
        0202020202000200020003000000000000000000000200020000030300050505
        0505050505000200020003030300050000000000050000000003030303000505
        0505050505050003030303030303000500000000000500030303030303030005
        0505050505050500030303030303030000000000000000000303}
    end
  end
  object PersonsHistoryQuery: TQuery
    OnCalcFields = PersonsHistoryQueryCalcFields
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM persons_history')
    Left = 384
    Top = 184
    object PersonsHistoryQueryDateChanged: TDateTimeField
      FieldName = 'DateChanged'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".DateChanged'
    end
    object PersonsHistoryQueryChangedBy: TStringField
      FieldName = 'ChangedBy'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".ChangedBy'
      Size = 50
    end
    object PersonsHistoryQueryComment: TStringField
      FieldName = 'Comment'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Comment'
    end
    object PersonsHistoryQueryID: TIntegerField
      FieldName = 'ID'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".ID'
    end
    object PersonsHistoryQueryName: TStringField
      FieldName = 'Name'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Name'
      Size = 200
    end
    object PersonsHistoryQueryEGN: TStringField
      FieldName = 'EGN'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".EGN'
      Size = 10
    end
    object PersonsHistoryQueryTelephone: TStringField
      FieldName = 'Telephone'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Telephone'
      Size = 50
    end
    object PersonsHistoryQueryAddress: TStringField
      FieldName = 'Address'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Address'
      Size = 200
    end
    object PersonsHistoryQuerySex: TIntegerField
      FieldName = 'Sex'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Sex'
    end
    object PersonsHistoryQuerySe: TStringField
      FieldKind = fkCalculated
      FieldName = 'Se'
      Size = 1
      Calculated = True
    end
    object PersonsHistoryQueryTax_id: TIntegerField
      FieldName = 'Tax_id'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Tax_id'
    end
    object PersonsHistoryQueryTax: TStringField
      FieldKind = fkLookup
      FieldName = 'Tax'
      LookupDataSet = Data.TaxesTable
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Tax_id'
      Size = 50
      Lookup = True
    end
    object PersonsHistoryQueryRoom_Code: TStringField
      FieldName = 'Room_Code'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".Room_Code'
      Size = 10
    end
    object PersonsHistoryQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".EntOn'
    end
    object PersonsHistoryQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Persons_History".EntBy'
      Size = 50
    end
  end
  object EntByQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT entby FROM persons_history')
    Left = 540
    Top = 168
    object EntByQueryentby: TStringField
      FieldName = 'entby'
      Size = 50
    end
  end
  object ChangedByQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT changedby FROM persons_history')
    Left = 540
    Top = 200
    object ChangedByQuerychangedby: TStringField
      FieldName = 'changedby'
      Size = 50
    end
  end
  object PersHistSource: TDataSource
    DataSet = PersonsHistoryQuery
    Left = 384
    Top = 216
  end
  object PersonsQuery: TQuery
    CachedUpdates = True
    AutoRefresh = True
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM dbo.Persons ORDER BY ID')
    Left = 424
    Top = 100
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
  end
  object PersonsSource: TDataSource
    DataSet = PersonsQuery
    Left = 456
    Top = 100
  end
  object ChangedWishQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT changedby FROM wishes_history')
    Left = 540
    Top = 232
    object StringField1: TStringField
      FieldName = 'changedby'
      Size = 50
    end
  end
  object WishesQuery: TQuery
    OnCalcFields = WishesQueryCalcFields
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT * FROM wishes_history')
    Left = 416
    Top = 184
    object WishesQueryDateChanged: TDateTimeField
      FieldName = 'DateChanged'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".DateChanged'
    end
    object WishesQueryChangedBy: TStringField
      FieldName = 'ChangedBy'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".ChangedBy'
      Size = 50
    end
    object WishesQueryComment: TStringField
      FieldName = 'Comment'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".Comment'
    end
    object WishesQueryPerson_ID: TIntegerField
      FieldName = 'Person_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".Person_ID'
    end
    object WishesQueryPerson: TStringField
      FieldKind = fkLookup
      FieldName = 'Person'
      LookupDataSet = PersonsQuery
      LookupKeyFields = 'ID'
      LookupResultField = 'Name'
      KeyFields = 'Person_ID'
      Size = 200
      Lookup = True
    end
    object WishesQueryProfile_ID: TIntegerField
      FieldName = 'Profile_ID'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".Profile_ID'
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
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".Priority'
    end
    object WishesQueryScore: TFloatField
      FieldName = 'Score'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".Score'
      DisplayFormat = '#0.00'
    end
    object WishesQueryFromOlymp: TBooleanField
      FieldName = 'FromOlymp'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".FromOlymp'
    end
    object WishesQueryFromOlym: TStringField
      FieldKind = fkCalculated
      FieldName = 'FromOlym'
      Size = 5
      Calculated = True
    end
    object WishesQueryOlympScore: TFloatField
      FieldName = 'OlympScore'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".OlympScore'
      DisplayFormat = '#0.00'
    end
    object WishesQueryGoToExam: TBooleanField
      FieldName = 'GoToExam'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".GoToExam'
    end
    object WishesQueryGoToExa: TStringField
      FieldKind = fkCalculated
      FieldName = 'GoToE'
      Size = 5
      Calculated = True
    end
    object WishesQueryEntOn: TDateTimeField
      FieldName = 'EntOn'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".EntOn'
    end
    object WishesQueryEntBy: TStringField
      FieldName = 'EntBy'
      Origin = 'RECEPTIONDATABASE."dbo.Wishes_History".EntBy'
      Size = 50
    end
  end
  object WishesSource: TDataSource
    DataSet = WishesQuery
    Left = 416
    Top = 216
  end
  object EntByWishQuery: TQuery
    DatabaseName = 'ReceptionDatabase'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'SELECT DISTINCT entby FROM Wishes_history')
    Left = 540
    Top = 264
    object StringField2: TStringField
      FieldName = 'entby'
      Size = 50
    end
  end
  object PersonsPopupMenu: TPopupMenu
    Left = 304
    Top = 212
    object NAll: TMenuItem
      Caption = #1042#1089#1080#1095#1082#1080
      OnClick = NAllClick
    end
    object N14: TMenuItem
      Caption = '-'
    end
    object N1: TMenuItem
      Caption = #1050#1086#1084#1077#1085#1090#1072#1088
      Checked = True
      Enabled = False
    end
    object N2: TMenuItem
      AutoCheck = True
      Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
      Checked = True
      OnClick = N2Click
    end
    object N3: TMenuItem
      AutoCheck = True
      Caption = #1055#1088#1086#1084#1077#1085#1077#1085#1086' '#1086#1090
      Checked = True
      OnClick = N3Click
    end
    object N4: TMenuItem
      AutoCheck = True
      Caption = #1042#1093'. '#1085#1086#1084#1077#1088
      Checked = True
      OnClick = N4Click
    end
    object N5: TMenuItem
      AutoCheck = True
      Caption = #1048#1084#1077' '#1085#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
      Checked = True
      OnClick = N5Click
    end
    object N6: TMenuItem
      AutoCheck = True
      Caption = #1045#1043#1053
      Checked = True
      OnClick = N6Click
    end
    object N7: TMenuItem
      AutoCheck = True
      Caption = #1055#1086#1083
      Checked = True
      OnClick = N7Click
    end
    object N8: TMenuItem
      AutoCheck = True
      Caption = #1058#1072#1082#1089#1072
      Checked = True
      OnClick = N8Click
    end
    object N9: TMenuItem
      AutoCheck = True
      Caption = #1058#1077#1083#1077#1092#1086#1085
      Checked = True
      OnClick = N9Click
    end
    object N10: TMenuItem
      AutoCheck = True
      Caption = #1040#1076#1088#1077#1089
      Checked = True
      OnClick = N10Click
    end
    object N11: TMenuItem
      AutoCheck = True
      Caption = #1057#1090#1072#1103
      Checked = True
      OnClick = N11Click
    end
    object N12: TMenuItem
      AutoCheck = True
      Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
      Checked = True
      OnClick = N12Click
    end
    object N13: TMenuItem
      AutoCheck = True
      Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
      Checked = True
      OnClick = N13Click
    end
  end
  object WishesPopupMenu: TPopupMenu
    Left = 304
    Top = 244
    object MenuItem1: TMenuItem
      Caption = #1042#1089#1080#1095#1082#1080
      OnClick = MenuItem1Click
    end
    object MenuItem2: TMenuItem
      Caption = '-'
    end
    object MenuItem3: TMenuItem
      Caption = #1050#1086#1084#1077#1085#1090#1072#1088
      Checked = True
      Enabled = False
    end
    object MenuItem4: TMenuItem
      AutoCheck = True
      Caption = #1044#1072#1090#1072' '#1085#1072' '#1087#1088#1086#1084#1103#1085#1072
      Checked = True
      OnClick = MenuItem4Click
    end
    object MenuItem5: TMenuItem
      AutoCheck = True
      Caption = #1055#1088#1086#1084#1077#1085#1077#1085#1086' '#1086#1090
      Checked = True
      OnClick = MenuItem5Click
    end
    object MenuItem6: TMenuItem
      AutoCheck = True
      Caption = #1042#1093'. '#1085#1086#1084#1077#1088
      Checked = True
      OnClick = MenuItem6Click
    end
    object MenuItem7: TMenuItem
      AutoCheck = True
      Caption = #1048#1084#1077' '#1085#1072' '#1082#1072#1085#1076#1080#1076#1072#1090#1072
      Checked = True
      OnClick = MenuItem7Click
    end
    object MenuItem8: TMenuItem
      AutoCheck = True
      Caption = #1055#1088#1086#1092#1080#1083
      Checked = True
      OnClick = MenuItem8Click
    end
    object MenuItem9: TMenuItem
      AutoCheck = True
      Caption = #1055#1088#1080#1086#1088#1080#1090#1077#1090
      Checked = True
      OnClick = MenuItem9Click
    end
    object MenuItem10: TMenuItem
      AutoCheck = True
      Caption = #1054#1094#1077#1085#1082#1072
      Checked = True
      OnClick = MenuItem10Click
    end
    object MenuItem11: TMenuItem
      AutoCheck = True
      Caption = #1054#1090' '#1086#1083#1080#1084#1087#1080#1072#1076#1072
      Checked = True
      OnClick = MenuItem11Click
    end
    object MenuItem12: TMenuItem
      AutoCheck = True
      Caption = #1054#1083#1080#1084'. '#1054#1094'.'
      Checked = True
      OnClick = MenuItem12Click
    end
    object MenuItem13: TMenuItem
      AutoCheck = True
      Caption = #1053#1072' '#1080#1079#1087#1080#1090
      Checked = True
      OnClick = MenuItem13Click
    end
    object MenuItem14: TMenuItem
      AutoCheck = True
      Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1085#1072
      Checked = True
      OnClick = MenuItem14Click
    end
    object MenuItem15: TMenuItem
      AutoCheck = True
      Caption = #1042#1098#1074#1077#1076#1077#1085#1086' '#1086#1090
      Checked = True
      OnClick = MenuItem15Click
    end
  end
end
