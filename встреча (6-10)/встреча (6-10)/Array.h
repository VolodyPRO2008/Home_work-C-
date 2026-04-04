#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Array {
public:
    int* data;
    int size;

    Array(int s = 10);
    Array(const Array& other);
    ~Array();

    // Вспомогательные функции (в public)
    int getSum() const;

    // Операторы
    int& operator[](int index);           // Возвращает элемент по индексу
    const int& operator[](int index) const;
    void operator()(int value);           // Увеличивает все элементы на value

    // Операторы преобразования типов
    operator int() const;                 // Преобразование к int (сумма элементов)
    operator const char* ();               // Преобразование к char* (строка значений)

    Array& operator=(const Array& other);

    friend ostream& operator<<(ostream& output, const Array& a);
    friend istream& operator>>(istream& input, Array& a);
};

#endif