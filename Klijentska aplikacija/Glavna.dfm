object FGlavna: TFGlavna
  Left = 0
  Top = 0
  Caption = 'FGlavna'
  ClientHeight = 312
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 608
    Height = 305
    Caption = 'Dobrodo'#353'ao '
    TabOrder = 0
    object Label1: TLabel
      Left = 128
      Top = 0
      Width = 3
      Height = 15
      OnClick = Label1Click
    end
    object Label2: TLabel
      Left = 3
      Top = 57
      Width = 76
      Height = 15
      Caption = 'Veli'#269'ina vozila:'
    end
    object Label3: TLabel
      Left = 3
      Top = 86
      Width = 67
      Height = 15
      Caption = 'Vrsta paketa:'
    end
    object Label4: TLabel
      Left = 3
      Top = 120
      Width = 97
      Height = 15
      Caption = 'Popust (postotak):'
    end
    object Label5: TLabel
      Left = 3
      Top = 200
      Width = 113
      Height = 15
      Caption = 'Unesi BRUTO promet:'
    end
    object Label6: TLabel
      Left = 3
      Top = 229
      Width = 112
      Height = 15
      Caption = 'Odaberi vrstu usluga:'
    end
    object Label7: TLabel
      Left = 3
      Top = 256
      Width = 84
      Height = 15
      Caption = 'Odaberi mjesto:'
    end
    object Memo1: TMemo
      Left = 440
      Top = 13
      Width = 165
      Height = 36
      TabOrder = 0
    end
    object BUpdate: TButton
      Left = 472
      Top = 55
      Width = 101
      Height = 21
      Caption = 'A'#382'uriraj EURO'
      TabOrder = 1
      OnClick = BUpdateClick
    end
    object Button1: TButton
      Left = 474
      Top = 176
      Width = 99
      Height = 25
      Caption = 'Baza Podataka'
      TabOrder = 2
      OnClick = Button1Click
    end
    object BAdmin: TButton
      Left = 472
      Top = 240
      Width = 99
      Height = 25
      Caption = 'Admin Panel'
      TabOrder = 3
      OnClick = BAdminClick
    end
    object BBazaEdit: TButton
      Left = 474
      Top = 208
      Width = 97
      Height = 25
      Caption = 'Uredi Bazu'
      TabOrder = 4
      OnClick = BBazaEditClick
    end
    object ComboBox1: TComboBox
      Left = 85
      Top = 54
      Width = 145
      Height = 23
      TabOrder = 5
      Text = 'ComboBox1'
    end
    object ComboBox2: TComboBox
      Left = 85
      Top = 83
      Width = 145
      Height = 23
      TabOrder = 6
      Text = 'ComboBox2'
    end
    object Edit1: TEdit
      Left = 106
      Top = 112
      Width = 50
      Height = 23
      Alignment = taCenter
      NumbersOnly = True
      TabOrder = 7
      Text = '0'
    end
    object Button2: TButton
      Left = 3
      Top = 141
      Width = 153
      Height = 25
      Caption = 'Izra'#269'unaj cijenu paketa'
      TabOrder = 8
      OnClick = Button2Click
    end
    object Edit2: TEdit
      Left = 122
      Top = 197
      Width = 63
      Height = 23
      NumbersOnly = True
      TabOrder = 9
      Text = '100'
    end
    object ComboBox3: TComboBox
      Left = 122
      Top = 226
      Width = 108
      Height = 23
      TabOrder = 10
      Text = 'ComboBox3'
    end
    object Button3: TButton
      Left = 3
      Top = 277
      Width = 153
      Height = 25
      Caption = 'Izra'#269'unaj NETO promet'
      TabOrder = 11
      OnClick = Button3Click
    end
    object ComboBox4: TComboBox
      Left = 122
      Top = 255
      Width = 108
      Height = 23
      TabOrder = 12
      Text = 'ComboBox4'
    end
    object CheckBox1: TCheckBox
      Left = 464
      Top = 271
      Width = 145
      Height = 17
      Caption = 'Sakrij admin panel'
      TabOrder = 13
      OnClick = CheckBox1Click
    end
  end
  object RESTClient1: TRESTClient
    Accept = 
      'https://v1.nocodeapi.com/croatthetop/cx/EOIMmwaXfzVmyewg/rates/c' +
      'onvert'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 
      'https://v1.nocodeapi.com/croatthetop/cx/EOIMmwaXfzVmyewg/rates/c' +
      'onvert'
    ContentType = 'application/x-www-form-urlencoded'
    Params = <>
    Left = 330
    Top = 126
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        Name = 'amount'
        Value = '1'
      end
      item
        Name = 'from'
        Value = 'HRK'
      end
      item
        Name = 'to'
        Value = 'EUR'
      end>
    Response = RESTResponse1
    Left = 482
    Top = 124
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 375
    Top = 231
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 417
    Top = 90
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = Memo1
      Track = False
    end
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 248
    Top = 24
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 363
    Top = 6
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
end
