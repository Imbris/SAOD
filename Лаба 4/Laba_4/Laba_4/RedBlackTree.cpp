#include "RedBlackTree.h"

RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::BalanceInsert(Node* x)
{
	// ���� � - ������
	if (x == this->root)
	{
		x->color = NodeColor::Black;
		return;
	}

	while (x->parent->color == NodeColor::Red)
	{
		// ���� ���� == ����� �������
		if (x->parent == x->parent->parent->left) {
			Node* y = x->parent->parent->right;

			// ���� ���� ����
			if (y)
			{
				// ���� ���� �������
				if (y->color == NodeColor::Red)
				{
					x->parent->color = NodeColor::Black;
					y->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->right) {
						x = x->parent;
						// ��� ������ ���� ������� ������ �����
					}

					x->parent->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					// ����� ������ ���� ������ ������
				}
			}
		}
		else { // ����� - ���� == ������ �������
			Node* y = x->parent->parent->left;

			// ���� ���� ����
			if (y)
			{
				// ���� ���� �������
				if (y->color == NodeColor::Red) {
					x->parent->color = NodeColor::Black;
					y->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->left) {
						x = x->parent;
						//����� ������ ���� ������� ������
					}

					x->parent->color = NodeColor::Black;
					x->parent->parent->color = NodeColor::Red;
					// ����� ������ ���� ������ �����
				}
			}

		}
	}

	this->root->color = NodeColor::Black;
}

Node* RedBlackTree::InsertNode(char data)
{
	Node* current, * parent, * x;

	current = root;
	parent = 0;

	// ���������� ���� ������, ������ �� �������
	// ��� ���� �� �������� ������� � ���� �� �������
	while (current)
	{
		if (data == current->data)
			return current;
		parent = current;
		current = data > current->data ? current->right : current->left;
	}

	// ��� ������ ���� ������� ������ �������
	x = new Node();
	x->data = data;

	// ���� ������ ����� ����� 1 �������
	if (parent) {
		// ���������� � ����� ������� �������� ����� ����
		if (data < parent->data) {
			parent->left = x;
		}
		else {
			parent->right = x;
		}
		x->parent = parent;
	}
	else {
		// ����� ������ ������� �������
		root = x;
	}

	BalanceInsert(x);
	return x;
}

void RedBlackTree::RotateRight(Node* x)
{
}

Node* RedBlackTree::GetRoot()
{
	return this->root;
}
