#include<iostream>
#include <vector>

#ifndef NOTE
#define NOTE

class Note {
private:

public: 
	Note() {};
	~Note() {};
	virtual void runNote() = 0;
	virtual void saveNote(FILE* fileOut, std::vector<Note*>* arrayNote, int num) = 0;
	virtual int getType() = 0;
	virtual int getId() = 0;
	virtual time_t getTime() = 0;
	virtual std::wstring getTxt() = 0;
	virtual bool getStatus() = 0;

};

#endif 




