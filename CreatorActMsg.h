#include "ClassGlobal.h"

#ifndef CREATORACTIONMSG
#define CREATORACTIONMSG

extern class Action;

class CreatorActMsg : public CreatorAct {
private:

public:
    CreatorActMsg() {};
    ~CreatorActMsg() {};
    Action* FactoryMethod(Note* note);

};

#endif 