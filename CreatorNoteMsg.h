
#include "Note.h"
#include "Creator.h"

#ifndef CREATORNOTEMSG
#define CREATORNOTEMSG

class CreatorNoteMsg : public Creator {
private:

public:
    CreatorNoteMsg() {};
    ~CreatorNoteMsg() {};
    Note* FactoryMethod(int id, std::wstring txt, time_t time, bool status);

};

#endif 