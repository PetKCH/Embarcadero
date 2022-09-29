//---------------------------------------------------------------------------

#ifndef BazaH
#define BazaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Dialogs.hpp>
#include "frxClass.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include "frxDBSet.hpp"
//---------------------------------------------------------------------------
class TFBaza : public TForm
{
__published:	// IDE-managed Components
	TButton *BCalculator;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TEdit *Ehrk;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TButton *BSearch;
	TEdit *ESearch;
	TButton *BDateASC;
	TButton *BDateDESC;
	TButton *BPrometASC;
	TButton *BPrometDESC;
	TCheckBox *CheckBox1;
	TDBImage *DBImage1;
	TfrxReport *frxReport1;
	TfrxPDFExport *frxPDFExport1;
	TfrxRTFExport *frxRTFExport1;
	TfrxDBDataset *frxPoslovnica;
	TfrxDBDataset *frxPromet;
	TButton *Button1;
	TEdit *Edit2;
	TButton *Button2;
	TCheckBox *CheckBox2;
	void __fastcall BCalculatorClick(TObject *Sender);
	void __fastcall BSearchClick(TObject *Sender);
	void __fastcall BDateASCClick(TObject *Sender);
	void __fastcall BDateDESCClick(TObject *Sender);
	void __fastcall BPrometASCClick(TObject *Sender);
	void __fastcall BPrometDESCClick(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall DBGrid1MouseEnter(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFBaza(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBaza *FBaza;
//---------------------------------------------------------------------------
#endif
