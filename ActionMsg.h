
#include<iostream>
#include <windows.h>
#include "ClassGlobal.h"
#include "GLobalUGI.h"

#ifndef ACTIONMSG
#define ACTIONMSG

extern IUserInterface* iUi;

class ActionMsg : public Action {
private:
	Note* note;

public:
	ActionMsg(Note* note);
	~ActionMsg() {};	
	int run();

};

#endif