#define _CRT_SECURE_NO_WARNINGS
#include <windowsx.h>
#include <ctime>
#include "GLobalUGI.h"
#include "ClassGlobal.h"

HWND FieldTime::create(int x, int y, int lenx, int leny, HWND parrent, int hMenu)
{
	HWND field = CreateWindow(L"SysDateTimePick32", NULL, style,
		x, y, lenx, leny, parrent, (HMENU)hMenu, NULL, NULL);
	return field;
}

void FieldTime::setTime(HWND fieldTime) 
{
	wchar_t form[] = L"''HH':'mm'  'dddd dd' 'MMM' 'yyy";
	time_t timeNow;
	timeNow = time(NULL);
	tm t;
	tm* prt = &t;
	prt = localtime(&timeNow);
	SYSTEMTIME st;
	memset(&st, 0, sizeof(SYSTEMTIME));
	st.wSecond = prt->tm_sec;
	st.wMinute = prt->tm_min;
	st.wHour = prt->tm_hour;
	st.wDay = prt->tm_mday;
	st.wMonth = prt->tm_mon + 1;
	st.wYear = prt->tm_year + 1900;
	DateTime_SetFormat(fieldTime, form);
	SendMessage(fieldTime, DTM_SETSYSTEMTIME, GDT_VALID, (LPARAM)&st);
}

void FieldTime::setTime(HWND fieldTime, int id)
{
	wchar_t form[] = L"''HH':'mm'  'dddd dd' 'MMM' 'yyy";
	if (id < 0) { return; };
	Note* note = manager->getNoteId(id);
	time_t time = note->getTime();
	tm t;
	tm* prt = &t;
	prt = localtime(&time);
	SYSTEMTIME st;
	memset(&st, 0, sizeof(SYSTEMTIME));
	st.wSecond = prt->tm_sec;
	st.wMinute = prt->tm_min;
	st.wHour = prt->tm_hour;
	st.wDay = prt->tm_mday;
	st.wMonth = prt->tm_mon + 1;
	st.wYear = prt->tm_year + 1900; 
	DateTime_SetFormat(fieldTime, form);
	SendMessage(fieldTime, DTM_SETSYSTEMTIME, GDT_VALID, (LPARAM)&st);
}

