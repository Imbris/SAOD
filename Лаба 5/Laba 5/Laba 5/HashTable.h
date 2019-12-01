#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// ��������� ����� ��� ����� ���-�������
/// TKey - ��� ��� �����
/// TValue - ��� ��� ��������
/// </summary>
template<class TKey, class TValue>
class HashTableNodePair
{
private:
	TKey key;
	TValue value;
	bool isVoid; // ��������� - ������ �� �������
public:

	/// <summary>
	/// �������������� ����� ������� � ���-�������
	/// </summary>
	/// <param name="key">���� � ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	HashTableNodePair(TKey key, TValue value)
	{
		this->key = key;
		this->value = value;
		this->isVoid = false;
	}

	TValue GetValue() {
		return value;
	}

	TKey GetKey() {
		return key;
	}

	void SetValue(TValue value) {
		this->value = value;
	}

	void SetIsVoid(bool value) {
		this->isVoid = value;
	}
};

/// <summary>
/// ��������� ����� ���-�������
/// TKey - ��� ��� �����
/// TValue - ��� ��� ��������
/// </summary>
template<class TKey, class TValue>
class HashTable
{
private:

	/// <summary>
	/// ������ ����� ���-�������
	/// </summary>
	HashTableNodePair<TKey, TValue> *mass;

	/// <summary>
	/// ������ ���-�������
	/// </summary>
	int size;

	/// <summary>
	/// ���-�������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="attempt">����� �������</param>
	/// <returns></returns>
	int GetIndex(TKey key, int attempt)
	{
		return (sizeof(key) % 12 - 'a' + attempt) % size;
	}
public:

	/// <summary>
	/// �������������� ���-������� � �������� ��������
	/// </summary>
	/// <param name="size">������ ���-�������</param>
	HashTable(int size)
	{
		mass = new HashTableNodePair<TKey, TValue>[size];
	}

	/// <summary>
	/// ��������� ����� ������� � ��� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	void Add(TKey key, TValue value)
	{
		int attempt = 0; // ���-�� ������� �������� ����� �������
		int index; // ������ ��� ������ ��������
		HashTableNodePair<TKey, TValue> node = 0; // ����� ������� �� ���������� � �������
		do
		{
			index = this->GetIndex(key, attempt);
			node = this->mass[index];
			attempt++;
		} while (node && node.isVoid == false && attempt != size); // ���� ���������� �� ��������� ����� �������

		
		if (node && node.isVoid == true) { // ���� �� ��������� ����� - ������� ������
			this->mass[index].SetValue(value);
			this->mass[index].SetIsVoid(false);
		}
		else if(!node){
			this->mass[index] = new HashTableNodePair<TKey, TValue>(key, value);
		}
		else {
			throw new exception("������� ���������");
		}
	}

	void Print()
	{
		for (size_t j = 0; j < 50; j++) cout << "_";
		cout << endl;

		cout << "|\tKey\t|";
		for (size_t i = 0; i < this->size; i++)
		{
			if(mass[i])
				cout << "|\t" <<mass[i].GetKey()<< "\t|";
			else
				cout << "|\tNULL\t|";
		}
		cout << endl;

		cout << "|\tValue\t|";
		for (size_t i = 0; i < this->size; i++)
		{
			if (mass[i])
				cout << "|\t" << mass[i].GetValue() << "\t|";
			else
				cout << "|\tNULL\t|";
		}
		cout << endl;
	}

	bool Remove(TKey key, TValue value) 
	{
		// ���� � ������� ���� ��������
		if (size)
		{
			int attempt = 0; // ���-�� ������� ������ �����
			int index; // ������ �������� ��������
			HashTableNodePair<TKey, TValue> node = 0; // ����� ������� �� ���������� � �������
			do
			{
				index = this->GetIndex(key, attempt);
				node = this->mass[index];
				attempt++;
			} while (node && (node.isVoid == true || node.GetValue != value) && attempt != size); // ���� �� �������� ������ ������� � �������� ������ � ���������
			
			// ����� ������� ������� � �������� ������ � ��������� � �������
			if (node && node.isVoid == true && node.GetValue == value) {
				this->mass[index].SetIsVoid(true); // �������� ��� ���������
			}
		}
	}
};

