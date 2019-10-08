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

	cout << "��������� ��������: " << n << endl;
	cout << "������� ����� ����������: "; cin >> head->phoneFrom;
	
	{
		int res = head->phoneFrom;
		int minValue = res / 1000000;
		int maxValue = res / 10000000;
		while ( !(minValue > 0 && maxValue == 0) )
		{
			cout << "����� �������� ������ �������� �� 7 ���� !\n��������� ����: ";
			cin >> res;
			minValue = res / 1000000;
			maxValue = res / 10000000;
		}
		head->phoneFrom = res;
	}

	cout << "������� ����� �����������: "; cin >> head->phoneTo;
	cout << "������� ����� ���������: "; cin >> head->timeTell;
	cout << "\n\n";

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

Node* getLastNode(Node* current)
{
	if (current)
	{
		if (current->next)
		{
			return getLastNode(current->next);
		}
		return current;
	}
	return nullptr;
}

void addNode(Node* lastNode, Node* nodeNew)
{
	nodeNew = createList(nodeNew, 1);
	lastNode->next = nodeNew;
}
