#pragma once
#include "Telephone.h"
#include <malloc.h>

//������� ������ �� n �����
Telephone* createList(Telephone* head, int n);

//������� �� ����� ������ list �� n �����
void showList(Telephone* list);

//������� ���� � �������� ������� ����������
Telephone* findNode(Telephone* current, int phoneFrom);