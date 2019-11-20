#pragma once
#include "Operation.h"
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

	/// <summary>
	/// ���������� ��� �� ������, �� � ����� ��������
	/// </summary>
	/// <param name="exp">������������ ���������</param>
	/// <param name="size_old">������ ������ �������</param>
	/// <param name="size_new">����� ������ �������</param>
	/// <returns></returns>
	Expression* updateSize(const Expression* exp, int size_old, int size_new);

	bool isExpression(string exp)
	{
		int index = -1;

		Expression obj;

		obj.getCharOperation(exp, index);

		if (index == -1)
			return false;
		else
			return true;
	}

	/// <summary>
	/// ���������� �������� ��������������� ���������
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

