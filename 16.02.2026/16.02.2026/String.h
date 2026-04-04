#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* data;     // Указатель на блок памяти
    size_t length;  // Длина строки без учёта нуль-терминатора

public:
    // Конструктор с параметром-строкой
    String(const char* str);

    // Конструктор с параметром длины
    explicit String(size_t len);

    // Конструктор копирования
    String(const String& other);

    // Деструктор
    ~String();

    // Сеттер (с возможностью перевыделения памяти)
    void setString(const char* str);

    // Геттеры
    const char* getString() const { return data; }
    size_t getLength() const { return length; }

    // Вывод строки
    void print() const;
};

#endif