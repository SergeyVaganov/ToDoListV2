#include <vector>
#include <iostream>
#include "ClassGlobal.h"

FileInterface::FileInterface(UseFiles* useFiles)
{
	this->useFiles = useFiles;
}

void FileInterface::loadArrayNote(std::vector<Note*>* arrayNote)
{
	for (int i = 0; i < arrayNote->size(); i++) {
		delete (*arrayNote)[i];
	}
	arrayNote->clear();
	int size(0);
	int type;
	Creator* creator = nullptr;
	FILE* fileIn;
	errno_t err;
	std::wstring datFile = useFiles->getDat();
	err = _wfopen_s(&fileIn, datFile.c_str(), L"rb");
	if (err) {
		MessageBoxW(NULL, L"Ошибка чтения файла данных", L"Ошибка", MB_YESNO);
	}
	fread(&size, sizeof(int), 1, fileIn);
	for (size_t i = 0; i < size; i++)
	{
		fread(&type, sizeof(int), 1, fileIn);
		if (type == 1) {creator = new CreatorNoteMsg();}
		Note* note = creator->FactoryMethod(fileIn, i);
		arrayNote->push_back(note); 
	}
	fclose(fileIn);
}

void FileInterface::saveArrayNote(std::vector<Note*>* arrayNote, const wchar_t file[50] = L"\0" )
{
	FILE* fileOut;
	errno_t err;
	std::wstring filew = useFiles->getDat();
	if (file == L"\0") file = filew.c_str();
	err = _wfopen_s(&fileOut, file, L"wb");
	if (err) {
		MessageBoxW(NULL, L"Ошибка записи файла данных", L"Ошибка", MB_YESNO);
	}
	int size = arrayNote->size();
	fwrite(&size, sizeof(int), 1, fileOut);
	for (size_t i = 0; i < size; i++)
	{
		(*arrayNote)[i]->saveNote(fileOut, arrayNote, i);
	}
	fclose(fileOut);
}

void FileInterface::setUseFile(UseFiles* useFiles)
{
	this->useFiles = useFiles;
}
