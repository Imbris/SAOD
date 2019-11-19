#pragma once
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

	/// <summary>
	/// ���������� ������ ���� �������� � ��������� 
	/// </summary>
	/// <param name="exp">������������ ���������</param>
	/// <param name="index">������ ����� �������� � ���������</param>
	/// <returns></returns>
	char getCharOperation(string exp, int &index);
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
};

