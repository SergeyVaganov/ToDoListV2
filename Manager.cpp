
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
	fileInter->saveArrayNote(arrayNote->getArr());
}

Note* Manager::creatNote(int type, int id, std::wstring str, time_t time, bool status)
{
	switch (type)
	{
	case 1:
	{Creator* note = new CreatorNoteMsg();
	Note* n = note->FactoryMethod(id, str, time, status);
	return n;
	}
	default:
		break;
	}
	return nullptr;
}

void Manager::delNote(int id)
{
	this->arrayNote->arrDel(id);
	this->fileInter->saveArrayNote(arrayNote->getArr());
}

void Manager::loadArrayNote()
{
	fileInter->loadArrayNote(arrayNote->getArr());
}

void Manager::creatNewBase(std::wstring nameDat)
{
	useFile->createIni(nameDat);
	arrayNote->creatNewEmpty();
	fileInter->saveArrayNote(arrayNote->getArr());
}

void Manager::creatDemoBase()
{
	std::wstring str = L"Demo.dat";
	useFile->createIni(str);
	arrayNote->creatDemoBase();
	fileInter->saveArrayNote(arrayNote->getArr());
}

void Manager::saveArrayNote()
{
	fileInter->saveArrayNote(arrayNote->getArr());
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
