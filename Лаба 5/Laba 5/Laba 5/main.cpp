#include <windows.h>
#include "Operation.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	int n = 0;
	HashTable<int, BankAccount*> *table = nullptr;

	while (answer != 0) {
		system("cls");
		cout << "������������ ������ �5 ������� �. �. ������� 2\n\n";
		cout << "����: ����������� ��� ����������� �������� ������ ������\n";
		cout << "����: �������� ������ �� ���������� ��� ������\n";
		cout << "\n����\n";
		cout << "1) ������������/����������� ���-������� �� n ���������\n";
		cout << "2) ������� ������ ������� �� ������ �����\n";
		cout << "3) ������� ���-�������\n";
		cout << "4) �������� ���. � ����� ������� ���-�������\n";
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
			cin >> n;
			table = new HashTable<int, BankAccount*>(n);
			cout << "������� ������� �������\n";
			system("pause");
			break;
		}
		case 2: {
			cout << "������� ����� ����� �������: ";
			int num = 0;
			cin >> num;
			int i = table->FindNode(num);
			if (i != -1) {
				HashTableNodePair<int, BankAccount*> *mass = table->GetMass();
				cout << "���: " << mass[i].GetValue()->FIO << endl;
				cout << "�����: " << mass[i].GetValue()->address << endl;
			}
			else {
				cout << "������� � ��������� ������� - ��� � �������\n";
			}

			system("pause");
			break;
		}
		case 3: {
			Print(table->GetMass(), n);
			system("pause");
			break;
		}
		case 4: {
			if (table->GetVoidCount())
			{
				BankAccount* account = nullptr;
				account = new BankAccount();
				table->Add(account->account_number, account);
				cout << "������ ������� ���������" << endl;
			}
			else {
				cout << "���-������� ��������� ���������\n��� ������� ��������� ����������� �" << endl;
			}
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