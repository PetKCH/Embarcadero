object DataModule1: TDataModule1
  Height = 600
  Width = 800
  PixelsPerInch = 120
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Password="";User ID=Admin;Data ' +
      'Source=Data.mdb;Mode=Share Deny None;Persist Security Info=True;' +
      'Jet OLEDB:System database="";Jet OLEDB:Registry Path="";Jet OLED' +
      'B:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Databas' +
      'e Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:G' +
      'lobal Bulk Transactions=1;Jet OLEDB:New Database Password="";Jet' +
      ' OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=F' +
      'alse;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Comp' +
      'act Without Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 80
    Top = 216
  end
  object TPoslovnica: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Poslovnica'
    Left = 140
    Top = 280
    object TPoslovnicaID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object TPoslovnicaNaziv: TWideStringField
      FieldName = 'Naziv'
      Size = 255
    end
    object TPoslovnicaAdresa: TWideStringField
      FieldName = 'Adresa'
      Size = 255
    end
    object TPoslovnicaBrojstanica: TIntegerField
      FieldName = 'Broj stanica'
    end
    object TPoslovnicaMjesto: TWideStringField
      FieldName = 'Mjesto'
      Size = 255
    end
    object TPoslovnicaSlika: TBlobField
      FieldName = 'Slika'
    end
  end
  object DPoslovnica: TDataSource
    DataSet = TPoslovnica
    Left = 152
    Top = 200
  end
  object TPromet: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Filtered = True
    OnCalcFields = TPrometCalcFields
    IndexFieldNames = 'ID_Poslovnica'
    MasterFields = 'ID'
    MasterSource = DPoslovnica
    TableName = 'Promet'
    Left = 232
    Top = 288
    object TPrometID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object TPrometDatum: TDateTimeField
      FieldName = 'Datum'
    end
    object TPrometUkupno: TIntegerField
      FieldName = 'Ukupno'
    end
    object TPrometID_Poslovnica: TIntegerField
      FieldName = 'ID_Poslovnica'
    end
    object TPrometEUR: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'EUR'
      Calculated = True
    end
  end
  object DPromet: TDataSource
    DataSet = TPromet
    Left = 240
    Top = 192
  end
  object TVrsta_Usluga: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Vrsta_Usluga'
    Left = 318
    Top = 296
    object TVrsta_UslugaID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object TVrsta_UslugaID_Poslovnica: TIntegerField
      FieldName = 'ID_Poslovnica'
    end
    object TVrsta_UslugaCar_Detailing: TBooleanField
      FieldName = 'Car_Detailing'
    end
    object TVrsta_UslugaMlaznica: TBooleanField
      FieldName = 'Mlaznica'
    end
    object TVrsta_UslugaAuto_Cetke: TBooleanField
      FieldName = 'Auto_Cetke'
    end
    object TVrsta_UslugaNaziv: TStringField
      FieldKind = fkLookup
      FieldName = 'Naziv'
      LookupDataSet = TPoslovnica
      LookupKeyFields = 'ID'
      LookupResultField = 'Naziv'
      KeyFields = 'ID_Poslovnica'
      Lookup = True
    end
    object TVrsta_UslugaOpis: TWideStringField
      FieldName = 'Opis'
      Size = 255
    end
  end
  object DVrsta_Usluga: TDataSource
    DataSet = TVrsta_Usluga
    Left = 322
    Top = 216
  end
end
