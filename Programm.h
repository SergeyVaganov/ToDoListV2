#include "ClassGlobal.h"
#include <vector>

#ifndef PROGRAMM
#define PROGRAMM

extern class UseFiles;
extern class FileInterface;
extern class ArrayNote;
extern class IFacade;
extern IFacade* manager;

class Programm {
private:
	UseFiles* useFile;
	FileInterface* fileInter;
	ArrayNote* arrayNote;
	IFacade* manager; 

public:
	Programm();
	~Programm() ;
	void setFileInter();
	IFacade* getFacade();

};

#endif 




