#include "Vector.h"
#include "Object.h"
#include "Book.h"
#include "Print.h"
#include <string>
#include <iostream>
#include "Event.h"
using namespace std;
void vector::Get_Name() {
	object** p = beg;
	int n;
	cout << "�������: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == n)
			(*p)->show();
		p++;
	}
};
vector::vector() {
	beg = 0;
	size = 0;
	cur = 0;
};
vector::~vector(void) {
	if (beg != 0) delete[]beg;
	beg = 0;
};
vector::vector(int n) {
	beg = new object * [n];
	cur = 0;
	size = n;
};
void vector::add(object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
};
void vector::add() {
	object* p;
	cout << "1.�������" << endl;
	cout << "2.�����" << endl;
	int y;
	cin >> y;
	if (y == 1) {
		Print* a = new Print;
		a->input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else {
		if (y == 2) {
			Book* b = new Book;
			b->input();
			p = b;
			if (cur < size) {
				beg[cur] = p;
				cur++;
			}
		}
	}
};
void vector::show() {
	if (cur == 0) cout << "������ �����" << endl;
	object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->show();
		p++;
	}
};
int vector::operator()() {
	return cur;
};
void vector::del() {
	if (cur == 0) return;
	cur--;
};