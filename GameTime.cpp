//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("PingPongUnit.cpp", PingPong_Form);
USEFORM("Point15Unit.cpp", Point15_Form);
USEFORM("Point21Unit.cpp", Point21_Form);
USEFORM("WestUnit.cpp", West_Form);
USEFORM("AccountUnit.cpp", AccountForm);
USEFORM("MainUnit.cpp", MainForm);
USEFORM("TTTUnit.cpp", TTT_Form);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Carbon");
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TPoint21_Form), &Point21_Form);
		Application->CreateForm(__classid(TAccountForm), &AccountForm);
		Application->CreateForm(__classid(TPingPong_Form), &PingPong_Form);
		Application->CreateForm(__classid(TPoint15_Form), &Point15_Form);
		Application->CreateForm(__classid(TWest_Form), &West_Form);
		Application->CreateForm(__classid(TTTT_Form), &TTT_Form);
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
