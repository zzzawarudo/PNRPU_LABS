#include "Object.h"
#include "Pair.h"
#include "Rightangle.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "rus");
	Vector v(5);//������ �� 5 ���������
	Pair a;//������ ������ Pair
	cout << "������� 2 ������� ������ Pair:\n";
	cin >> a;
	Rightangle b;// ������ ������ Rightangle
	cout << "������� 2 ������� ������ Pair:\n";
	cin >> b;
	Object* p = &a;//������ ��������� �� ������ ������ Pair
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Rectangle
	v.Add(p); //��������� ������ � ������
	cout << v;//����� �������
	return 0;
}