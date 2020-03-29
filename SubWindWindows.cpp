#include "SubWindWindows.h"

#ifdef ATWin

#include <Windows.h>

bool SubWindWindows::CreateWnd()
{
	return false;
}

bool SubWindWindows::Run()
{
	return false;
}

bool SubWindWindows::Update()
{
	return false;
}

HWND SubWindWindows::GetHandle()
{
	return HWND();
}


#endif

