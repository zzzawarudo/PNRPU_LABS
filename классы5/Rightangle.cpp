#include "Rightangle.h"
Rightangle::Rightangle()
{
}
Rightangle::Rightangle(int f, int s) : Pair(f, s)
{
}
Rightangle::Rightangle(const Rightangle& p)
{
    first = p.first;
    second = p.second;
}
double Rightangle::getHipotenuse()
{
    return sqrt(first * first + second * second);
}
void Rightangle::Show()
{
    cout << "\nFirst : " << first;
    cout << "\nSecond : " << second;
    cout << "\nHipotenuse : " << sqrt(first * first + second * second);
    cout << "\n";
}
istream& operator>>(istream& in, Rightangle& p) {
    in >> p.first >> p.second;
    return in;
}