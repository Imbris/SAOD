#pragma once

/// <summary>
/// ������������ ����� ������
/// </summary>
enum NodeColor
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
} BinaryTreeNode;