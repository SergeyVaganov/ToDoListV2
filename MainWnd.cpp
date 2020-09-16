#define _CRT_SECURE_NO_WARNINGS
#include "GLobalUGI.h"
#include <commctrl.h>
#include <ctime>
#include <stdio.h>
#include <string>
#include <windowsx.h>

extern HINSTANCE hInst;

void MainWnd::start()
{
	this->registWnd();
	this->creatWnd();
}

void MainWnd::registWnd()
{
	wchar_t szClassName[] = L"MainWnd";
	this->wc.cbSize = sizeof(this->wc);
	this->wc.style = CS_HREDRAW | CS_VREDRAW ;
	this->wc.lpfnWndProc = MainWnd::WndProc;
	this->wc.cbClsExtra = 0;
	this->wc.cbWndExtra = 0;
	this->wc.hInstance = hInst;
	this->wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	this->wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	this->wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	this->wc.lpszMenuName = MAKEINTRESOURCE (IDC_TODOLISTV2);
	this->wc.lpszClassName = szClassName;
	this->wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wc)) {
		wchar_t msg[100] = L"Ошибка в регистриации главного окна";
		wcscat_s(msg, szClassName);
		MessageBox(NULL, msg, L"Ошибка", MB_OK);
		return;
	}
}

void MainWnd::creatWnd() 
{
	this->hWnd = CreateWindow(L"MainWnd", L"ToDoList", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		100, 100, 800, 380, NULL, (HMENU)NULL, hInst, NULL);
	if (!hWnd) {
		wchar_t text[100] = L"Ошибка в создании главного окна";
		wcscat_s(text, L"ToDoList");
		MessageBox(NULL, text, L"Ошибка", MB_OK);
		return;
	}
		ShowWindow(this->hWnd, SW_SHOW);
}

LRESULT MainWnd::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Buttons buttonRun, buttonAdd, buttonEdit, buttonArch, buttonDel;
	FieldEdit fieldEdit;
	FieldTime fieldTime;
	ListView listView;
	static HWND lView, fEdit, fTime, bRun, bAdd, bEdit, bArch, bDel;
	int userReply;
	int id;
	switch (uMsg)
	{
		case WM_CREATE: 
		{
			bRun = buttonRun.create(L"Фоновый режим", 635, 10, 115, 25, hWnd, ID_BUTTON_RUN);
			bAdd =  buttonAdd.create(L"Добавить", 635, 50, 115, 25, hWnd, ID_BUTTON_ADD);
			bEdit = buttonEdit.create(L"Редактировать", 635, 90, 115, 25, hWnd, ID_BUTTON_EDIT);
			bDel = buttonDel.create(L"Удалить", 635, 130, 115, 25, hWnd, ID_BUTTON_DEL);
			bArch = buttonArch.create(L"Архив", 635, 170, 115, 25, hWnd, ID_BUTTON_ARCH);
			fEdit = fieldEdit.create(5, 235, 600, 80, hWnd, ID_FIELD_EDIT);
			fTime = fieldTime.create (5, 210, 200, 25, hWnd, ID_FIELD_TIME);
			lView = listView.create(5, 5, 600, 200, hWnd, ID_LIST) ;
			listView.createColumn(lView);
			listView.completeList(lView, false);
		}
		break;

		case WM_NOTIFYICONMSG: {
			switch (lParam) {
			case WM_LBUTTONDOWN:
			{	
				ShowWindow(hWnd, SW_SHOW);
			}
				break;
			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		}

		case WM_UPDATE_LIST: {
			SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
			listView.completeList(lView, false);
		}
		break;

		case WM_NOTIFY: 
		{
			switch (LOWORD(wParam))
			{
				case ID_LIST:
				{
					switch (((LPNMHDR)lParam)->code)
					{
						case NM_CLICK:
						case LVN_ITEMACTIVATE:
						{
							id = listView.getSelectId(lView);
							fieldEdit.setText(fEdit, id);
							fieldTime.setTime(fTime, id);
						}
						break;
						case LVN_COLUMNCLICK:
						{
							NMLISTVIEW* pListView = (NMLISTVIEW*)lParam;
							switch (pListView->iSubItem)
							{
							case 0:
								manager->sortArrayName();
								SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
								listView.completeList(lView, false);
								break;
							case 1:
								manager->sortArrayTime();
								SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
								listView.completeList(lView, false);
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
			}	
		}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			case ID_BUTTON_DEL: 
			{
				id = listView.getSelectId(lView);
				if (id < 0) { break; };
				userReply = MessageBox(hWnd, L"Вы хотите удалить запись?", L"", 
					MB_YESNO | MB_ICONQUESTION);
				if (IDYES == userReply)
				{
					manager->delNote(id);
					SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
					listView.completeList(lView, false);
					fieldEdit.setText(fEdit);
					fieldTime.setTime(fTime);
				}
			}
			break;

			case ID_BUTTON_ADD:
			{
				EnableWindow(hWnd, false);
				WndAdd wndAdd;
				wndAdd.start();
				EnableWindow(hWnd, true);
				SetForegroundWindow(hWnd);				
				ShowWindow(hWnd, SW_SHOW);
				SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
				listView.completeList(lView, false);
				fieldEdit.setText(fEdit);
				fieldTime.setTime(fTime);
			}
			break;

			case ID_BUTTON_EDIT: 
			{
				id = listView.getSelectId(lView);
				if (id < 0) { break; }
				idEdit = id;
				EnableWindow(hWnd, false);
				WndEdit wndEdit;
				wndEdit.start();
				EnableWindow(hWnd, true);
				SetForegroundWindow(hWnd);
				ShowWindow(hWnd, SW_SHOW);
				SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
				listView.completeList(lView, false);
				fieldEdit.setText(fEdit);
				fieldTime.setTime(fTime);
			}
			break;

			case ID_BUTTON_ARCH:
			{
				EnableWindow(hWnd, false);
				WndArch wndArch;
				wndArch.start();
				EnableWindow(hWnd, true);
				SetForegroundWindow(hWnd);
				ShowWindow(hWnd, SW_SHOW);
			}
			break;

			case ID_BUTTON_RUN:
			{	
			buttonRun.StatusIcon(NIM_ADD);
			ShowWindow(hWnd, SW_HIDE);
			}
			break;

			case ID_MENU_OPEN :
			{ 
				OPENFILENAME ofn;      
				wchar_t szFile[250];       
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFile = szFile;
				ofn.lpstrFile[0] = L'\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = L"All\0*.*\0Data\0*.dat\0";
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
				if (GetOpenFileName(&ofn) == TRUE)
				{
					manager->setName(ofn.lpstrFile);
					SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
					listView.completeList(lView, false);
				}
			}
			break;

			case ID_MENU_NEW :
			{
				OPENFILENAME ofn;      
				wchar_t szFile[250];     
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFile = szFile;
				ofn.lpstrFile[0] = L'\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = L"All\0*.*\0Data\0*.dat\0";
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST;
				if (GetSaveFileName(&ofn) == TRUE) {
					manager->creatNewBase(ofn.lpstrFile);
					SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
					listView.completeList(lView, false);
				}
			}
			break;
			case ID_MENU_DEMO:
			{
				manager->creatDemoBase();
				SendMessage(lView, LVM_DELETEALLITEMS, 0, 0);
				listView.completeList(lView, false);
			}
			break;

			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
			
			case IDM_EXIT:
				SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;
			
			default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
		break;
	case WM_CLOSE:
		userReply = MessageBox(hWnd, L"Вы хотите выйти из программы?",
			L"", MB_YESNO | MB_ICONQUESTION);
		if (IDYES == userReply)
			DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

		return 0;
	}
}

INT_PTR CALLBACK MainWnd::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

HWND MainWnd::getHwnd()
{
	return hWnd;
}

void MainWnd::enebleWnd(bool enable)
{
	EnableWindow(hWnd, enable);
}

void MainWnd::updataWnd()
{
	SendMessage(hWnd, WM_UPDATE_LIST, 0, 0);
}
