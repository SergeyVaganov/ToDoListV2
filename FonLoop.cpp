#include "ClassGlobal.h"
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
			manager->getNote(i)->runNote();
			if (!flag) { return; };
			iUi->updataWnd();
		}
	}
	if (!flag) { return; };
	Sleep(5000);
	}
}
