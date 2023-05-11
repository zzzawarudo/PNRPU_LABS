#pragma once
#include "Pair.h"
#include <fstream>
class Rightangle : public Pair
{
public:
    Rightangle(); // ����������� ��� ����������
    Rightangle(int l, int w); // ����������� � �����������
    Rightangle(const Rightangle&); // ����������� �����������
    ~Rightangle() {}; // ����������
    void Show();//������� ��� ��������� ��������� ������ � ������� ���������
    double getHipotenuse(); // ����� ��� ���������� ����������
    friend istream& operator>>(istream& in, Rightangle& p); // ���������� �������� ����� �������
};
