//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include <System.SysUtils.hpp>
#include "uTPLb_Hash.hpp"
#include "uTPLb_Signatory.hpp"
//---------------------------------------------------------------------------
class TFLogin : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TStaticText *TUsername;
	TStaticText *TPassword;
	TEdit *username;
	TEdit *password;
	TButton *BLogin;
	TIdTCPClient *IdTCPClient1;
	TXMLDocument *XMLDocument1;
	TCodec *Codec1;
	TCryptographicLibrary *CryptographicLibrary1;
	TSignatory *Signatory1;
	TCodec *Codec2;
	TCryptographicLibrary *CryptographicLibrary2;
	TCheckBox *CheckBox1;
	void __fastcall BLoginClick(TObject *Sender);
	void __fastcall XMLDocument1BeforeOpen(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLogin *FLogin;
//---------------------------------------------------------------------------
class credentials {
public:
	int permission_level;
	String username = 'none';
	String fw_username() {
		return username;
	}
	int fw_permission_level() {
		return permission_level;
	}
	credentials(int perm, String user) {
		permission_level = perm; username = user;
	}
};
#endif
