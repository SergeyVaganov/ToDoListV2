#include "SaveCompleteMsg.h"

SaveCompleteMsg::SaveCompleteMsg(Note* note)
{
	this->note = note;
}

void SaveCompleteMsg::run(bool ok)
{
	int id = note->getId();
	std::wstring text = note->getTxt();
	time_t timeAdd = note->getTime();
	int type = note->getType();
	manager->delNote(id);
	Note* newNote;
	if (ok)	{
		newNote = manager->creatNote(type, id, text, timeAdd, false);
	}
	else {
		timeAdd = time(NULL) + 60 * 5;
		newNote = manager->creatNote(type, id, text, timeAdd, true);
	}
		manager->newNote(newNote);
}
