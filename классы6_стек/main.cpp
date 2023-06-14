#include <iostream>
#include"stack.h"

int main()
{
	setlocale(0, "ru");
	Stack x;
	int dl;
	int k;

	cin >> x;
	cout << x << endl;
	cout << "введите номер элемента стека, который хотите удалить: ";
	cin >> dl;
	cout << "сколько удалить? ";
	cin >> k;
	x.popel(dl, k);
	cout << "\n" << x;
	cout << "\nвведите элемент, который хотите добавить в стек "; cin >> dl;
	cout << "\nвведите ключ, перед которым нужно добавить элемент "; cin >> k;
	x.addVal(dl, k);
	cout << x;
	return 0;
}