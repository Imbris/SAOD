#include <windows.h>
#include "Operation.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	HashTable<int, BankAccount*> *table = nullptr;

	while (answer != 0) {
		system("cls");
		cout << "������������ ������ �5 ������� �. �. ������� 2\n\n";
		cout << "����: ����������� ��� ����������� �������� ������ ������\n";
		cout << "����: �������� ������ �� ���������� ��� ������\n";
		cout << "\n����\n";
		cout << "1) ������������ ���-������� �� n ���������\n";
		cout << "0) �����\n";
		cout << "\n��� �����: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //������ �������� �� ���� ����   
			cout << "ERROR\n";
			cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
			cin.sync();//������ ������ �� �������
			cout << "��������� ���� : ";
		}
		system("cls");
		cout << "������������ ������ �5 ������� �. �. ������� 2\n\n";
		switch (answer)
		{
		case 1: {
			cout << "������� ������ ���-�������: ";
			int n = 0;
			cin >> n;
			table = new HashTable<int, BankAccount*>(n);
			CreateTable(table, n);
			table->Print();
			system("pause");
			break;
		}
		case 0: {
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}