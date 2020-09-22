#include "ClassGlobal.h"

#ifndef ACTION
#define ACTION

extern class ActMessage;
extern class SaveComplete;

class Action {
private:
	ActMessage* message;
	SaveComplete* saveCom;

public:
	Action() {};
	~Action() {};
	virtual void messageBox() = 0;
	virtual bool itisOk() = 0;
	virtual void saveComp(bool ok) = 0;

};

#endif 

