#include <iostream>
#include "Rectangle.h"
void main()
{
	setlocale(LC_ALL, "ru");
	Rectangle a(5, 4);
	cout << "������� ��������������:" << a.getArea() << endl;
	cout << "�������� ��������������:" << a.getPerimeter() << endl;
}