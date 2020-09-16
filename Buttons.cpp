#include "GLobalUGI.h"

HWND Buttons::create(LPCWSTR name, int x, int y, int lenx, int leny, HWND parrent, int hMenu)
{
	this->parrent = parrent;
	HWND button = CreateWindow(L"button", name, style,
		x, y, lenx, leny, parrent, (HMENU)hMenu, NULL, NULL);
	return button;
}

void Buttons::StatusIcon(DWORD message)
{
	NOTIFYICONDATA tnd;
	memset(&tnd, 0, sizeof(NOTIFYICONDATA));
	lstrcpyn(tnd.szInfoTitle, L" ", sizeof(tnd.szInfoTitle));
	lstrcpyn(tnd.szInfo, L" ", sizeof(tnd.szInfo));
	tnd.cbSize = sizeof(NOTIFYICONDATA);
	tnd.hWnd = hWnd;
	tnd.uID = 1;
	tnd.uTimeout = 3000;
	tnd.dwInfoFlags = NIIF_INFO;
	tnd.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	tnd.uCallbackMessage = WM_NOTIFYICONMSG;
	tnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	lstrcpyn(tnd.szTip, L"ToDoLIST", sizeof(tnd.szTip) / sizeof(tnd.szTip[0]));
	Shell_NotifyIcon(message, &tnd);
}
