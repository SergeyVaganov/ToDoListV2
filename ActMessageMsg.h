#include "ClassGlobal.h"

#ifndef ACTMESSAGEMSG
#define ACTMESSAGEMSG

extern IUserInterface* iUi;

class ActMessageMsg : public ActMessage {
private:
	Note* note;

public:
	ActMessageMsg(Note* note);
	~ActMessageMsg() {};
	int run();

};

#endif // !ACTMESSAGEMSG




