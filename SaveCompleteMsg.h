#include "ClassGlobal.h"

#ifndef SAVECOMPLETEMSG
#define SAVECOMPLETEMSG

class SaveCompleteMsg : public SaveComplete {
private:
	Note* note;

public:
	SaveCompleteMsg(Note* note);
	~SaveCompleteMsg() {};
	void run (bool ok);
	
};

#endif // !SAVECOMPLETEMSG




