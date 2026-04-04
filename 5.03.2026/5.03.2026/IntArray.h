#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <iostream>

using namespace std;

class IntArray {
private:
    int* data;      // Указатель на динамический массив
    size_t size;    // Количество элементов

public:
    // Конструктор по умолчанию (создаёт пустой массив)
    IntArray();

    // Конструктор от размера (выделяет память под n элементов, заполняет нулями)
    explicit IntArray(size_t n);

    // Конструктор копирования (глубокое копирование)
    IntArray(const IntArray& other);

    // Конструктор перемещения (передаёт владение ресурсом, обнуляя источник)
    IntArray(IntArray&& other) noexcept;

    // Деструктор (освобождает память)
    ~IntArray();

    // Оператор присваивания копированием
    IntArray& operator=(const IntArray& other);

    // Оператор присваивания перемещением
    IntArray& operator=(IntArray&& other) noexcept;

    // Метод для вывода элементов массива
    void print() const;

    // Метод для получения размера
    size_t getSize() const { return size; }

    // Метод для доступа к элементам
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
};

#endif