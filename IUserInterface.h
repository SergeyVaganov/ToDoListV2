#include <Windows.h>

#ifndef IUSERINTERFACE
#define IUSERINTERFACE

class IUserInterface {
private:

public:
	IUserInterface() {};
	~IUserInterface() {};
	virtual void start() = 0;
	virtual void enebleWnd(bool enable) = 0;
	virtual void updataWnd() = 0;
	virtual HWND getHwnd() = 0;
	
};

#endif // !IUSERINTERFACE



