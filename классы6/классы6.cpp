#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    vector a(5);
    int f;
    cout << a << endl;
    cout << "������� ��������" << endl;
    cin >> a;
    cout << "��������� a: " << a << endl;
    vector b(10);
    b = a;
    cout << "��������� b: " << b << endl;
    vector c(10);
    cout << "�����, �� ������� ����� ��������: ";
    cin >> f;
    c = b * f;
    cout << "��������� c(b*a):" << c << endl;
    cout << "������ �������: " << *(a.first()) << endl;
    Iterator it = a.first();
    ++it;
    cout << "������ �������: " << *it << endl;
    for (it = a.first(); it != a.last(); ++it)
        cout << *it << " ";
    int n;
    cout << endl << "������� ����� ��������, ������� ����� �������: ";
    cin >> n;
    it = a - n;
    cout << n << "-� " << "�������: " << *it;
    return 0;
}