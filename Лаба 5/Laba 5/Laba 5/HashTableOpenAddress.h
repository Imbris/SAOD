#pragma once
#include "HashTable.h"
#include "BankAccount.h"

class HashTableOpenAddress :
	public HashTable<int, BankAccount*>
{
public: 
	HashTableOpenAddress(int size) :HashTable(size) {}

	/// <summary>
	/// ���-�������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="attempt">����� �������</param>
	/// <returns></returns>
	int GetIndex(int key, int attempt)
	{
		return (sizeof(key) % 12 + attempt) % size;
	}

	/// <summary>
	/// ���������� ������ �������� � �������� ������ � ��������� � ������� ���-�������
	/// ��� -1 � ������ ���� ����� ������� �� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <returns></returns>
	int FindNode(int key)
	{
		int attempt = 0; // ���-�� ������� ������ �����
		int index; // ������ �������� ��������
		bool flag = false; // ���� �����������, ��� ���� �������
		HashTableNodePair<int, BankAccount*>* node = 0;
		do
		{
			index = this->GetIndex(key, attempt);
			node = &this->mass[index];
			attempt++;

			flag = node && !node->GetIsVoid() ? (node->GetValue()->account_number == key ? true : false) : false;
			if (flag) break;

		} while (node && attempt != size); // ���� �� �������� ������ ������� � �������� ������ � ���������

		// ���� ������� ������� � �������� ������ � ��������� � �������
		if (node && flag) {
			return index;
		}
		else {
			return -1;
		}
	}
};

