#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;
Pair make_Pair(double a, double b) {
    Pair p;
    p.Init(a, b);
    return p;
}
int main() {
    Pair v;
    double f, s;
    setlocale(0, "");
    Pair p1;
    p1.Init(3, 4);
    cout<<"(3, 4)";
    cout << " ����������: " << p1.hipotenuse() << endl;
    Pair p2;
    p2.Read();
    cout << "����������: " << p2.hipotenuse() << endl;
    Pair* arr = new Pair[3];
    for (int i = 0; i < 3; i++) {
        arr[i].Read();
        arr[i].Show();
        cout << " ����������: " << arr[i].hipotenuse() << endl;
    }
    Pair arrs[3];
    for (int i = 0; i < 3; i++) {
        arrs[i].Read();
        arrs[i].Show();
        cout << " ����������: " << arrs[i].hipotenuse() << endl;
    }
    Pair* elem = new Pair;
    elem->Init(7, 24);
    elem->Show();
    cout << " ����������: " << elem->hipotenuse()<< endl;
    cout << "������� ������ ��������: ";
    cin >> f;
    cout << "������� ������ ��������: ";
    cin >> s;
    v = make_Pair(f, s);
    v.Show();
    cout << " ����������: " << v.hipotenuse() << endl;
    delete[] arr;
    delete elem;
    return 0;
}