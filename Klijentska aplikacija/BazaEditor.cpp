//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BazaEditor.h"
#include "SQL.h"
#include "jpeg.hpp"
#include "pngimage.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFBazaEditor *FBazaEditor;
//---------------------------------------------------------------------------
__fastcall TFBazaEditor::TFBazaEditor(TComponent* Owner)
	: TForm(Owner)
{
    DBImage1->DoubleBuffered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFBazaEditor::Button2Click(TObject *Sender)
{
	DataModule1->TPromet->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TFBazaEditor::DDodajClick(TObject *Sender)
{
	DataModule1->TPoslovnica->Append();
	DataModule1->TPoslovnica->FieldByName("naziv")->AsString = DBEdit1->Text;
	DataModule1->TPoslovnica->FieldByName("adresa")->AsString = DBEdit2->Text;
	DataModule1->TPoslovnica->FieldByName("broj stanica")->AsInteger = DBEdit3->Text.ToInt();
	DataModule1->TPoslovnica->FieldByName("mjesto")->AsString = DBEdit4->Text;
	DataModule1->TPoslovnica->Post();
}
//---------------------------------------------------------------------------


void __fastcall TFBazaEditor::Button1Click(TObject *Sender)
{
	if(OpenDialog1->Execute()){
	DataModule1->TPoslovnica->Edit();
	static_cast<TBlobField*>(DataModule1->TPoslovnica->FieldByName("Slika"))->LoadFromFile(OpenDialog1->FileName);
	DataModule1->TPoslovnica->Post();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFBazaEditor::Button3Click(TObject *Sender)
{
	DataModule1->TPoslovnica->Edit();
	DataModule1->TPoslovnica->FieldByName("Slika")->Clear();
	DataModule1->TPoslovnica->Post();
}
//---------------------------------------------------------------------------

