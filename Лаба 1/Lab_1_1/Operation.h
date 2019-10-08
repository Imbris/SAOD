#pragma once
#include "Telephone.h"
#include <malloc.h>

//������� ������ �� n �����
Node* createList(Node* head, int n);

//������� �� ����� ������ list �� n �����
void showList(Node* list);

//������� ���� � �������� ������� ����������
Node* findNode(Node* current, int phoneFrom);

//���������� ��������� �� ��������� ������� ������
Node* getLastNode(Node* current);

//��������� � ����� ������ ����� ����
void addNode(Node* lastNode, Node* nodeNew);