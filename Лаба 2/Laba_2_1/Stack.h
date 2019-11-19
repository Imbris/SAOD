#pragma once
#include "Expression.h"
#include "stdlib.h"

class Stack
{
private:
	Expression* mass;
	int size;

public:
	Stack();

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
};

