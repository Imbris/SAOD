#pragma once
#include "Operation.h"
#include <string>
using namespace std;


class Expression
{
private:
	/// <summary>
	/// ������ ��������
	/// </summary>
	string firstArg;

	/// <summary>
	/// ������ ��������
	/// </summary>
	string lastArg;

	/// <summary>
	/// ���� ��������
	/// </summary>
	char operation;
public:
	/// <summary>
	/// ������� ������ �� ���������
	/// </summary>
	Expression();

	/// <summary>
	/// ������� ������ ��������� ���������
	/// </summary>
	/// <param name="expression">���������, ������� ������ ����������</param>
	Expression(string expression);

	/// <summary>
	/// ���������� ��������� ���������
	/// </summary>
	/// <returns></returns>
	double getResult();

	string getLastArg();
};

