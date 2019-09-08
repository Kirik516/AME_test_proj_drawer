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
  DesignSize = (
    600
    400)
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonRefresh: TButton
    Left = 488
    Top = 367
    Width = 104
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Refresh'
    TabOrder = 0
  end
  inline GraphView1: TGraphView
    Left = 8
    Top = 8
    Width = 584
    Height = 345
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 1
    ExplicitLeft = 8
    ExplicitTop = 8
    ExplicitWidth = 584
    ExplicitHeight = 345
    inherited Graph: TLabel
      Width = 553
      Height = 316
    end
    inherited LabelX: TLabel
      Top = 332
      Width = 584
      ExplicitTop = 332
    end
    inherited LabelY: TLabel
      Height = 316
    end
    inherited LabelTitle: TLabel
      Width = 584
    end
  end
end
