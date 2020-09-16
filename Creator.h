#include"Note.h"

#ifndef CREATOR
#define CREATOR

class Creator {
private:
       
public:
    Creator() {};
    ~Creator() {};
    virtual Note* FactoryMethod(int id, std::wstring txt, time_t time, bool status) = 0;

};

#endif 