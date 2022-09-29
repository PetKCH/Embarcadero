object FBazaEditor: TFBazaEditor
  Left = 0
  Top = 0
  Caption = 'FBazaEditor'
  ClientHeight = 561
  ClientWidth = 1111
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Naziv: TLabel
    Left = 823
    Top = 22
    Width = 32
    Height = 15
    Caption = 'Naziv:'
  end
  object Label1: TLabel
    Left = 823
    Top = 67
    Width = 39
    Height = 15
    Caption = 'Adresa:'
  end
  object Label2: TLabel
    Left = 984
    Top = 22
    Width = 64
    Height = 15
    Caption = 'Broj stanica:'
  end
  object Label3: TLabel
    Left = 984
    Top = 67
    Width = 39
    Height = 15
    Caption = 'Mjesto:'
  end
  object Button2: TButton
    Left = 286
    Top = 342
    Width = 75
    Height = 25
    Caption = 'Izbri'#353'i'
    TabOrder = 0
    OnClick = Button2Click
  end
  object DDodaj: TButton
    Left = 822
    Top = 117
    Width = 131
    Height = 25
    Caption = 'Dodaj Poslovnicu'
    TabOrder = 1
    OnClick = DDodajClick
  end
  object DBGrid1: TDBGrid
    Left = 40
    Top = 24
    Width = 617
    Height = 120
    DataSource = DataModule1.DPoslovnica
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Naziv'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Adresa'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Broj stanica'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Slika'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mjesto'
        Width = 100
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 40
    Top = 216
    Width = 425
    Height = 120
    DataSource = DataModule1.DPromet
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ukupno'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ID_Poslovnica'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'EUR'
        Visible = True
      end>
  end
  object DBGrid3: TDBGrid
    Left = 40
    Top = 392
    Width = 697
    Height = 120
    DataSource = DataModule1.DVrsta_Usluga
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ID_Poslovnica'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Car_Detailing'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mlaznica'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Auto_Cetke'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Naziv'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Opis'
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 40
    Top = 150
    Width = 240
    Height = 25
    DataSource = DataModule1.DPoslovnica
    TabOrder = 5
  end
  object DBNavigator2: TDBNavigator
    Left = 40
    Top = 342
    Width = 234
    Height = 25
    DataSource = DataModule1.DPromet
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbEdit, nbPost, nbCancel, nbRefresh]
    TabOrder = 6
  end
  object DBNavigator3: TDBNavigator
    Left = 40
    Top = 518
    Width = 240
    Height = 25
    DataSource = DataModule1.DVrsta_Usluga
    TabOrder = 7
  end
  object DBEdit1: TEdit
    Left = 822
    Top = 38
    Width = 121
    Height = 23
    Hint = 'Naziv'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
  end
  object DBEdit2: TEdit
    Left = 823
    Top = 88
    Width = 121
    Height = 23
    Hint = 'Adresa'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
  end
  object DBEdit3: TEdit
    Left = 984
    Top = 38
    Width = 121
    Height = 23
    Hint = 'Broj stanica'
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
  end
  object DBEdit4: TEdit
    Left = 984
    Top = 88
    Width = 121
    Height = 23
    Hint = 'Mjesto'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
  end
  object DBImage1: TDBImage
    Left = 663
    Top = 24
    Width = 122
    Height = 120
    DataField = 'Slika'
    DataSource = DataModule1.DPoslovnica
    TabOrder = 12
  end
  object Button1: TButton
    Left = 662
    Top = 150
    Width = 123
    Height = 25
    Caption = 'Unesi Sliku'
    TabOrder = 13
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 662
    Top = 181
    Width = 123
    Height = 25
    Caption = 'Izbri'#353'i Sliku'
    TabOrder = 14
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Left = 664
    Top = 212
  end
end
