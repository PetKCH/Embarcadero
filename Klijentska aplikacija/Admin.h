//---------------------------------------------------------------------------

#ifndef AdminH
#define AdminH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Hash.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TFAdmin : public TForm
{
__published:	// IDE-managed Components
	TButton *BLoad;
	TXMLDocument *XMLDocument1;
	TListView *LXML;
	TButton *BDelete;
	TButton *BChange;
	TButton *BAdd;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *BEditor;
	TCodec *Codec1;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall BLoadClick(TObject *Sender);
	void __fastcall BDeleteClick(TObject *Sender);
	void __fastcall BChangeClick(TObject *Sender);
	void __fastcall BAddClick(TObject *Sender);
	void __fastcall BEditorClick(TObject *Sender);
	void __fastcall XMLDocument1BeforeOpen(TObject *Sender);
	void __fastcall XMLDocument1BeforeClose(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAdmin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAdmin *FAdmin;
//---------------------------------------------------------------------------
#endif
