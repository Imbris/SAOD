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

double StackHellper::getResultExpression(stack<Expression>& mass)
{
	Expression hellper;

	//����������� � ����� �����, ������ ����������� ��������
	while (mass.size() != 1)
	{
		int indexLast = mass.size() - 1;//������ ���������� ���������

		Expression* last = &mass.top();
		Expression* preLast = nullptr;
		Expression* prePreLast = nullptr;
		{
			Expression copyPre = mass.top();
			mass.pop();
			preLast = &mass.top();

			Expression copyPrePre = mass.top();
			if (mass.size() != 1)
			{
				mass.pop();
				prePreLast = &mass.top();

				mass.push(copyPrePre);
			}
			mass.push(copyPre);
		}
			

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

			if (prePreLast != nullptr && prePreLast->getOperation() == '-')
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
		mass.pop();
	}
	return mass.top().getResult();//this->mass[0].getResult();
}
