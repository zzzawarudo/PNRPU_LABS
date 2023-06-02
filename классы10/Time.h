#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Time
{
protected:
	int min;
	int sec;

public:
	Time();
	Time(int, int);
	Time(const Time&);
	Time operator=(const Time&);
	int get_min() { return min; }
	int get_sec() { return sec; }
	bool operator ==(const Time&);
	void razn();
	friend ostream& operator<<(ostream& out, const Time& t) {

		int temp2 = t.min * 60 + t.sec;
		Time p;
		p.min = (temp2) / 60;
		p.sec = (temp2) % 60;
		out << "min/sec: " << ' ' << p.min << ": " << p.sec << "\n";

		return out;
	}
	friend istream& operator>>(istream& in, Time& t) {
		cout << "min: "; in >> t.min;
		cout << "sec: "; in >> t.sec;
		//int temp1 = min * 60 + sec;
		/*int temp2 = t.min * 60 + t.sec;
		Time p;
		p.min = (temp2) / 60;
		p.sec = (temp2) % 60;*/
		return in;
	}
	friend fstream& operator>>(fstream& fin, Time& p) {
		/*int temp2 = p.min * 60 + p.sec;
		Time t;
		t.min = (temp2) / 60;
		t.sec = (temp2) % 60;*/
		fin >> p.min;
		fin >> p.sec;
		return fin;
	}
	friend fstream& operator << (fstream& fout, const Time& p) {
		int temp2 = p.min * 60 + p.sec;
		Time t;
		t.min = (temp2) / 60;
		t.sec = (temp2) % 60;
		fout << p.min << "\n" << p.sec << "\n";
		return fout;
	}
	~Time() {};
};