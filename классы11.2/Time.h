#pragma once
#include <iostream>
using namespace std;
class Time {
	int min, sec;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();
	int get_min() { return min; }
	void set_min(int s) { min = s; }
	int get_sec() { return sec; }
	void set_sec(int t) { sec = t; }
	void show();
	Time& operator=(const Time&);
	Time operator+(const Time&);
	Time operator-(const Time&);
	bool operator==(const Time&);
	bool operator >(const Time&);
	bool operator <(const Time&);

	//int& operator[](int index);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};
