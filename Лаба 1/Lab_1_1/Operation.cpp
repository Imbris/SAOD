#include "Operation.h"
#include <iostream>

using namespace std;

Node* createList(Node* head, int n)
{
	if (n == 0)
	{
		return nullptr;
	}

	head = (Node*)malloc(sizeof(Node));

	cout << "������� ����� ����������: "; cin >> head->phoneFrom;
	cout << "������� ����� �����������: "; cin >> head->phoneTo;
	cout << "������� ����� ���������: "; cin >> head->timeTell;

	head->next = createList(head->next, n - 1);

	return head;
}

void showList(Node* list)
{
	if (list)
	{
		cout << "����� �����������: " << list->phoneFrom << "\t����� ����������: " << list->phoneTo << "\t����� ���������: " << list->timeTell << endl;
		showList(list->next);
	}
}

Node* findNode(Node* current, int phoneFrom)
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
