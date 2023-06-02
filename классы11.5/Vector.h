#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <class T>
class Vector
{
    priority_queue <T> q;
    priority_queue <T> qtmp;
    int len;
public:
    Vector();
    Vector(int s);
    Vector(const Vector<T>& a);
    ~Vector();
    void Print();
    void add(T key);
    void del(T key);
    void min_max();
private:
    int size;
    T* data;
};

template <class T>
Vector<T>::Vector()
{
    size = 0;
}

template <class T>
Vector<T>::Vector(int n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }
    len = q.size();
}

template <class T>
Vector<T>::Vector(const Vector& v)
{
    q = v.q;
}

template <class T>
Vector<T>::~Vector()
{
    delete[]data;
    data = 0;
}


template <class T>
void Vector<T>::Print()
{
    if (q.empty()) cout << "Empty" << endl;
    while (!q.empty())
    {
        cout << q.top() << endl;
        qtmp.push(q.top());
        q.pop();
    }

    while (!qtmp.empty())
    {
        q.push(qtmp.top());
        qtmp.pop();
    }
}

template <class T>
void Vector<T>::add(T key) {
    bool found = false;
    while (!q.empty() && !found)
    {
        if (q.top() == key) {
            found = true;
            q.push(key);
        }
        else {
            qtmp.push(q.top());
            q.pop();
        }
    }

    while (!qtmp.empty())
    {
        q.push(qtmp.top());
        qtmp.pop();
    }
}

template <class T>
void Vector<T>::del(T key) {
    bool found = false;
    while (!q.empty() && !found)
    {
        if (q.top() == key) {
            found = true;
            q.pop();
        }
        else {
            qtmp.push(q.top());
            q.pop();
        }
    }

    while (!qtmp.empty())
    {
        q.push(qtmp.top());
        qtmp.pop();
    }
    if (found) cout << "Ёлемент найден" << endl;
    else cout << "Ёлемент не найден" << endl;
}

template <class T>
void Vector<T>::min_max() {
    bool found = false;
    T min = q.top();
    T max = q.top();
    while (!q.empty())
    {
        if (q.top() < min) min = q.top();
        if (q.top() > max) max = q.top();
        qtmp.push(q.top());
        q.pop();
    }
    while (!qtmp.empty())
    {
        q.push(qtmp.top() - (max - min));
        qtmp.pop();
    }
}