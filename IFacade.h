#include "ClassGlobal.h"

#ifndef IFACADE
#define IFACADE

class IFacade {
private:

public:
	IFacade() {};
	~IFacade() {};
	virtual void setName(std::wstring nameDat) = 0;
	virtual Note* getNoteId(int id) =0 ;
	virtual int sizeArrayNote() = 0;
	virtual void newNote(Note* note) = 0;
	virtual Note* creatNote(int type, int id, std::wstring str, time_t time, bool status) =0 ;
	virtual void delNote(int id) = 0;
	virtual void loadArrayNote() = 0;
	virtual void creatNewBase(std::wstring nameDat) = 0;
	virtual void creatDemoBase() = 0;
	virtual void saveArrayNote() =0 ;
	virtual void sortArrayName() =0 ;
	virtual void sortArrayTime() =0 ;
	virtual int nextId() = 0;
	virtual Note* getNote(int num) =0;

};

#endif