#include <iostream>
#include <deque>
#include <cstdlib>
#include "Time.h"
using namespace std;
typedef deque<Time> deq2;

deq2 make_deque(int kol) {
    deq2 v;
    int min, sec;
    for (int i = 0; i < kol; i++) {
        min = rand() % 60;
        sec = rand() % 60;
        Time a(min, sec);
        //a = rand()/1.1;
       // a.set_min() = 30;//rand() % 100 - 50;
        v.push_back(a);
    }
    return v;
}
void print_deque(deq2 v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
bool find_key(deq2 v, Time key) {
    for (int i = 0; i < v.size(); i++) {
        if (key == v[i]) {
            return 1;

            ////auto result = find(v.begin(), v.end(), key);
            //if (result != v.end()) {
            //    return 1;
        }
    }
    return 0;
}
void add_deque(deq2& v, Time key, int pos) {
    v.insert(v.begin() + pos, key);
}
void del_deque(deq2& v, int pos) {
    v.erase(v.begin() + pos);
}
void max_min_deque(deq2& v) {
    Time min = v[0];
    Time max = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min) min = v[i];
        if (v[i] > max) max = v[i];
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] - (max - min);
    }
}

int main()
{
    setlocale(0, "ru");
    try {
        deq2 v;
        //deq::iterator di = d.begin();
        int kol;
        cout << "Введите количество элементов: ";
        cin >> kol;
        v = make_deque(kol);
        print_deque(v);
        Time key; //значение элемента
        bool pos; //индекс элемента
        int index;
        cout << "Введите значение элемента для добавления: "; cin >> key;
        pos = find_key(v, key);
        if (pos == 0) throw 1;
        else {
            cout << "Введите индекс для добавления: "; cin >> index;
            add_deque(v, key, index);
        }
        print_deque(v);
        cout << "Введите значение элемента для удаления: "; cin >> key;
        pos = find_key(v, key);
        if (pos == -1) throw 1;
        else del_deque(v, pos);
        print_deque(v);
        max_min_deque(v);
        print_deque(v);
    }
    catch (int) {
        cout << "Error";

    }
}