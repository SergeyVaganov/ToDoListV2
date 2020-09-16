#include <Windows.h>

#ifndef FIELDEDIT
#define FIELDEDIT

extern IFacade* manager;

class FieldEdit {
private:
	DWORD style = WS_CHILD | WS_VISIBLE |WS_BORDER | ES_LEFT | ES_MULTILINE | WS_VSCROLL;

public:
	FieldEdit() {};
	~FieldEdit() {};
	void setText(HWND field);
	void setText(HWND field, int id);
	HWND create(int  x, int y, int lenx, int leny, HWND parrent, int hMenu);
	
};

#endif


