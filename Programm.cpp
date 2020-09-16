#include "ClassGlobal.h"

Programm::Programm()
{
	this->useFile = new UseFiles;
	this->fileInter = new FileInterface(useFile);
	this->arrayNote = new ArrayNote;
	this->manager = new Manager(useFile, fileInter, arrayNote);
	std::wstring datFile;
	if (useFile->haveIni() == false) {
		datFile = L"ToDo.dat";
		useFile->createIni(datFile);
		arrayNote->creatDemoBase();
		fileInter->saveArrayNote(arrayNote->getArr(), L"Demo.dat");		
		arrayNote->creatNewEmpty();
		fileInter->saveArrayNote(arrayNote->getArr());
	}
	else {
		useFile->setFiles();
		fileInter->loadArrayNote(arrayNote->getArr());
	}
	manager = this->manager;
}

Programm::~Programm()
{
	delete 	this->useFile;
	delete this->fileInter;
	delete this->arrayNote;
	delete this->manager;
}

void Programm::setFileInter()
{
	fileInter->setUseFile(useFile);
}

IFacade* Programm::getFacade()
{
	return manager;
}
