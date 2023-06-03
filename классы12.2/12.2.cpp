#include <iostream>
#include <set>
#include "Time.h"
using namespace std;
bool operator<(const Time& pr1, const Time& pr2)
{
    return ((pr1.min < pr2.min) || ((pr1.min == pr2.min) && (pr1.sec < pr2.sec)));
}
typedef multiset<Time> mset;
mset::iterator it;

mset make_set(int n)
{
    mset m;
    Time a;
    for (int i = 0; i < n; i++)
    {
        cout << "?"; cin >> a;
        m.insert(a);
    }
    return m;
}

void print_set(mset m)
{
    for (it = m.begin(); it != m.end(); it++)
        cout << *it << " " << endl;
}

mset mset_add(mset m, Time key) {
    int founded = m.count(key);
    if (founded > 0) m.insert(key);
    else cout << "Элемент не найден" << endl;
    return m;
}

mset mset_del(mset m, Time key) {
    int founded = m.count(key);
    if (founded > 0) m.erase(key);
    else cout << "Элемент не найден" << endl;
    return m;
}

mset mset_min_max(mset m) {
    Time min, max, cur;
    mset tmp;
    it = m.begin();
    min = *it;
    it = m.end();
    it--;
    max = *it;
    tmp = m;
    m.clear();
    for (it = tmp.begin(); it != tmp.end(); it++) {
        cur = *it;
        cur = cur - (max - min);
        m.insert(cur);
    }
    return m;
}

int main()
{
    setlocale(0, "ru");
    int n;
    Time key;
    cout << "Введите количество элементов в множестве: "; cin >> n;
    mset m = make_set(n);
    cout << "Множество:" << endl;
    print_set(m);
    cout << "Задание 3" << endl;
    cout << "Введите элемент для добавления: "; cin >> key;
    m = mset_add(m, key);
    print_set(m);
    cout << "Задание 4" << endl;
    cout << "Введите элемент для удаления: "; cin >> key;
    m = mset_del(m, key);
    print_set(m);
    cout << "Задание 5" << endl;
    m = mset_min_max(m);
    print_set(m);
}