#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;      // Указатель на строку
    int length;     // Длина строки

public:
    // Конструктор по умолчанию (строка 80 символов)
    String();

    // Конструктор для создания строки произвольного размера
    String(int size);

    // Конструктор для инициализации строкой от пользователя
    String(const char* input);

    // Конструктор копирования
    String(const String& other);

    // Деструктор
    ~String();

    // Методы для ввода и вывода
    void inputFromKeyboard();
    void display() const;

    // Метод для получения строки
    const char* getString() const;

    // Метод для получения длины
    int getLength() const;
};

#endif