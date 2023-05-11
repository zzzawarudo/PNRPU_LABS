#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    vector a(5);
    int f;
    cout << a << endl;
    cout << "Введите элементы" << endl;
    cin >> a;
    cout << "Контейнер a: " << a << endl;
    vector b(10);
    b = a;
    cout << "Контейнер b: " << b << endl;
    vector c(10);
    cout << "Число, на которое нужно умножить: ";
    cin >> f;
    c = b * f;
    cout << "Контейнер c(b*a):" << c << endl;
    cout << "Первый элемент: " << *(a.first()) << endl;
    Iterator it = a.first();
    ++it;
    cout << "Второй элемент: " << *it << endl;
    for (it = a.first(); it != a.last(); ++it)
        cout << *it << " ";
    int n;
    cout << endl << "Введите номер элемента, который нужно вывести: ";
    cin >> n;
    it = a - n;
    cout << n << "-й " << "элемент: " << *it;
    return 0;
}