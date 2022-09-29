//---------------------------------------------------------------------------

#ifndef BazaEditorH
#define BazaEditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFBazaEditor : public TForm
{
__published:	// IDE-managed Components
	TButton *Button2;
	TButton *DDodaj;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TDBNavigator *DBNavigator1;
	TDBNavigator *DBNavigator2;
	TDBNavigator *DBNavigator3;
	TEdit *DBEdit1;
	TEdit *DBEdit2;
	TEdit *DBEdit3;
	TEdit *DBEdit4;
	TLabel *Naziv;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TDBImage *DBImage1;
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TButton *Button3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall DDodajClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFBazaEditor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBazaEditor *FBazaEditor;
//---------------------------------------------------------------------------
#endif
