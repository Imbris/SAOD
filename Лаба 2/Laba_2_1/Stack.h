#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class Stack
{
private:
	Expression* mass;
	int size;

public:
	Stack();
	~Stack();
	
	/// <summary>
	/// �������������� ����
	/// </summary>
	/// <param name="exp">�������������� ���������</param>
	void init(string exp);

	/// <summary>
	/// ��������� � ����� ����� ����� �������
	/// </summary>
	/// <param name="elem">����� ���������</param>
	void push(Expression elem);

	/// <summary>
	/// ������� ��������� ������� �� �����
	/// </summary>
	void pop();

	/// <summary>
	/// ���������� ��������� ������� � �����
	/// </summary>
	Expression top();

	/// <summary>
	/// ���������� ��� �� ������, �� � ����� ��������
	/// </summary>
	/// <param name="exp">������������ ���������</param>
	/// <param name="size_old">������ ������ �������</param>
	/// <param name="size_new">����� ������ �������</param>
	/// <returns></returns>
	Expression* updateSize(const Expression* exp, int size_old, int size_new);

	/// <summary>
	/// ���������� �������� ��������������� ���������
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

