#include <windows.h>
#include "Operation.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	int n_old = 0, n_new = 0;
	HashTableOpenAddress *table = nullptr;

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
		cout << "5) ������� ���. � ������� � ��������� ������� �����\n";
		cout << "6) ���������� �������������\n";
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
		try
		{

			switch (answer)
			{
			case 1: {
				cout << "������� ������ ���-�������: ";
				cin >> n_old;
				table = new HashTableOpenAddress(n_old);
				cout << "������� ������� �������\n";
				system("pause");
				break;
			}
			case 2: {
				if (table)
				{
					cout << "������� ����� ����� �������: ";
					int num = 0;
					cin >> num;
					int i = table->FindNode(num);
					if (i != -1) {
						HashTableNodePair<int, BankAccount*>* mass = table->GetMass();
						cout << "���: " << mass[i].GetValue()->FIO << endl;
						cout << "�����: " << mass[i].GetValue()->address << endl;
					}
					else {
						cout << "������� � ��������� ������� - ��� � �������\n";
					}
				}
				else {
					cout << "���-������� ������" << endl;
				}
				system("pause");
				break;
			}
			case 3: {
				if (table)
				{
					Print(table->GetMass(), n_old);
				}
				else {
					cout << "���-������� ������" << endl;
				}
				system("pause");
				break;
			}
			case 4: {
				if (table && table->GetVoidCount())
				{
					BankAccount* account = nullptr;
					account = new BankAccount();
					table->Add(account->account_number, account);

					Print(table->GetMass(), n_old);

					cout << "������ ������� ���������" << endl;
				}
				else {
					cout << "���-������� ��������� ���������\n��� ������� ��������� ����������� �" << endl;
				}
				system("pause");
				break;
			}
			case 5: {
				if (table && table->GetVoidCount() != n_old)
				{
					cout << "������� ����� ����� �������: ";
					int num = 0;
					cin >> num;
					if (table->Remove(num))
						cout << "���������� � ������� ������� �������" << endl;
					else
						cout << "������� ������� ��� � ���-�������" << endl;
				} else {
					cout << "���-������� ������" << endl;
				}
				system("pause");
				break;
			}
			case 6: {
				if (table && table->GetVoidCount() != n_old)
				{
					cout << "������� ����� ������ ���-�������: ";
					cin >> n_new;
					HashTableOpenAddress *tableNew = new HashTableOpenAddress(n_new);
					tableNew->CopyMass(table->GetMass(), n_old);

					table = tableNew;

					cout << "������������� ��������� �������\n";
					n_old = n_new;
					system("pause");
					break;
				}
				else {
					cout << "���-������� ������" << endl;
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
		catch (const std::exception& exc)
		{
			cout << "ERROR: " << exc.what() << endl;
			system("pause");
		}
	}
	return 0;
}