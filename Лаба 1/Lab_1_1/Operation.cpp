#include "Operation.h"
#include <iostream>

using namespace std;

Telephone* createList(Telephone* head, int n)
{
	if (n == 0)
	{
		return head;
	}

	head = (Telephone*)malloc(sizeof(Telephone));

	cout << "������� ����� ����������: "; cin >> head->phoneFrom;
	cout << "������� ����� �����������: "; cin >> head->phoneTo;
	cout << "������� ����� ���������: "; cin >> head->timeTell;

	createList(head->next, n-1);
}

void showList(Telephone* list)
{
	if (list)
	{
		cout << "����� �����������: " << list->phoneFrom << "\t����� ����������: " << node->list << "\t����� ���������: " << node->list << endl;
		showList(list->next);
	}
}

Telephone* findNode(Telephone* current, int phoneFrom)
{
	if (current)
	{
		if (current->phoneFrom == phoneFrom)
		{
			return current;
		}
		return findNode(current->next, phoneFrom);
	}
	return nullptr;
}
