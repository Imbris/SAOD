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

/// <summary>
/// ���������� ��� �� ������, �� � ����� ��������
/// </summary>
/// <param name="exp">������������ ���������</param>
/// <param name="size_old">������ ������ �������</param>
/// <param name="size_new">����� ������ �������</param>
/// <returns></returns>
Expression* updateSize(const Expression* exp, int size_old, int size_new);

/// <summary>
/// ���������� true - ���� exp ����� ���������� ������
/// false - � ���� ������
/// </summary>
/// <param name="exp">���. ���������</param>
/// <returns></returns>
bool isCoorectExpression(string exp);