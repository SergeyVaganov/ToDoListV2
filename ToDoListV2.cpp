#include "ToDoListV2.h"
#include "GLobalUGI.h"
#include "ClassGlobal.h"
#include "FonLoop.h"

HINSTANCE hInst;
HWND hWnd;
IFacade* manager;
IUserInterface* iUi;
int idEdit;
bool FonLoop::flag = true;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    hInst = hInstance;
   
    Programm programm;
    manager = programm.getFacade();
   
    IUserInterface* iUser = new MainWnd;
    iUser->start(); 
    hWnd = iUser->getHwnd();
    iUi = iUser;

    FonLoop demon;
    std::future<void> fut = std::async(demon.run);
 
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    demon.stop();
    return (int)msg.wParam;
}
