#include "Operation.h"


void CreateTree(RedBlackTree* root, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "������� �������� ��� " << i << " ����: ";
		char value = ' ';
		cin >> value;
		root->InsertNode(value);
	}
}

void CreateRandomTree(RedBlackTree* root, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		char value = rand()%100;
		root->InsertNode(value);
	}
}

void PrintTree(BinaryTreeNode* p, int level)
{
	if (p && p->data != ' ')
	{
		PrintTree(p->right, level + 1);
		for (size_t i = 0; i < level; i++) cout << "\t";
		cout << (int)p->data <<"-"<<(p->color == NodeColor::Black ? "Black" : "Red")<< endl;
		PrintTree(p->left, level + 1);
	}
}

int InOrderTravelRL(BinaryTreeNode* root, int sum)
{
	// ���� ������ ���� �� NIL
	if (root && root->data != ' ')
	{
		sum = (int)root->data;
	} else return 0;

	sum += InOrderTravelRL(root->right, sum);
	sum += InOrderTravelRL(root->left, sum);
	
	return sum;
}

BinaryTreeNode* FindMax(BinaryTreeNode* root)
{
	Node* max = new Node(*root);
	while (max && max->right && max->right->data != ' ') {
		max = max->right;
	}
	return max;
}

/// <summary>
/// ���������� ��������� �� ������� � �������� data
/// </summary>
/// <param name="root">��������� �� ������ ������</param>
/// <param name="data">�������� �������� ���� ������</param>
/// <returns></returns>
BinaryTreeNode* FindNode(BinaryTreeNode* root, char data)
{
	BinaryTreeNode* node = new Node(*root);

	
	if (node->data == data) {// ���� ���� ������ - ���������� ���
		return node;
	}
	else if(node->data <= data){//���� �������� ������ �������� ����� - ���� ������ ������� ������
		if (node->right)
			return FindNode(node->right, data);
		else 
			return nullptr;
	}
	else {// ���� �������� ������ �������� ����� - ���� ������ ������� �����
		if (node->left)
			return FindNode(node->left, data);
		else 
			return nullptr;
	}
}
