#define _CRT_SECURE_NO_WARNINGS

#include "IntArray.h"

// Конструктор
IntArray::IntArray(int n) : size(n) {
    if (n <= 0) {
        throw invalid_argument("Ошибка: размер массива должен быть положительным!");
    }

    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }

    cout << "[IntArray] Создан массив из " << size << " элементов" << endl;
}

// Конструктор копирования
IntArray::IntArray(const IntArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    cout << "[IntArray] Создана копия массива" << endl;
}

// Деструктор
IntArray::~IntArray() {
    delete[] data;
    cout << "[IntArray] Уничтожен массив из " << size << " элементов" << endl;
}

// Оператор присваивания
IntArray& IntArray::operator=(const IntArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "[IntArray] Оператор присваивания" << endl;
    }
    return *this;
}

// Метод at с проверкой границ (неконстантный)
int& IntArray::at(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Ошибка: индекс выходит за границы массива!");
    }
    return data[index];
}

// Метод at с проверкой границ (константный)
const int& IntArray::at(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Ошибка: индекс выходит за границы массива!");
    }
    return data[index];
}

// Оператор индексации (без проверки)
int& IntArray::operator[](int index) {
    return data[index];
}

const int& IntArray::operator[](int index) const {
    return data[index];
}

int IntArray::getSize() const {
    return size;
}

void IntArray::fill(int value) {
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
    cout << "[IntArray] Массив заполнен значением " << value << endl;
}

void IntArray::print() const {
    cout << "Массив [" << size << "]: [ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}