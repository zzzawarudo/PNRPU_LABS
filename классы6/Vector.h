#pragma once
#include <string>
#include <iostream>
using namespace std;
class vector;
class Iterator {
	friend class vector;
private:
	int* elem;
public:
	Iterator() {
		elem = 0;
	}
	~Iterator() {

	}
	bool operator==(const Iterator& i) {
		return elem == i.elem;
	}
	bool operator!=(const Iterator& i) {
		return elem != i.elem;
	}
	void operator++() {
		elem++;
	}
	void operator--() {
		--elem;
	}
	int& operator*() const {
		return *elem;
	}
};

class vector {
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	vector(int s, int k = 0);
	vector(const vector& a);
	~vector();
	vector();
	vector& operator=(const vector& a);
	int& operator[](int index);
	vector operator*(const int k);
	int operator()();
	friend ostream& operator<<(ostream& out, const vector& a);
	friend istream& operator>>(istream& in, vector& a);
	Iterator first() {
		return beg;
	}
	Iterator last() {
		return end;
	}
	friend  Iterator operator-(vector& a, int n);

};