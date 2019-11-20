#pragma once
#include <string>
#include "Expression.h"
using namespace std;

/// <summary>
/// true - ������ exp �������� ���������
/// false - ������ exp �������� ����������
/// </summary>
/// <param name="exp">������ �������� � �������������� ���������</param>
/// <returns></returns>
bool isExpression(string exp);

/// <summary>
/// �������� ��������� �������, �������� �������� �������� �������� - �������� �������
/// </summary>
/// <param name="last">��������� ���������</param>
/// <param name="preLast">������������� ���������</param>
void changeNodes(Expression &last, Expression &preLast);

/// <summary>
/// �������� ��������� � ��������� �������
/// </summary>
/// <param name="last">��������� ���������</param>
void changeArgs(Expression& last);