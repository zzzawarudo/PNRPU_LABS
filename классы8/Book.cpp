#include "Book.h"
#include "Print.h"
#include <string>
#include<iostream>
using namespace std;

Book::Book(void) :Print() {
	pages = 0;
	publisher = "";
};
Book::~Book(void) {

};
Book::Book(string name, string author, int pages, string publisher) :Print(name, author)
{
	this->pages = pages;
	this->publisher = publisher;
};
Book::Book(const Book& a) {
	pages = a.pages;
	publisher = a.publisher;
	name = a.name;
	author = a.author;
};
void Book::set_pages(int pages) {
	this->pages = pages;
};
void Book::set_publisher(string p) {
	publisher = p;
};
Book& Book::operator=(const Book& a) {
	if (&a == this)return *this;
	name = a.name;
	author = a.author;
	return *this;
};
void Book::show() {
	cout << endl << "�����: " << endl;
	cout << "��������: " << name << endl;
	cout << "�����: " << author << endl;
	cout << "���������� �������: " << pages << endl;
	cout << "������������: " << publisher << endl;
};
void  Book::input() {
	cout << "�����: " << endl << "������� �������� �����: ";
	getchar();
	getline(cin, name);
	cout << "������� ��� ������: ";
	getline(cin, author);
	cout << "������� ���������� �������: ";
	cin >> pages;
	cout << "������� ������������: ";
	getchar();
	getline(cin, publisher);
};