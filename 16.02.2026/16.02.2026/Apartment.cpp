#define _CRT_SECURE_NO_WARNINGS

#include "Apartment.h"

// Вспомогательная функция для копирования
void Apartment::copyFrom(const Apartment& other) {
    apartmentNumber = other.apartmentNumber;
    residentCount = other.residentCount;
    capacity = other.capacity;
    residents = new Person[capacity];
    for (int i = 0; i < residentCount; i++) {
        residents[i] = other.residents[i];
    }
}

// Вспомогательная функция для освобождения памяти
void Apartment::freeMemory() {
    delete[] residents;
    residents = nullptr;
    residentCount = 0;
    capacity = 0;
}

Apartment::Apartment(int num) : apartmentNumber(num), residentCount(0), capacity(2) {
    residents = new Person[capacity];
    cout << "[Квартира] Создана квартира №" << apartmentNumber << endl;
}

// ПРАВИЛЬНЫЙ конструктор копирования (глубокое копирование)
Apartment::Apartment(const Apartment& other) {
    copyFrom(other);
    cout << "[Квартира] Создана КОПИЯ квартиры №" << apartmentNumber << endl;
}

// ПРАВИЛЬНЫЙ деструктор
Apartment::~Apartment() {
    cout << "[Квартира] Уничтожена квартира №" << apartmentNumber << endl;
    freeMemory();
}

void Apartment::resize() {
    capacity = capacity * 2;
    Person* newResidents = new Person[capacity];
    for (int i = 0; i < residentCount; i++) {
        newResidents[i] = residents[i];
    }
    delete[] residents;
    residents = newResidents;
    cout << "[Квартира] Расширена до " << capacity << " мест" << endl;
}

void Apartment::addResident(const Person& person) {
    if (residentCount >= capacity) {
        resize();
    }
    residents[residentCount] = person;
    residentCount++;
    cout << "[Квартира] Добавлен жилец в квартиру №" << apartmentNumber << endl;
}

void Apartment::removeResident(int index) {
    if (index < 0 || index >= residentCount) {
        cout << "Ошибка: неверный индекс" << endl;
        return;
    }
    for (int i = index; i < residentCount - 1; i++) {
        residents[i] = residents[i + 1];
    }
    residentCount--;
    cout << "[Квартира] Удалён жилец из квартиры №" << apartmentNumber << endl;
}

void Apartment::print() const {
    cout << "=== Квартира №" << apartmentNumber << " ===" << endl;
    cout << "Количество жильцов: " << residentCount << endl;
    for (int i = 0; i < residentCount; i++) {
        cout << "  Жилец " << i + 1 << ":" << endl;
        residents[i].print();
    }
}

// ПРАВИЛЬНЫЙ оператор присваивания
Apartment& Apartment::operator=(const Apartment& other) {
    if (this == &other) return *this;

    freeMemory();
    copyFrom(other);

    cout << "[Квартира] Оператор присваивания для квартиры №" << apartmentNumber << endl;
    return *this;
}