#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack() {
	size = 0;
	head = nullptr;
}
Stack::Stack(int s, int val) {
	size = s;
	head = nullptr;
	for (int i = 0; i < size; i++) {
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
	}
}
Stack::Stack(const Stack& l) {
	size = l.size;
	if (l.head == nullptr) {
		head = nullptr;
		return;
	}
	head = new Node;
	head->data = l.head->data;
	Node* current = l.head->next;
	Node* NewCurrecnt = head;
	while (current != nullptr) {
		Node* newNode = new Node;
		newNode->data = current->data;
		NewCurrecnt->next = newNode;
		NewCurrecnt = newNode;
		current = current->next;
	}
	NewCurrecnt->next = nullptr;
}
Stack::~Stack() {
	while (head != nullptr) {
		Node* NodeToRemove = head;
		head = head->next;
		delete NodeToRemove;
	}
}
void Stack::push(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = head;
	head = newNode;
	size++;
}
void Stack::pop() {
	if (head == nullptr) {
		return;
	}
	else {
		Node* NodeToRemove = head;
		Node* NodeToRemove1 = NodeToRemove->next;
		int temp = NodeToRemove->data;
		head = NodeToRemove1;
		delete NodeToRemove;
		size--;
	}
}
void Stack::popel(int pos, int k) {
	int data;
	Stack temp;
	for (int i = 1; i < pos; i++) {
		temp.push(head->data);
		pop();
	}
	for (int i = pos; i < pos + k; i++) {
		pop();
	}
	while (temp.head != nullptr) {
		push(temp.head->data);
		temp.head = temp.head->next;
	}
}
ostream& operator<<(ostream& out, const Stack& t) {
	Node* current = t.head;
	while (current != nullptr) {
		out << current->data << ' ';
		current = current->next;
	}
	return out;
}
void Stack::addVal(int key, int number) {
	Node* current = head;
	Stack temp;
	while (current->data != number && current != nullptr) {
		temp.push(current->data);
		pop();
		current = head;
	}
	push(key);
	while (temp.head != nullptr) {
		push(temp.head->data);
		temp.head = temp.head->next;
	}
}
Stack& Stack::operator=(const Stack& e) {
	if (this == &e) return*this;
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	Node* Ncurrent = e.head;
	while (Ncurrent != nullptr) {
		push(Ncurrent->data);
		Ncurrent = Ncurrent->next;
	}
	return *this;
}
int& Stack::operator[](int index) {
	if (index >= 0 && index < size) {
		Node* cur = head;
		int i = size - 1;
		while (i != index) {
			cur = cur->next;
			i--;
		}
		return cur->data;
	}
	else {
		cout << "error";
		exit(222);
	}
}
int Stack::operator()() {
	return size;
}
istream& operator>>(istream& in, Stack& y) {
	int count;
	cout << "¬ведите кол-во значений стека: ";
	in >> count;
	cout << "¬ведите значени€: ";
	for (int i = 0; i < count; i++) {
		int value;
		cin >> value;
		y.push(value);
	}
	return in;
}