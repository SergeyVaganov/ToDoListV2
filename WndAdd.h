#include<Windows.h>
#include "ClassGlobal.h"
#include <ctime>

#ifndef WNDADD
#define WNDADD

extern IFacade* manager;
extern HINSTANCE hInst;

class WndAdd {
private:
	WNDCLASSEX wce;
	HWND hWnd;

public:
	WndAdd() {};
	~WndAdd() {};
	void start();
	void registWnd();
	void creatWnd();
	static LRESULT CALLBACK WndProcAdd(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	int loopProc();
	
};

#endif 




