#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;
inline int CreateFile(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Time p;
	cout << "Сколько ?"; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}
inline int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p; int i = 0;
	while (stream >> p) {
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
inline int del_file(const char* f_name, int k, int l)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Time p;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (p.get_min() != k && p.get_sec() != l) temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
inline int add_file(const char* f_name, Time j, Time d) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time op;
	int i = 0;
	while (stream >> op) {
		if (stream.eof()) break;
		i++;
		temp << op;
		if (op == j) {
			temp << d;
			i++;
		}

	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

inline int add_end(const char* f_name, Time j) {
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << j;
	return 1;
}
inline int change_file(const char* f_name, Time p) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0, l = 0;
	while (stream >> t) {
		if (t.get_min() == p.get_min() && t.get_sec() == p.get_sec() && !stream.eof()) {
			t.razn();
			i++;
			temp << t;
		}
		else {
			temp << t;
		}
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}