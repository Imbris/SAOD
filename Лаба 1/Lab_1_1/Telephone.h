#pragma once
typedef struct Node
{
	//����� �����������
	int phoneFrom;

	//����� ����������
	int phoneTo;

	//����� ��������� � �������
	int timeTell;

	//������ �� ��������� ������� ������
	struct Node* next;
} Telephone;