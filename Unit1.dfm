object GraphView: TGraphView
  Left = 0
  Top = 0
  Width = 320
  Height = 240
  TabOrder = 0
  object Graph: TLabel
    Left = 31
    Top = 16
    Width = 289
    Height = 211
    Align = alClient
    Caption = 'Graph'
    ExplicitLeft = 112
    ExplicitTop = 80
    ExplicitWidth = 29
    ExplicitHeight = 13
  end
  object LabelX: TLabel
    Left = 0
    Top = 227
    Width = 320
    Height = 13
    Align = alBottom
    Alignment = taCenter
    Caption = 'LabelX'
    ExplicitLeft = 128
    ExplicitTop = 168
    ExplicitWidth = 31
  end
  object LabelY: TLabel
    Left = 0
    Top = 16
    Width = 31
    Height = 211
    Align = alLeft
    Caption = 'LabelY'
    ExplicitLeft = 40
    ExplicitTop = 80
    ExplicitHeight = 13
  end
  object LabelTitle: TLabel
    Left = 0
    Top = 0
    Width = 320
    Height = 16
    Align = alTop
    Caption = 'Graph for function: y = A + Bsin(Ct)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 235
  end
end
