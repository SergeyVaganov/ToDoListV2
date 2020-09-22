#include "CreatNewBase.h"
#include "ClassGlobal.h"
#include<ctime>

std::vector<Note*> CreatNewBase::newDemoBase()
{
	std::vector<Note*> arr;
	Note* n = new NoteMsg(
		1, L"Упадешь телом — поднимут, упадешь духом — затопчут.", time(NULL) + 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		2, L"Каждое утро — это время начать жизнь снова.Коэльо", time(NULL) + 2 * 60, true);
	arr.push_back(n);	
	n = new NoteMsg(
		3, L"Если это не весело, значит вы делаете это неправильно.",
		time(NULL) + 3 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		4, L"Ничто так не украшает человека, как дружба с собственной головой.",
		time(NULL) + 4 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		5, L"Гораздо легче найти ошибку, чем истину.",
		time(NULL) + 5 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		6, L"Существуют три вида лжи: ложь, наглая ложь и статистика.",
		time(NULL) + 6 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		7, L"Там, где кончается терпение, начинается выносливость. - Конфуций.",
		time(NULL) + 7 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		8, L"Ничто так не способствует развитию интернета, как деградация телевидения.",
		time(NULL) + 8 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		9, L"Надо всегда быть радостным. Если радость кончается, ищи, в чём ошибся. ",
		time(NULL) + 9 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		10, L"В жизни, как на велосипеде: тяжело – значит, подъем!",
		time(NULL) + 10 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		11, L"Все чудеса начинаются со смены восприятия.",
		time(NULL) + 11 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		12, L"И помни: Никакой агрессии — бей и улыбайся.",
		time(NULL) + 3 * 30, true);
	arr.push_back(n);
	n = new NoteMsg(
		13, L"Нет никаких ключей от счастья. Дверь всегда открыта. - Мать Тереза.",
		time(NULL) + 5 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		14, L"В основе оптимизма лежит чистейший страх. Оскар Уайльд",
		time(NULL) + 7 * 30, true);
	arr.push_back(n);
	n = n = new NoteMsg(
		15, L"Мысли о старости действительно старят.",
		time(NULL) + 9 * 30, true);
	arr.push_back(n);
	n = new NoteMsg(
		16, L"Ничто так не выдает человека, как то, над чем он смеётся. Гёте",
		time(NULL) + 11 * 30, true);
	arr.push_back(n);
	n = new NoteMsg(
		17, L"Добрым словом и револьвером вы сможете добиться большего, чем одним только добрым словом.",
		time(NULL) + 13 * 30, true);
	arr.push_back(n);
	n = n = new NoteMsg(
		18, L"Плата за индивидуальность — одиночество.",
		time(NULL) + 15 * 30, true);
	arr.push_back(n);
	n = new NoteMsg(
		19, L"Все будет правильно, на этом построен мир. Булгаков",
		time(NULL) + 9 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		20, L"Виноваты, конечно, всегда другие…",
		time(NULL) + 10 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		21, L"Время утекает сквозь пальцы опущенных рук.",
		time(NULL) + 11 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		22, L"Хуже каменного сердца может быть только жидкий мозг.",
		time(NULL) + 12 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		23, L"Побеждают лишь те, кто сражается.",
		time(NULL) + 13 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		24, L"Всё, что есть хорошего в жизни, либо незаконно, либо аморально, либо ведет к ожирению.",
		time(NULL) - 10 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		25, L"Жизнь требует движений.  Аристотель",
		time(NULL) - 30 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		26, L"В жизни ни к чему нельзя привыкать, даже к жизни.  Будда",
		time(NULL) - 15 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		27, L"Надо работать не по 12 часов в день, а головой. Стив Джобс",
		time(NULL) + 17 * 60, true);
	arr.push_back(n);
	n = new NoteMsg(
		28, L"Часто повторяемая глупость со временем превращается в бесспорную истину.",
		time(NULL) + 18 * 60, true);
	arr.push_back(n);
	return arr;
}

std::vector<Note*> CreatNewBase::newEmptyBase()
{
	std::vector<Note*> arr;
	Note* n = new NoteMsg(
		1, L"Это первая запись в вашей базе", time(NULL) + 60, true);
	arr.push_back(n);
	return arr;
};
