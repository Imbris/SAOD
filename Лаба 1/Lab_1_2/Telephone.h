#pragma once
using namespace std;

class Telephone
{
private:
	//Номер отправителя
	int phoneFrom;

	//Номер получателя
	int phoneTo;

	//Время разговора в минутах
	int timeTell;

	//Ссылка на следующий элемент списка
	Telephone* next;

public:
	Telephone();

	int getPhoneFrom();
	int getPhoneTo();
	int getTimeTell();
	Telephone* getNext();

	void setPhoneFrom(int phoneFrom);
	void setPhoneTo(int phoneTo);
	void setTimeTell(int timeTell);
	void setNext(Telephone* next);
};
