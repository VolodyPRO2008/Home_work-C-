#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

class Set {
private:
    int* elements;   // Динамический массив элементов
    int size;        // Текущее количество элементов
    int capacity;    // Вместимость массива

    // Вспомогательные методы
    void resize();                    // Увеличение размера массива
    int findIndex(int value) const;   // Поиск индекса элемента (-1 если не найден)

public:
    // Конструкторы
    Set();                            // Конструктор по умолчанию
    Set(int initialCapacity);         // Конструктор с параметром
    Set(const Set& other);            // Конструктор копирования

    // Деструктор
    ~Set();

    // Оператор присваивания
    Set& operator=(const Set& other);

    // Основные методы
    bool contains(int value) const;   // Проверка принадлежности элемента
    void add(int value);              // Добавление элемента
    void remove(int value);           // Удаление элемента
    int getSize() const { return size; }
    void display() const;             // Вывод множества

    // Перегрузка операторов

    // Операторы добавления
    Set& operator+=(int value);       // Добавление элемента (+=)
    Set operator+(int value) const;   // Добавление элемента (+)
    Set& operator+=(const Set& other); // Объединение множеств (+=)
    Set operator+(const Set& other) const; // Объединение множеств (+)

    // Операторы удаления
    Set& operator-=(int value);       // Удаление элемента (-=)
    Set operator-(int value) const;   // Удаление элемента (-)
    Set& operator-=(const Set& other); // Разность множеств (-=)
    Set operator-(const Set& other) const; // Разность множеств (-)

    // Оператор пересечения
    Set& operator*=(const Set& other); // Пересечение множеств (*=)
    Set operator*(const Set& other) const; // Пересечение множеств (*)

    // Оператор сравнения
    bool operator==(const Set& other) const; // Сравнение множеств
    bool operator!=(const Set& other) const { return !(*this == other); }

    // Операторы ввода-вывода
    friend ostream& operator<<(ostream& output, const Set& set);
    friend istream& operator>>(istream& input, Set& set);
};

#endif