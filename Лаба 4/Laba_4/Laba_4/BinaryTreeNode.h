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
		this->color = NodeColor::Black;
		this->left = 0;
		this->parent = 0;
		this->right = 0;
		this->data = ' ';
	}
} BinaryTreeNode;