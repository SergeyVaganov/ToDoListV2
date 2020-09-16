#define _CRT_SECURE_NO_WARNINGS
#include "GLobalUGI.h"
#include <windowsx.h>
#include <commctrl.h>
#include <string>

void WndArch::start()
{
	this->registWnd();
	this->creatWnd();
	this->loopProc();
}

void WndArch::registWnd()
{
	wchar_t szClassName[] = L"WndArch";
	this->wcarch.cbSize = sizeof(this->wcarch);
	this->wcarch.style = CS_HREDRAW | CS_VREDRAW;
	this->wcarch.lpfnWndProc = WndArch::WndProcArch;
	this->wcarch.cbClsExtra = 0;
	this->wcarch.cbWndExtra = 0;
	this->wcarch.hInstance = hInst;
	this->wcarch.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	this->wcarch.hCursor = LoadCursor(NULL, IDC_ARROW);
	this->wcarch.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	this->wcarch.lpszMenuName = NULL;
	this->wcarch.lpszClassName = szClassName;
	this->wcarch.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	!RegisterClassEx(&wcarch);
}

void WndArch::creatWnd()
{
	this->hWnd = CreateWindow(L"WndArch", L"Архив записей", 
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		100, 100, 800, 250, NULL, (HMENU)NULL, hInst, NULL);
	if (!hWnd) {
		wchar_t text[100] = L"Ошибка открытия окна - Архив записей";
		MessageBox(NULL, text, L"Ошибка", MB_OK);
		return;
	}
	ShowWindow(this->hWnd, SW_SHOW);
}

LRESULT WndArch::WndProcArch(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Buttons buttonDel;
	Buttons buttonCansel;
	ListView listView;
	static HWND lView, bDel, bCansel;
	int id;
	int userReply;
	switch (uMsg)
	{
	case WM_CREATE:
	{
		bDel = buttonDel.create(L"Удалить", 635, 10, 115, 25, hWnd, ID_ARCH_DEL);
		bCansel = buttonCansel.create(L"Выход", 635, 50, 115, 25, hWnd, ID_ARCH_CANSEL);
		lView = listView.create(5, 5, 600, 200, hWnd, ID_LIST_ARCH);
		listView.createColumn(lView);
		listView.completeList(lView, true);
	}
	break;

	case WM_NOTIFY:
	{
		switch (LOWORD(wParam))
		{
		case ID_LIST_ARCH:
		{
			switch (((LPNMHDR)lParam)->code)
			{
			case LVN_COLUMNCLICK:
			{
				NMLISTVIEW* pListView = (NMLISTVIEW*)lParam;
				switch (pListView->iSubItem)
				{
				case 0:
					manager->sortArrayName();
					SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
					listView.completeList(lView, true);
					break;
				case 1:
					manager->sortArrayTime();
					SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
					listView.completeList(lView, true);
					break;
				default:
					break;
				}
			}
			break;

			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		}
		break;
		}
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_ARCH_DEL:
		{
			id = listView.getSelectId(lView);
			if (id < 0) { break; };
			userReply = MessageBox(hWnd, L"Вы хотите удалить запись?", L"",
				MB_YESNO | MB_ICONQUESTION);
			if (IDYES == userReply)
			{
				manager->delNote(id);
				SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
				listView.completeList(lView, true);
			}
		}
		break;
		case ID_ARCH_CANSEL:
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;

		}
	}
		break;	

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

	}
	return 0;
};

int WndArch::loopProc()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
