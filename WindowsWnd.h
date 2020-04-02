#pragma once
#include "DEFINES.h"

#ifdef ATWin

#include <Windows.h>
#include "IWindow.h"
#include "SubWindWindows.h"
#include "ISubWindow.h"
#include <map>

class WindowsWnd : public IWindow
{
private:
	WNDCLASSEX _wnd;
	HWND _handle;
	MSG msg{ 0 };

	std::map<HWND, SubWindWindows*> _subWindow;
	
public:

	WindowsWnd(const wchar_t* title, int width, int height) :IWindow(title, width, height) {};
	~WindowsWnd() {};

	virtual bool CreateWnd();
	virtual bool LogicUpdate();
	virtual bool Redraw();
	virtual bool ShowWnd();
	virtual bool HideWnd();
	virtual bool CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

#endif

