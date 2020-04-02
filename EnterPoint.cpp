#include "DEFINES.h"
#include "IWindow.h"

#ifdef ATWin
#include "WindowsWnd.h"
#endif 


int main() {
#ifdef ATWin
	IWindow* window = new WindowsWnd(L"main window", 800, 600);
#endif
    window->CreateWnd();
    window->ShowWnd();
    while (true)
        window->LogicUpdate();

    

}