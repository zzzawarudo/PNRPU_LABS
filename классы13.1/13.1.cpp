#include <iostream>
#include <deque> 
#include "Time.h"
#include <algorithm>
using namespace std;
typedef deque<Time> deq;

deq make_deque(int kol) {
    deq v;
    for (int i = 0; i < kol; i++) {
        Time a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}
void print_deque(deq q) {
    for_each(q.begin(), q.end(), [](Time t) {cout << t << endl; });
    cout << endl;
}

deq del_deque(deq q, Time s) {
    auto it = remove(q.begin(), q.end(), s);
    q.erase(it, q.end());
    return q;
}

deq add_deque(deq q, Time s, int pos) {
    deq tmp;
    if (find(q.begin(), q.end(), s) != q.end()) {
        copy(q.begin(), q.begin() + pos - 1, back_inserter(tmp));
        tmp.push_back(s);
        copy(q.begin() + pos - 1, q.end(), back_inserter(tmp));
    }
    else cout << "�������� ������� �� ������" << endl;
    return tmp;
}

deq min_max_deque(deq q) {
    Time min = *min_element(q.begin(), q.end());
    Time max = *max_element(q.begin(), q.end());
    cout << endl;
    for_each(q.begin(), q.end(), [&min, &max](Time& t) {t = t - (max - min); });
    return q;
}
struct sort_less // ��� ���������� �� ��������
{
public:
    bool operator()(Time t1, Time t2)
    {
        if (t2 < t1) return true;
        else return false;
    }
};

int main()
{
    setlocale(0, "ru");
    deq d;
    int kol;
    Time s;
    cout << "������� ���������� ���������: ";
    cin >> kol;
    d = make_deque(kol);
    cout << "��������� �������:" << endl;
    print_deque(d);
    cout << "������� ������������ ���� �������� ��� ����������: ";
    cin >> s;
    cout << "������� ����� ������� ��� ����������: ";
    cin >> kol;
    d = add_deque(d, s, kol);
    print_deque(d);
    cout << "������� ���� �������� ��� ��������: ";
    cin >> s;
    d = del_deque(d, s);
    print_deque(d);
    cout << "������� ���� �������� ��� ������: ";
    cin >> s;
    if (find(d.begin(), d.end(), s) != d.end()) cout << "������� ������";
    else cout << "������� �� ������";
    cout << endl;
    cout << "�� ������� �������� ������� ������� ������������� � ������������ ���������" << endl;
    d = min_max_deque(d);
    print_deque(d);
    cout << "���������� �� �����������" << endl;
    sort(d.begin(), d.end());
    print_deque(d);
    cout << "���������� �� ��������" << endl;
    sort(d.begin(), d.end(), sort_less());
    print_deque(d);
}