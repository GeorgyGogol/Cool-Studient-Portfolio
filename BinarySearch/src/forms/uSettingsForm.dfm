object Settings: TSettings
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 160
  ClientWidth = 276
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  Padding.Left = 6
  Padding.Top = 3
  Padding.Right = 6
  Padding.Bottom = 3
  OldCreateOrder = True
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    Left = 6
    Top = 3
    Width = 264
    Height = 127
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 140.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = Label1
        Row = 0
      end
      item
        Column = 1
        Control = eMinVal
        Row = 0
      end
      item
        Column = 0
        Control = Label2
        Row = 1
      end
      item
        Column = 1
        Control = eMaxVal
        Row = 1
      end
      item
        Column = 1
        Control = eAccuracy
        Row = 2
      end
      item
        Column = 0
        Control = Label3
        Row = 2
      end>
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 27.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 27.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 27.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 0
    ExplicitHeight = 104
    object Label1: TLabel
      Left = 0
      Top = 0
      Width = 55
      Height = 13
      Align = alClient
      Alignment = taCenter
      Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077
      Layout = tlCenter
    end
    object eMinVal: TEdit
      AlignWithMargins = True
      Left = 143
      Top = 3
      Width = 118
      Height = 21
      Align = alClient
      TabOrder = 0
      Text = '0'
    end
    object Label2: TLabel
      Left = 0
      Top = 27
      Width = 49
      Height = 13
      Align = alClient
      Alignment = taCenter
      Caption = #1050#1086#1085#1077#1095#1085#1086#1077
      Layout = tlCenter
    end
    object eMaxVal: TEdit
      AlignWithMargins = True
      Left = 143
      Top = 30
      Width = 118
      Height = 21
      Align = alClient
      TabOrder = 1
      Text = '100'
    end
    object eAccuracy: TEdit
      AlignWithMargins = True
      Left = 143
      Top = 57
      Width = 118
      Height = 21
      Align = alClient
      TabOrder = 2
      Text = '2'
    end
    object Label3: TLabel
      Left = 0
      Top = 54
      Width = 130
      Height = 13
      Align = alClient
      Alignment = taCenter
      Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100', '#1089#1090#1077#1087#1077#1085#1100' 10'
      Layout = tlCenter
    end
  end
  object FlowPanel1: TFlowPanel
    Left = 6
    Top = 130
    Width = 264
    Height = 27
    Align = alBottom
    BevelOuter = bvNone
    Caption = 'FlowPanel1'
    FlowStyle = fsRightLeftTopBottom
    ShowCaption = False
    TabOrder = 1
    ExplicitTop = 107
    object BitBtn1: TBitBtn
      Left = 189
      Top = 0
      Width = 75
      Height = 25
      DoubleBuffered = True
      Kind = bkCancel
      ParentDoubleBuffered = False
      TabOrder = 0
    end
    object BitBtn2: TBitBtn
      Left = 114
      Top = 0
      Width = 75
      Height = 25
      DoubleBuffered = True
      Kind = bkOK
      ParentDoubleBuffered = False
      TabOrder = 1
    end
    object bbSetDefault: TBitBtn
      Left = 39
      Top = 0
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1086#1084#1085#1080#1090#1100'...'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 2
      OnClick = bbSetDefaultClick
    end
  end
end
