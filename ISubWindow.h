#pragma once
#include "IWindow.h"

class ISubWindow {
protected:
	const char* _title = nullptr;
	int _width = 0;
	int _height = 0;

	IWindow* _parent = nullptr;

public:

	ISubWindow(const char* title, int width, int height, IWindow* parent) { _title = title; _width = width; _height = height; _parent = parent; }
	~ISubWindow() {}

	virtual bool CreateWnd() { return false; }

	virtual bool Run() { return false; }

	virtual bool Update() { return false; }
};