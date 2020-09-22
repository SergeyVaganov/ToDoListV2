
#include "ClassGlobal.h"

Manager::Manager(UseFiles *useFile, FileInterface *fileInter, ArrayNote *arrayNote)
{
	this->useFile = useFile;
	this->fileInter = fileInter;
	this->arrayNote = arrayNote;
}

void Manager::setName(std::wstring nameDat)
{
	useFile->createIni(nameDat);
	arrayNote->arrClear();
	fileInter->loadArrayNote(arrayNote->getArr());
}

Note* Manager::getNoteId(int id)
{
	for (int i = 0; i < arrayNote->arrSize(); i++)
	{
		if (arrayNote->getNoteNum(i)->getId() == id) {
			return arrayNote->getNoteNum(i);
		}
	}
	return nullptr;
}

int Manager::sizeArrayNote()
{
	return this->arrayNote->arrSize();
}

void Manager::newNote(Note* note)
{
	arrayNote->arrAdd(note);
	fileInter->saveArrayNote(arrayNote->getArr(), L"\0");
}

Note* Manager::creatNote(int type, int id, std::wstring str, time_t time, bool status)
{
	Note* note = nullptr;
	if (type == 1) {
	note = new NoteMsg(id, str, time, status);	
	}
	return note;
}

void Manager::delNote(int id)
{
	this->arrayNote->arrDel(id);
	this->fileInter->saveArrayNote(arrayNote->getArr(), L"\0");
}

void Manager::loadArrayNote()
{
	fileInter->loadArrayNote(arrayNote->getArr());
}

void Manager::creatNewBase(std::wstring nameDat)
{
	useFile->createIni(nameDat);
	arrayNote->creatNewEmpty();
	fileInter->saveArrayNote(arrayNote->getArr(), L"\0");
}

void Manager::creatDemoBase()
{
	std::wstring str = L"Demo.dat";
	useFile->createIni(str);
	arrayNote->creatDemoBase();
	fileInter->saveArrayNote(arrayNote->getArr(), L"\0");
}

void Manager::saveArrayNote()
{
	fileInter->saveArrayNote(arrayNote->getArr(), L"\0");
}

void Manager::sortArrayName()
{
	arrayNote->sortArrayName();
}

void Manager::sortArrayTime()
{
	arrayNote->sortArrayTime();
}

int Manager::nextId()
{
	return arrayNote->nextId();
}

Note* Manager::getNote(int num)
{
	return arrayNote->getNoteNum(num);
}