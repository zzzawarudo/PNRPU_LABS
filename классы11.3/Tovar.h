#pragma once
#include <iostream>
using namespace std;
template <class T> 
class Vector
{
public:
	Vector(int s, T k);
	Vector(const Vector<T>& a);
	~Vector();
	Vector& operator=(const Vector<T>& a);
	T& operator[](int index);
	Vector operator+(const T k);
	Vector operator+(const Vector<T> b);
	int operator()();
	friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);
	bool find_key(T key);
	void max_min_vector();
	void push(int pos, T key);
	void pop(T key);
private:
	int size;
	T* data;
};

template <class T>
void Vector<T>::push(int pos, T key) {
	if (pos > size) throw 1;
	T* temp = new T[size + 1];
	for (int i = 0; i < pos; i++) {
		temp[i] = data[i];
	}
	temp[pos] = key;
	for (int i = pos + 1; i < size + 1; i++) {
		temp[i] = data[i - 1];
	}
	delete[] data;
	data = temp;
	size++;
}
template <class T>
bool Vector<T>::find_key(T key) {
	for (int i = 0; i < size; i++) {
		if (key == data[i]) {
			return 1;
		}
	}
	return 0;
}
template <class T>
void Vector<T>::pop(T key) {
	T* temp = new T[size - 1];
	int i = 0;
	while (data[i] != key) {
		temp[i] = data[i];
		i++;
	}
	for (int j = i; j < size - 1; j++) {
		temp[j] = data[j + 1];
	}
	delete[] data;
	data = temp;
	size--;
}
template <class T>
void Vector<T>::max_min_vector() {
	T min = data[0];
	T max = data[0];
	for (int i = 0; i < size; i++) {
		if (data[i] < min) min = data[i];
		if (data[i] > max) max = data[i];
	}
	for (int i = 0; i < size; i++) {
		data[i] = data[i] - (max - min);
	}
}



template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
template <class T>
Vector<T> Vector<T>::operator+(const T k)
{
	Vector<T> temp(size, k);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}
template <class T>
int Vector<T>::operator ()()
{
	return size;
}
template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> b) {
	Vector temp(size, 0);
	for (int i = 0; i < size; i++) {
		temp.data[i] = b.data[i] + data[i];
	}
	return temp;
}
