#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

Print::Print(void) {
	name = "";
	author = "";
};
Print::Print(string name, string author) {
	name = name;
	author = author;
};
Print::Print(const Print& a) {
	this->author = a.author;
	this->name = a.name;
};
Print::~Print(void) {

};
Print& Print::operator=(const Print& a) {
	if (&a == this) return*this;
	name = a.name;
	author = a.author;
	return *this;
};
void Print::setname(string m) {
	name = m;
};
void Print::setauthor(string a) {
	author = a;
};
void Print::show() {
	cout << endl << "�������: " << endl;
	cout << "��������: " << name << endl;
	cout << "�����: " << author << endl;
};
void Print::input() {
	cout << "�������: " << endl << "������� �������� �����: ";
	getchar();
	getline(cin, name);
	cout << "������� ��� ������: ";
	getline(cin, author);
};