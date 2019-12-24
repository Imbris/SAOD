#include "Operation.h"
#include <iostream>

using namespace std;

Telephone* createList(Telephone* head, int n)
{
	if (n == 0)
	{
		return NULL;
	}

	head = (Telephone*)malloc(sizeof(Telephone));

	cout << "Осталость добавить: " << n << endl;
	cout << "Введите номер получателя: "; 

	int phoneFrom;
	cin >> phoneFrom;
	head->setPhoneFrom(phoneFrom);

	{
		int res = head->getPhoneFrom();
		int minValue = res / 1000000;
		int maxValue = res / 10000000;
		while (!(minValue > 0 && maxValue == 0))
		{
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cin.ignore();
			cout << "Номер телефона долежн состоять из 7 цифр !\nПовторите ввод: ";
			cin >> res;
			minValue = res / 1000000;
			maxValue = res / 10000000;
		}
		head->setPhoneFrom(res);
	}

	cout << "Введите номер отправителя: ";
	int phoneTo;
	cin >> phoneTo;
	head->setPhoneTo(phoneTo);

	cout << "Введите время разговора: "; 
	int timeTell;
	cin >> timeTell;
	head->setTimeTell(timeTell);
	cout << "\n\n";

	head->setNext(createList(head->getNext(), n - 1));

	return head;
}

void showList(Telephone* list)
{
	if (list)
	{
		cout << "Номер отправителя: " << list->getPhoneFrom() << "\tНомер получателя: " << list->getPhoneTo() << "\tВремя разговора: " << list->getTimeTell() << endl;
		showList(list->getNext());
	}
}

Telephone* findNode(Telephone* current, int phoneFrom)
{
	if (current)
	{
		if (current->getPhoneFrom() == phoneFrom)
		{
			return current;
		}
		return findNode(current->getNext(), phoneFrom);
	}
	return NULL;
}

Telephone* getLastNode(Telephone* current)
{
	if (current)
	{
		if (current->getNext())
		{
			return getLastNode(current->getNext());
		}
		return current;
	}
	return NULL;
}

void addNode(Telephone* lastNode, Telephone* nodeNew)
{
	nodeNew = createList(nodeNew, 1);
	lastNode->setNext(nodeNew);
}

int getNum(int phone)
{
	int num1 = (phone / 1000000);
	int num2 = (phone / 100000) % 10;
	int num3 = (phone / 10000) % 10;
	return num1 * 100 + num2 * 10 + num3;
}

void swapDataNode(Telephone* node1, Telephone* node2)
{
	int phoneFrom = node1->getPhoneFrom(),
		phoneTo = node1->getPhoneTo(),
		timeTell = node1->getTimeTell();

	node1->setPhoneFrom(node2->getPhoneFrom());
	node1->setPhoneTo(node2->getPhoneTo());
	node1->setTimeTell(node2->getTimeTell());

	node2->setPhoneFrom(phoneFrom);
	node2->setPhoneTo(phoneTo);
	node2->setTimeTell(timeTell);
}

void sortList(Telephone* head)
{
	Telephone* first = head, * second = 0;
	for (second = head; second; second = second->getNext())
	{
		for (first = head; first->getNext(); first = first->getNext())
		{
			if (getNum(first->getPhoneFrom()) > getNum(first->getNext()->getPhoneFrom()))
			{
				swapDataNode(first, first->getNext());
			}
		}
	}
}

Telephone* getLastNodeForDelete(Telephone* head, int phoneFrom)
{
	Telephone* last = NULL;
	for (Telephone* i = head; i; i = i->getNext())
	{
		if (i->getPhoneFrom() == phoneFrom)
		{
			last = i;
		}
	}
	return last;
}

void deletChoosenNode(Telephone* head)
{
	int phoneFrom;
	cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
	Telephone* last = getLastNodeForDelete(head, phoneFrom);
	Telephone* prev = head;
	for (Telephone* i = head; i; i = i->getNext())
	{
		if (i == last)
		{
			if (i->getNext()) prev->setNext(i->getNext()); else prev->setNext(NULL);
			free(i);
			i = prev;
			return;
		}
		prev = i;
	}
}

int sumTimeTell(Telephone* head, int phoneFrom)
{
	int sum = 0;
	for (Telephone* i = head; i; i = i->getNext())
	{
		if (i->getPhoneFrom() == phoneFrom)
			sum += i->getTimeTell();
	}
	return sum;
}
