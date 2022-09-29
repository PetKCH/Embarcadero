//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include <IOUtils.hpp>
#include <System.Hash.hpp>
#include <IdHashSHA.hpp>
#include <windows.h>
#include <memory>
#include "history.h"
#include <fstream>
#include "Glavna.cpp"
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
#pragma resource "*.dfm"
TFLogin *FLogin;
//---------------------------------------------------------------------------
bool login = false;
bool admin = false;
__fastcall TFLogin::TFLogin(TComponent* Owner)
	: TForm(Owner)
{

	TIniFile *temp = new TIniFile(GetCurrentDir() + "\\postavke.ini");
	String save = temp->ReadString("Login", "Save" , "false");
	String korisnicko_ime = temp->ReadString("Login", "Username", "");
	if (save=="true") {
	   username->Text = korisnicko_ime;
		if (username->Text!="") {
			CheckBox1->Checked = true;
		}
	}


}
//---------------------------------------------------------------------------
void __fastcall TFLogin::BLoginClick(TObject *Sender)
{


	if (password->Text=="") {
       ShowMessage("Lozinka je obavezna!");
	}
	else {
	IdTCPClient1->Connect();
    //TIP TCP zahtjeva
	IdTCPClient1->Socket->WriteLn(1);
	//Primi public key
	UnicodeString naziv = "server_public_key.bin";
	UnicodeString naziv2 = "server_private_key.bin";
	int velicina = IdTCPClient1->Socket->ReadInt64();
	std::unique_ptr<TFileStream> key(new TFileStream(naziv, fmCreate));
	IdTCPClient1->Socket->ReadStream(key.get(), velicina);
	FileClose(key->Handle);
	key.reset();
	//sifriraj password i posalji
	Codec2->CryptoLibrary = CryptographicLibrary2;
	Codec2->BlockCipherId = "native.RSA";
	Codec2->AsymetricKeySizeInBits = 1024;
	Codec2->ChainModeId = "native.CBC";
	Signatory1->Codec = Codec2;
	std::unique_ptr<TMemoryStream> publicKey(new TMemoryStream);
	publicKey->LoadFromFile("server_public_key.bin");

    String lozinka;
	String sifriranaLozinka;
	lozinka = password->Text;
	Signatory1->LoadKeysFromStream(publicKey.get(), TKeyStoragePartSet() << partPublic);
	Codec2->EncryptString( lozinka , sifriranaLozinka, TEncoding::UTF8);
	//send
	IdTCPClient1->Socket->WriteLn(username->Text);
	IdTCPClient1->Socket->WriteLn(sifriranaLozinka);
	//ShowMessage("Poslano!");
	//ShowMessage(lozinka);
	int response, level = 0;
	response = IdTCPClient1->Socket->ReadLongInt();
	level = IdTCPClient1->Socket->ReadLongInt();
    //ShowMessage(response+level);
	if (response == 1) {
		login = true;
        ime = username->Text;
		if (level==1) {
		   admin = true;
           perm = true;
		}
	}
	else {
		_di_IXMLeventsType temp = Getevents(XMLDocument1);
		_di_IXMLeventType temp2 = temp->Add();

		temp2->Set_username(username->Text);
		temp2->Set_timestamp(Now());
		XMLDocument1->SaveToFile(XMLDocument1->FileName);
		Codec1->CryptoLibrary = CryptographicLibrary1;
		Codec1->BlockCipherId = "native.AES-256";
		Codec1->ChainModeId = "native.CBC";
		Codec1->Password = "autopraona";
		std::unique_ptr<TFileStream> Izvorna(new TFileStream("history.xml", fmOpenReadWrite));
		std::unique_ptr<TFileStream> Sifrirana(new TFileStream("history.coded", fmCreate));
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



	IdTCPClient1->Disconnect();
	Close();
    }


}


//---------------------------------------------------------------------------


void __fastcall TFLogin::XMLDocument1BeforeOpen(TObject *Sender)
{
	if (FileExists("history.coded")) {
			Codec1->BlockCipherId = "native.AES-256";
			Codec1->ChainModeId = "native.CBC";
			Codec1->Password = "autopraona";
			DeleteFile("history.xml");
			std::unique_ptr<TFileStream> Desifrirana(new TFileStream("history.xml", fmCreate));
			std::unique_ptr<TFileStream> Sifrirana(new TFileStream("history.coded", fmOpenReadWrite));
			Codec1->DecryptStream(Desifrirana.get(), Sifrirana.get());
			//&Desifrirana->Free;
			//&Sifrirana->Free;
			FileClose(Desifrirana->Handle);
			FileClose(Sifrirana->Handle);
			Desifrirana.reset();
			Sifrirana.reset();

	}
	else {
		_di_IXMLDocument document = interface_cast<Xmlintf::IXMLDocument>
			(new TXMLDocument(NULL));
		document->Active = true;

		document->DocumentElement = document->CreateNode("events",
			ntElement, "events");

		document->SaveToFile(".\\history.xml");
    }

}
//---------------------------------------------------------------------------


void __fastcall TFLogin::FormClose(TObject *Sender, TCloseAction &Action)
{

	TIniFile *temp = new TIniFile(GetCurrentDir() + ".\\postavke.ini");

		if (CheckBox1->Checked==true) {
			temp->WriteString("Login", "Save" , "true");
			temp->WriteString("Login", "Username", username->Text);
		}
		else {
			temp->WriteString("Login", "Username", "");
            temp->WriteString("Login", "Save" , "false");
		}

	delete temp;

}
//---------------------------------------------------------------------------

