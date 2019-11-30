#pragma once

/// <summary>
/// ������������ ����� ������
/// </summary>
enum class NodeColor
{
	Black,
	Red
};

/// <summary>
/// ��������� ������� ������-������� ������
/// </summary>
typedef struct Node {
	/// <summary>
	/// ����� ����
	/// </summary>
	struct Node* left;   
	
	/// <summary>
	/// ������ ����
	/// </summary>
	struct Node* right;

	/// <summary>
	/// ������������ ����
	/// </summary>
	struct Node* parent;

	/// <summary>
	/// ���� ������� parent
	/// </summary>
	NodeColor color;

	/// <summary>
	/// �������������� ����� ������� parent
	/// </summary>
	char data;

	Node() {
		this->color = NodeColor::Red;
		this->left = 0;
		this->parent = 0;
		this->right = 0;
		this->data = ' ';
	}

	/// <summary>
	/// ��� ��������� NIL
	/// </summary>
	/// <param name="isNil">����, ��� ���������� NIL</param>
	Node(struct Node* left, struct Node* right, struct Node* parent, NodeColor color, char data)
	{
		this->left = left;
		this->right = right;
		this->parent = parent;
		this->color = color;
		this->data = data;
	}
} BinaryTreeNode;