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
	cout << "������� ����� �������� �����, ������� ������ �������: ";
	cin >> dl;
	cout << "������� �������? ";
	cin >> k;
	x.popel(dl, k);
	cout << "\n" << x;
	cout << "\n������� �������, ������� ������ �������� � ���� "; cin >> dl;
	cout << "\n������� ����, ����� ������� ����� �������� ������� "; cin >> k;
	x.addVal(dl, k);
	cout << x;
	return 0;
}