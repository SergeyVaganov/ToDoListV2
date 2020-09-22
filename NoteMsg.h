#include<iostream>
#include "ClassGlobal.h"

#ifndef NOTEMSG
#define NOTEMSG

class NoteMsg : public Note {
private:
	int type = 1;	
	int id;
	time_t time;	
	std::wstring txt;
	bool status;

public:
	NoteMsg(int id, std::wstring txt, time_t time, bool status);
	~NoteMsg() {};
	void runNote();
	void saveNote(FILE* fileOut, std::vector<Note*>* arrayNote, int num);
	int getId();
	time_t getTime();
	std::wstring getTxt() ;
	bool getStatus();
	int getType();

};

#endif 