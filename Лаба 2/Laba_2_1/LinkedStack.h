#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class LinkedStack
{
private:
	Expression* next;
	Expression* current;
	int size;

public:
	LinkedStack();
	~LinkedStack();

	/// <summary>
	/// �������������� ����
	/// </summary>
	/// <param name="exp">�������������� ���������</param>
	void init(string exp);

	/// <summary>
	/// ��������� � ����� ����� ����� �������
	/// </summary>
	/// <param name="elem">����� ���������</param>
	void push(Expression* elem);

	/// <summary>
	/// ������� ��������� ������� �� �����
	/// </summary>
	void pop();

	/// <summary>
	/// ���������� ��������� ������� � �����
	/// </summary>
	Expression top();

	/// <summary>
	/// ���������� �������� ��������������� ���������
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

