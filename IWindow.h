#pragma once
#include <map>
#include "ISubWindow.h"

class IWindow {
protected:
	const char* _title;
	int _width;
	int _height;

	static std::map<void*, ISubWindow*> _subWindow;

public:
	
	IWindow(const char* title, int width, int height) { _title = title; _width = width; _height = height; }
	~IWindow() {}

	virtual bool CreateWnd() { return false; };

	virtual bool Run() { return false; };

	virtual bool Update() { return false; };

	virtual bool CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height) { return false; };
};