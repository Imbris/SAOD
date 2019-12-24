#pragma once
typedef struct Node
{
	//Номер отправителя
	int phoneFrom;

	//Номер получателя
	int phoneTo;

	//Время разговора в минутах
	int timeTell;

	//Ссылка на следующий элемент списка
	struct Node* next;
} Telephone;
