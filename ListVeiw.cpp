#define _CRT_SECURE_NO_WARNINGS
#include "GLobalUGI.h"
#include <ctime>
#include <string>
#include <commctrl.h>

HWND ListView::create(int x, int y, int lenx, int leny, HWND parrent, int hMenu)
{
	 HWND listView = CreateWindow(L"SysListView32", NULL, style,
		x, y, lenx, leny, parrent, (HMENU)hMenu, NULL, NULL);
	SendMessage(listView, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT);
	return listView;
}

void ListView::completeList(HWND listView, bool arch)
{
	time_t nowTime = time(0);
	std::wstring txt;
	time_t time;
	wchar_t Temp[30];
	struct tm* timeinfo;
	int id;
	LVITEM LvItem;
	memset(&LvItem, 0, sizeof(LvItem));	
	ListView_SetTextBkColor(listView, RGB(240, 240, 240));
	LvItem.mask = LVIF_TEXT; 
	for (int i = 0; i < manager->sizeArrayNote(); i++)
	{
		if ((manager->getNote(i)->getStatus() == false) && (arch==false)) { continue; };
		bool status = manager->getNote(i)->getStatus();
		LvItem.cchTextMax = 1024;
		LvItem.iItem = 0; 
		LvItem.iSubItem = 0; 
		txt = manager->getNote(i)->getTxt();
		LvItem.pszText = (LPWSTR)txt.c_str(); 
		SendMessage(listView, LVM_INSERTITEM, 0, (LPARAM)&LvItem); 
		LvItem.iSubItem = 1;
		time = manager->getNote(i)->getTime();
		timeinfo = localtime(&time);
		wcsftime(Temp, 30, L"%H:%M   %d %b. %Y", timeinfo);
		LvItem.pszText = (LPWSTR)Temp; 
		SendMessage(listView, LVM_SETITEM, 0, (LPARAM)&LvItem);
		LvItem.iSubItem = 2;
		id = manager->getNote(i)->getId();
		txt = std::to_wstring(id);
		LvItem.pszText = (LPWSTR)txt.c_str();
		SendMessage(listView, LVM_SETITEM, 0, (LPARAM)&LvItem);
	}
}

void ListView::createColumn(HWND listView)
{
	LV_COLUMN lvColumn;
	memset(&lvColumn, 0, sizeof(LV_COLUMN));
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
	lvColumn.cx = 400;
	lvColumn.pszText = (LPWSTR)L"Name";
	SendMessage(listView, LVM_INSERTCOLUMN, 0, (LPARAM)&lvColumn);
	lvColumn.cx = 200;
	lvColumn.pszText = (LPWSTR)L"Data";
	SendMessage(listView, LVM_INSERTCOLUMN, 1, (LPARAM)&lvColumn);
	lvColumn.cx = 0;
	lvColumn.pszText = (LPWSTR)L"Id";
	SendMessage(listView, LVM_INSERTCOLUMN, 2, (LPARAM)&lvColumn);
}

int ListView::getSelectId(HWND listView) {
	int id(0);
	int iSelect(0);
	iSelect = SendMessage(listView, LVM_GETNEXTITEM, -1, LVNI_FOCUSED);
	if (iSelect == -1)
	{
		MessageBox(NULL, L"Строка не выбрана",
			L"Ошибка", MB_OK | MB_ICONINFORMATION);	return -1;
	}
	LVITEM lvi;
	memset(&lvi, 0, sizeof(lvi));
	lvi.mask = LVIF_TEXT;
	wchar_t buffer[257];
	lvi.pszText = buffer;
	lvi.cchTextMax = 255;
	lvi.iItem = iSelect;
	lvi.iSubItem = 2;
	ListView_GetItem(listView, &lvi);
	lvi.pszText;
	id = _wtoi(lvi.pszText);
	return id;
}
