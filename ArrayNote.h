#include "ClassGlobal.h"
#include<vector>

#ifndef ARRYANOTE
#define ARRYANOTE

class ArrayNote {
private:
	std::vector<Note*> arrayNote;

public:
	ArrayNote() {};
	~ArrayNote();
	std::vector<Note*>* getArr();
	void creatNewEmpty();
	void creatDemoBase();
	void arrAdd(Note* Note);
	void arrDel(int id);
	void arrClear();
	Note* getNoteId(int id);
	Note* getNoteNum(int num);
	int arrSize();
	int nextId();
	void sortArrayName();
	void sortArrayTime();
};

#endif