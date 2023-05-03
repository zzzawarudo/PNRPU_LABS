#include "exam.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
Exam::Exam()
{
	name = "";
	subject = "";
	mark = 0;
}
//конструктор с параметрами
Exam::Exam(string N, string K, double S)
{
	name = N;
	subject = K;
	mark = S;
}
//конструктор копирования
Exam::Exam(const Exam& t)
{
	name = t.name;
	subject = t.subject;
	mark = t.mark;
}
//деструктор
Exam::~Exam()
{
}
//селекторы
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
//модификаторы
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
//метод для просмотра атрибутов
void Exam::show()
{
	cout << "name: " << name << endl;
	cout << "subject: " << subject << endl;
	cout << "mark: " << mark << endl << endl;
}