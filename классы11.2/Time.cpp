#include "Time.h"
#include <iostream>
using namespace std;

Time::Time() {
	min = 2;
	sec = 30;
}
Time::Time(int a, int b) {
	min = a;
	sec = b;
}
Time::Time(const Time& p) {
	min = p.min;
	sec = p.sec;
}
Time::~Time() {

}
Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

Time Time::operator-(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	if (temp2 > temp1) {
		Time q;
		q.min = 0; q.sec = 0;
		return q;
	}
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "min?"; in >> t.min;
	cout << "sec?"; in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << "(" << t.min << " : " << t.sec << ")");
}
bool Time::operator==(const Time& r)
{
	if (min == r.min && sec == r.sec) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Time::operator >(const Time& t) {
	if (min > t.min)return true;
	if (min == t.min && sec > t.sec) return true;
	else return false;
}
bool Time::operator<(const Time& s) {
	if (min < s.min) return true;
	if (min == s.min && sec < s.sec)return true;
	return false;
}