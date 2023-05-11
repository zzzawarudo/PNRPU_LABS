#include "Vector.h"
#include <iostream>
using namespace std;
Iterator operator-(vector& a, int n) {
	for (int i = 0; i <= a.size - n; i++) {
		--a.end;
	}
	return a.end;
}
vector::vector() {
	size = 0;
	data = 0;
}
vector::vector(int s, int k) {
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
};
vector::vector(const vector& a) {
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
};
vector::~vector() {
	delete[] data;
	data = 0;
};
vector& vector:: operator=(const vector& a) {
	if (this == &a)
		return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
};
int& vector:: operator[](int index) {
	if (index < size || index>0) return data[index];
	else cout << "Такого индекса нет";
};
vector vector:: operator*(const int k) {
	vector tmp(size);
	for (int i = 0; i < size; i++)
		tmp.data[i] += data[i] * k;
	return tmp;
};
int vector:: operator()() {
	return size;
};
ostream& operator<<(ostream& out, const vector& a) {
	for (int i = 0; i < a.size; i++)
		out << a.data[i] << " ";
	return out;
};
istream& operator>>(istream& in, vector& a) {
	for (int i = 0; i < a.size; i++)
		in >> a.data[i];
	return in;
};