#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exam
{
	//��������
	string name;
	string subject;
	double mark;
public:
	Exam();//����������� ��� ����������
	Exam(string, string, double);//����������� � �����������
	Exam(const Exam&);//����������� �����������
	~Exam();//����������
	string get_name();//��������
	void set_name(string);//�����������
	string get_subject();//��������
	void set_subject(string); //�����������
	double get_mark();//��������
	void set_mark(double); //�����������
	void show();//�������� ���������
};