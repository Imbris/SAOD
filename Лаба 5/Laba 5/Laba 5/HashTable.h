#pragma once

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
		return (sizeof(key) % 12 + attempt) % size;
	}
public:

	/// <summary>
	/// �������������� ���-������� � �������� ��������
	/// </summary>
	/// <param name="size">������ ���-�������</param>
	HashTable(int size)
	{
		this->size = size;
		mass = new HashTableNodePair<TKey, TValue>[size];
	}

	HashTableNodePair<TKey, TValue>* GetMass()
	{
		return this->mass;
	}

	/// <summary>
	/// ��������� ����� ������� � ��� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	void Add(TKey key, TValue value)
	{
		// ���� ���������� �������� ��� � �������
		if (this->FindNode(key, value) == -1)
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
			}
			else {
				throw new exception("������� ���������");
			}
		}
		else {
			throw new exception("������� � ��������� ������ � ��������� ��� ����������");
		}
	}

	/// <summary>
	/// ������� ������� �� ������� � �������� ������ � ���������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	/// <returns></returns>
	bool Remove(TKey key, TValue value) 
	{
		// ���� � ������� ���� ��������
		if (size)
		{
			int index = this->FindNode(key, value); 

			// ���� ������� ������� � �������� ������ � ��������� � �������
			if (index != -1)
			{
				this->mass[index].SetIsVoid(true); // �������� ��� ���������
			}
			else {
				throw new exception("�������� � ��������� ������ � ��������� - ��� � �������");
			}
		}
	}

	/// <summary>
	/// ���������� ������ �������� � �������� ������ � ��������� � ������� ���-�������
	/// ��� -1 � ������ ���� ����� ������� �� �������
	/// </summary>
	/// <param name="key">���� �������� �� ���-�������</param>
	/// <param name="value">�������� ��������������� ������� �����</param>
	/// <returns></returns>
	int FindNode(TKey key, TValue value)
	{
		int attempt = 0; // ���-�� ������� ������ �����
		int index; // ������ �������� ��������
		HashTableNodePair<TKey, TValue> *node = 0;
		do
		{
			index = this->GetIndex(key, attempt);
			node = &this->mass[index];
			attempt++;
		} while (node && (node->GetIsVoid() == true || node->GetValue() != value) && attempt != size); // ���� �� �������� ������ ������� � �������� ������ � ���������

		// ���� ������� ������� � �������� ������ � ��������� � �������
		if (node && node->GetIsVoid() == true && node->GetValue() == value) {
			return index;
		}
		else {
			return -1;
		}
	}
};