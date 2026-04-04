#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <algorithm>

using namespace std;

class Array {
private:
    int* data;      // Указатель на динамический массив
    int size;       // Текущий размер массива
    int capacity;   // Вместимость массива

public:
    // Конструкторы
    Array();                            // По умолчанию
    Array(int initialCapacity);         // С заданным размером
    Array(const Array& other);          // Конструктор копирования

    // Деструктор
    ~Array();

    // Оператор присваивания
    Array& operator=(const Array& other);

    // Методы для работы с массивом
    void fillFromKeyboard();            // Заполнение с клавиатуры
    void fillRandom(int minVal, int maxVal); // Заполнение случайными числами
    void display() const;               // Отображение содержимого
    void resize(int newCapacity);       // Изменение размера
    void sort();                        // Сортировка массива
    int getMin() const;                 // Минимальное значение
    int getMax() const;                 // Максимальное значение

    // Дополнительные методы
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    void addElement(int value);         // Добавление элемента
};

#endif