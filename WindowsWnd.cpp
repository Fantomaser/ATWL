#include "WindowsWnd.h"

#ifdef ATWin

#include <Windows.h>

bool WindowsWnd::CreateWnd()
{
	return false;
}

bool WindowsWnd::Run()
{
	return false;
}

bool WindowsWnd::Update()
{
	return false;
}

bool WindowsWnd::CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height)
{
	SubWindWindows* SubWindow = new SubWindWindows(title, width, height, this);
	this->_subWindow[SubWindow->GetHandle()] = SubWindow;
	subWindow = SubWindow;
	return true;
}

#endif


