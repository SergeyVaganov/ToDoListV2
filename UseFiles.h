#include <string>
#include <Windows.h>
#include "ClassGlobal.h"

#ifndef USEFILES
#define USEFILES

class UseFiles {
private:
	std::wstring iniFile = L"ToDo.ini";
	std::wstring datFile;

public:
	UseFiles() {};
	~UseFiles() {};
	bool haveIni();
	bool createIni(std::wstring datFile);
	std::wstring getDat();
	void setFiles();

};

#endif