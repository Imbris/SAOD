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
	HashTableNodePair()
	{
		this->isVoid = true;
	}

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

	bool GetIsVoid() {
		return this->isVoid;
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
protected:

	/// <summary>
	/// ������ ����� ���-�������
	/// </summary>
	HashTableNodePair<TKey, TValue> *mass;

	/// <summary>
	/// ������ ���-�������
	/// </summary>
	int size;

	/// <summary>
	/// ���-�� �������� ������ � �������
	/// </summary>
	int count_not_void;

	/// <summary>
	/// ���-�������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="attempt">����� �������</param>
	/// <returns></returns>
	virtual int GetIndex(TKey key, int attempt) = 0;
public:

	/// <summary>
	/// �������������� ���-������� � �������� ��������
	/// </summary>
	/// <param name="size">������ ���-�������</param>
	HashTable<TKey, TValue>(int size)
	{
		this->size = size;
		this->count_not_void = size;
		mass = new HashTableNodePair<TKey, TValue>[size];
	}

	HashTableNodePair<TKey, TValue>* GetMass()
	{
		return this->mass;
	}

	/// <summary>
	/// ���������� ���-�� ������ ������ � ���-�������
	/// </summary>
	/// <returns></returns>
	int GetVoidCount() 
	{
		return this->count_not_void;
	}

	/// <summary>
	/// ��������� ����� ������� � ��� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	void Add(TKey key, TValue value)
	{
		// ���� ���������� �������� ��� � �������
		if (this->FindNode(key) == -1)
		{
			int attempt = 0; // ���-�� ������� �������� ����� �������
			int index; // ������ ��� ������ ��������
			HashTableNodePair<TKey, TValue> *node = 0; // ����� ������� �� ���������� � �������
			do
			{
				index = this->GetIndex(key, attempt);
				node = &this->mass[index];
				attempt++;
			} while (node && node->GetIsVoid() == false && attempt != size); // ���� ���������� �� ��������� ����� �������
		
			if ( (node && node->GetIsVoid()) || !node) { // ���� �� ��������� ����� - ������� ������
				this->mass[index] = HashTableNodePair<TKey, TValue>(key, value);
				this->count_not_void--;
			}
			else {
				throw exception("������� ���������");
			}
		}
		else {
			throw exception("������� � ��������� ������ � ��������� ��� ����������");
		}
	}

	/// <summary>
	/// ������� ������� �� ������� � �������� ������ � ���������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <returns></returns>
	bool Remove(TKey key) 
	{
		// ���� � ������� ���� ��������
		if (size)
		{
			int index = this->FindNode(key); 

			// ���� ������� ������� � �������� ������ � ��������� � �������
			if (index != -1)
			{
				this->mass[index].SetIsVoid(true); // �������� ��� ���������
			}
			else {
				throw exception("�������� � ��������� ������ � ��������� - ��� � �������");
			}
		}
	}

	/// <summary>
	/// ���������� ������ �������� � �������� ������ � ��������� � ������� ���-�������
	/// ��� -1 � ������ ���� ����� ������� �� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <returns></returns>
	virtual int FindNode(TKey key) = 0;
};