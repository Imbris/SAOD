#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

/// <summary>
/// ���������� n-�� ����� ���������
/// </summary>
/// <param name="n">����� ����� ���������</param>
/// <param name="sum_first">k-1 ����� ���������</param>
/// <param name="sum_second">k ����� ���������</param>
/// <param name="depth">������� ��������</param>
int Fibonachi(int n, int sum_first, int sum_second, short& depth);

/// <summary>
/// ������� ������������� ������ �� ����� �����
/// </summary>
/// <param name="head">��������� �� ������� ������</param>
/// <param name="n">���-�� ���������, ������� ����� �������� � head</param>
/// <returns></returns>
LinkedList* CreateList(Node* head, int n);