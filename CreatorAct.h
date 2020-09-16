#include "ClassGlobal.h"

#ifndef CREATORACT
#define CREATORACT

extern class Action;

class CreatorAct {
private:

public:
    CreatorAct() {};
    ~CreatorAct() {};
    virtual Action* FactoryMethod(Note* note) = 0;

};

#endif 