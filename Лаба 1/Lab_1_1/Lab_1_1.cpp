#include <iostream>
//#include <windows.h>
#include "stdlib.h"
#include "Operation.h"
#include "Telephone.h"

using namespace std;

int main()
{
	short answer2 = 10;
	Telephone* list = NULL;

	while (answer2 != 0) {
		system("clear");
		cout << "Лабораторная работа №1 Вайнштейн Д.П. Вариант 2\n\n";
		cout << "Задание 1\nРазработать многомодульную программу, \nкоторая демонстрирует выполнение всех операций, \nопределенных вариантом, над линейным однонаправленным \nдинамическим списком.\n";
		cout << "\nМеню\n";
		cout << "1) Создать новый список из n узлов\n";
		cout << "2) Вывести список\n";
		cout << "3) Найти первый узел с указанным номером отправителя\n";
		cout << "4) Добавит новый узел в список\n";
		cout << "5) Упорядочить список по 1-ым четырем цифрам телефона\n";
		cout << "6) Удалить последний узел с заданным значением телефона отправителя\n";
		cout << "7) Подчитать суммарное время разговора с заданным номером отправителя\n";
		cout << "0) Выход\n";
		cout << "\nВаш выбор: ";
		while ((!(cin >> answer2)) || cin.get() != '\n') {     //делаем проверку на ввод букв   
			cout << "ERROR\n";
			cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
			cin.sync();//Удалим данные из буффера
			cin.ignore();
			cout << "Повторите ввод : ";
		}
		system("clear");
		cout << "Лабораторная работа №1 Вайнштейн Д.П. Вариант 2\n\n";
		switch (answer2)
		{
		case 0: {
			//system("pause");
			//cin.get();			
			break;
		}
		case 1:
		{
			if (list)
			{
				free(list);
			}
			int n = 0;
			cout << "Список из скольких элементов вы хотите создать? : ";
			cin >> n;
			cout << "\n\n";
			list = (Telephone*)malloc(sizeof(Telephone));
			list = createList(list, n);

			cout << "\n\nСписок сформирован";
			cin.ignore(); cin.get();
			//system("pause");
			break;
		}
		case 2: 
		{
			if (list)
			{
				cout << "Вывод списка\n\n";
				showList(list);
			}
			else {
				cout << "Список пуст";
			}
			//cin.ignore(); 
			cin.get();
			//system("pause");
			break;
		}
		case 3:
		{
			if (list)
			{
				int phoneFrom = 0;
				cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
				Telephone* finded = findNode(list, phoneFrom);
				if (finded)
				{
					cout << "\n\n";
					cout << "Номер отправителя: " << finded->phoneFrom << "\tНомер получателя: " << finded->phoneTo << "\tВремя разговора: " << finded->timeTell << endl;
				}
				else {
					cout << "Узле с указанным телефоном отправителя - не найден"<<endl;
				}
				cin.ignore(); 
			}
			else {
				cout << "Список пуст\n\n";
			}
			cin.get();
			//system("pause");
			break;
		}
		case 4:
		{
			if (list)
			{
				addNode(getLastNode(list), NULL);
				cout << "\n\nНовый узел добавлен";
				cin.ignore();
			}
			else {
				cout << "Список пуст\n\n";
			}
			cin.get();
			//system("pause");
			break;
		}
		case 5:
		{
			if (list)
			{
				sortList(list);
				cout << "\n\nСписок упорядочен" << endl;
			}
			else {
				cout << "Список пуст\n\n";
			}
			cin.get();
			//system("pause");
			break;
		}
		case 6:
		{
			if (list)
			{
				deletChoosenNode(list);
				cout << "\n\nОперация выполнена успешно" << endl;
				cin.ignore();
			}
			else {
				cout << "Список пуст\n\n";
			}
			cin.get();
			//system("pause");
			break;
		}
		case 7:
		{
			if (list)
			{
				int phoneFrom = 0;
				cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
				cout << "\n\nВремя разговора с данным телефоном = "<< sumTimeTell(list, phoneFrom)<< endl;
				cin.ignore();
			}
			else {
				cout << "Список пуст\n\n";
			}
			cin.get();
			//system("pause");
			break;
		}
		default:
		{
			cin.ignore(); cin.get();
			//system("pause");
		}
		break;
		}
	}

	if (list)
	{
		free(list);
	}
	return 0;
}
