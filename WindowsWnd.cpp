#include "WindowsWnd.h"

#ifdef ATWin

#include <Windows.h>

bool WindowsWnd::CreateWnd()
{
    static bool isCreated = false;

    if (isCreated) return false;

    HINSTANCE hInst = GetModuleHandle(NULL);

    _wnd.cbSize = sizeof(WNDCLASSEX);                                 // structure size
    _wnd.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                  // window style
    _wnd.lpfnWndProc = WndProc;                               // pointer to window procedure WndProc
    _wnd.cbClsExtra = 0;                                              // shared memory
    _wnd.cbWndExtra = 0;                                              // number of additional bytes
    _wnd.hInstance = hInst;                                           // application handle
    _wnd.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));   // icon descriptor
    _wnd.hCursor = LoadCursor(NULL, IDC_ARROW);                       // cursor descriptor
    _wnd.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_MENU + 1);    // background brush descriptor
    _wnd.lpszMenuName = NULL;                                         // menu name
    const wchar_t* className = this->_title;
    _wnd.lpszClassName = className;                      // window class name
    _wnd.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION)); // small icon descriptor

    if (!RegisterClassEx(&_wnd))
    {
        MessageBox(NULL,
            L"Call to RegisterClassEx failed!",
            L"CreateWnd()",
            NULL);

        return false;
    }

    _handle = ::CreateWindow(
        _wnd.lpszClassName,   // window class name
            _title,                // window title
            WS_OVERLAPPEDWINDOW,          // window type
            CW_USEDEFAULT, CW_USEDEFAULT, // starting window location in pixels (x, y)
            _width,                        // window width in pixels
            _height,                       // window height in pixels
            NULL,                         // parent window descriptor
            NULL,                         // menu descriptor
            GetModuleHandle(NULL),        // application descriptor
            NULL);

    if (!_handle){
        MessageBox(NULL,
            L"Call to CreateWindow failed!",
            L"CreateWnd()",
            NULL);

        return false;
    }

    isCreated = true;

	return true;
}

bool WindowsWnd::LogicUpdate()
{ 
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

bool WindowsWnd::Redraw()
{
	return false;
}

bool WindowsWnd::ShowWnd()
{
    ::ShowWindow(
        _handle,         // window handle
        SW_SHOWNORMAL); // show options

    // redraw window
    ::UpdateWindow(_handle);
    return true;
}

bool WindowsWnd::HideWnd()
{
    ::CloseWindow(_handle);
    return true;
}

bool WindowsWnd::CreateSubWindow(ISubWindow* subWindow, const char* title, int width, int height)
{
	SubWindWindows* SubWindow = new SubWindWindows(title, width, height, this);
	this->_subWindow[SubWindow->GetHandle()] = SubWindow;
	subWindow = SubWindow;
	return true;
}

LRESULT WindowsWnd::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_PAINT: { break; }
        case WM_MOUSEMOVE: { break; }
        case WM_LBUTTONDOWN: { break; }
        case WM_LBUTTONUP: { break; }
        case WM_TIMER: { break; }
        case WM_KEYDOWN: { break; }
        case WM_KEYUP: { break; }
        case WM_COMMAND: { break; }
        case WM_SIZE: { break; }

        case WM_DESTROY:{
            PostQuitMessage(0);
            break;
        }

        default:{
            return ::DefWindowProc(hWnd, message, wParam, lParam);
        }
    }

    return 0;
}

#endif


