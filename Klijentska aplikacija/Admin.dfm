object FAdmin: TFAdmin
  Left = 0
  Top = 0
  Caption = 'FAdmin'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object BLoad: TButton
    Left = 8
    Top = 255
    Width = 75
    Height = 25
    Caption = 'Ucitaj'
    TabOrder = 0
    OnClick = BLoadClick
  end
  object LXML: TListView
    Left = 8
    Top = 8
    Width = 313
    Height = 241
    Columns = <
      item
        Caption = 'Username'
        Width = 100
      end
      item
        Caption = 'Timestamp'
      end>
    TabOrder = 1
    ViewStyle = vsReport
  end
  object BDelete: TButton
    Left = 89
    Top = 255
    Width = 75
    Height = 25
    Caption = 'Obrisi'
    TabOrder = 2
    OnClick = BDeleteClick
  end
  object BChange: TButton
    Left = 170
    Top = 255
    Width = 75
    Height = 25
    Caption = 'Izmjeni'
    TabOrder = 3
    OnClick = BChangeClick
  end
  object BAdd: TButton
    Left = 352
    Top = 66
    Width = 70
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 4
    OnClick = BAddClick
  end
  object Edit1: TEdit
    Left = 352
    Top = 8
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'invalid'
  end
  object Edit2: TEdit
    Left = 352
    Top = 37
    Width = 121
    Height = 23
    TabOrder = 6
    Text = '1.1.1960.'
  end
  object BEditor: TButton
    Left = 488
    Top = 400
    Width = 99
    Height = 33
    Caption = 'Login Editor'
    TabOrder = 7
    OnClick = BEditorClick
  end
  object XMLDocument1: TXMLDocument
    FileName = 'history.xml'
    Options = [doNodeAutoCreate, doAttrNull, doAutoPrefix, doNamespaceDecl, doAutoSave]
    BeforeOpen = XMLDocument1BeforeOpen
    BeforeClose = XMLDocument1BeforeClose
    Left = 96
    Top = 40
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 88
    Top = 184
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 160
    Top = 176
  end
end
