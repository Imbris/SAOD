#pragma once
#include <iostream>
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
	/// ���������� ������ ���� �������� � ��������� 
	/// </summary>
	/// <param name="exp">������������ ���������</param>
	/// <param name="index">������ ����� �������� � ���������</param>
	/// <returns></returns>
	static char getCharOperation(string exp, int& index);

	/// <summary>
	/// ���������� ��������� ���������
	/// </summary>
	/// <returns></returns>
	double getResult();

	/// <summary>
	/// true - ���� �������� ����� ������� ���������
	/// false - ���� ������ ���������
	/// </summary>
	/// <returns></returns>
	bool isPriorityOperation();

	string getLastArg();
	string getFirstArg();
	char getOperation();

	void setLastArg(string lastArg);
	void setFirstArg(string firstArg);
	void setOperation(char operation);
};

