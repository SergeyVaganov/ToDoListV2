#include "NoteMsg.h"

void NoteMsg::runNote()
{
	Action* action = new ActionMsg(this);
	action->messageBox();
	action->saveComp(action->itisOk());
	delete action;
}

void NoteMsg::saveNote(FILE* fileOut, std::vector<Note*>* arrayNote, int num)
{
	int type(1);
	int id = (*arrayNote)[num]->getId();
	time_t time = (*arrayNote)[num]->getTime();
	bool status = (*arrayNote)[num]->getStatus();
	std::wstring str = (*arrayNote)[num]->getTxt();
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

int NoteMsg::getId()
{
	return id;
}

time_t NoteMsg::getTime()
{
	return this->time;
}

std::wstring NoteMsg::getTxt()
{
	return this->txt;
}

bool NoteMsg::getStatus()
{
	return this->status;
}

int NoteMsg::getType()
{
	return type;
}

NoteMsg::NoteMsg(int id, std::wstring txt, time_t time, bool status)
{
	this->txt = txt;
	this->time = time;
	this->status = status;
	this->id = id;
}

