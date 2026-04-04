#define _CRT_SECURE_NO_WARNINGS

#include "Array.h"
#include <sstream>

Array::Array(int s) : size(s) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
    cout << "Создан массив из " << size << " элементов" << endl;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    cout << "Создана копия массива" << endl;
}

Array::~Array() {
    cout << "Уничтожен массив" << endl;
    delete[] data;
}

int Array::getSum() const {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += data[i];
    return sum;
}

int& Array::operator[](int index) {
    return data[index];
}

const int& Array::operator[](int index) const {
    return data[index];
}

void Array::operator()(int value) {
    for (int i = 0; i < size; i++) data[i] += value;
    cout << "Все элементы увеличены на " << value << endl;
}

Array::operator int() const {
    return getSum();
}

Array::operator const char* () {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size; i++) {
        ss << data[i];
        if (i < size - 1) ss << ", ";
    }
    ss << "]";
    string* str = new string(ss.str());
    return str->c_str();
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
    return *this;
}

ostream& operator<<(ostream& output, const Array& a) {
    output << "[";
    for (int i = 0; i < a.size; i++) {
        output << a.data[i];
        if (i < a.size - 1) output << ", ";
    }
    output << "]";
    return output;
}

istream& operator>>(istream& input, Array& a) {
    cout << "Введите " << a.size << " элементов: ";
    for (int i = 0; i < a.size; i++) input >> a.data[i];
    return input;
}