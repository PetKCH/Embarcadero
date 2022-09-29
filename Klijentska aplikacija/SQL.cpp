//---------------------------------------------------------------------------


#pragma hdrstop
#include "SQL.h"
#include "Glavna.h"
extern float EURO;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::TPrometCalcFields(TDataSet *DataSet)
{
	int hrk = DataSet->FieldByName("Ukupno")->AsInteger;
	DataSet->FieldByName("EUR")->AsInteger = hrk / EURO;
}
//---------------------------------------------------------------------------




