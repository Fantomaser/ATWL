#pragma once
#include "DEFINES.h"

#ifdef ATWin

#include <Windows.h>
#include "IWindow.h"
#include "ISubWindow.h"
#include "SubWindWindows.h"

class WindowsWnd : public IWindow
{
private:
	WNDCLASSEX s_WndClassEx;
	HWND handle;
	
public:

	WindowsWnd(const char* title, int width, int height) :IWindow(title, width, height) {};
	~WindowsWnd() {};

	virtual bool CreateWnd();
	virtual bool Run();
	virtual bool Update();
	virtual bool CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height);

};

#endif

