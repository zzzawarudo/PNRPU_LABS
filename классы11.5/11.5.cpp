#include <iostream>
#include "Vector.h"
#include <queue> 
#include <vector>
using namespace std;
typedef priority_queue <int>  deq;

int main()
{
    setlocale(0, "rus");
    int kol, key;
    cout << "������� ���������� ���������: ";
    cin >> kol;
    Vector<int> v(kol);
    cout << "���������:" << endl;
    v.Print();
    cout << "������� 3" << endl;
    cout << "������� �������� �������� ��� ����������: "; cin >> key;
    v.add(key);
    v.Print();
    cout << "������� 4" << endl;
    cout << "������� �������� �������� ��� ��������: "; cin >> key;
    v.del(key);
    v.Print();
    cout << "������� 5" << endl;
    v.min_max();
    v.Print();
    return 0;
}