#pragma once
#include "Telephone.h"
#include <malloc.h>

//������� ������ �� n �����
Telephone* createList(Telephone* head, int n);

//������� �� ����� ������ list �� n �����
void showList(Telephone* list);

//������� ���� � �������� ������� ����������
Telephone* findNode(Telephone* current, int phoneFrom);

//���������� ��������� �� ��������� ������� ������
Telephone* getLastNode(Telephone* current);

//��������� � ����� ������ ����� ����
void addNode(Telephone* lastNode, Telephone* nodeNew);

//���������� ������ 4 ����� ��������
int getNum(int phone);

//������ �������� ��������� ������
void swapDataNode(Telephone* node1, Telephone* node2);

//��������� ������ �� ������ ������� ������ ��������
void sortList(Telephone* head);

//���������� ������ �� ��������� ����, ���������� ��������������� ����� �����������
Telephone* getLastNodeForDelete(Telephone* head, int phoneFrom);

//������� ��������� ����
void deletChoosenNode(Telephone* head);

//���������� ��������� ����������� ��������� �� ���������� ������ �����������
int sumTimeTell(Telephone* head, int phoneFrom);