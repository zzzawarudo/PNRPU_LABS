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
	cout << "Введите количество элементов в множестве: "; cin >> n;
	Vector<int> v(n);
	cout << "Множество:" << endl;
	v.Print();
	cout << "Задание 3" << endl;
	cout << "Введите элемент для добавления: "; cin >> key;
	v.add(key);
	v.Print();
	cout << "Задание 4" << endl;
	cout << "Введите значение элемента для удаления: "; cin >> key;
	v.del(key);
	v.Print();
	cout << "Задание 5" << endl;
	v.min_max();
	v.Print();
}