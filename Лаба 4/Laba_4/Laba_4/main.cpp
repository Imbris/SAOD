#include <iostream>
#include <windows.h>
#include "RedBlackTree.h"

/// <summary>
/// ��������� ������� ��� ������������ � ������-������ ������
/// </summary>
#define NIL sentinel
BinaryTreeNode sentinel = { &NIL, &NIL, 0, NodeColor::Black, 0 };

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	RedBlackTree rbTree;

	while (answer != 0) {
		system("cls");
		cout << "������������ ������ �4 ������� �. �. ������� 2\n\n";
		cout << "������������  ���������������� �������� ������ (��������� ������-������ �������)\n";
		cout << "�������������� ����� ���� �������� ���������� ��������\n";
		cout << "\t� ������� ������ �� n �����.\n";
		cout << "\t� ���������� ����� ����, ������������ � ������, �������� �������� ������������� ������\n";
		cout << "\t� ����� ������ ��������� ��������� ������� � ������� ��������� �� ����\n";
		cout << "\t� ����� ������������ �������� ����� ������� ������\n";
		cout << "\n����\n";
		cout << "1) ������� ����� ������ �� n �����\n";
		cout << "0) �����\n";
		cout << "\n��� �����: ";
		while ((!(cin >> answer)) || cin.get() != '\n') {     //������ �������� �� ���� ����   
			cout << "ERROR\n";
			cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
			cin.sync();//������ ������ �� �������
			cout << "��������� ���� : ";
		}
		system("cls");
		cout << "������������ ������ �4 ������� �. �. ������� 2\n\n";
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