#pragma once
#include "Expression.h"
class Stack
{
private:
	Expression* mass;
	int size;
public:
	Stack(string exp);

	/// <summary>
	/// ��������� � ����� ����� ����� �������
	/// </summary>
	/// <param name="elem">����� ���������</param>
	void push(Expression elem);
};

