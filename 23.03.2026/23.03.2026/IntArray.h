#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <iostream>
#include <stdexcept>

using namespace std;

class IntArray {
private:
    int* data;      // Указатель на динамический массив
    int size;       // Размер массива

public:
    // Конструктор
    explicit IntArray(int n);

    // Конструктор копирования
    IntArray(const IntArray& other);

    // Деструктор
    ~IntArray();

    // Оператор присваивания
    IntArray& operator=(const IntArray& other);

    // Метод доступа с проверкой границ
    int& at(int index);
    const int& at(int index) const;

    // Оператор индексации (без проверки для скорости)
    int& operator[](int index);
    const int& operator[](int index) const;

    // Геттер размера
    int getSize() const;

    // Заполнение массива
    void fill(int value);

    // Вывод массива
    void print() const;
};

#endif