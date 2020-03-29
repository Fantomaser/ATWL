#pragma once

#include "DEFINES.h"

#ifdef ATWin

#include <Windows.h>
#include "ISubWindow.h"

class SubWindWindows : public ISubWindow
{
public:
	SubWindWindows(const char* title, int width, int height, IWindow* parent) :ISubWindow(title, width, height, parent) {};
	~SubWindWindows() {};

	virtual bool CreateWnd();
	virtual bool Run();
	virtual bool Update();
	HWND GetHandle();

};

#endif
