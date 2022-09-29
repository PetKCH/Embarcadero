//---------------------------------------------------------------------------

#include <vcl.h>
#include <memory.h>
#include <IOUtils.hpp>
#include <vector>
#pragma hdrstop
#include <System.hpp>
#include <System.SysUtils.hpp>

#include "Editor.h"
#include "Glavna.h"
extern String ime;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
#pragma resource "*.dfm"
TFEditor *FEditor;
//---------------------------------------------------------------------------
class MojFormat {
public:
	wchar_t ime[15];
	float inacica;

	MojFormat() {

		wcsncpy(ime, L"AdminNalog", 15);
		inacica = 1.0;
	}
};
//---------------------------------------------------------------------------

class Nalog {
public:
	wchar_t vrsta[50];
	wchar_t korisnik[50];
	wchar_t admin[50];
    wchar_t status[50];

	Nalog() = default;

	Nalog(wchar_t* _vrsta, wchar_t* _korisnik, wchar_t* _admin, wchar_t* _status) {

		wcsncpy(vrsta, _vrsta, 50);
		wcsncpy(korisnik, _korisnik, 50);
		wcsncpy(admin, _admin, 50);
        wcsncpy(status, _status, 50);
	}
};
//---------------------------------------------------------------------------
__fastcall TFEditor::TFEditor(TComponent* Owner)
	: TForm(Owner)
{
    PrikazMemo->Clear();
	String Dir = ".\\nalozi";
	if( TDirectory::Exists(Dir) ) {}
	else {
		TDirectory::CreateDirectory(Dir);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFEditor::Button1Click(TObject *Sender)
{
    long int response = 0;
	String datum = Now();
    String status = "Fail";
    datum.Trim();
	datum = StringReplace(datum, _D("/"), _D("-"), TReplaceFlags() << rfReplaceAll);
	datum = StringReplace(datum, _D(":"), _D("-"), TReplaceFlags() << rfReplaceAll);
	if (EUsername->Text == ime) {
        ShowMessage("Ne možete izmjeniti svoje podatke!");
	}
	else if (EUsername->Text != "" && EPassword->Text != "" && EAdmin->Text != "" && EIme->Text != ""
	&& EPrezime->Text != "" && EOIB->Text != "" && EPlaca->Text != "") {
		IdTCPClient1->Connect();
		//TIP TCP zahtjeva - 2 upis
		IdTCPClient1->Socket->WriteLn(2);
		//Primi public key
		UnicodeString naziv = "server_public_key.bin";
		UnicodeString naziv2 = "server_private_key.bin";
		int velicina = IdTCPClient1->Socket->ReadInt64();
		std::unique_ptr<TFileStream> fs(new TFileStream(naziv, fmCreate));
		IdTCPClient1->Socket->ReadStream(fs.get(), velicina);
		FileClose(fs->Handle);
		fs.reset();
		//sifriraj password i posalji
		Codec1->CryptoLibrary = CryptographicLibrary1;
		Codec1->BlockCipherId = "native.RSA";
		Codec1->AsymetricKeySizeInBits = 1024;
		Codec1->ChainModeId = "native.CBC";
		Signatory1->Codec = Codec1;
		std::unique_ptr<TMemoryStream> publicKey(new TMemoryStream);
		publicKey->LoadFromFile("server_public_key.bin");

		String lozinka;
		String sifriranaLozinka;
		lozinka = EPassword->Text;
		Signatory1->LoadKeysFromStream(publicKey.get(), TKeyStoragePartSet() << partPublic);
		Codec1->EncryptString( lozinka , sifriranaLozinka, TEncoding::UTF8);
		//send
		IdTCPClient1->Socket->WriteLn(EUsername->Text);
		IdTCPClient1->Socket->WriteLn(sifriranaLozinka);
		IdTCPClient1->Socket->Write(EAdmin->Text.ToInt());
		IdTCPClient1->Socket->WriteLn(EIme->Text);
		IdTCPClient1->Socket->WriteLn(EPrezime->Text);
		IdTCPClient1->Socket->Write(EOIB->Text.ToInt());
		IdTCPClient1->Socket->Write(EPlaca->Text.ToInt());
		response = IdTCPClient1->Socket->ReadLongInt();
		if (response == 1) {
			ShowMessage("Uspješno provedeno!");
			status = "Pass";
		}
		else {
			ShowMessage("Greška pri upisu...");
		}


		IdTCPClient1->Disconnect();
	}
	else {
        ShowMessage("Sva polja moraju biti popunjena!");
    }
	//spremi kao nalog
	std::vector<Nalog> nalog =
	{
		Nalog(L"Upis", EUsername->Text.w_str(),ime.w_str(),status.w_str())
	};

	MojFormat Header;
	std::unique_ptr<TFileStream> nalogStream(new TFileStream("nalozi/"+EUsername->Text+"_"+datum+".mft", fmCreate));

	nalogStream->Write(&Header, sizeof(MojFormat));
	nalogStream->Write(&nalog[0], sizeof(Nalog));
	//kontaktStream->SaveToFile("nalozi/"+EUsername->Text+"_"+datum+".mft");



}
//---------------------------------------------------------------------------
void __fastcall TFEditor::Button2Click(TObject *Sender)
{

    String path = "";
    if(OpenDialog1->Execute()== true){
		path = OpenDialog1->FileName;
	}

	std::unique_ptr<TMemoryStream> nalogStream(new TMemoryStream);
	nalogStream->LoadFromFile(path);

	MojFormat Header;
	nalogStream->Read(&Header, sizeof(MojFormat));

	if(String(Header.ime) != "AdminNalog" || Header.inacica != 1.0){

		Application->MessageBox(L"Krivi format!", L"Greška", MB_OK|MB_ICONERROR);
		return;
	}

	Nalog tmp;
	for(int i = 0; i < 1; i++){

		UnicodeString vrsta;
		UnicodeString korisnik;
		UnicodeString admin;
        UnicodeString status;

		nalogStream->Read(&tmp, sizeof(Nalog));

		vrsta += String(tmp.vrsta);
		korisnik += String(tmp.korisnik);
		admin += String(tmp.admin);
        status += String(tmp.status);


		PrikazMemo->Clear();
		PrikazMemo->Font->Size = 8;

		PrikazMemo->Lines->Add("Vrsta promjene: " + vrsta);
		PrikazMemo->Lines->Add("");
		PrikazMemo->Lines->Add("Promjena na korisniku: " + korisnik);
		PrikazMemo->Lines->Add("");
		PrikazMemo->Lines->Add("Promjenio je: " + admin);
        PrikazMemo->Lines->Add("");
		PrikazMemo->Lines->Add("Pass/Fail: " + status);
	}


}




void __fastcall TFEditor::Button3Click(TObject *Sender)
{
	if (EUsername->Text == "") {
		ShowMessage("Unesite korisničko ime prije pretrage!");
	 }
	 else {
		IdUDPClient1->ReceiveTimeout = 1000;
		IdUDPClient1->SendBuffer("127.0.0.1", 11111, ToBytes(EUsername->Text));
		int response = IdUDPClient1->ReceiveString().ToInt();
		if (response == 0) {
			ShowMessage("Korisničko ime nije pronađeno!");
		}
		else {
			String username, admin, ime, prezime, oib, placa;
			username = IdUDPClient1->ReceiveString();
			admin = IdUDPClient1->ReceiveString();
			ime = IdUDPClient1->ReceiveString();
			prezime = IdUDPClient1->ReceiveString();
			oib = IdUDPClient1->ReceiveString();
			placa = IdUDPClient1->ReceiveString();
			EUsername->Text = username;
			EAdmin->Text = admin;
            EPassword->Text = "";
			EIme->Text = ime;
			EPrezime->Text = prezime;
			EOIB->Text = oib;
			EPlaca->Text = placa;

		}
	 }
}
//---------------------------------------------------------------------------


void __fastcall TFEditor::Button4Click(TObject *Sender)
{
	TaskDialog1->Caption = "Upozorenje";
	TaskDialog1->Title = "Brisanje baze";
	TaskDialog1->Text = "Želite li sigurno izbrisati korisnika " + EUsername->Text + "?";
	TaskDialog1->CommonButtons << tcbOk << tcbCancel;
	TaskDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::TaskDialog1ButtonClicked(TObject *Sender, TModalResult ModalResult,
          bool &CanClose)
{
	if(TaskDialog1->ModalResult == tcbOk) {
		 IdTCPClient1->Connect();
				//TIP TCP zahtjeva - 3 delete
		IdTCPClient1->Socket->WriteLn(3);
		IdTCPClient1->Socket->WriteLn(EUsername->Text);
		String datum = Now();
		String status;
		datum.Trim();
		datum = StringReplace(datum, _D("/"), _D("-"), TReplaceFlags() << rfReplaceAll);
		datum = StringReplace(datum, _D(":"), _D("-"), TReplaceFlags() << rfReplaceAll);
        //status
		int response = IdTCPClient1->Socket->ReadLongInt();
		if (response == 1) {
			ShowMessage("Korisnik je izbrisan!");
			status = "Pass";
		}
		else if (response == 2) {
			 ShowMessage("Korisnik nije pronađen.");
			 status = "Not found";
		}
		else {
			ShowMessage("Greška pri brisanju...");
			status = "Error";
		}


		//spremi kao nalog
		std::vector<Nalog> nalog =
		{
			Nalog(L"Izbriši", EUsername->Text.w_str(),ime.w_str(),status.w_str())
		};

		MojFormat Header;
		std::unique_ptr<TFileStream> nalogStream(new TFileStream("nalozi/"+EUsername->Text+"_"+datum+".mft", fmCreate));

		nalogStream->Write(&Header, sizeof(MojFormat));
		nalogStream->Write(&nalog[0], sizeof(Nalog));

	}
}
//---------------------------------------------------------------------------

void __fastcall TFEditor::FormShow(TObject *Sender)
{
	//ShowMessage(ime);
}
//---------------------------------------------------------------------------

