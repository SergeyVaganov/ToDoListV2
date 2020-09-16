#include <vector>
#include <iostream>
#include "ClassGlobal.h"

FileInterface::FileInterface(UseFiles* useFiles)
{
	this->useFiles = useFiles;
}

Note* FileInterface::loadNoteMsg(FILE* fileIn, int i)
{
	int type(1);
	int id ;
	time_t time;
	bool status;
	size_t size(0);
	std::wstring str;
	fread(&id, sizeof(int), 1, fileIn);
	fread(&time, sizeof(time_t), 1, fileIn);
	fread(&status, sizeof(bool), 1, fileIn);
	fread(&size, sizeof(int), 1, fileIn);
	wchar_t ch;
	for (int i = 0; i < size; i++)
	{
		fread(&ch, sizeof(wchar_t), 1, fileIn);
		str.push_back(ch);
	}
	Creator* note = new CreatorNoteMsg();
	Note* n = note->FactoryMethod(id, str, time, status);
	return n;
}

void FileInterface::loadArrayNote(std::vector<Note*>* arrayNote)
{
	for (int i = 0; i < arrayNote->size(); i++) {
		delete (*arrayNote)[i];
	}
	arrayNote->clear();
	int size(0);
	int type;
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
		switch (type)
		{
		case 1:
			{Note* note(this->loadNoteMsg(fileIn, i));
			arrayNote->push_back(note); }
			break;
		default:
			break;
		}
	}
	fclose(fileIn);
}

void FileInterface::saveArrayNote(std::vector<Note*>* arrayNote, const wchar_t file[50] )
{
	FILE* fileOut;
	errno_t err;
	err = _wfopen_s(&fileOut, file, L"wb");
	if (err) {
		MessageBoxW(NULL, L"Ошибка записи файла данных", L"Ошибка", MB_YESNO);
	}
	int size = arrayNote->size();
	fwrite(&size, sizeof(int), 1, fileOut);
	for (size_t i = 0; i < size; i++)
	{
		switch ((*arrayNote)[i]->getType())
		{
		case 1:
			this->saveNoteMsg(fileOut, arrayNote, i);
			break;
		default:
			break;
		}
	}
	fclose(fileOut);
}

void FileInterface::saveArrayNote(std::vector<Note*>* arrayNote)
{
	FILE* fileOut;
	errno_t err;
	std::wstring datFile = useFiles->getDat();
	err = _wfopen_s(&fileOut, datFile.c_str(), L"wb");
	if (err) {
		MessageBoxW(NULL, L"Ошибка записи файла данных", L"Ошибка", MB_YESNO);
	}
	int size = arrayNote->size();
	fwrite(&size, sizeof(int), 1, fileOut);
	for (size_t i = 0; i < size; i++)
	{
		switch ((*arrayNote)[i]->getType())
		{
		case 1:
			this->saveNoteMsg(fileOut, arrayNote, i);
			break;
		default:
			break;
		}
	}
	fclose(fileOut);
}

void FileInterface::setUseFile(UseFiles* useFiles)
{
	this->useFiles = useFiles;
}

void FileInterface::saveNoteMsg(FILE* fileOut, std::vector<Note*>* arrayNote, int i)
{
	int type(1);
	int id = (*arrayNote)[i]->getId();
	time_t time = (*arrayNote)[i]->getTime();
	bool status = (*arrayNote)[i]->getStatus();
	std::wstring str = (*arrayNote)[i]->getTxt();
	int size = str.size();
	fwrite(&type, sizeof(int), 1, fileOut);
	fwrite(&id, sizeof(int), 1, fileOut);
	fwrite(&time, sizeof(time_t), 1, fileOut);
	fwrite(&status, sizeof(bool), 1, fileOut);
	fwrite(&size, sizeof(int), 1, fileOut);
	wchar_t ch;
	for (int i = 0; i < size; i++)
	{
		ch = str[i];
		fwrite(&ch, sizeof(wchar_t), 1, fileOut);
	}
}



