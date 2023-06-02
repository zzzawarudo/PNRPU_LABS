#include <iostream>
#include "Tovar.h"
using namespace std;

int main()
{
	try {
		setlocale(0, "rus");
		bool pos = 0;
		int key, index;
		Vector<int>A(5, 0);
		cin >> A;
		cout << A << endl;
		cout << "Введите значение элемента для добавления: "; cin >> key;
		pos = A.find_key(key);
		if (pos == 0) throw 1;
		else {
			cout << "Введите индекс для добавления: "; cin >> index;
			A.push(index, key);
		}
		cout << A << endl;
		cout << "Введите значение элемента для удаления: "; cin >> key;
		pos = A.find_key(key);
		if (pos == -1) throw 1;
		else A.pop(key);
		cout << A;
		A.max_min_vector();
		cout << endl << A;
	}
	catch (int) {
		cout << "Error";

	}

	return 0;
}