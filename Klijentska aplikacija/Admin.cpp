//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Admin.h"
#include "history.h"
#include "Editor.h"
#include "Glavna.h"
#include <memory>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"
TFAdmin *FAdmin;
//---------------------------------------------------------------------------
__fastcall TFAdmin::TFAdmin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TDateTime __fastcall NowUTC()
{
  SYSTEMTIME SystemTime;
  ::GetSystemTime(&SystemTime);
  return EncodeDate(SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay) + EncodeTime(SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliseconds);
}
void __fastcall TFAdmin::BLoadClick(TObject *Sender)
{
	//ShowMessage(Now());
		_di_IXMLeventsType ucitaj = Getevents(XMLDocument1);
		LXML->Items->Clear();
		for(int i=0; i<ucitaj->Count; i++){

		LXML->Items->Add();
		LXML->Items->Item[i]->Caption = ucitaj->event[i]->Get_username();
		LXML->Items->Item[i]->SubItems->Add(ucitaj->event[i]->Get_timestamp());
	}

}
//---------------------------------------------------------------------------


void __fastcall TFAdmin::BDeleteClick(TObject *Sender)
{
	if(LXML->ItemIndex == -1){

		Application->MessageBox(L"Potrebno je odabrati redak koji želimo obrisati", L"Info", MB_OK|MB_ICONINFORMATION);
		return;
	}

	_di_IXMLeventsType temp = Getevents(XMLDocument1);

	temp->Delete(LXML->ItemIndex);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);
    BLoadClick(this);

}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BChangeClick(TObject *Sender)
{
	if(LXML->ItemIndex == -1){

		Application->MessageBox(L"Potrebno je odabrati redak koji želimo izmjeniti", L"Info", MB_OK|MB_ICONINFORMATION);
		return;
	}

	_di_IXMLeventsType temp = Getevents(XMLDocument1);
	_di_IXMLeventType temp2 = temp->event[LXML->ItemIndex];

	temp2->Set_username(Edit1->Text);
	temp2->Set_timestamp(Edit2->Text);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);
    BLoadClick(this);



}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BAddClick(TObject *Sender)
{

	_di_IXMLeventsType temp = Getevents(XMLDocument1);
	_di_IXMLeventType temp2 = temp->Add();

	temp2->Set_username(Edit1->Text);
	temp2->Set_timestamp(Edit2->Text);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);
    BLoadClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BEditorClick(TObject *Sender)
{
    FEditor->ShowModal();
}
//---------------------------------------------------------------------------




void __fastcall TFAdmin::XMLDocument1BeforeOpen(TObject *Sender)
{
	Codec1->CryptoLibrary = CryptographicLibrary1;
	Codec1->BlockCipherId = "native.AES-256";
	Codec1->ChainModeId = "native.CBC";
	Codec1->Password = "autopraona";
		if (FileExists("history.coded")) {
			DeleteFile("history.xml");
			std::unique_ptr<TFileStream> Desifrirana(new TFileStream("history.xml", fmCreate));
			std::unique_ptr<TFileStream> Sifrirana(new TFileStream("history.coded", fmOpenReadWrite));
			Codec1->DecryptStream(Desifrirana.get(), Sifrirana.get());
			//&Desifrirana->Free;
			//&Sifrirana->Free;
			FileClose(Desifrirana->Handle);
			FileClose(Sifrirana->Handle);
			Desifrirana.release();
			Desifrirana.reset();
			Sifrirana.release();
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


void __fastcall TFAdmin::XMLDocument1BeforeClose(TObject *Sender)
{
    FGlavna->zatvori=1;
    FGlavna->Label1Click(this);
}
//---------------------------------------------------------------------------

