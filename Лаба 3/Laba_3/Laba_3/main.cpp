#include <windows.h>
#include "Opeartion.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	short answer = 10;
	
	try
	{
		while (answer != 0) {
			system("cls");
			cout << "������������ ������ �3 ������� �. �. ������� 2\n\n";
			cout << "����� n-�� ����� ���������\n";
			cout << "\n����\n";
			cout << "1) ���������\n";
			cout << "0) �����\n";
			cout << "\n��� �����: ";
			while ((!(cin >> answer)) || cin.get() != '\n') {     //������ �������� �� ���� ����   
				cout << "ERROR\n";
				cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
				cin.sync();//������ ������ �� �������
				cout << "��������� ���� : ";
			}
			system("cls");
			cout << "������������ ������ �2 ������� �. �. ������� 2\n\n";
			switch (answer) {
				case 1: {
					cout << "������� n: ";

					short n = 0, depth = 0;
					cin >> n;
					cout << "F[" << n << "] = " << Fibonachi(n, 0, 0, depth) << endl<<"������� ��������: "<<depth<<endl;
					system("pause");
					break;
				}
				case 0: {

					break;
				}
				default:
					break;
			}
		}
	}
	catch (const std::exception* exc)
	{
		cout << "Error: " << exc->what()<<endl;
	}


	return 0;
}