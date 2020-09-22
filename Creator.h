#include"Note.h"

#ifndef CREATOR
#define CREATOR

class Creator {
private:
       
public:
    Creator() {};
    ~Creator() {};
    virtual Note* FactoryMethod(FILE* fileIn, int num) = 0;

};

#endif 