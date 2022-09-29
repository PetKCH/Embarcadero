object FEditor: TFEditor
  Left = 0
  Top = 0
  Caption = 'FEditor'
  ClientHeight = 444
  ClientWidth = 629
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 103
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label2: TLabel
    Left = 8
    Top = 140
    Width = 45
    Height = 15
    Caption = 'Prezime:'
  end
  object Label3: TLabel
    Left = 8
    Top = 16
    Width = 81
    Height = 15
    Caption = 'Korisni'#269'ko ime:'
  end
  object Label4: TLabel
    Left = 8
    Top = 45
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label5: TLabel
    Left = 8
    Top = 82
    Width = 39
    Height = 15
    Caption = 'Admin:'
  end
  object Label6: TLabel
    Left = 8
    Top = 161
    Width = 22
    Height = 15
    Caption = 'OIB:'
  end
  object Label7: TLabel
    Left = 8
    Top = 190
    Width = 31
    Height = 15
    Caption = 'Pla'#263'a:'
  end
  object Button1: TButton
    Left = 8
    Top = 211
    Width = 75
    Height = 25
    Caption = 'Unesi'
    TabOrder = 0
    OnClick = Button1Click
  end
  object EUsername: TEdit
    Left = 112
    Top = 13
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object EPassword: TEdit
    Left = 112
    Top = 42
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object EAdmin: TEdit
    Left = 112
    Top = 71
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 3
  end
  object EIme: TEdit
    Left = 112
    Top = 100
    Width = 121
    Height = 23
    TabOrder = 4
  end
  object EPrezime: TEdit
    Left = 112
    Top = 129
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object EOIB: TEdit
    Left = 112
    Top = 158
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 6
  end
  object EPlaca: TEdit
    Left = 112
    Top = 187
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 7
  end
  object Button2: TButton
    Left = 470
    Top = 408
    Width = 104
    Height = 25
    Caption = 'U'#269'itaj promjenu'
    TabOrder = 8
    OnClick = Button2Click
  end
  object PrikazMemo: TMemo
    Left = 429
    Top = 280
    Width = 185
    Height = 122
    Lines.Strings = (
      'PrikazMemo')
    ParentShowHint = False
    ReadOnly = True
    ShowHint = False
    TabOrder = 9
  end
  object Button3: TButton
    Left = 89
    Top = 211
    Width = 104
    Height = 25
    Caption = 'Dohvati korisnika'
    TabOrder = 10
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 199
    Top = 211
    Width = 98
    Height = 25
    Caption = 'Izbri'#353'i korisnika'
    TabOrder = 11
    OnClick = Button4Click
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    Host = '127.0.0.1'
    Port = 25555
    ReadTimeout = 1000
    Left = 177
    Top = 276
  end
  object OpenDialog1: TOpenDialog
    Left = 584
    Top = 344
  end
  object IdUDPClient1: TIdUDPClient
    Active = True
    Port = 0
    Left = 88
    Top = 288
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 536
    Top = 96
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 528
    Top = 192
  end
  object Signatory1: TSignatory
    Left = 480
    Top = 144
  end
  object TaskDialog1: TTaskDialog
    Buttons = <>
    RadioButtons = <>
    OnButtonClicked = TaskDialog1ButtonClicked
    Left = 296
    Top = 336
  end
end
