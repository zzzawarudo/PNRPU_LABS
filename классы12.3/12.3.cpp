#include <iostream>
#include <set>
#include "Vector.h"
#include "Time.h"
using namespace std;
//bool operator<(const Time& pr1, const Time& pr2)
//{
//	return ((pr1.min < pr2.min) || ((pr1.min == pr2.min) && (pr1.sec < pr2.sec)));
//}

int main()
{
	setlocale(0, "rus");
	bool pos = 0;
	int n, index, key;
	cout << "������� ���������� ��������� � ���������: "; cin >> n;
	Vector<int> v(n);
	cout << "���������:" << endl;
	v.Print();
	cout << "������� 3" << endl;
	cout << "������� ������� ��� ����������: "; cin >> key;
	v.add(key);
	v.Print();
	cout << "������� 4" << endl;
	cout << "������� �������� �������� ��� ��������: "; cin >> key;
	v.del(key);
	v.Print();
	cout << "������� 5" << endl;
	v.min_max();
	v.Print();
}