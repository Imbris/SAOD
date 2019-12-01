#pragma once

/// <summary>
/// ���������, ����������� ������� �����
/// </summary>
typedef struct Node
{
	/// <summary>
	/// ����� ����� � �����
	/// </summary>
	int account_number;

	/// <summary>
	/// ��� - ������� �����
	/// </summary>
	string FIO;

	/// <summary>
	/// ����� ���������� �������
	/// </summary>
	string address;

	Node()
	{
		cout << "������� ����� ����� � �����: ";
		cin >> this->account_number;

		cout << "������� ���: ";
		cin >> this->FIO;

		cout << "������� ����� ����������: ";
		cin >> this->address;
	}

	Node(const Node& obj) {
		this->account_number = obj.account_number;
		this->address = obj.address;
		this->FIO = obj.FIO;
	}
}BankAccount;

