#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
class Stack
{
private:
	int size;
	Node* head;
public:
	Stack();
	Stack(int, int);
	Stack(const Stack&);
	~Stack();
	void push(int);
	void pop();
	void popel(int, int);
	void addVal(int, int);
	Stack& operator=(const Stack&);
	int& operator[](int);
	int operator()();
	friend ostream& operator<<(ostream&, const Stack&);
	friend istream& operator>>(istream&, Stack&);

};