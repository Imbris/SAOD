#pragma once
#include "Telephone.h"
#include <malloc.h>

//Создает список из n узлов
Node* createList(Node* head, int n);

//Выводит на экран список list из n узлов
void showList(Node* list);

//Находит узел с заданынм номером отправтеля
Node* findNode(Node* current, int phoneFrom);

//Возвращает указатель на последний элемент списка
Node* getLastNode(Node* current);

//Добавляет в конец списка новый узел
void addNode(Node* lastNode, Node* nodeNew);

//Возвращает первые 4 цифры телефона
int getNum(int phone);

//Меняет значения элементов списка
void swapDataNode(Node* node1, Node* node2);

//Сортирует список по первым четырем цифрам телефона
void sortList(Node* head);

//Возвращает ссылку на последний узел, содержащий соответствующий номер отправителя
Node* getLastNodeForDelete(Node* head, int phoneFrom);

//Удаляет выбранный узел
void deletChoosenNode(Node* head);

//Возвращает суммарную длиельность разговора по указанному номеру отправителя
int sumTimeTell(Node* head, int phoneFrom);
