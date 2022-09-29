object ServerForm: TServerForm
  Left = 0
  Top = 0
  Caption = 'ServerForm'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 248
    Top = 48
    Width = 97
    Height = 25
    Caption = 'Generiraj klju'#269
    TabOrder = 0
    OnClick = Button1Click
  end
  object IdTCPServer1: TIdTCPServer
    Active = True
    Bindings = <
      item
        IP = '127.0.0.1'
        Port = 25555
      end>
    DefaultPort = 25555
    OnExecute = IdTCPServer1Execute
    Left = 216
    Top = 160
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Password="";User ID=Admin;Data ' +
      'Source=Users.mdb;Mode=Share Deny None;Extended Properties="";Per' +
      'sist Security Info=True;Jet OLEDB:System database="";Jet OLEDB:R' +
      'egistry Path="";Jet OLEDB:Database Password="";Jet OLEDB:Engine ' +
      'Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partia' +
      'l Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New ' +
      'Database Password="";Jet OLEDB:Create System Database=False;Jet ' +
      'OLEDB:Encrypt Database=False;Jet OLEDB:Don'#39't Copy Locale on Comp' +
      'act=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLE' +
      'DB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 304
    Top = 288
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Users'
    Left = 384
    Top = 232
    object ADOTable1ID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object ADOTable1Username: TWideStringField
      FieldName = 'Username'
      Size = 255
    end
    object ADOTable1Password: TWideMemoField
      FieldName = 'Password'
      BlobType = ftWideMemo
    end
    object ADOTable1Admin: TIntegerField
      FieldName = 'Admin'
    end
    object ADOTable1Ime: TWideMemoField
      FieldName = 'Ime'
      BlobType = ftWideMemo
    end
    object ADOTable1Prezime: TWideMemoField
      FieldName = 'Prezime'
      BlobType = ftWideMemo
    end
    object ADOTable1OIB: TIntegerField
      FieldName = 'OIB'
    end
    object ADOTable1Salt: TWideStringField
      FieldName = 'Salt'
      Size = 255
    end
    object ADOTable1Placa: TIntegerField
      FieldName = 'Placa'
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 328
    Top = 246
  end
  object IdUDPServer1: TIdUDPServer
    Active = True
    Bindings = <
      item
        IP = '127.0.0.1'
        Port = 11111
      end>
    DefaultPort = 0
    OnUDPRead = IdUDPServer1UDPRead
    Left = 152
    Top = 288
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 88
    Top = 224
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object Signatory1: TSignatory
    Left = 72
    Top = 296
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 48
    Top = 176
  end
end
