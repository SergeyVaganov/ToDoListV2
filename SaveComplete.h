#include "ClassGlobal.h"

#ifndef SAVECOMPLETE
#define SAVECOMPLETE

class SaveComplete {
private:

public:
	SaveComplete() {};
	~SaveComplete() {};
	virtual void run(bool ok) = 0;

};

#endif // !SAVECOMPLETE


