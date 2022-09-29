//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <System.Hash.hpp>
#include <IdHashSHA.hpp>
#include <iostream>
#include <string>
#include <random>
#include <memory>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
#pragma resource "*.dfm"
TServerForm *ServerForm;
//---------------------------------------------------------------------------
__fastcall TServerForm::TServerForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TServerForm::IdTCPServer1Execute(TIdContext *AContext)
{

	UnicodeString TIP = AContext->Connection->Socket->ReadLn();
    UnicodeString korisnickoIme;
	if (TIP == "1" || TIP  == "2") {
	UnicodeString public_key = "server_public_key.bin";
	std::unique_ptr<TFileStream> pubKey(new TFileStream(public_key, fmOpenRead));
	AContext->Connection->Socket->Write(pubKey->Size); //size
	AContext->Connection->Socket->Write(pubKey.get()); //send
	pubKey.reset();

		//ucitaj TCP podatke
		korisnickoIme = AContext->Connection->Socket->ReadLn();
		lozinka = AContext->Connection->Socket->ReadLn();
		//decrypt

		Codec1->CryptoLibrary = CryptographicLibrary1;
		Codec1->BlockCipherId = "native.RSA";
		Codec1->AsymetricKeySizeInBits = 1024;
		Codec1->ChainModeId = "native.CBC";
		Signatory1->Codec = Codec1;
		std::auto_ptr<TMemoryStream> privateKey (new TMemoryStream);
		privateKey->LoadFromFile("server_private_key.bin");
		lozinka.Trim();
		String decrypted;

		Signatory1->LoadKeysFromStream(privateKey.get(), TKeyStoragePartSet() << partPrivate);
		Codec1->DecryptString(decrypted, lozinka, TEncoding::UTF8);
		lozinka = decrypted;
	}
	if (TIP == "1") {

		//search
		int response = 0;
		int level = 0;
		ADOTable1->First();
		for(int i=0; i<ADOTable1->RecordCount; i++){
			UnicodeString username = ADOTable1->FieldByName("username")->AsString;
			UnicodeString password = ADOTable1->FieldByName("password")->AsString;
			UnicodeString salt = ADOTable1->FieldByName("salt")->AsString;
			UnicodeString lozinka_salted = THashSHA2::GetHashString(lozinka+salt, THashSHA2::TSHA2Version::SHA256);



			if(username == korisnickoIme){
				if (password == lozinka_salted){
					response = 1;
					UnicodeString permission = ADOTable1->FieldByName("admin")->AsString;
					level = permission.ToInt();
				}
				break;
			}
			ADOTable1->Next();

		}

		AContext->Connection->Socket->Write(response);
		AContext->Connection->Socket->Write(level);
	}

	if (TIP == "2"){
		int response = 0;
		//UnicodeString korisnickoIme = AContext->Connection->Socket->ReadLn();
		//UnicodeString lozinka = AContext->Connection->Socket->ReadLn();
		int level = AContext->Connection->Socket->ReadLongInt();
		UnicodeString ime = AContext->Connection->Socket->ReadLn();
		UnicodeString prezime = AContext->Connection->Socket->ReadLn();
		int OIB = AContext->Connection->Socket->ReadLongInt();
		int placa = AContext->Connection->Socket->ReadLongInt();
		//ShowMessage("Varijable su:" + korisnickoIme + " " + lozinka + " " + level + " " + ime + " " + prezime
		//+ " " + OIB + " " + placa);
		//salt
		int i, j, N;
		String SeedString = "abcdefghijklmnopqrstuvwxyz";
		String salt;
		salt = "";
		for (i = 0; j < 6; j++) {
		N = Random(SeedString.Length()) + 1;
		salt += SeedString[N];
		}
		UnicodeString lozinka_salted = THashSHA2::GetHashString(lozinka+salt, THashSHA2::TSHA2Version::SHA256);

		TLocateOptions Opts;
		Opts.Clear();
		Opts << loCaseInsensitive;
		if (ADOTable1->Locate("username", korisnickoIme, Opts) == false) {
			ADOTable1->Append();
			ADOTable1->FieldByName("Username")->AsString = korisnickoIme;
			ADOTable1->FieldByName("Password")->AsString = lozinka_salted;
			ADOTable1->FieldByName("Salt")->AsString = salt;
			ADOTable1->FieldByName("Admin")->AsString = level;
			ADOTable1->FieldByName("Ime")->AsString = ime;
			ADOTable1->FieldByName("Prezime")->AsString = prezime;
			ADOTable1->FieldByName("Oib")->AsString = OIB;
			ADOTable1->FieldByName("Placa")->AsString = placa;
			ADOTable1->Post();

            response = 1;
		}
		else {
			ADOTable1->Locate("username", korisnickoIme, Opts);
            ADOTable1->Edit();
			ADOTable1->FieldByName("Username")->AsString = korisnickoIme;
			ADOTable1->FieldByName("Password")->AsString = lozinka_salted;
			ADOTable1->FieldByName("Salt")->AsString = salt;
			ADOTable1->FieldByName("Admin")->AsString = level;
			ADOTable1->FieldByName("Ime")->AsString = ime;
			ADOTable1->FieldByName("Prezime")->AsString = prezime;
			ADOTable1->FieldByName("Oib")->AsString = OIB;
			ADOTable1->FieldByName("Placa")->AsString = placa;
			ADOTable1->Post();

            response = 1;
        }

		AContext->Connection->Socket->Write(response);
	}
	if (TIP == "3") {
        int response = 0;
		UnicodeString korisnickoIme = AContext->Connection->Socket->ReadLn();
		TLocateOptions Opts;
		Opts.Clear();
		Opts << loPartialKey;
		if (ADOTable1->Locate("username", korisnickoIme, Opts) == true) {
			ADOTable1->Delete();
			response = 1;
		}
		else {
            response = 2;
		}

        AContext->Connection->Socket->Write(response);
	}


	AContext->Connection->Disconnect();
}
//---------------------------------------------------------------------------






void __fastcall TServerForm::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
     	UnicodeString username = BytesToString(AData);
    //ShowMessage(username);
	int response = 0;
    TLocateOptions Opts;
	Opts.Clear();
	Opts << loCaseInsensitive;
	if(ADOTable1->Locate("Username", username, Opts) == true){
        response = 1;
		AThread->Server->Send(ABinding->PeerIP, ABinding->PeerPort, response);
		ADOTable1->First();
		UnicodeString korisnickoIme, admin, ime, prezime, oib, placa;
		for(int i=0; i<ADOTable1->RecordCount; i++){
			korisnickoIme = ADOTable1->FieldByName("Username")->AsString;
			if (username == korisnickoIme) {
				korisnickoIme = ADOTable1->FieldByName("Username")->AsString;
				admin = ADOTable1->FieldByName("Admin")->AsString;
				ime = ADOTable1->FieldByName("Ime")->AsString;
				prezime = ADOTable1->FieldByName("Prezime")->AsString;
				oib = ADOTable1->FieldByName("oib")->AsString;
				placa = ADOTable1->FieldByName("placa")->AsString;
				break;
			}
            ADOTable1->Next();

		}
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, korisnickoIme);
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, admin);
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, ime);
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, prezime);
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, oib);
		IdUDPServer1->Send(ABinding->PeerIP, ABinding->PeerPort, placa);
	}
	else {
       AThread->Server->Send(ABinding->PeerIP, ABinding->PeerPort, response);
	}
}
//---------------------------------------------------------------------------


void __fastcall TServerForm::Button1Click(TObject *Sender)
{

	Codec1->CryptoLibrary = CryptographicLibrary1;
	Codec1->BlockCipherId = "native.RSA";
	Codec1->AsymetricKeySizeInBits = 1024;
	Codec1->ChainModeId = "native.CBC";
	Signatory1->Codec = Codec1;

    std::unique_ptr<TMemoryStream> privateKey (new TMemoryStream);
	std::unique_ptr<TMemoryStream> publicKey (new TMemoryStream);
    if(Signatory1->GenerateKeys()){
        Signatory1->StoreKeysToStream(privateKey.get(), TKeyStoragePartSet() << partPrivate);
        Signatory1->StoreKeysToStream(publicKey.get(), TKeyStoragePartSet() << partPublic);
		privateKey->SaveToFile("server_private_key.bin");
        publicKey->SaveToFile("server_public_key.bin");
	}
	privateKey.reset();
	publicKey.reset();

}
//---------------------------------------------------------------------------




