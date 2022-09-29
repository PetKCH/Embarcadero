//---------------------------------------------------------------------------

#ifndef EditorH
#define EditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Signatory.hpp"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TFEditor : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *EUsername;
	TEdit *EPassword;
	TEdit *EAdmin;
	TEdit *EIme;
	TEdit *EPrezime;
	TEdit *EOIB;
	TEdit *EPlaca;
	TIdTCPClient *IdTCPClient1;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	TMemo *PrikazMemo;
	TIdUDPClient *IdUDPClient1;
	TButton *Button3;
	TButton *Button4;
	TCodec *Codec1;
	TCryptographicLibrary *CryptographicLibrary1;
	TSignatory *Signatory1;
	TTaskDialog *TaskDialog1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall TaskDialog1ButtonClicked(TObject *Sender, TModalResult ModalResult,
          bool &CanClose);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFEditor(TComponent* Owner);
    String administrator;
};
//---------------------------------------------------------------------------
extern PACKAGE TFEditor *FEditor;
//---------------------------------------------------------------------------
#endif
