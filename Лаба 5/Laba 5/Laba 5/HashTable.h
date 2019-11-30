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
	/// <returns></returns>
	int GetIndex(TKey key)
	{
		return (sizeof(key) % 12 - 'a') % size;
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
		int index = this->GetIndex(key);

		HashTableNodePair<TKey, TValue> node = this->mass[index];

		if(! node) {
			node = new HashTableNodePair<TKey, TValue>(key, value);
			mass[index] = node;
		}
	}
};

