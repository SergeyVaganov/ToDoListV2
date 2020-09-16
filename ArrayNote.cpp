#include "ClassGlobal.h"
#include <algorithm>


ArrayNote::~ArrayNote()
{
	for (int i = 0; i < arrayNote.size(); i++) {
		delete arrayNote[i];	
	}
}

std::vector<Note*>* ArrayNote::getArr()
{
	return &arrayNote;
}

void ArrayNote::creatNewEmpty()
{
	for (int i = 0; i < arrayNote.size(); i++) {
		delete arrayNote[i];	
	}
	CreatNewBase* base = new CreatNewBase();
	this->arrayNote = base->newEmptyBase();
	delete base;
}

void ArrayNote::creatDemoBase()
{
	for (int i = 0; i < arrayNote.size(); i++) {
		delete arrayNote[i];	
	}
	CreatNewBase* base = new CreatNewBase();
	this->arrayNote = base->newDemoBase();
	delete base;
}

void ArrayNote::arrAdd(Note* Note)
{
	arrayNote.push_back(Note);
}

void ArrayNote::arrDel(int id)
{
	int position;
	for (int i = 0; i < arrayNote.size(); i++)
	{
		if (arrayNote[i]->getId() == id) {
			position = i;
			break;
		}
	}
	delete arrayNote[position];
	arrayNote.erase(arrayNote.begin() + position);
}

void ArrayNote::arrClear()
{
	for (int i = 0; i < arrayNote.size(); i++)
	{
		delete arrayNote[i];
	}
	arrayNote.clear();
}

Note* ArrayNote::getNoteId(int id)
{
	for (int i = 0; i < arrayNote.size(); i++)
	{
		if (arrayNote[i]->getId() == id) {
			return arrayNote[i];
		}
	}
	return nullptr;
}

Note* ArrayNote::getNoteNum(int num)
{
	return arrayNote[num];
}

int ArrayNote::arrSize()
{
	return arrayNote.size();
}

int ArrayNote::nextId()
{
	int maxid(0);
	for (int i = 0; i < arrayNote.size(); i++) {
		if (arrayNote[i]->getId() > maxid) {
			maxid = arrayNote[i]->getId();
		};
	}
	maxid++;
	return maxid;
}

void ArrayNote::sortArrayName()
{
	std::sort(arrayNote.begin(), arrayNote.end(),
	[](Note* left, Note* right) {return left->getTxt() > right->getTxt();});
}

void ArrayNote::sortArrayTime()
{
	std::sort(arrayNote.begin(), arrayNote.end(),
	[](Note* left, Note* right) {return left->getTime() > right->getTime();});
}
