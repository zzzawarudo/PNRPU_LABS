#include "Time.h" 
#include <iostream> 
using namespace std;

Time::Time() {
	min = 0;
	sec = 0;
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
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "min: "; in >> t.min;
	cout << "sec: "; in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << "(" << t.min << " : " << t.sec << ")");
}
bool Time::operator==(const Time& time) const
{
	if (this->min == time.min && this->sec == time.sec)
		return true;
	else return false;
}
bool Time::operator<(const Time& time) const
{
	if (this->min < time.min || ((this->min == time.min) && (this->sec < time.sec)))
		return true;
	else return false;
}