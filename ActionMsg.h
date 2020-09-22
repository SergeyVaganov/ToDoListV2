
#include<iostream>
#include <windows.h>
#include "ClassGlobal.h"
#include "GLobalUGI.h"
#include "FonLoop.h"

#ifndef ACTIONMSG
#define ACTIONMSG

extern bool flag;

class ActionMsg : public Action {
private:
	Note* note;
	ActMessage* message;
	SaveComplete* saveCom;
	int userReady;

public:
	ActionMsg(Note* note);
	~ActionMsg();
	bool itisOk();
	void messageBox();
	void saveComp(bool ok);

};

#endif