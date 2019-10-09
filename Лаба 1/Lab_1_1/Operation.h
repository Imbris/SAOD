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

//���������� ������ 4 ����� ��������
int getNum(int phone);

//������ �������� ��������� ������
void swapDataNode(Node* node1, Node* node2);

//��������� ������ �� ������ ������� ������ ��������
void sortList(Node* head);

//���������� ������ �� ��������� ����, ���������� ��������������� ����� �����������
Node* getLastNodeForDelete(Node* head, int phoneFrom);

//������� ��������� ����
void deletChoosenNode(Node* head);