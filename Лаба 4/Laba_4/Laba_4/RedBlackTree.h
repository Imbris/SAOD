#pragma once
#include "BinaryTreeNode.h"

class RedBlackTree: BinaryTreeNode
{
private:
	/// <summary>
	/// �������� ������ �����
	/// </summary>
	/// <param name="node">���� ������, ����� �������� ����� �������</param>
	/// <returns></returns>
	BinaryTreeNode* RotateToLeft(BinaryTreeNode* node);

	/// <summary>
	/// ������������ ������ �� ������ ������������ ����
	/// </summary>
	/// <param name="root">����� ���� ������</param>
	void BalanceInsert(BinaryTreeNode** root);

	/// <summary>
	/// ��������� ����� ���� � �������� ���������
	/// </summary>
	/// <param name="value">�������� ����</param>
	/// <returns></returns>
	BinaryTreeNode* InsertNode(char value);
public:

	/// <summary>
	/// �������������� ������ ���� ������
	/// </summary>
	RedBlackTree();
	~RedBlackTree();

	/// <summary>
	/// ���������� ������� ����.
	/// ���������� true ���� ��������� �� ���� ��� ���� ������������ � ������� �� �����
	/// </summary>
	/// <param name="value">�������� ������������ ����</param>
	/// <param name="root">��������� �� �������� ���� ������/���������</param>
	/// <returns></returns>
	bool Insert(char value, BinaryTreeNode** root);
};

