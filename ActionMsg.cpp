#include "ActionMsg.h"
#include "resource.h"

ActionMsg::ActionMsg(Note* note)
{
	this->note = note;
}

int ActionMsg::run()
{
	iUi->enebleWnd(false); //EnableWindow(hWnd, false);
	int idYesNo =  MessageBox(iUi->getHwnd(), this->note->getTxt().c_str(), L"Оповещение", MB_YESNO);
	iUi->enebleWnd(true); // EnableWindow(hWnd, true);
	return idYesNo;
}


