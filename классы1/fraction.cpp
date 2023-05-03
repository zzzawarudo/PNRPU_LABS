#include "fraction.h"
#include <iostream>
#include <cmath>
using namespace std;
double first, second;
void Pair::Init(double a, double b) {
    first = a;
    second = b;
}
void Pair::Read() {
        cout << "¬ведите первое значение: ";
        cin >> first;
        cout << "¬ведите второе значение: ";
        cin >> second;
}
void Pair::Show() {
        cout << "(" << first << ", " << second << ")" << endl;
}
double Pair::hipotenuse() {
    return sqrt(first * first + second * second);
}