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
	void loadArrayNote(std::vector<Note*>* arrayNote);
	void saveArrayNote(std::vector<Note*>* arrayNote, const wchar_t file[50]);

};

#endif 


