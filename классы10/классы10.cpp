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
		cout << "\n1. создать файл";
		cout << "\n2. печать файла";
		cout << "\n3. удалить объект из потока";
		cout << "\n4. добавить k записей после элемента с заданным значением";
		cout << "\n5. уменьшить все записи, с заданным значением на 90 сек";
		cout << "\n0. выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: cout << "имя файла?"; cin >> file_name;
			k = CreateFile(file_name);
			if (k < 0) cout << "ошибка, файл создать невозможно";
			break;
		case 2: cout << "имя файла: "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "файл пустой";
			if (k < 0) cout << "невозможно открыть файл";
			break;
		case 3: cout << "имя файла: "; cin >> file_name;
			int dmin; cout << "введите минуты, которые удалить: "; cin >> dmin;
			int dsec; cout << "введите секунды, которые удалить: "; cin >> dsec;
			k = del_file(file_name, dmin, dsec);
			if (k < 0)cout << "ошибка чтения файла";
			break;
		case 4: { cout << "имя файла: "; cin >> file_name;
			Time znach; int kolvo;
			cout << "введите кол-во, добавляемых элементов"; cin >> kolvo;
			cout << "введите после какого элемента добавлять: "; cin >> znach;
			Time e;
			for (int i = 0; i < kolvo; i++) {
				cout << "введите время: ";
				cin >> e;
				k = add_file(file_name, znach, e);
				znach = e;
			} break; }

		case 5: { cout << "имя файла: ";  cin >> file_name;
			Time znach;
			cout << "введите значение, которое уменьшить на 90 секунд: "; cin >> znach;
			k = change_file(file_name, znach);
			if (k < 0)cout << "ошибка чтения файла";
			if (k == 0)cout << "файл пустой";
			break; }
		}
	} while (c != 0);
	return 0;
}