#include "exam.h"
#include <iostream>
#include <string>
using namespace std;
//������� ��� �������� ������� ��� ����������
Exam make_Exam()
{
	string s;
	string i;
	double d;
	cout << "Enter the student's name: ";
	cin >> s;
	cout << "Enter the subject: ";
	cin >> i;
	cout << "Enter the mark of exam: " << endl;
	cin >> d;
	Exam t(s, i, d);
	return t;
}
//������� ��� �������� ������� ��� ���������
void print_Exam(Exam t)
{
	t.show();
}
void main()
{
	//����������� ��� ����������
	Exam s1;
	s1.show();
	//���������� � �����������
	Exam s2("Zakharov Dmitry Sergeevich", "History", 4.0);
	s2.show();
	//����������� �����������
	Exam s3 = s2;
	s3.set_name("Yakushev Michael Vitalievich");
	s3.set_subject("Mathematics");
	s3.set_mark(5.0);
	//����������� �����������
	print_Exam(s3);
	//����������� �����������
	s1 = make_Exam();
	s1.show();
}