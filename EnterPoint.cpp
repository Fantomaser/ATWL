#include "DEFINES.h"
#include "IWindow.h"

#ifdef ATWin
#include "WindowsWnd.h"
#endif 


int main() {

#ifdef ATWin
	IWindow* window = new WindowsWnd("main window", 800, 600);
#endif

}