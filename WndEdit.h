#include<Windows.h>
#include "ClassGlobal.h"
#include <ctime>

#ifndef WNDEDIT
#define WNDEDIT

extern HINSTANCE hInst;
extern IFacade* manager;
extern int idEdit;

class WndEdit {
private:
	WNDCLASSEX wce;
	HWND hWnd;
	int id;

public:
	WndEdit() {};
	~WndEdit() {};
	void start();
	void registWnd();
	void creatWnd();
	static LRESULT CALLBACK WndProcEdit(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	int loopProc();

};

#endif 
