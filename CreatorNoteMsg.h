
#include "Note.h"
#include "Creator.h"

#ifndef CREATORNOTEMSG
#define CREATORNOTEMSG

class CreatorNoteMsg : public Creator {
private:

public:
    CreatorNoteMsg() {};
    ~CreatorNoteMsg() {};
    Note* FactoryMethod(FILE* fileIn, int num);

};

#endif 