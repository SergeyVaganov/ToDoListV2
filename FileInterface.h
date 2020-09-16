#include<vector>
#include<Windows.h>
#include "ClassGlobal.h"

#ifndef FILEINTERFACE
#define FILEINTERFACE

extern class UseFile;

class FileInterface {
private:
	UseFiles *useFiles;

public:
	FileInterface(UseFiles* useFiles);
	~FileInterface() {};
	void setUseFile(UseFiles *useFiles);
	Note* loadNoteMsg(FILE* fileIn, int i);
	void loadArrayNote(std::vector<Note*>* arrayNote);
	void saveArrayNote(std::vector<Note*>* arrayNote, const wchar_t file[50]);
	void saveArrayNote(std::vector<Note*>* arrayNote);
	void saveNoteMsg(FILE* fileOut, std::vector<Note*>* arrayNote, int i);

};

#endif 


