#include <iostream>
#include <windows.h>
#include "Operation.h"


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short answer = 10;
	RedBlackTree* rbTree = nullptr;
	int n = 0;

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
		cout << "2) ���������� ����� ����, ������������ � ������, �������� �������� ������������� ������\n";
		cout << "3) ����� ������ ��������� ��������� ������� � ������� ��������� �� ���� \n";
		cout << "4) ����� ������������ �������� ����� ������� ������\n";
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
			case 1: {
				cout << "������� ���-�� ����� � ������: ";
				cin >> n;
				if (rbTree != nullptr)
					free(rbTree);
				rbTree = new RedBlackTree();
				CreateTree(rbTree, n);
				PrintTree(rbTree->GetRoot(), n);
				system("pause");
				break;
			}
			case 2: {
				if (rbTree)
				{
					PrintTree(rbTree->GetRoot(), n);
					cout << "����� �������� � ����� ������: " << InOrderTravelRL(rbTree->GetRoot(), 0) << endl;
				}
				else {
					cout << "��� ������ ������� �� ������ ������\n";
				}
				system("pause");
				break;
			}
			case 3: {
				if (rbTree)
				{
					cout << "������� �������� ��� ������ � ������: ";
					char c;
					cin >> c;
					Node* node = FindNode(rbTree->GetRoot(), c);
					if (node && node->data != ' ') {
						cout << "���� ������, ��� �����: " << &node << " ��� ���������: " << node->data << endl;
					}
					else {
						cout << "������� ���� ��� � ������\n";
					}
				}
				else {
					cout << "��� ������ ������� �� ������ ������\n";
				}
				system("pause");
				break;
			}
			case 4: {
				if (rbTree) {
					BinaryTreeNode* max_node = FindMax(rbTree->GetRoot());
					cout << "������������ ������� ������ ����� ��������: " << max_node->data << " � �������� �����: " << (int)max_node->data << endl;
				}else {
					cout << "��� ������ ������� �� ������ ������\n";
				}
				system("pause");
				break;
			}
			default:
				break;
		}
	}

	return 0;
}