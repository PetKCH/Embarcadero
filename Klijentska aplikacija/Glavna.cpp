//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Glavna.h"
#include "Baza.h"
#include "Admin.h"
#include "BazaEditor.h"
#include "Editor.h"
#include <DBXJSON.hpp>
#include "Packet.h"
#include <math.h>
#include <registry.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TFGlavna *FGlavna;
String ime;
bool perm = false;
float EURO = 7.543;
bool EURO_update = false;
//---------------------------------------------------------------------------
__fastcall TFGlavna::TFGlavna(TComponent* Owner)
	: TForm(Owner)
{

	TIniFile *temp = new TIniFile(GetCurrentDir() + "\\postavke.ini");
	String buttons = temp->ReadString("Hide", "Selection" ,"");
	if (buttons=="true") {
	   BBazaEdit->Hide();
	   BAdmin->Hide();
       CheckBox1->Checked = true;
	}
	EURO = temp->ReadFloat("CURRENCY", "EURO", EURO);

	FGlavna->GroupBox1->Caption="Dobrodošao " + ime;
	ComboBox1->AddItem("Osobno vozilo",NULL);
	ComboBox1->AddItem("SUV vozilo",NULL);
	ComboBox1->AddItem("Kombi",NULL);
	ComboBox1->ItemIndex = 0;
	ComboBox2->AddItem("Small paket",NULL);
	ComboBox2->AddItem("Medium paket",NULL);
	ComboBox2->AddItem("Large paket",NULL);
	ComboBox2->ItemIndex = 1;
	ComboBox3->AddItem("Self-Service",NULL);
	ComboBox3->AddItem("Car Wash",NULL);
	ComboBox3->AddItem("Detailing",NULL);
	ComboBox3->ItemIndex = 0;
	ComboBox4->AddItem("Zagreb",NULL);
	ComboBox4->AddItem("Rijeka",NULL);
	ComboBox4->ItemIndex = 0;
    //ShowMessage(EURO);
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::BUpdateClick(TObject *Sender)
{
	RESTRequest1->Execute();
	TJSONObject* JSON = (TJSONObject*)TJSONObject::ParseJSONValue(Memo1->Text);
	TJSONValue *EUR = JSON->GetValue("result");
    //ShowMessage(EUR->Value());
	Memo1->Clear();
	Memo1->Font->Size = 8;
	Memo1->Lines->Append("1 HRK = " + EUR->Value() + "EUR");
	EURO = StrToFloat(EUR->Value());
	EURO = 1/EURO;
    EURO_update = true;
   //	Memo1->Lines->Add("Datum: " + Date);

}
//---------------------------------------------------------------------------


void __fastcall TFGlavna::Button1Click(TObject *Sender)
{
	FBaza->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFGlavna::BAdminClick(TObject *Sender)
{

	 if (perm==false) {
		ShowMessage("Korisnik nije Admin!");
	}else {
      FAdmin->ShowModal();
	}
}

//---------------------------------------------------------------------------

void __fastcall TFGlavna::BBazaEditClick(TObject *Sender)
{
	if (perm==false) {
		ShowMessage("Korisnik nije Admin!");
	}else {
      FBazaEditor->ShowModal();
    }

}
//---------------------------------------------------------------------------



void __fastcall TFGlavna::Label1Click(TObject *Sender)
{
	if(zatvori==1) {
    	DeleteFile("history.coded");
		Codec1->CryptoLibrary = CryptographicLibrary1;
		Codec1->BlockCipherId = "native.AES-256";
		Codec1->ChainModeId = "native.CBC";
		Codec1->Password = "autopraona";
		std::auto_ptr<TFileStream> Sifrirana(new TFileStream("history.coded", fmCreate));
		std::unique_ptr<TFileStream> Izvorna(new TFileStream("history.xml", fmOpenReadWrite));
		Codec1->EncryptStream(Izvorna.get(), Sifrirana.get());
		//&Izvorna->Free;
		//&Sifrirana->Free;
		FileClose(Izvorna->Handle);
		FileClose(Sifrirana->Handle);
		Izvorna.release();
		Izvorna.reset();
		Sifrirana.release();
		Sifrirana.reset();
		DeleteFile("history.xml");
		_di_IXMLDocument document = interface_cast<Xmlintf::IXMLDocument>
			(new TXMLDocument(NULL));
		document->Active = true;

		document->DocumentElement = document->CreateNode("events",
			ntElement, "events");

		document->SaveToFile(".\\history.xml");
	}

}
//---------------------------------------------------------------------------
class neto_izracun {
public:
	int bruto;
	int mjesto;
	int vrsta;
	neto_izracun(int _bruto, int _vrsta, int _mjesto) {
		bruto = _bruto;
        vrsta = _vrsta;
		mjesto = _mjesto;
	}

	String porez_value() {
        double ispis = porez_calc();
		return ispis;
	}
	String prirez_value() {
		return prirez_calc();
	}
	String ispis() {
		double troskovi = trosak(vrsta);
		double rezultat = (bruto*troskovi)-porez_calc()-prirez_calc();
		return rezultat;
	}
private:
	float trosak(int vrsta) {
        float troskovi = 0;
		if (vrsta==0) {
			//10%
			troskovi = 0.9;
		}
		else if (vrsta==1) {
			troskovi = 0.87;
		}
		else if (vrsta==2) {
			 troskovi = 0.85;
		}
        return troskovi;
	}

	double porez_calc() {
		double porez;
		switch(mjesto) {
		  case 0:
			porez = bruto*0.25;
			break;
		  case 1:
			porez = bruto*0.25;
			break;
		}
		return porez;
	}
	double prirez_calc() {
		double porez = porez_calc();
        double prirez;
		switch(mjesto) {
		  case 0:
			prirez = porez*0.18;
			break;
		  case 1:
			prirez = porez*0.14;
			break;
		}
        return prirez;
	}



};

//---------------------------------------------------------------------------


void __fastcall TFGlavna::Button2Click(TObject *Sender)
{
	izracun novi(ComboBox1->ItemIndex,ComboBox2->ItemIndex,Edit1->Text.ToInt());
	if (Edit1->Text.ToInt()<0 || Edit1->Text.ToInt()>99) {
		ShowMessage("Greška! Popust može biti 1-99%");
	}
	else if (Edit1->Text.ToInt()==0) {
		String str = novi.cijena_paketa().c_str();
		ShowMessage("Cijena paketa: "+ str);
	}
	else {
		String str_old = novi.cijena_paketa().c_str();
		String str_new = novi.cijena_paketa_popust().c_str();
		str_new = str_new.SubString(1, (Pos('.', str_new)+2));
		String popust =str_old - str_new;
		ShowMessage("Stara cijena paketa:" + str_old
		+"\r\n"+"Nova cijena paketa: " + popust +
		+"\r\n"+"Ušteda: " + str_new);
	}
}
//---------------------------------------------------------------------------



void __fastcall TFGlavna::Button3Click(TObject *Sender)
{
	neto_izracun vrijednost(Edit2->Text.ToInt(), ComboBox3->ItemIndex, ComboBox4->ItemIndex);
	if (Edit2->Text.ToInt()==0) {
		ShowMessage("Greška! Unesite neku BRUTO vrijednost.");
	}
	else {
		String porez = vrijednost.porez_value();
		String prirez = vrijednost.prirez_value();
		String neto = vrijednost.ispis();
        neto = neto.SubString(1, (Pos('.', neto)+2));
		ShowMessage("BRUTO:" + Edit2->Text
		+"\r\n"+"NETO: " + neto
		+"\r\n"+"POREZ: " + porez
		+"\r\n"+"PRIREZ: " + prirez);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile *temp = new TIniFile(GetCurrentDir() + ".\\postavke.ini");
	if (CheckBox1->Checked==true) {
		temp->WriteString("Hide", "Selection" ,"true");
	}
	else {
        temp->WriteString("Hide", "Selection" ,"false");
	}
		if (EURO_update) {
		temp->WriteFloat("CURRENCY", "EURO" , EURO);
	}

	delete temp;

}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked==true) {
		BBazaEdit->Hide();
	   BAdmin->Hide();
	}
	else {
		BBazaEdit->Show();
	   BAdmin->Show();
	}

}
//---------------------------------------------------------------------------

