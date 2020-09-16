#include <Windows.h>

#ifndef BUTTONS
#define BUTTONS

extern HWND hWnd;

class Buttons {
private:
	HWND parrent = nullptr;
	DWORD style = WS_CHILD | WS_VISIBLE | BS_FLAT;

public:
	Buttons() {};
	~Buttons() {};
	void StatusIcon(DWORD message);
	HWND create(LPCWSTR name, int  x, int y, int lenx, int leny, HWND parrent, int hMenu);

};

#endif