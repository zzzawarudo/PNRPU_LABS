#include <iostream>
#include <map> 
#include "Time.h"
#include <algorithm>
using namespace std;
typedef map<int, Time> mp;
istream& operator>>(istream& in, pair<int, Time>& p)
{
    cout << "������� ���� �������: "; in >> p.first;
    cout << "\t������� �������� �������:\n"; in >> p.second;
    return in;
}

mp make_deque(int kol) {
    mp v;
    for (int i = 0; i < kol; i++) {
        Time a;
        cin >> a;
        v.emplace(i, a);
    }
    return v;
}
void print_deque(mp q) {
    for (auto& p : q) {
        cout << p.first << " " << p.second << endl;
    }
}
void find_el2(mp& lst, Time p)
{
    if (find_if(lst.begin(), lst.end(), [&p](const pair<int, Time>& p2) { return (p == p2.second); }) != lst.end())
        cout << "������� ������" << endl;
    else
        cout << "������� �� ������" << endl;
}

void add_el(mp& lst, Time p, int pos)
{
    if (find_if(lst.begin(), lst.end(), [&p](const pair<int, Time>& p2) { return (p == p2.second); }) != lst.end()) {
        cout << "������� ������" << endl;
        lst.emplace(pos, p);
    }
    else
        cout << "������� �� ������" << endl;
}
void del_el(mp& d, int pos)
{
    d.erase(pos);
}

void min_max_mp(mp& d) {
    auto maxIt = max_element(d.begin(), d.end(),
        [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
    auto minIt = min_element(d.begin(), d.end(),
        [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
    Time maxVal = maxIt->second;
    Time minVal = minIt->second;
    for (auto& p : d) {
        p.second = p.second - (maxVal - minVal);
    }
}

int main()
{
    setlocale(0, "ru");
    mp d;
    int kol;
    Time s;
    cout << "������� ���������� ���������: ";
    cin >> kol;
    d = make_deque(kol);
    cout << "��������� �������: ���� (��������)" << endl;
    print_deque(d);
    cout << "������� ������������ �������� �������� ��� ����������:" << endl;
    cin >> s;
    cout << "������� ����� ������� ��� ����������: ";
    cin >> kol;
    add_el(d, s, kol);
    print_deque(d);
    cout << "������� ���� �������� ��� ��������: ";
    cin >> kol;
    del_el(d, kol);
    print_deque(d);
    cout << "������� ���� �������� ��� ������: ";
    cin >> s;
    find_el2(d, s);
    cout << "�� ������� �������� ������� ������� ������������� � ������������ ���������" << endl;
    min_max_mp(d);
    print_deque(d);
}
