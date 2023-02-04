object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Binary Search'
  ClientHeight = 97
  ClientWidth = 480
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = mmMain
  TextHeight = 13
  object MainLabel: TLabel
    Left = 0
    Top = 0
    Width = 480
    Height = 19
    Align = alTop
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1076#1083#1103' '#1091#1075#1072#1076#1099#1074#1072#1085#1080#1103' '#1095#1080#1089#1083#1072' '#1073#1080#1085#1072#1088#1085#1099#1084' '#1089#1087#1086#1089#1086#1073#1086#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ExplicitWidth = 402
  end
  object LabelNumber: TLabel
    Left = 0
    Top = 19
    Width = 480
    Height = 19
    Align = alTop
    Caption = '000 - '#1041#1086#1083#1100#1096#1077', '#1084#1077#1085#1100#1096#1077' '#1080#1083#1080' '#1091#1075#1072#1076#1072#1083'?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ExplicitWidth = 257
  end
  object GridPanel1: TGridPanel
    Left = 0
    Top = 47
    Width = 480
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        Value = 33.333333333333340000
      end
      item
        Value = 33.333333333333340000
      end
      item
        Value = 33.333333333333310000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = Button1
        Row = 0
      end
      item
        Column = 1
        Control = Button2
        Row = 0
      end
      item
        Column = 2
        Control = Button3
        Row = 0
      end>
    RowCollection = <
      item
        Value = 100.000000000000000000
      end>
    TabOrder = 0
    object Button1: TButton
      AlignWithMargins = True
      Left = 30
      Top = 3
      Width = 100
      Height = 25
      Margins.Left = 30
      Margins.Right = 30
      Action = aLess
      Align = alClient
      TabOrder = 0
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 190
      Top = 3
      Width = 100
      Height = 25
      Margins.Left = 30
      Margins.Right = 30
      Action = aReady
      Align = alClient
      TabOrder = 1
    end
    object Button3: TButton
      AlignWithMargins = True
      Left = 350
      Top = 3
      Width = 100
      Height = 25
      Margins.Left = 30
      Margins.Right = 30
      Action = aMore
      Align = alClient
      TabOrder = 2
    end
  end
  object sbMain: TStatusBar
    Left = 0
    Top = 78
    Width = 480
    Height = 19
    Panels = <
      item
        Text = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100': 10^2'
        Width = 120
      end
      item
        Text = #1052#1080#1085': -000'
        Width = 75
      end
      item
        Text = #1052#1072#1082#1089': -000'
        Width = 75
      end
      item
        Text = #1058#1077#1082#1091#1097#1072#1103' '#1080#1090#1077#1088#1072#1094#1080#1103': 000'
        Width = 150
      end
      item
        Width = 50
      end>
  end
  object mmMain: TMainMenu
    Left = 72
    Top = 128
    object N1: TMenuItem
      Caption = '&'#1055#1088#1086#1075#1088#1072#1084#1084#1072
      object aStart1: TMenuItem
        Action = aStart
      end
      object N3: TMenuItem
        Action = aReset
      end
      object N2: TMenuItem
        Action = aAutoSearch
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Action = aShowSettingsForm
      end
    end
  end
  object amMain: TActionManager
    Left = 16
    Top = 128
    StyleName = 'Platform Default'
    object aShowSettingsForm: TAction
      Category = #1060#1086#1088#1084#1099
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      OnExecute = aShowSettingsFormExecute
    end
    object aReset: TAction
      Category = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = #1057#1073#1088#1086#1089#1080#1090#1100
      ShortCut = 16466
      OnExecute = aResetExecute
    end
    object aMore: TAction
      Category = 'Runtime'
      Caption = #1041#1086#1083#1100#1096#1077
      Enabled = False
      ShortCut = 16461
      OnExecute = aMoreExecute
    end
    object aLess: TAction
      Category = 'Runtime'
      Caption = #1052#1077#1085#1100#1096#1077
      Enabled = False
      ShortCut = 16460
      OnExecute = aLessExecute
    end
    object TAction
    end
    object aReady: TAction
      Category = 'Runtime'
      Caption = #1059#1075#1072#1076#1072#1083
      Enabled = False
      ShortCut = 16455
      OnExecute = aReadyExecute
    end
    object aStart: TAction
      Category = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = #1053#1072#1095#1072#1090#1100' '#1091#1075#1072#1076#1099#1074#1072#1090#1100
      ShortCut = 16467
      OnExecute = aStartExecute
    end
    object aAutoSearch: TAction
      Category = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = #1040#1074#1090#1086#1074#1099#1095#1080#1089#1083#1077#1085#1080#1077
      OnExecute = aAutoSearchExecute
    end
  end
end
