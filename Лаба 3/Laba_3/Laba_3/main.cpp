#include <windows.h>
#include "Opeartion.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	short answer = 10;
	LinkedList* linkLst = nullptr;

	try
	{
		while (answer != 0) {
			system("cls");
			cout << "������������ ������ �3 ������� �. �. ������� 2\n\n";
			cout << "\n����\n";
			cout << "1) ����� n-�� ����� ���������\n";
			cout << "2) ����� ��������� �� n-�� ������� ������\n";
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
			short n = 0;
			switch (answer) {
				case 1: {
					cout << "������� n: ";

					short depth = 0;
					cin >> n;
					cout << "F[" << n << "] = " << Fibonachi(n, 0, 0, depth) << endl<<"������� ��������: "<<depth<<endl;
					system("pause");
					break;
				}
				case 2: {
					cout << "������� n: ";

					cin >> n;
					if (linkLst != nullptr)
						ClearList(linkLst);

					linkLst = CreateList(linkLst, n);
					
					cout << "������� �������� �������� ����: ";

					int value = 0;
					cin >> value;
					
					LinkedList* elem = FindNode(linkLst, value);
					if (elem != nullptr) {
						cout << "������ ���� ����� �����: " << &elem << endl;
					}
					else {
						cout << "���� � �������� �������� value - �� ������ � ������\n";
					}

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
		if (linkLst != nullptr)
			ClearList(linkLst);
	}
	catch (const std::exception* exc)
	{
		cout << "Error: " << exc->what()<<endl;
	}


	return 0;
}