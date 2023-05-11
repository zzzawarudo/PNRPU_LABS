#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Pair
{
public:
    Pair();
    Pair(int f, int c);
    Pair(const Pair&);
    virtual ~Pair(void) {};
    void setFirst(int f);
    void setSecond(int c);
    int getFirst() { return first; };
    int getSecond() { return second; };
    int getProduct();
    Pair& operator=(const Pair&);
    friend ostream& operator<<(ostream& os, const Pair& p);
    friend istream& operator>>(istream& is, Pair& p);
protected:
    int first;
    int second;
};