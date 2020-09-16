#include "FonLoop.h"

#include <Windows.h>
#include <future>
#include "IFacade.h"
#include "ClassGlobal.h"
#include "resource.h"
#include <ctime>




void FonLoop::run()
{
	Sleep(5000);
	while (true)
	{
	for (int i = 0; i < manager->sizeArrayNote(); i++) {
		if ((manager->getNote(i)->getTime() < time(0)) && 
			(manager->getNote(i)->getStatus() == true))
		{
			switch (manager->getNote(i)->getType())
			{
				case 1: 
				{
					int idYesNo = runMsg(i);
					saveCompleteMsg(i, idYesNo);
				}
				break;
			default:
				break;
			}
			if ( FonLoop::flag == false) { return; };
			iUi->updataWnd();
		}
	}
	if ( FonLoop::flag == false) { return; };
	Sleep(5000);
	}
}

int FonLoop::runMsg(int num)
{	
	Note* note = manager->getNote(num);
	CreatorAct* action = new CreatorActMsg;
	Action* act = action->FactoryMethod((note));
	int chek = act->run();
	delete act;
	delete action;
	return chek;
}

void FonLoop::stop()
{
	FonLoop::flag = false;
}

void FonLoop::saveCompleteMsg(int num ,int idYesNo)
{
	Note* note = manager->getNote(num);
	int id = note->getId();
	std::wstring text = note->getTxt();
	time_t timeAdd = note->getTime();
	int type = note->getType();
	if ((idYesNo == IDYES) && (flag == true))
	{
		manager->delNote(id);
		Note* newNote = manager->creatNote(type, id, text, timeAdd, false);
		manager->newNote(newNote);
	}
	else if ((idYesNo == IDNO) && (flag == true))
	{
		manager->delNote(id);
		timeAdd = time(NULL) + 60 * 5;
		Note* newNote = manager->creatNote(type, id, text, timeAdd, true);
		manager->newNote(newNote);
	}
	else return;
}
