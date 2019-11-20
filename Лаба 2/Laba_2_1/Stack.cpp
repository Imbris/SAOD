#include "Stack.h"

Stack::Stack()
{
	this->mass = new Expression[1];
	this->size = 0;
}

void Stack::init(string exp)
{
	Expression obj(exp);
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
	this->mass = this->updateSize(this->mass, this->size, this->size + 1);
	//this->mass = (Expression*)realloc(this->mass, sizeof(Expression) * this->size);
	this->size++;

	if (this->mass) {
		this->mass[size - 1] = elem;
	}
	else {
		throw new exception("�� ������� �������� ������ \n");
	}
}

Expression* Stack::updateSize(const Expression* exp, int size_old, int size_new)
{
		Expression* updateMass = NULL;
		updateMass = new Expression[size_new];
		if (updateMass) {
			size_t i = 0;

			for (i = 0; i < size_old; i++)
			{
				updateMass[i] = exp[i];
			}

			for (; i < size_new; i++)
			{
				updateMass[i] = Expression();
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

		Expression last = this->mass[indexLast];
		Expression preLast = this->mass[indexLast - 1];

		//���� ���� �������� ���������� �������� ����� - ����� ������� ���������
		if (last.isPriorityOperation() || !preLast.isPriorityOperation())
		{
			preLast.setLastArg(to_string(last.getResult()));
		}
		else {
			changeNodes(last, preLast);
			preLast.setLastArg(to_string(last.getResult()));
		}
		//��� ������ ���� this.mass.pop()
	}
	return this->mass[0].getResult();
}
