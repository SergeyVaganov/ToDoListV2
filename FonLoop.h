#include <vector>
#include "ClassGlobal.h"
#include "GLobalUGI.h"
#include <thread>
#include <future>

#ifndef FONLOOP
#define FONLOOP

extern HWND hWnd;

extern class IFacad;
extern IFacade* manager;
extern IUserInterface* iUi;

class FonLoop {
private:
	static bool flag;
	
public:
	FonLoop() {};
	~FonLoop() {};
	static void run();
	static int runMsg(int id);
	void stop();
	static void saveCompleteMsg(int num, int idYesNo);

};

#endif // !FILEINTERFACE

