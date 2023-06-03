#pragma once
#include <iostream>
#include <set>
using namespace std;

template <class T> 
class Vector
{
	multiset <T> q;
	multiset <T> tmp;
	int len; 
public:
	Vector();
	Vector(int s);
	Vector(const Vector<T>& a);
	~Vector();
	void Print();
	void add(T key);
	void del(T key);
	void min_max();
private:
	int size;
	T* data;
};

template <class T>
Vector<T>::Vector()
{
	size = 0;
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		q.insert(a);
	}
	len = q.size();
}

template <class T>
Vector<T>::Vector(const Vector& v)
{
	q = v.q;
}

template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}

template <class T>
void Vector<T>::Print()
{
	for (auto i = q.begin(); i != q.end(); i++)
		cout << *i << " " << endl;
}


template <class T>
void Vector<T>::add(T key) {
	int founded = q.count(key);
	if (founded > 0) q.insert(key);
	else cout << "Ёлемент не найден" << endl;
}

template <class T>
void Vector<T>::del(T key) {
	int founded = q.count(key);
	if (founded > 0) q.erase(key);
	else cout << "Ёлемент не найден" << endl;
}
template <class T>
void Vector<T>::min_max() {
	T min, max, cur;
	auto it = q.begin();
	min = *it;
	it = q.end();
	it--;
	max = *it;
	for (auto i = q.begin(); i != q.end(); i++) {
		cur = *i;
		cur = cur - (max - min);
		tmp.insert(cur);
	}
	q = tmp;
	tmp.clear();
}