#pragma once
#include <stack>
#include "Operation.h"

static class StackHellper
{
public:
	/// <summary>
	/// �������������� ����
	/// </summary>
	/// <param name="exp">�������������� ���������</param>
	static void init(stack<Expression>& mass, Expression elem, string exp);

private:
	static Expression* mass;
};