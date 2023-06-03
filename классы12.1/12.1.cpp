#include <iostream>
#include <set>
using namespace std;
typedef multiset<double, less<double>>mset;
mset::iterator it;

mset make_set(int n)
{
    mset m;
    double a;
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

mset mset_add(mset m, double key) {
    int founded = m.count(key);
    if (founded > 0) m.insert(key);
    else cout << "������� �� ������" << endl;
    return m;
}

mset mset_del(mset m, double key) {
    int founded = m.count(key);
    if (founded > 0) m.erase(key);
    else cout << "������� �� ������" << endl;
    return m;
}

mset mset_min_max(mset m) {
    double min, max;
    mset tmp;
    it = m.begin();
    min = *it;
    it = m.end();
    it--;
    max = *it;
    tmp = m;
    m.clear();
    for (it = tmp.begin(); it != tmp.end(); it++)
        m.insert(*it - (max - min));
    return m;
}

int main()
{
    setlocale(0, "ru");
    int n;
    double key;
    cout << "������� ���������� ��������� � ���������: "; cin >> n;
    mset m = make_set(n);
    cout << "���������:" << endl;
    print_set(m);
    cout << "������� 3" << endl;
    cout << "������� ������� ��� ����������: "; cin >> key;
    m = mset_add(m, key);
    print_set(m);
    cout << "������� 4" << endl;
    cout << "������� ������� ��� ��������: "; cin >> key;
    m = mset_del(m, key);
    print_set(m);
    cout << "������� 5" << endl;
    m = mset_min_max(m);
    print_set(m);
}