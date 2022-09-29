//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <memory>
#include "login.h"
#include "login.cpp"
//---------------------------------------------------------------------------
USEFORM("Login.cpp", FLogin);
USEFORM("Glavna.cpp", FGlavna);
USEFORM("SQL.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("Editor.cpp", FEditor);
USEFORM("BazaEditor.cpp", FBazaEditor);
USEFORM("Baza.cpp", FBaza);
USEFORM("Admin.cpp", FAdmin);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		//Application->CreateForm(__classid(TFLogin), &FLogin);
		std::auto_ptr<TFLogin> FLogin(new TFLogin(0));
		FLogin->ShowModal();
		if (login==true) {
			Application->CreateForm(__classid(TFGlavna), &FGlavna);
		Application->CreateForm(__classid(TFBaza), &FBaza);
		Application->CreateForm(__classid(TFAdmin), &FAdmin);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TFEditor), &FEditor);
		Application->CreateForm(__classid(TFBazaEditor), &FBazaEditor);
		Application->Run();
		}
		/*else {
			ShowMessage("Krivi unos podataka!");
		}      */
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}

//---------------------------------------------------------------------------
