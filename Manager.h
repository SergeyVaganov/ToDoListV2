#include "ClassGlobal.h"

#ifndef MANAGER
#define MANAGER

class Manager : public IFacade {
private:
	UseFiles *useFile = nullptr;
	FileInterface *fileInter = nullptr;
	ArrayNote *arrayNote = nullptr;

public:
	Manager (UseFiles* useFile, FileInterface* fileInter, ArrayNote* arrayNote);
	~Manager () {};
	void setName(std::wstring nameDat);
	Note* getNoteId(int id);
	int sizeArrayNote();
	void newNote(Note* note);
	Note* creatNote(int type, int id, std::wstring str, time_t time, bool status) ;
	void delNote(int id);
	void loadArrayNote();
	void creatNewBase(std::wstring nameDat);
	void creatDemoBase();	
	void saveArrayNote();
	void sortArrayName();
	void sortArrayTime();
	int nextId();
	Note* getNote(int num);


};

#endif