#include"Time.h"
#include <iostream>
#include<fstream>
#include "work.h"
using namespace std;

int main()
{
	setlocale(0, "rus");
	/*Time x;
	cin >> x;
	cout << x;
	Time y;
	y = x;
	cout << y;*/
	Time p;
	int k, c;
	char file_name[30];
	do {
		cout << "\n1. ������� ����";
		cout << "\n2. ������ �����";
		cout << "\n3. ������� ������ �� ������";
		cout << "\n4. �������� k ������� ����� �������� � �������� ���������";
		cout << "\n5. ��������� ��� ������, � �������� ��������� �� 90 ���";
		cout << "\n0. �����" << endl;
		cin >> c;
		switch (c)
		{
		case 1: cout << "��� �����?"; cin >> file_name;
			k = CreateFile(file_name);
			if (k < 0) cout << "������, ���� ������� ����������";
			break;
		case 2: cout << "��� �����: "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "���� ������";
			if (k < 0) cout << "���������� ������� ����";
			break;
		case 3: cout << "��� �����: "; cin >> file_name;
			int dmin; cout << "������� ������, ������� �������: "; cin >> dmin;
			int dsec; cout << "������� �������, ������� �������: "; cin >> dsec;
			k = del_file(file_name, dmin, dsec);
			if (k < 0)cout << "������ ������ �����";
			break;
		case 4: { cout << "��� �����: "; cin >> file_name;
			Time znach; int kolvo;
			cout << "������� ���-��, ����������� ���������"; cin >> kolvo;
			cout << "������� ����� ������ �������� ���������: "; cin >> znach;
			Time e;
			for (int i = 0; i < kolvo; i++) {
				cout << "������� �����: ";
				cin >> e;
				k = add_file(file_name, znach, e);
				znach = e;
			} break; }

		case 5: { cout << "��� �����: ";  cin >> file_name;
			Time znach;
			cout << "������� ��������, ������� ��������� �� 90 ������: "; cin >> znach;
			k = change_file(file_name, znach);
			if (k < 0)cout << "������ ������ �����";
			if (k == 0)cout << "���� ������";
			break; }
		}
	} while (c != 0);
	return 0;
}