#include "CreatorNoteMsg.h"
#include "NoteMsg.h"


Note* CreatorNoteMsg::FactoryMethod(int id, std::wstring txt, time_t time, bool status)
{
    Note* note = new NoteMsg(id, txt, time, status);
    return note;
}
