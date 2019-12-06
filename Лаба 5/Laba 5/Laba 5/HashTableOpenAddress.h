#pragma once
#include "HashTable.h"
#include "BankAccount.h"

class HashTableOpenAddress :
	public HashTable<int, BankAccount*>
{
public: 
	HashTableOpenAddress(int size) :HashTable(size) {}

	/// <summary>
	/// �������� ������ �� ������� ������� � �����
	/// </summary>
	/// <param name="massOld">������ ������</param>
	/// <param name="sizeOld">������ ������</param>
	void CopyMass(HashTableNodePair<int, BankAccount*>* massOld, int sizeOld) override
	{
		if (this->size >= sizeOld)
		{
			for (size_t i = 0; i < sizeOld; i++)
			{
				if (!massOld[i].GetIsVoid()) {
					this->Add(massOld[i].GetKey(), massOld[i].GetValue());
				}
			}
		}
		else {
			for (size_t count = 0, i = 0; count < this->size; i++)
			{
				if (!massOld[i].GetIsVoid()) {
					this->Add(massOld[i].GetKey(), massOld[i].GetValue());
					count++;
				}
			}
		}
	}

	/// <summary>
	/// ���-�������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="attempt">����� �������</param>
	/// <returns></returns>
	int GetIndex(int key, int attempt) override
	{
		return (sizeof(key) % 12 + attempt) % size;
	}

	/// <summary>
	/// ���������� ������ �������� � �������� ������ � ��������� � ������� ���-�������
	/// ��� -1 � ������ ���� ����� ������� �� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <returns></returns>
	int FindNode(int key)  override
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

