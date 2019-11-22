#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
}

LinkedStack::~LinkedStack()
{
}

void LinkedStack::init(string exp)
{
	this->current = new Expression(exp);

	if (this->current) {
		Expression* obj = new Expression(exp);
		this->current = obj;

		//���� ������ �������� �������� ���. ���������� - ��������� � ����
		while (isExpression(obj->getLastArg()))
		{
			Expression* secondExp = new Expression(obj->getLastArg());
			this->push(secondExp);
			obj = secondExp;
		}
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

void LinkedStack::push(Expression* elem)
{
}

void LinkedStack::pop()
{
}

Expression LinkedStack::top()
{
	return Expression();
}

double LinkedStack::getResultExpression()
{
	return 0.0;
}
