//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <IdContext.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Signatory.hpp"
#include <System.SysUtils.hpp>
String lozinka;
//---------------------------------------------------------------------------
class TServerForm : public TForm
{
__published:	// IDE-managed Components
	TIdTCPServer *IdTCPServer1;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TAutoIncField *ADOTable1ID;
	TWideStringField *ADOTable1Username;
	TWideMemoField *ADOTable1Password;
	TIntegerField *ADOTable1Admin;
	TWideMemoField *ADOTable1Ime;
	TWideMemoField *ADOTable1Prezime;
	TIntegerField *ADOTable1OIB;
	TWideStringField *ADOTable1Salt;
	TIdUDPServer *IdUDPServer1;
	TIntegerField *ADOTable1Placa;
	TCodec *Codec1;
	TSignatory *Signatory1;
	TCryptographicLibrary *CryptographicLibrary1;
	TButton *Button1;
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TServerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServerForm *ServerForm;
//---------------------------------------------------------------------------
#endif
