#include <Windows.h>
#include <commctrl.h>

#ifndef LISTVIEW
#define LISTVIEW

extern IFacade* manager;

class ListView
{
private:
	HWND listView;
	DWORD style = LVS_REPORT | WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | LVS_AUTOARRANGE | WS_BORDER;

public:
	ListView() {};
	~ListView() {};
	HWND create(int  x, int y, int lenx, int leny, HWND parrent, int hMenu);
	void completeList(HWND listView, bool arch);
	void createColumn(HWND listView);
	int getSelectId(HWND listView);

};

#endif