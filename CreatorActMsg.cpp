#include "CreatorActMsg.h"

Action* CreatorActMsg::FactoryMethod(Note* note)
{
    Action* action = new ActionMsg(note);
    return action;
}
