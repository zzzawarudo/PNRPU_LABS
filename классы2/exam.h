#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//атрибуты
	string name;
	string subject;
	double mark;
public:
	Exam();//конструктор без параметров
	Exam(string, string, double);//конструктор с параметрами
	Exam(const Exam&);//конструктор копирования
	~Exam();//деструктор
	string get_name();//селектор
	void set_name(string);//модификатор
	string get_subject();//селектор
	void set_subject(string); //модификатор
	double get_mark();//селектор
	void set_mark(double); //модификатор
	void show();//просмотр атрибутов
};