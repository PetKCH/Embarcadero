//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Baza.h"
#include "calculator.h"
#include "SQL.h"
#include "jpeg.hpp"
#include "pngimage.hpp"
#include "Glavna.h"
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TFBaza *FBaza;
extern float EURO;
//---------------------------------------------------------------------------
__fastcall TFBaza::TFBaza(TComponent* Owner)
	: TForm(Owner)
{

	TIniFile *temp = new TIniFile(GetCurrentDir() + "\\postavke.ini");
    String checked = temp->ReadString("BAZA", "Checked" , "false");
	String visina = temp->ReadString("BAZA", "Visina" , "125");
	if (checked=="true") {
	   DBGrid2->Height = visina.ToInt();
       CheckBox2->Checked = true;
	}
	Edit2->Text = DBGrid2->Height;
}
//---------------------------------------------------------------------------
void __fastcall TFBaza::BCalculatorClick(TObject *Sender)
{
	_di_CalculatorSoap Calc = GetCalculatorSoap();
	double hrk = Ehrk->Text.ToDouble();
	double sum = Calc->Divide(hrk, EURO);
	Edit1->Text = sum;

}
//---------------------------------------------------------------------------


void __fastcall TFBaza::BSearchClick(TObject *Sender)
{
		if(CheckBox1->Checked) {
		DataModule1->TPoslovnica->Filter = "Naziv LIKE " + QuotedStr("%"+ESearch->Text+"%");
		DataModule1->TPoslovnica->Filtered = true;
		}
		else {
			TLocateOptions SearchOptions;
			SearchOptions.Clear();
			SearchOptions << loCaseInsensitive;
			if(DataModule1->TPoslovnica->Locate("Naziv", ESearch->Text, SearchOptions)){
			}
			else
				Application->MessageBox(L"Lokacija nije pronađena!",L"Informacija",MB_OK|MB_ICONINFORMATION);
		}

}
//---------------------------------------------------------------------------

void __fastcall TFBaza::BDateASCClick(TObject *Sender)
{
	DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica,Datum ASC";
	//DataModule1->TPromet->Sort = "Datum";
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::BDateDESCClick(TObject *Sender)
{
	DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica,Datum DESC";
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::BPrometASCClick(TObject *Sender)
{
	DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica,Ukupno ASC";
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::BPrometDESCClick(TObject *Sender)
{
	DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica,Ukupno DESC";
}
//---------------------------------------------------------------------------


void __fastcall TFBaza::DBGrid1CellClick(TColumn *Column)
{
	//DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica";
}
//---------------------------------------------------------------------------


void __fastcall TFBaza::DBGrid1MouseEnter(TObject *Sender)
{
	//DataModule1->TPromet->IndexFieldNames = "ID_Poslovnica";
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked == false) {
       DataModule1->TPoslovnica->Filtered = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::Button1Click(TObject *Sender)
{
	frxReport1->ShowReport();
}
//---------------------------------------------------------------------------


void __fastcall TFBaza::Button2Click(TObject *Sender)
{
	DBGrid2->Height = Edit2->Text.ToInt();
	TIniFile *temp = new TIniFile(GetCurrentDir() + ".\\postavke.ini");
	if (CheckBox2->Checked==true) {
		temp->WriteString("BAZA", "Visina" , Edit2->Text);
		temp->WriteString("BAZA", "Checked" ,"true");
	}
	delete temp;
}
//---------------------------------------------------------------------------

void __fastcall TFBaza::CheckBox2Click(TObject *Sender)
{
	TIniFile *temp = new TIniFile(GetCurrentDir() + ".\\postavke.ini");
	if (CheckBox2->Checked==false) {
		temp->WriteString("BAZA", "Checked" ,"false");
	}
	delete temp;
}
//---------------------------------------------------------------------------

