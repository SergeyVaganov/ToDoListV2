#include <Windows.h>

#ifndef FIELDTIME
#define FIELDTIME

class FieldTime {
private:
	DWORD style = WS_CHILD | WS_VISIBLE;
	
public:
	FieldTime() {};
	~FieldTime() {};
	HWND create(int  x, int y, int lenx, int leny, HWND parrent, int hMenu);
	void setTime(HWND fieldTime);	
	void setTime(HWND fieldTime, int id);

};

#endif