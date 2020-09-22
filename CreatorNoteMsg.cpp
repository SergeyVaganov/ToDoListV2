#include "CreatorNoteMsg.h"
#include "NoteMsg.h"


Note* CreatorNoteMsg::FactoryMethod(FILE* fileIn, int num)
{
	int type(1);
	int id;
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
	Note* note = new NoteMsg(id, str, time, status);
    return note;
}
