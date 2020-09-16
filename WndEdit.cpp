#define _CRT_SECURE_NO_WARNINGS
#include "GLobalUGI.h"
#include <windowsx.h>
#include <commctrl.h>

void WndEdit::start()
{
	this->registWnd();
	if (manager->getNoteId(idEdit) < 0) { return; };
	this->creatWnd();
	this->loopProc();
}

void WndEdit::registWnd()
{
	wchar_t szClassName[] = L"WndEdit";
	this->wce.cbSize = sizeof(this->wce);
	this->wce.style = CS_HREDRAW | CS_VREDRAW;
	this->wce.lpfnWndProc = WndEdit::WndProcEdit;
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

void WndEdit::creatWnd()
{
	this->hWnd = CreateWindow(L"WndEdit", L"Редактировать запись", 
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		100, 100, 800, 160, NULL, (HMENU)NULL, hInst, NULL);
	if (!hWnd) {
		wchar_t text[100] = L"Ошибка открытия окна - Редактировать запись";
		MessageBox(NULL, text, L"Ошибка", MB_OK);
		return;
	}
	ShowWindow(this->hWnd, SW_SHOW);
}

LRESULT WndEdit::WndProcEdit(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Buttons buttonOk;
	Buttons buttonCansel;
	FieldEdit fieldEdit;
	FieldTime fieldTime;
	static HWND fEdit, fTime, bOk, bCansel;
	Note* editNote;
	static HWND fieldEdit1;
	static HWND fieldEdit2;
	wchar_t form[] = L"''HH':'mm'-'dddd dd','MMM' 'yyy";
	editNote = manager->getNoteId(idEdit);
	int id(0);
	switch (uMsg)
	{
	case WM_CREATE: 
	{
		bOk = buttonOk.create(L"Ок", 635, 10, 115, 25, hWnd, ID_EDIT_BUTTON_OK);
		bCansel = buttonCansel.create(L"Выход", 635, 50, 115, 25, hWnd, ID_EDIT_BUTTON_CANSEL);
		fEdit = fieldEdit.create(5, 5, 600, 80, hWnd, ID_ADD_EDIT);
		fTime = fieldTime.create(5, 90, 200, 25, hWnd, ID_ADD_TIME);
		id = editNote->getId();
		fieldEdit.setText(fEdit, id);
		fieldTime.setTime(fTime, id);
	}
		break;

	case WM_COMMAND:

		if (wParam == ID_EDIT_BUTTON_OK) {
			int id = editNote->getId();
			wchar_t textadd[1024];
			Edit_GetText(fEdit, textadd, 1024);
			tm tm;
			SYSTEMTIME st;
			DateTime_GetSystemtime(fTime, &st);
			tm.tm_sec = st.wSecond;
			tm.tm_min = st.wMinute;
			tm.tm_hour = st.wHour;
			tm.tm_mday = st.wDay;
			tm.tm_mon = st.wMonth - 1;
			tm.tm_year = st.wYear - 1900;
			tm.tm_isdst = -1;
			std::time_t timeAdd = std::mktime(&tm);
			manager->delNote(id);
			Note* n = manager->creatNote(1, id, textadd, timeAdd, true);
			manager->newNote(n);
			SendMessage(hWnd, WM_CLOSE,	0, 0);
			break;		
		};

		if (wParam == ID_EDIT_BUTTON_CANSEL) {
			SendMessage(hWnd, WM_CLOSE,	0, 0);
			break;
		};

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

		return 0;
	}
}

int WndEdit::loopProc()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
