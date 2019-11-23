#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class StackDynamic
{
private:
	Expression* mass;
	int size;

public:
	StackDynamic();
	~StackDynamic();
	
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
	/// ���������� �������� ��������������� ���������
	/// </summary>
	/// <returns></returns>
	double getResultExpression();
};

