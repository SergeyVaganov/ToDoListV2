#include <windowsx.h>
#include <string>
#include "GLobalUGI.h"
#include "ClassGlobal.h"

void FieldEdit::setText(HWND field)
{
	std::wstring str = L" ";
	LPCWSTR txt = str.c_str();
	Edit_SetText(field, txt);
}

void FieldEdit::setText(HWND field, int id)
{
	if (id < 0) { return; };
	Note* note = manager->getNoteId(id);
	std::wstring str = note->getTxt();
	LPCWSTR txt = str.c_str();
	Edit_SetText(field, txt);
}

 HWND FieldEdit::create(int x, int y, int lenx, int leny, HWND parrent, int hMenu)
{
	HWND field = CreateWindow(L"edit", NULL, style,
		x, y, lenx, leny, parrent, (HMENU)hMenu, NULL, NULL);
	return field;
}

