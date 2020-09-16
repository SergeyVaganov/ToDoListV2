#include "GLobalUGI.h"
#include <windowsx.h>
#include <commctrl.h>

void WndAdd::start()
{
	this->registWnd();
	this->creatWnd();
	this->loopProc();
}

void WndAdd::registWnd()
{
	wchar_t szClassName[] = L"WndAdd";
	this->wce.cbSize = sizeof(this->wce);
	this->wce.style = CS_HREDRAW | CS_VREDRAW;
	this->wce.lpfnWndProc = WndAdd::WndProcAdd;
	this->wce.cbClsExtra = 0;
	this->wce.cbWndExtra = 0;
	this->wce.hInstance = hInst;
	this->wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	this->wce.hCursor = LoadCursor(NULL, IDC_ARROW);
	this->wce.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	this->wce.lpszMenuName = NULL;
	this->wce.lpszClassName = szClassName;
	this->wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wce);
}

void WndAdd::creatWnd()
{
	this->hWnd = CreateWindow(L"WndAdd", L"Добавить новую запись", 
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX ,
		100, 100, 800, 160, NULL, (HMENU)NULL, hInst, NULL);
	if (!hWnd) {
		wchar_t text[100] = L"Ошибка открытия окна - Добавить запись";
		MessageBox(NULL, text, L"Ошибка", MB_OK);
		return;
	}
	ShowWindow(this->hWnd, SW_SHOW);
}

LRESULT WndAdd::WndProcAdd(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Buttons buttonOk;
	Buttons buttonCansel;
	FieldEdit fieldEdit;
	FieldTime fieldTime;
	static HWND fEdit, fTime, bOk, bCansel;
	tm tm;
	SYSTEMTIME st;
	switch (uMsg)
	{
	case WM_CREATE:
		bOk = buttonOk.create(L"Ок", 635, 10, 115, 25, hWnd, ID_ADD_BUTTON_OK);
		bCansel = buttonCansel.create(L"Выход", 635, 50, 115, 25, hWnd, ID_ADD_BUTTON_CANSEL);
		fEdit = fieldEdit.create(5, 5, 600, 80, hWnd, ID_ADD_EDIT);
		fTime = fieldTime.create(5, 90, 300, 25, hWnd, ID_ADD_TIME);
		fieldTime.setTime(fTime);
		break;

	case WM_COMMAND: 
	{
		if (wParam == ID_ADD_BUTTON_OK) 
		{
			int nextid = manager->nextId();
			wchar_t textadd[1024];
			Edit_GetText(fEdit, textadd, 1024);
			DateTime_GetSystemtime(fTime, &st);
			tm.tm_sec = st.wSecond;
			tm.tm_min = st.wMinute;
			tm.tm_hour = st.wHour;
			tm.tm_mday = st.wDay;
			tm.tm_mon = st.wMonth - 1;
			tm.tm_year = st.wYear - 1900;
			tm.tm_isdst = -1;
			std::time_t timeAdd = std::mktime(&tm);
			Note* note = manager->creatNote(1, nextid, textadd, timeAdd, true);
			manager->newNote(note);
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		};

		if (wParam == ID_ADD_BUTTON_CANSEL) 
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		};
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

		return 0;
	}
}

int WndAdd::loopProc()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
