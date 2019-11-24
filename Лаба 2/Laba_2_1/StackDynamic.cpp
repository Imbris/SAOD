#include "StackDynamic.h"

StackDynamic::StackDynamic()
{
	this->mass = nullptr;
	this->size = 0;
}

StackDynamic::~StackDynamic()
{
	if (mass != nullptr && this->size != 0)
		free(mass);
}

void StackDynamic::init(string exp)
{
	this->mass = new Expression[1];
	this->size = 1;

	
	while(!this->mass) this->mass = new Expression[1];

	if (this->mass) {
		Expression obj(exp);
		this->mass[0] = obj;
		
		//���� ������ �������� �������� ���. ���������� - ��������� � ����
		while (isExpression(obj.getLastArg()))
		{
			Expression secondExp(obj.getLastArg());
			this->push(secondExp);
			obj = secondExp;
		}
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

void StackDynamic::push(Expression elem)
{
	this->mass = updateSize(this->mass, this->size, this->size + 1);
	this->size++;

	if (this->mass) {
		this->mass[size - 1] = elem;
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

void StackDynamic::pop()
{
	this->mass = updateSize(this->mass, this->size, this->size - 1);
	this->size--;
}

Expression StackDynamic::top()
{
	if (this->size != 0)
		return this->mass[this->size - 1];
	else
		return Expression();
}

double StackDynamic::getResultExpression()
{
	Expression hellper;

	//����������� � ����� �����, ������ ����������� ��������
	while (this->size != 1)
	{
		int indexLast= this->size - 1;//������ ���������� ���������

		Expression *last = &this->mass[indexLast];
		Expression *preLast = &this->mass[indexLast - 1];
		Expression* prePreLast = &this->mass[indexLast - 2];

		//���� ���� �������� ���������� �������� ����� - ����� ������� ���������
		if (last->isPriorityOperation() || (!preLast->isPriorityOperation() && preLast->getOperation() != '-'))
		{
			preLast->setLastArg(to_string(last->getResult()));
		}
		else if (preLast->getOperation() == '-') {
			//���� ��� ����� ������������
			if (last->getOperation() == '-')
			{
				last->setOperation('+');
				preLast->setLastArg(to_string(last->getResult()));
			}
			else {
				//changeNodes(*last, *preLast);
				last->setOperation('-');

				//������ ������� ��������� � ����� ������������ �������
				changeArgs(*last);
				double res = last->getResult();
				if (res < 0)
				{
					preLast->setOperation('-');
				}
				else {
					preLast->setOperation('+');
				}
				preLast->setLastArg(to_string(abs(res)));
			}
		}
		else {
			changeNodes(*last, *preLast);
			changeArgs(*last);

			if (prePreLast->getOperation() == '-')
			{
				preLast->setOperation('-');
				prePreLast->setOperation('+');
				preLast->setLastArg(to_string(last->getResult()));
			}
			else {
				preLast->setLastArg(to_string(last->getResult()));
				if (preLast->getOperation() == '-') {
					changeArgs(*preLast);
				}
			}
		}
		this->pop();
	}
	return this->mass[0].getResult();
}
