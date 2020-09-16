#include "CreatNewBase.h"
#include "ClassGlobal.h"
#include<ctime>

std::vector<Note*> CreatNewBase::newDemoBase()
{
	std::vector<Note*> arr;
	Creator* note = new CreatorNoteMsg();
	Note* n = note->FactoryMethod(
		1, L"������� ����� � ��������, ������� ����� � ��������.", time(NULL) + 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		2, L"������ ���� � ��� ����� ������ ����� �����.������", time(NULL) + 2 * 60, true);
	arr.push_back(n);	
	n = note->FactoryMethod(
		3, L"���� ��� �� ������, ������ �� ������� ��� �����������.",
		time(NULL) + 3 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		4, L"����� ��� �� �������� ��������, ��� ������ � ����������� �������.",
		time(NULL) + 4 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		5, L"������� ����� ����� ������, ��� ������.",
		time(NULL) + 5 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		6, L"���������� ��� ���� ���: ����, ������ ���� � ����������.",
		time(NULL) + 6 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		7, L"���, ��� ��������� ��������, ���������� ������������. - ��������.",
		time(NULL) + 7 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		8, L"����� ��� �� ������������ �������� ���������, ��� ���������� �����������.",
		time(NULL) + 8 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		9, L"���� ������ ���� ���������. ���� ������� ���������, ���, � ��� ������. ",
		time(NULL) + 9 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		10, L"� �����, ��� �� ����������: ������ � ������, ������!",
		time(NULL) + 10 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		11, L"��� ������ ���������� �� ����� ����������.",
		time(NULL) + 11 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		12, L"� �����: ������� �������� � ��� � ��������.",
		time(NULL) + 3 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		13, L"��� ������� ������ �� �������. ����� ������ �������. - ���� ������.",
		time(NULL) + 5 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		14, L"� ������ ��������� ����� ��������� �����. ����� ������",
		time(NULL) + 7 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		15, L"����� � �������� ������������� ������.",
		time(NULL) + 9 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		16, L"����� ��� �� ������ ��������, ��� ��, ��� ��� �� ������. ø��",
		time(NULL) + 11 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		17, L"������ ������ � ����������� �� ������� �������� ��������, ��� ����� ������ ������ ������.",
		time(NULL) + 13 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		18, L"����� �� ���������������� � �����������.",
		time(NULL) + 15 * 30, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		19, L"��� ����� ���������, �� ���� �������� ���. ��������",
		time(NULL) + 9 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		20, L"��������, �������, ������ ������",
		time(NULL) + 10 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		21, L"����� ������� ������ ������ ��������� ���.",
		time(NULL) + 11 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		22, L"���� ��������� ������ ����� ���� ������ ������ ����.",
		time(NULL) + 12 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		23, L"��������� ���� ��, ��� ���������.",
		time(NULL) + 13 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		24, L"��, ��� ���� �������� � �����, ���� ���������, ���� ���������, ���� ����� � ��������.",
		time(NULL) - 10 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		25, L"����� ������� ��������.  ����������",
		time(NULL) - 30 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		26, L"� ����� �� � ���� ������ ���������, ���� � �����.  �����",
		time(NULL) - 15 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		27, L"���� �������� �� �� 12 ����� � ����, � �������. ���� �����",
		time(NULL) + 17 * 60, true);
	arr.push_back(n);
	n = note->FactoryMethod(
		28, L"����� ����������� �������� �� �������� ������������ � ���������� ������.",
		time(NULL) + 18 * 60, true);
	arr.push_back(n);
	return arr;
}

std::vector<Note*> CreatNewBase::newEmptyBase()
{
	std::vector<Note*> arr;
	Creator* note = new CreatorNoteMsg();
	Note* n = note->FactoryMethod(
		1, L"��� ������ ������ � ����� ����", time(NULL) + 60, true);
	arr.push_back(n);
	return arr;
};
