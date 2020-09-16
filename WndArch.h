#include<Windows.h>
#include "ClassGlobal.h"
#include <ctime>

#ifndef WNDARCH
#define WNDARCH

extern IFacade* manager;
extern HINSTANCE hInst;

class WndArch {
private:
	WNDCLASSEX wcarch;
	HWND hWnd;

public:
	WndArch() {};
	~WndArch() {};
	void start();
	void registWnd();
	void creatWnd();
	static LRESULT CALLBACK WndProcArch(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	int loopProc();

};

#endif 