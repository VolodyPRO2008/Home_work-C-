#define _CRT_SECURE_NO_WARNINGS

#include "Buffer.h"

// ============================================
// КОНСТРУКТОР ПО УМОЛЧАНИЮ
// ============================================
Buffer::Buffer() : data(nullptr), size(0) {
    cout << "[Buffer] Конструктор по умолчанию" << endl;
}

// ============================================
// КОНСТРУКТОР ОТ РАЗМЕРА
// ============================================
Buffer::Buffer(size_t n) : data(new char[n]()), size(n) {
    cout << "[Buffer] Конструктор от размера: " << size << " байт" << endl;
}

// ============================================
// КОНСТРУКТОР КОПИРОВАНИЯ
// ============================================
Buffer::Buffer(const Buffer& other) : data(nullptr), size(other.size) {
    if (size > 0) {
        data = new char[size];
        memcpy(data, other.data, size);
    }
    cout << "[Buffer] Конструктор копирования: скопировано " << size << " байт (МЕДЛЕННО)" << endl;
}

// ============================================
// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ (ДОБАВЛЕН)
// ============================================
// Передаёт владение ресурсом без копирования (БЫСТРО)
// noexcept важен для использования в std::vector
// ============================================
Buffer::Buffer(Buffer&& other) noexcept
    : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
    cout << "[Buffer] КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ: ресурс перемещён (БЫСТРО)" << endl;
}

// ============================================
// ДЕСТРУКТОР
// ============================================
Buffer::~Buffer() {
    cout << "[Buffer] Деструктор: удаление " << size << " байт" << endl;
    delete[] data;
}

// ============================================
// ОПЕРАТОР ПРИСВАИВАНИЯ КОПИРОВАНИЕМ
// ============================================
Buffer& Buffer::operator=(const Buffer& other) {
    cout << "[Buffer] Оператор присваивания копированием (МЕДЛЕННО)" << endl;

    if (this == &other) return *this;

    delete[] data;
    size = other.size;

    if (size > 0) {
        data = new char[size];
        memcpy(data, other.data, size);
    }
    else {
        data = nullptr;
    }

    return *this;
}

// ============================================
// ОПЕРАТОР ПРИСВАИВАНИЯ ПЕРЕМЕЩЕНИЕМ (ДОБАВЛЕН)
// ============================================
// Передаёт владение ресурсом без копирования (БЫСТРО)
// ============================================
Buffer& Buffer::operator=(Buffer&& other) noexcept {
    cout << "[Buffer] ОПЕРАТОР ПРИСВАИВАНИЯ ПЕРЕМЕЩЕНИЕМ: ресурс перемещён (БЫСТРО)" << endl;

    if (this == &other) return *this;

    delete[] data;

    data = other.data;
    size = other.size;

    other.data = nullptr;
    other.size = 0;

    return *this;
}

void Buffer::print() const {
    cout << "Буфер: " << size << " байт";
    if (size > 0 && data != nullptr) {
        cout << ", данные: \"";
        for (size_t i = 0; i < size && data[i] != '\0'; i++) {
            cout << data[i];
        }
        cout << "\"";
    }
    cout << endl;
}