#include "StackHellper.h"

void StackHellper::init(stack<Expression> &mass, Expression elem,  string exp)
{
	mass.push(elem);

	//���� ������ �������� �������� ���. ���������� - ��������� � ����
	while (isExpression(elem.getLastArg()))
	{
		Expression secondExp(elem.getLastArg());
		mass.push(secondExp);

		elem = secondExp;
	}
}
