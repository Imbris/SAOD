#include "Stack.h"

Stack::Stack()
{

}

void Stack::init(string exp)
{
	Expression obj(exp);
	this->mass = new Expression[1];
	while(!this->mass) this->mass = new Expression[1];

	if (this->mass) {
		this->size = 1;
		this->mass[0] = obj;
		
		//���� ������ �������� �������� ���. ���������� - ��������� � ����
		if (isExpression(obj.getLastArg()))
		{
			Expression secondExp(obj.getLastArg());
			this->push(secondExp);
		}
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

void Stack::push(Expression elem)
{
	//this->mass = updateSize(this->mass, this->size, this->size + 1);//(Expression*)realloc(this->mass, sizeof(Expression)*this->size);
	this->size++;

	if (this->mass) {
		throw new exception("�� ������� �������� ������ \n");
	}
	else {
		this->mass[size - 1] = elem;
	}
}
