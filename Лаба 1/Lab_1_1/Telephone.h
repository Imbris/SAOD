#pragma once
typedef struct Telephone
{
	//����� �����������
	int phoneFrom;

	//����� ����������
	int phoneTo;

	//������ �� ��������� ������� ������
	struct Telephone* next;
} lstTelephone;