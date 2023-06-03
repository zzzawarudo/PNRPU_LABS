#pragma once 
#include <iostream> 
using namespace std;
class Time {
	//int min, sec;
public:
	int min, sec;
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();
	int get_min();
	void set_min(int);
	int get_sec();
	void set_sec(int);
	void show();
	Time& operator=(const Time&);
	Time operator+(const Time&);
	Time operator-(const Time&);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};
