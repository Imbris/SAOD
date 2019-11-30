#pragma once

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

void CreateTree(RedBlackTree* root, int n);

void PrintTree(BinaryTreeNode* p, int level);

/// <summary>
/// � ������� ������������� ������ ������ - ���������� ����� ���� �������� �����
/// </summary>
int InOrderTravelRL(BinaryTreeNode* root, int sum);