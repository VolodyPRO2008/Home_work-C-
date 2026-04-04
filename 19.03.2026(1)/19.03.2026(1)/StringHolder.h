#ifndef STRING_HOLDER_H
#define STRING_HOLDER_H

#include <iostream>
#include <cstring>

using namespace std;

// Базовый класс StringHolder
class StringHolder {
protected:
    char* str;  // Указатель на динамически выделенную строку

public:
    // Конструктор: выделяет память и копирует строку
    StringHolder(const char* input);

    // Виртуальный деструктор (обязателен для полиморфного удаления)
    virtual ~StringHolder();

    // Виртуальный метод для вывода строки
    virtual void print() const;

    // Геттер для получения строки
    const char* getString() const;
};

// Производный класс ReverseString (выводит строку задом наперёд)
class ReverseString : public StringHolder {
private:
    char* reversedStr;  // Дополнительная динамическая память для перевёрнутой строки

public:
    ReverseString(const char* input);
    ~ReverseString();

    void print() const override;
};

#endif