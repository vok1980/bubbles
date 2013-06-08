
#include <windows.h>

#include "Application.h"



// WinMain
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int iInitRet = CApplication::instance().Initialize(hInst, "Bubbles", "Bubbles game");

	if (0 != iInitRet)
	{
		return 1;
	}

	return CApplication::instance().Run();
}



