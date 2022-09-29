object FBaza: TFBaza
  Left = 0
  Top = 0
  Caption = 'FBaza'
  ClientHeight = 666
  ClientWidth = 893
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Label1: TLabel
    Left = 703
    Top = 260
    Width = 34
    Height = 15
    Caption = 'HRK ~'
  end
  object Label2: TLabel
    Left = 791
    Top = 260
    Width = 21
    Height = 15
    Caption = 'EUR'
  end
  object BCalculator: TButton
    Left = 695
    Top = 286
    Width = 75
    Height = 25
    Caption = 'Kalkulator'
    TabOrder = 0
    OnClick = BCalculatorClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 577
    Height = 120
    DataSource = DataModule1.DPoslovnica
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnMouseEnter = DBGrid1MouseEnter
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 34
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Naziv'
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Adresa'
        Width = 112
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Broj stanica'
        Width = 76
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Slika'
        Width = 88
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mjesto'
        Width = 67
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 8
    Top = 474
    Width = 433
    Height = 100
    DataSource = DataModule1.DPromet
    ReadOnly = True
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
    Left = 8
    Top = 257
    Width = 577
    Height = 120
    DataSource = DataModule1.DVrsta_Usluga
    ReadOnly = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Naziv'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ID'
        Width = 30
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ID_Poslovnica'
        Width = 26
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
        FieldName = 'Opis'
        Width = 350
        Visible = True
      end>
  end
  object Ehrk: TEdit
    Left = 656
    Top = 257
    Width = 41
    Height = 23
    BiDiMode = bdRightToLeft
    NumbersOnly = True
    ParentBiDiMode = False
    TabOrder = 4
    Text = '1'
  end
  object Edit1: TEdit
    Left = 743
    Top = 257
    Width = 42
    Height = 23
    ReadOnly = True
    TabOrder = 5
  end
  object ESearch: TEdit
    Left = 64
    Top = 134
    Width = 97
    Height = 23
    TabOrder = 6
    TextHint = 'Naziv'
  end
  object BSearch: TButton
    Left = 65
    Top = 187
    Width = 73
    Height = 25
    Caption = 'Pretra'#382'i'
    TabOrder = 7
    OnClick = BSearchClick
  end
  object BDateASC: TButton
    Left = 90
    Top = 412
    Width = 97
    Height = 25
    Caption = 'Datum Uzlazno'
    TabOrder = 8
    OnClick = BDateASCClick
  end
  object BDateDESC: TButton
    Left = 90
    Top = 443
    Width = 97
    Height = 25
    Caption = 'Datum Silazno'
    TabOrder = 9
    OnClick = BDateDESCClick
  end
  object BPrometASC: TButton
    Left = 201
    Top = 412
    Width = 96
    Height = 25
    Caption = 'Promet Uzlazno'
    TabOrder = 10
    OnClick = BPrometASCClick
  end
  object BPrometDESC: TButton
    Left = 201
    Top = 443
    Width = 96
    Height = 25
    Caption = 'Promet Silazno'
    TabOrder = 11
    OnClick = BPrometDESCClick
  end
  object CheckBox1: TCheckBox
    Left = 64
    Top = 163
    Width = 97
    Height = 17
    Caption = 'Filter'
    TabOrder = 12
    OnClick = CheckBox1Click
  end
  object DBImage1: TDBImage
    Left = 591
    Top = 8
    Width = 274
    Height = 243
    DataField = 'Slika'
    DataSource = DataModule1.DPoslovnica
    TabOrder = 13
  end
  object Button1: TButton
    Left = 480
    Top = 134
    Width = 105
    Height = 25
    Caption = 'Napravi izvje'#353'taj'
    TabOrder = 14
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 447
    Top = 488
    Width = 90
    Height = 23
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 15
  end
  object Button2: TButton
    Left = 447
    Top = 517
    Width = 90
    Height = 25
    Caption = 'Izmjeni visinu'
    TabOrder = 16
    OnClick = Button2Click
  end
  object CheckBox2: TCheckBox
    Left = 447
    Top = 548
    Width = 97
    Height = 17
    Caption = 'Spremi visinu'
    TabOrder = 17
    OnClick = CheckBox2Click
  end
  object frxReport1: TfrxReport
    Version = '2022.2.7'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44751.629460671300000000
    ReportOptions.LastChange = 44751.754359166700000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 486
    Top = 336
    Datasets = <
      item
        DataSet = frxPoslovnica
        DataSetName = 'frxPoslovnica'
      end
      item
        DataSet = frxPromet
        DataSetName = 'frxPromet'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNone
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Height = 113.385900000000000000
        ParentFont = False
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 230.551330000000000000
          Top = 15.118120000000000000
          Width = 257.008040000000000000
          Height = 41.574830000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Izvje'#353'taj o poslovnici')
          ParentFont = False
        end
        object frxDBDataset1Naziv: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 188.976500000000000000
          Top = 60.472480000000000000
          Width = 340.157700000000000000
          Height = 26.456710000000000000
          DataField = 'Naziv'
          DataSet = frxPoslovnica
          DataSetName = 'frxPoslovnica'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxPoslovnica."Naziv"]')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 207.874150000000000000
        Top = 192.756030000000000000
        Width = 718.110700000000000000
        Child = frxReport1.Child2
        DataSet = frxPoslovnica
        DataSetName = 'frxPoslovnica'
        RowCount = 0
        object frxDBDataset1Naziv1: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Top = 34.015770000000000000
          Width = 177.637910000000000000
          Height = 18.897650000000000000
          DataField = 'Naziv'
          DataSet = frxPoslovnica
          DataSetName = 'frxPoslovnica'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxPoslovnica."Naziv"]')
          ParentFont = False
        end
        object frxPoslovnicaAdresa: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Top = 71.811070000000000000
          Width = 411.968770000000000000
          Height = 18.897650000000000000
          DataSet = frxPoslovnica
          DataSetName = 'frxPoslovnica'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxPoslovnica."Adresa"], [frxPoslovnica."Mjesto"]')
          ParentFont = False
        end
        object frxPoslovnicaBrojstanica: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 102.047310000000000000
          Top = 109.606370000000000000
          Width = 207.874150000000000000
          Height = 18.897650000000000000
          DataField = 'Broj stanica'
          DataSet = frxPoslovnica
          DataSetName = 'frxPoslovnica'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxPoslovnica."Broj stanica"]')
          ParentFont = False
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Top = 109.606370000000000000
          Width = 98.267780000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'Broj stanica:')
          ParentFont = False
        end
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 415.748300000000000000
          Top = 15.118120000000000000
          Width = 302.362400000000000000
          Height = 170.078850000000000000
          DataField = 'Slika'
          DataSet = frxPoslovnica
          DataSetName = 'frxPoslovnica'
          Frame.Typ = []
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 37.795300000000000000
        Top = 468.661720000000000000
        Width = 718.110700000000000000
        DataSet = frxPromet
        DataSetName = 'frxPromet'
        RowCount = 30
        object frxPrometDatum: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 204.094620000000000000
          Top = 15.118120000000000000
          Width = 143.622140000000000000
          Height = 18.897650000000000000
          DataField = 'Datum'
          DataSet = frxPromet
          DataSetName = 'frxPromet'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxPromet."Datum"]')
          ParentFont = False
        end
        object frxPrometUkupno: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 366.614410000000000000
          Top = 15.118120000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataSet = frxPromet
          DataSetName = 'frxPromet'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxPromet."Ukupno"] KN')
          ParentFont = False
        end
        object frxPrometEUR: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 464.882190000000000000
          Top = 15.118120000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataSet = frxPromet
          DataSetName = 'frxPromet'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxPromet."EUR"] EUR')
          ParentFont = False
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Left = 351.496290000000000000
          Height = 37.795300000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line3: TfrxLineView
          AllowVectorExport = True
          Left = 457.323130000000000000
          Height = 37.795300000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
      end
      object Child2: TfrxChild
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 423.307360000000000000
        Width = 718.110700000000000000
        ToNRows = 0
        ToNRowsMode = rmCount
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 204.094620000000000000
          Top = -3.779530000000000000
          Width = 143.622140000000000000
          Height = 30.236240000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Highlight.Font.Charset = DEFAULT_CHARSET
          Highlight.Font.Color = clRed
          Highlight.Font.Height = -13
          Highlight.Font.Name = 'Arial'
          Highlight.Font.Style = []
          Highlight.Condition = 'Value = 1'
          Highlight.FillType = ftBrush
          Highlight.Frame.Typ = []
          Memo.UTF8W = (
            'Datum')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 366.614410000000000000
          Top = -3.779530000000000000
          Width = 79.370130000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Promet')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 464.882190000000000000
          Top = -3.779530000000000000
          Width = 79.370130000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'EUR')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Top = 22.677180000000000000
          Width = 718.110700000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
      end
    end
  end
  object frxPDFExport1: TfrxPDFExport
    FileName = 'Untitled.pdf'
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    CreationTime = 44751.671713043980000000
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Transparency = False
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 589
    Top = 300
  end
  object frxRTFExport1: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    OpenAfterExport = False
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 550
    Top = 321
  end
  object frxPoslovnica: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'frxPoslovnica'
    CloseDataSource = False
    DataSource = DataModule1.DPoslovnica
    BCDToCurrency = False
    DataSetOptions = []
    Left = 578
    Top = 252
  end
  object frxPromet: TfrxDBDataset
    UserName = 'frxPromet'
    CloseDataSource = False
    DataSource = DataModule1.DPromet
    BCDToCurrency = False
    DataSetOptions = []
    Left = 479
    Top = 296
  end
end
