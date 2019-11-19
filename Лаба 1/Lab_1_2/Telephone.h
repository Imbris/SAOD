#pragma once
class Telephone
{
private:
	//����� �����������
	int phoneFrom;

	//����� ����������
	int phoneTo;

	//����� ��������� � �������
	int timeTell;

	//������ �� ��������� ������� ������
	Telephone* next = nullptr;

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

