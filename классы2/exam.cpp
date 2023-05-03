#include "exam.h"
#include <iostream>
#include <string>
using namespace std;
//����������� ��� ����������
Exam::Exam()
{
	name = "";
	subject = "";
	mark = 0;
}
//����������� � �����������
Exam::Exam(string N, string K, double S)
{
	name = N;
	subject = K;
	mark = S;
}
//����������� �����������
Exam::Exam(const Exam& t)
{
	name = t.name;
	subject = t.subject;
	mark = t.mark;
}
//����������
Exam::~Exam()
{
}
//���������
string Exam::get_name()
{
	return name;
}
string Exam::get_subject()
{
	return subject;
}
double Exam::get_mark()
{
	return mark;
}
//������������
void Exam::set_name(string N)
{
	name = N;
}
void Exam::set_subject(string K)
{
	subject = K;
}
void Exam::set_mark(double S)
{
	mark = S;
}
//����� ��� ��������� ���������
void Exam::show()
{
	cout << "name: " << name << endl;
	cout << "subject: " << subject << endl;
	cout << "mark: " << mark << endl << endl;
}