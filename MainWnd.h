#include<Windows.h>
#include <ctime>
#include "ClassGlobal.h"
#include <shellapi.h>

#ifndef MAINWND
#define MAINWND

extern IFacade* manager;
extern HINSTANCE hInst;
extern int idEdit;

class MainWnd : public IUserInterface {
private:
	WNDCLASSEX wc;
	HWND hWnd;

public:
	MainWnd() {};
	~MainWnd() {};
	void start();
	void registWnd();
	void creatWnd();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	HWND getHwnd();
	void enebleWnd(bool enable);
	void updataWnd();

};

#endif 


