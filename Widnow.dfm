object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'AME drawer'
  ClientHeight = 400
  ClientWidth = 600
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    600
    400)
  PixelsPerInch = 96
  TextHeight = 13
  object PathLabel: TLabel
    Left = 8
    Top = 367
    Width = 48
    Height = 13
    Alignment = taCenter
    Anchors = [akLeft, akBottom]
    Caption = 'File path'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 584
    Height = 353
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Graph for function: y = A + Bsin(Ct)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Padding.Left = 2
    Padding.Top = 2
    Padding.Right = 2
    Padding.Bottom = 2
    ParentFont = False
    TabOrder = 0
    object GraphLabel: TLabel
      Left = 47
      Top = 20
      Width = 533
      Height = 313
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 3
      ExplicitHeight = 13
    end
    object LabelX: TLabel
      Left = 4
      Top = 333
      Width = 576
      Height = 16
      Align = alBottom
      Alignment = taCenter
      Caption = 'LabelX'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 43
    end
    object LabelY: TLabel
      Left = 4
      Top = 20
      Width = 43
      Height = 313
      Align = alLeft
      Caption = 'LabelY'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitHeight = 16
    end
  end
  object ButtonRefresh: TButton
    Left = 488
    Top = 367
    Width = 104
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Refresh'
    TabOrder = 1
  end
  object PathEdit: TEdit
    Left = 62
    Top = 367
    Width = 339
    Height = 21
    Anchors = [akLeft, akBottom]
    TabOrder = 2
    Text = 'D:\Embarcadero\Projects\graph_coefs.tgh'
  end
  object ReopenButton: TButton
    Left = 407
    Top = 367
    Width = 75
    Height = 25
    Caption = 'Reopen'
    TabOrder = 3
    OnClick = ReopenButtonClick
  end
  object ResizeTimer: TTimer
    Enabled = False
    Interval = 200
    OnTimer = ResizeTimerTimer
    Left = 16
    Top = 48
  end
  object ScrollTimer: TTimer
    Enabled = False
    Interval = 16
    OnTimer = ScrollTimerTimer
    Left = 80
    Top = 48
  end
end
