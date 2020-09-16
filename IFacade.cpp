
/*#include "ClassGlobal.h"

IFacade::IFacade(UseFiles *useFile, FileInterface *fileInter, ArrayNote *arrayNote)
{
	this->useFile = useFile;
	this->fileInter = fileInter;
	this->arrayNote = arrayNote;
}

void IFacade::setName(std::wstring nameDat)
{
	useFile->createIni(nameDat);
	arrayNote->arrClear();
	fileInter->loadArrayNote(arrayNote->getArr());
}

Note* IFacade::getNoteId(int id)
{
	for (int i = 0; i < arrayNote->arrSize(); i++)
	{
		if (arrayNote->getNoteNum(i)->getId() == id) {
			return arrayNote->getNoteNum(i);
		}
	}
	return nullptr;
}

int IFacade::sizeArrayNote()
{
	return this->arrayNote->arrSize();
}

void IFacade::newNote(Note* note)
{
	arrayNote->arrAdd(note);
	fileInter->saveArrayNote(arrayNote->getArr());
}

Note* IFacade::creatNote(int type, int id, std::wstring str, time_t time, bool status)
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

void IFacade::delNote(int id)
{
	this->arrayNote->arrDel(id);
	this->fileInter->saveArrayNote(arrayNote->getArr());
}

void IFacade::loadArrayNote()
{
	fileInter->loadArrayNote(arrayNote->getArr());
}

void IFacade::creatNewBase(std::wstring nameDat)
{
	useFile->createIni(nameDat);
	arrayNote->creatNewEmpty();
	fileInter->saveArrayNote(arrayNote->getArr());
}

void IFacade::saveArrayNote()
{
	fileInter->saveArrayNote(arrayNote->getArr());
}

void IFacade::sortArrayName()
{
	arrayNote->sortArrayName();
}

void IFacade::sortArrayTime()
{
	arrayNote->sortArrayTime();
}

int IFacade::nextId()
{
	return arrayNote->nextId();
}

Note* IFacade::getNote(int num)
{
	return arrayNote->getNoteNum(num);
}
*/