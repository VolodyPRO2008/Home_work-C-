#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <cstring>

using namespace std;

class Buffer {
private:
    char* data;
    size_t size;

public:
    // Конструктор по умолчанию
    Buffer();

    // Конструктор от размера
    explicit Buffer(size_t n);

    // Конструктор копирования
    Buffer(const Buffer& other);

    // КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ (добавлен)
    Buffer(Buffer&& other) noexcept;

    // Деструктор
    ~Buffer();

    // Оператор присваивания копированием
    Buffer& operator=(const Buffer& other);

    // ОПЕРАТОР ПРИСВАИВАНИЯ ПЕРЕМЕЩЕНИЕМ (добавлен)
    Buffer& operator=(Buffer&& other) noexcept;

    // Методы
    void print() const;
    size_t getSize() const { return size; }
};

#endif