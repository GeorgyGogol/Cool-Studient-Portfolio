object CalcAge: TCalcAge
  Left = 0
  Top = 0
  Caption = #1042#1086#1079#1088#1072#1089#1090
  ClientHeight = 176
  ClientWidth = 229
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Padding.Left = 3
  Padding.Right = 3
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 15
  object gpClient: TGridPanel
    AlignWithMargins = True
    Left = 6
    Top = 3
    Width = 217
    Height = 143
    Align = alClient
    BevelOuter = bvNone
    Caption = 'gpClient'
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 80.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 1
        Control = dtpInput
        Row = 0
      end
      item
        Column = 0
        Control = Label1
        Row = 0
      end
      item
        Column = 0
        ColumnSpan = 2
        Control = Label2
        Row = 1
      end
      item
        Column = 1
        Control = lAges
        Row = 2
      end
      item
        Column = 0
        Control = Label4
        Row = 2
      end
      item
        Column = 0
        Control = Label5
        Row = 3
      end
      item
        Column = 1
        Control = lMonthes
        Row = 3
      end
      item
        Column = 0
        Control = Label7
        Row = 4
      end
      item
        Column = 1
        Control = lDays
        Row = 4
      end>
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 26.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 25.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 25.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 25.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 25.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 0
    ExplicitWidth = 195
    object dtpInput: TDateTimePicker
      AlignWithMargins = True
      Left = 83
      Top = 3
      Width = 131
      Height = 20
      Align = alClient
      Date = 36526.000000000000000000
      Time = 36526.000000000000000000
      TabOrder = 0
      ExplicitLeft = 84
      ExplicitTop = 4
      ExplicitWidth = 107
    end
    object Label1: TLabel
      Left = 0
      Top = 0
      Width = 80
      Height = 26
      Align = alClient
      Caption = #1042#1074#1077#1076#1080' '#1076#1072#1090#1091':'
      Layout = tlCenter
      ExplicitLeft = 1
      ExplicitTop = 1
      ExplicitWidth = 61
      ExplicitHeight = 15
    end
    object Label2: TLabel
      Left = 0
      Top = 26
      Width = 217
      Height = 25
      Align = alClient
      Alignment = taCenter
      Caption = #1055#1086#1083#1091#1095#1077#1085#1085#1099#1081' '#1074#1086#1079#1088#1072#1089#1090', '#1074#1089#1077#1075#1086
      Layout = tlCenter
      ExplicitLeft = 1
      ExplicitTop = 27
      ExplicitWidth = 153
      ExplicitHeight = 15
    end
    object lAges: TLabel
      Left = 80
      Top = 51
      Width = 137
      Height = 25
      Align = alClient
      Caption = 'lAges'
      Layout = tlCenter
      ExplicitLeft = 81
      ExplicitTop = 52
      ExplicitWidth = 29
      ExplicitHeight = 15
    end
    object Label4: TLabel
      Left = 0
      Top = 51
      Width = 80
      Height = 25
      Align = alClient
      Caption = #1051#1077#1090':'
      Layout = tlCenter
      ExplicitLeft = 1
      ExplicitTop = 52
      ExplicitWidth = 22
      ExplicitHeight = 15
    end
    object Label5: TLabel
      Left = 0
      Top = 76
      Width = 80
      Height = 25
      Align = alClient
      Caption = #1052#1077#1089#1103#1094#1077#1074':'
      Layout = tlCenter
      ExplicitLeft = 1
      ExplicitTop = 77
      ExplicitWidth = 51
      ExplicitHeight = 15
    end
    object lMonthes: TLabel
      Left = 80
      Top = 76
      Width = 137
      Height = 25
      Align = alClient
      Caption = 'lMonthes'
      Layout = tlCenter
      ExplicitLeft = 81
      ExplicitTop = 77
      ExplicitWidth = 50
      ExplicitHeight = 15
    end
    object Label7: TLabel
      Left = 0
      Top = 101
      Width = 80
      Height = 25
      Align = alClient
      Caption = #1044#1085#1077#1081
      Layout = tlCenter
      ExplicitLeft = 1
      ExplicitTop = 102
      ExplicitWidth = 28
      ExplicitHeight = 15
    end
    object lDays: TLabel
      Left = 80
      Top = 101
      Width = 137
      Height = 25
      Align = alClient
      Caption = 'lDays'
      Layout = tlCenter
      ExplicitLeft = 81
      ExplicitTop = 102
      ExplicitWidth = 28
      ExplicitHeight = 15
    end
  end
  object fpBottomControl: TFlowPanel
    Left = 3
    Top = 149
    Width = 223
    Height = 27
    Align = alBottom
    BevelOuter = bvNone
    Caption = 'fpBottomControl'
    FlowStyle = fsRightLeftBottomTop
    Padding.Left = 3
    Padding.Right = 3
    ShowCaption = False
    TabOrder = 1
    ExplicitWidth = 201
    object bbReturn: TBitBtn
      Left = 130
      Top = 2
      Width = 90
      Height = 25
      Caption = '&'#1047#1072#1082#1088#1099#1090#1100
      DoubleBuffered = True
      Kind = bkClose
      ParentDoubleBuffered = False
      TabOrder = 0
    end
    object bbCalc: TBitBtn
      Left = 40
      Top = 2
      Width = 90
      Height = 25
      Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 1
      OnClick = bbCalcClick
    end
  end
end
