#pragma once
//#include "ISubWindow.h"

class ISubWindow;

class IWindow {
protected:
	const wchar_t* _title;
	int _width;
	int _height;

public:
	
	IWindow(const wchar_t* title, int width, int height) { _title = title; _width = width; _height = height; }
	~IWindow() {}

	virtual bool CreateWnd() { return false; }

	virtual bool LogicUpdate() { return false; }

	virtual bool Redraw() { return false; }

	virtual bool ShowWnd() { return false; }

	virtual bool HideWnd() { return false; }

	virtual bool CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height) { return false; }
};