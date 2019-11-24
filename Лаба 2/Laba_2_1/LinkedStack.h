#pragma once
#include "Operation.h"
#include "stdlib.h"
#include "math.h"

class LinkedStack
{
private:
	LinkedStack* next;
	Expression value;

	/// <summary>
	/// ���������� ������������� ������� � �����
	/// </summary>
	LinkedStack* preTop();

	/// <summary>
	/// ���������� ������������� ������� � �����
	/// </summary>
	LinkedStack* prePreTop();
public:
	LinkedStack(Expression elem);
	~LinkedStack();

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
	LinkedStack* top();

	/// <summary>
	/// ���������� �������� ��������������� ���������
	/// </summary>
	/// <returns></returns>
	double getResultExpression(LinkedStack* head);
};

