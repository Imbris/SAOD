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
	/// ��������� � ������ ������� � ��������� ���������
	/// </summary>
	/// <param name="data">�������� ������������ ����</param>
	/// <returns></returns>
	Node* InsertNode(char data);
};

