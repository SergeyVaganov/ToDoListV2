#include "NoteMsg.h"

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

