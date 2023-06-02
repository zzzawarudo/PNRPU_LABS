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
    cout << "Введите количество элементов: ";
    cin >> kol;
    Vector<int> v(kol);
    cout << "Контейнер:" << endl;
    v.Print();
    cout << "Задание 3" << endl;
    cout << "Введите значение элемента для добавления: "; cin >> key;
    v.add(key);
    v.Print();
    cout << "Задание 4" << endl;
    cout << "Введите значение элемента для удаления: "; cin >> key;
    v.del(key);
    v.Print();
    cout << "Задание 5" << endl;
    v.min_max();
    v.Print();
    return 0;
}