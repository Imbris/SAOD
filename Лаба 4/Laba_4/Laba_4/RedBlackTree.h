#pragma once
#include "BinaryTreeNode.h"

class RedBlackTree
{
private:
	Node* root;
public:
	/// <summary>
	/// �������������� ������ ���� ������
	/// </summary>
	RedBlackTree() {}
	~RedBlackTree();

	/// <summary>
	/// ������ ������������ ������������ ���� �
	/// </summary>
	/// <param name="x">����������� ���� � ������</param>
	void BalanceInsert(Node* x);


	/// <summary>
	/// ��������� � ������ ������� � ��������� ���������
	/// </summary>
	/// <param name="data">�������� ������������ ����</param>
	/// <returns></returns>
	Node* InsertNode(char data);

	/// <summary>
	/// �����
	/// </summary>
	/// <param name="x"></param>
	void RotateRight(Node* x);

	/// <summary>
	/// ��������� ��������� �� ������������ ������ ������
	/// </summary>
	/// <returns></returns>
	Node* GetRoot();
};

