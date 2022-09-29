//---------------------------------------------------------------------------

#ifndef GlavnaH
#define GlavnaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TFGlavna : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *BUpdate;
	TGroupBox *GroupBox1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TBindingsList *BindingsList1;
	TRESTResponse *RESTResponse1;
	TLinkControlToField *LinkControlToField1;
	TButton *Button1;
	TButton *BAdmin;
	TButton *BBazaEdit;
	TCryptographicLibrary *CryptographicLibrary1;
	TCodec *Codec1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TEdit *Edit1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit2;
	TComboBox *ComboBox3;
	TLabel *Label6;
	TButton *Button3;
	TComboBox *ComboBox4;
	TLabel *Label7;
	TCheckBox *CheckBox1;
	void __fastcall BUpdateClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BAdminClick(TObject *Sender);
	void __fastcall BBazaEditClick(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFGlavna(TComponent* Owner);
	int zatvori = 0;
};
//---------------------------------------------------------------------------
extern PACKAGE TFGlavna *FGlavna;
//---------------------------------------------------------------------------

#endif
