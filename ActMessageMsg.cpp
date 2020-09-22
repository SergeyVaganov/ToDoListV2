#include "ActMessageMsg.h"

ActMessageMsg::ActMessageMsg(Note* note)
{
	this->note = note;
}

int ActMessageMsg::run()
{
	iUi->enebleWnd(false); 
	int idYesNo = MessageBox(iUi->getHwnd(), this->note->getTxt().c_str(), L"Оповещение", MB_YESNO);
	iUi->enebleWnd(true); 
	return idYesNo;
}
