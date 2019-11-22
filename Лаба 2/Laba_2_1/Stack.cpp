#include "Stack.h"

Stack::Stack()
{
	this->mass = nullptr;
	this->size = 0;
}

Stack::~Stack()
{
	if (mass != nullptr && this->size != 0)
		free(mass);
}

void Stack::init(string exp)
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

void Stack::push(Expression elem)
{
	this->mass = this->updateSize(this->mass, this->size, this->size + 1);
	this->size++;

	if (this->mass) {
		this->mass[size - 1] = elem;
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

void Stack::pop()
{
	this->mass = updateSize(this->mass, this->size, this->size - 1);
	this->size--;
}

Expression Stack::top()
{
	if (this->size != 0)
		return this->mass[this->size - 1];
	else
		return Expression();
}

Expression* Stack::updateSize(const Expression* exp, int size_old, int size_new)
{
		Expression* updateMass = NULL;
		updateMass = new Expression[size_new];
		if (updateMass) {
			size_t i = 0;

			//���� ������ ����� ����������
			if (size_new < size_old)
			{
				//�������� ��� �������� �� ����������� ����������
				for (i = 0; i < size_new; i++)
				{
					updateMass[i] = exp[i];
				}
			}
			else {
				for (i = 0; i < size_old; i++)
				{
					updateMass[i] = exp[i];
				}

				for (; i < size_new; i++)
				{
					updateMass[i] = Expression();
				}
			}
		}

		return updateMass;
}

double Stack::getResultExpression()
{
	Expression hellper;

	//����������� � ����� �����, ������ ����������� ��������
	while (this->size != 1)
	{
		int indexLast= this->size - 1;//������ ���������� ���������

		Expression *last = &this->mass[indexLast];
		Expression *preLast = &this->mass[indexLast - 1];

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
			
			preLast->setLastArg(to_string(last->getResult()));
			if (preLast->getOperation() == '-') {
				changeArgs(*preLast);
			}
		}
		this->pop();
	}
	return this->mass[0].getResult();
}
