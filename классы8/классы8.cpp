#include "Book.h"
#include "Print.h"
#include "Vector.h"
#include "Event.h"
#include "Dialog.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	/*Print* a = new Print;
	a->input();
	Book* b = new Book;
	b->input();
	vector A(10);
	object* p = a;
	cout << ": " << endl;
	A.add(p);
	A.show();
	cout << ": " << endl;
	p = b;
	A.add(p);
	A.show();
	A.add();
	A.show();
	cout << ": " << A();
	A.del();*/
	Dialog D;
	cout << "��������:\nm - ������� ������\n+ - �������� �������\n- - ������� �������\ns - ������� ���������� �� ��������� ������\nz - ������� ���������� � �������� �������� ������ � ������� k\nq - ����� ������" << endl;
	D.Execute();
	return 0;
}