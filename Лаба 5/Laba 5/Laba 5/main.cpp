#include <iostream>
#include <windows.h>
	
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;

	while (answer != 0) {
		system("cls");
		cout << "������������ ������ �5 ������� �. �. ������� 2\n\n";
		cout << "����: ����������� ��� ����������� �������� ������ ������\n";
		cout << "����: �������� ������ �� ���������� ��� ������\n";
		cout << "\n����\n";
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