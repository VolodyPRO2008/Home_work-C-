#define _CRT_SECURE_NO_WARNINGS

#include "String.h"

// Конструктор с параметром-строкой
String::String(const char* str) {
    if (str != nullptr) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    else {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
    cout << "[Строка] Создана строка: \"" << data << "\"" << endl;
}

// Конструктор с параметром длины
String::String(size_t len) : length(len) {
    data = new char[length + 1];
    memset(data, 0, length + 1);
    cout << "[Строка] Создана пустая строка длиной " << length << endl;
}

// Конструктор копирования
String::String(const String& other) : length(other.length) {
    data = new char[length + 1];
    strcpy(data, other.data);
    cout << "[Строка] Создана КОПИЯ строки: \"" << data << "\"" << endl;
}

// Деструктор
String::~String() {
    cout << "[Строка] Уничтожена строка: \"" << data << "\"" << endl;
    delete[] data;
}

// Сеттер с перевыделением памяти при необходимости
void String::setString(const char* str) {
    if (str == nullptr) {
        return;
    }

    size_t newLen = strlen(str);

    // Если текущей памяти недостаточно, перевыделяем
    if (newLen > length) {
        delete[] data;
        length = newLen;
        data = new char[length + 1];
    }

    strcpy(data, str);
    length = newLen;
    cout << "[Строка] Установлено новое значение: \"" << data << "\"" << endl;
}

// Вывод строки
void String::print() const {
    cout << "Строка: \"" << data << "\", длина: " << length << endl;
}