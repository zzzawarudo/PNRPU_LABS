#include "Rectangle.h"
Rectangle::Rectangle() : Pair()
{
}
Rectangle::Rectangle(int f, int s) : Pair(f, s)
{
}
Rectangle::Rectangle(const Rectangle& p)
{
    first = p.first;
    second = p.second;
}
int Rectangle::getArea()
{
    return first * second;
}
int Rectangle::getPerimeter()
{
    return 2 * first + 2 * second;
}