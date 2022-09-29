//---------------------------------------------------------------------------

#ifndef SQLH
#define SQLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOTable *TPoslovnica;
	TAutoIncField *TPoslovnicaID;
	TWideStringField *TPoslovnicaNaziv;
	TWideStringField *TPoslovnicaAdresa;
	TIntegerField *TPoslovnicaBrojstanica;
	TWideStringField *TPoslovnicaMjesto;
	TDataSource *DPoslovnica;
	TADOTable *TPromet;
	TAutoIncField *TPrometID;
	TDateTimeField *TPrometDatum;
	TIntegerField *TPrometUkupno;
	TIntegerField *TPrometID_Poslovnica;
	TIntegerField *TPrometEUR;
	TDataSource *DPromet;
	TADOTable *TVrsta_Usluga;
	TAutoIncField *TVrsta_UslugaID;
	TIntegerField *TVrsta_UslugaID_Poslovnica;
	TBooleanField *TVrsta_UslugaCar_Detailing;
	TBooleanField *TVrsta_UslugaMlaznica;
	TBooleanField *TVrsta_UslugaAuto_Cetke;
	TStringField *TVrsta_UslugaNaziv;
	TDataSource *DVrsta_Usluga;
	TWideStringField *TVrsta_UslugaOpis;
	TBlobField *TPoslovnicaSlika;
	void __fastcall TPrometCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
