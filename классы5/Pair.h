#pragma once
#include <iostream>
#include <fstream>
#include "Object.h"
using namespace std;
class Pair : public Object
{
public:
    Pair(void);
    Pair(int f, int c);
    Pair(const Pair&);
    virtual ~Pair(void) {};
    void Show();
    void setFirst(int f);
    void setSecond(int c);
    int getFirst() { return first; };
    int getSecond() { return second; };
    Pair& operator=(const Pair&);
    friend ostream& operator<<(ostream& os, const Pair& p);
    friend istream& operator>>(istream& is, Pair& p);
protected:
    int first;
    int second;
};