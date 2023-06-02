#include "Time.h"
Time::Time() {
	min = 0;
	sec = 0;
}
Time::Time(int a, int b) {
	min = a;
	sec = b;
}
Time::Time(const Time& t) {
	min = t.min;
	sec = t.sec;
}
Time Time::operator=(const Time& t) {
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
bool Time::operator==(const Time& l) {
	if (min == l.min && sec == l.sec) {
		return 1;
	}
	return 0;
}
void Time::razn() {
	; if (min <= 1 && sec <= 30) {
		min = 0; sec = 0;
	}
	else {
		int temp2 = min * 60 + sec;
		temp2 -= 90;
		min = temp2 / 60;
		sec = temp2 % 60;
	}


}