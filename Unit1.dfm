object Form1: TForm1
  Left = 680
  Top = 270
  Caption = 'Sudoku '#1080#1075#1088#1072
  ClientHeight = 425
  ClientWidth = 381
  Color = clMenuBar
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 10
    Top = 38
    Width = 2
    Height = 365
    Brush.Color = clBlack
  end
  object Shape2: TShape
    Left = 133
    Top = 38
    Width = 2
    Height = 365
    Brush.Color = clBlack
  end
  object Shape3: TShape
    Left = 252
    Top = 38
    Width = 2
    Height = 365
    Brush.Color = clBlack
  end
  object Shape4: TShape
    Left = 10
    Top = 38
    Width = 365
    Height = 2
    Brush.Color = clBlack
  end
  object Shape5: TShape
    Left = 10
    Top = 156
    Width = 365
    Height = 2
    Brush.Color = clBlack
  end
  object Shape7: TShape
    Left = 10
    Top = 278
    Width = 365
    Height = 2
    Brush.Color = clBlack
  end
  object Shape9: TShape
    Left = 10
    Top = 400
    Width = 365
    Height = 2
    Brush.Color = clBlack
  end
  object Shape10: TShape
    Left = 372
    Top = 38
    Width = 2
    Height = 365
    Brush.Color = clBlack
  end
  object Label1: TLabel
    Left = 142
    Top = -1
    Width = 105
    Height = 39
    Caption = 'Sudoku'
    Color = clGradientInactiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Tahoma'
    Font.Style = []
    Font.Quality = fqAntialiased
    ParentColor = False
    ParentFont = False
  end
  object Lock: TButton
    Left = 272
    Top = 7
    Width = 83
    Height = 25
    Caption = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    Visible = False
    OnClick = LockClick
  end
  object Button1: TButton
    Left = 40
    Top = 7
    Width = 75
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100
    TabOrder = 1
    OnClick = CheckValues
  end
  object MainMenu1: TMainMenu
    Left = 16
    object File1: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object New: TMenuItem
        Caption = #1053#1072#1095#1072#1090#1100
        OnClick = NewClick
      end
      object N1: TMenuItem
        Caption = #1059#1088#1086#1074#1077#1085#1100
        object mnuEasy: TMenuItem
          Caption = #1051#1077#1075#1082#1086
          Checked = True
          OnClick = LvlEasy
        end
        object mnuMiddle: TMenuItem
          Caption = #1057#1088#1077#1076#1085#1077
          OnClick = LvlMiddle
        end
        object mnuHard: TMenuItem
          Caption = #1057#1083#1086#1078#1085#1086
          OnClick = LvlHard
        end
      end
      object Exit1: TMenuItem
        Caption = #1042'&'#1099#1093#1086#1076
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object Rules1: TMenuItem
        Caption = '&'#1055#1088#1072#1074#1080#1083#1072
        OnClick = Rules1Click
      end
    end
    object About1: TMenuItem
      Caption = '&'#1040#1074#1090#1086#1088
      OnClick = About1Click
    end
  end
end
