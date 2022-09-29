object FLogin: TFLogin
  Left = 0
  Top = 0
  Caption = 'Login_Forma'
  ClientHeight = 172
  ClientWidth = 292
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = -5
    Top = 3
    Width = 289
    Height = 169
    Caption = 'Login_Group'
    TabOrder = 0
    object TUsername: TStaticText
      Left = 16
      Top = 32
      Width = 85
      Height = 19
      Caption = 'Korisni'#269'ko ime:'
      TabOrder = 0
    end
    object TPassword: TStaticText
      Left = 16
      Top = 57
      Width = 47
      Height = 19
      Caption = 'Lozinka:'
      TabOrder = 1
    end
    object username: TEdit
      Left = 107
      Top = 28
      Width = 121
      Height = 23
      TabOrder = 2
    end
    object password: TEdit
      Left = 107
      Top = 57
      Width = 121
      Height = 23
      TabOrder = 3
    end
    object BLogin: TButton
      Left = 107
      Top = 109
      Width = 86
      Height = 25
      Caption = 'Login'
      TabOrder = 4
      OnClick = BLoginClick
    end
    object CheckBox1: TCheckBox
      Left = 107
      Top = 86
      Width = 142
      Height = 17
      Caption = 'Spremi korisni'#269'ko ime'
      TabOrder = 5
    end
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    Host = '127.0.0.1'
    Port = 25555
    ReadTimeout = -1
    Left = 16
    Top = 120
  end
  object XMLDocument1: TXMLDocument
    FileName = 'history.xml'
    BeforeOpen = XMLDocument1BeforeOpen
    Left = 200
    Top = 112
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 104
    Top = 168
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 200
    Top = 184
  end
  object Signatory1: TSignatory
    Codec = Codec2
    Left = 32
    Top = 176
  end
  object Codec2: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary2
    Left = 72
    Top = 144
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary2: TCryptographicLibrary
    Left = 288
    Top = 144
  end
end
