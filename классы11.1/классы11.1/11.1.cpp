#include <iostream>

#include <deque>
#include <cstdlib>
using namespace std;
typedef deque<double> deq;

deq make_deque(int kol) {
    deq d;
    for (int i = 0; i < kol; i++) {
        double a;
        //a = rand()/1.1;
        a = (double)(rand() % (10000 - (-10000) + 1) + (-10000)) / 100;
        d.push_back(a);
    }
    return d;
}

void print_deque(deq d) {
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
}

int find_key(deq d, double key) {
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == key) return i;
    }
    return -1; //элемент не найден
}

void add_deque(deq& d, double key, int pos) {
    d.insert(d.begin() + pos, key);
}

void del_deque(deq& d, int pos) {
    d.erase(d.begin() + pos);
}

void max_min_deque(deq& d) {
    double min = d[0];
    double max = d[0];
    for (int i = 0; i < d.size(); i++) {
        if (d[i] < min) min = d[i];
        if (d[i] > max) max = d[i];
    }
    for (int i = 0; i < d.size(); i++) {
        d[i] = d[i] - (max - min);
    }
}

void main()
{
    setlocale(0, "ru");
    try {
        deq d;
        //deq::iterator di = d.begin();
        int kol;
        cout << "Введите количество элементов: ";
        cin >> kol;
        d = make_deque(kol);
        print_deque(d);
        double key; //значение элемента
        int pos; //индекс элемента
        cout << "Введите значение элемента для добавления: "; cin >> key;
        pos = find_key(d, key);
        if (pos == -1) throw 1;
        else {
            cout << "Введите номер позиции для добавления: "; cin >> pos;
            add_deque(d, key, pos);
        }
        print_deque(d);
        cout << "Введите значение элемента для удаления: "; cin >> key;
        pos = find_key(d, key);
        if (pos == -1) throw 1;
        else del_deque(d, pos);
        print_deque(d);
        max_min_deque(d);
        print_deque(d);
    }
    catch (int) {
        cout << "Error";
    }
}