#pragma once
typedef struct Telephone
{
	//����� �����������
	int phoneFrom;

	//����� ����������
	int phoneTo;

	//����� ��������� � �������
	int timeTell;

	//������ �� ��������� ������� ������
	struct Telephone* next;
} lstTelephone;