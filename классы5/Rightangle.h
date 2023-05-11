#pragma once
#include "Pair.h"
#include <fstream>
class Rightangle : public Pair
{
public:
    Rightangle(); // конструктор без параметров
    Rightangle(int l, int w); // конструктор с параметрами
    Rightangle(const Rightangle&); // конструктор копирования
    ~Rightangle() {}; // деструктор
    void Show();//функция для просмотра атрибутов класса с помощью указателя
    double getHipotenuse(); // метод для вычисления гипотенузы
    friend istream& operator>>(istream& in, Rightangle& p); // перегрузка операции ввода объекта
};
