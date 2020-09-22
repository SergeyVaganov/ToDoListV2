#include "ActionMsg.h"
#include "resource.h"

ActionMsg::ActionMsg(Note* note)
{
	this->note = note;
	message = new ActMessageMsg(note);
	saveCom = new SaveCompleteMsg(note);
}

ActionMsg::~ActionMsg()
{
	delete message;
	delete saveCom;
}

bool ActionMsg::itisOk()
{
	if ((userReady == 6) && (flag)) { return true; };
	return false;
}

void ActionMsg::messageBox()
{
	userReady = message->run();
}

void ActionMsg::saveComp(bool ok)
{
	saveCom->run(ok);
}

