//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", ServerForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	HWND server = FindWindow(L"TServerForm", NULL);
	HANDLE hMutex = CreateMutex(NULL, FALSE, L"Server");
	if (hMutex == NULL) {
        ShowMessage(GetLastError());
	}
	else
		{
			if(GetLastError() == ERROR_ALREADY_EXISTS) {
				ShowMessage("Server je već pokrenut!");
                SetForegroundWindow(server);
                return -1;
            }
        }
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TServerForm), &ServerForm);
		Application->Run();
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
