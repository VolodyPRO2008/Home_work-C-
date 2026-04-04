#define _CRT_SECURE_NO_WARNINGS

#include "House.h"

House::House(const string& addr) : address(addr), apartmentCount(0), capacity(5) {
    apartments = new Apartment[capacity];
    cout << "[Дом] Создан дом по адресу: " << address << endl;
}

House::House(const House& other)
    : address(other.address), apartmentCount(other.apartmentCount), capacity(other.capacity) {
    apartments = new Apartment[capacity];
    for (int i = 0; i < apartmentCount; i++) {
        apartments[i] = other.apartments[i];
    }
    cout << "[Дом] Создана КОПИЯ дома" << endl;
}

House::~House() {
    delete[] apartments;
    cout << "[Дом] Уничтожен дом по адресу: " << address << endl;
}

void House::resize() {
    capacity = capacity * 2;
    Apartment* newApartments = new Apartment[capacity];
    for (int i = 0; i < apartmentCount; i++) {
        newApartments[i] = apartments[i];
    }
    delete[] apartments;
    apartments = newApartments;
    cout << "[Дом] Расширен до " << capacity << " квартир" << endl;
}

void House::addApartment(const Apartment& apt) {
    if (apartmentCount >= capacity) {
        resize();
    }
    apartments[apartmentCount] = apt;
    apartmentCount++;
    cout << "[Дом] Добавлена квартира №" << apt.getApartmentNumber() << endl;
}

void House::removeApartment(int index) {
    if (index < 0 || index >= apartmentCount) {
        cout << "Ошибка: неверный индекс" << endl;
        return;
    }
    for (int i = index; i < apartmentCount - 1; i++) {
        apartments[i] = apartments[i + 1];
    }
    apartmentCount--;
    cout << "[Дом] Удалена квартира" << endl;
}

Apartment& House::getApartment(int index) {
    if (index < 0 || index >= apartmentCount) {
        cout << "Ошибка: неверный индекс" << endl;
        static Apartment dummy;
        return dummy;
    }
    return apartments[index];
}

void House::print() const {
    cout << "\n=========================================" << endl;
    cout << "ДОМ по адресу: " << address << endl;
    cout << "Количество квартир: " << apartmentCount << endl;
    cout << "=========================================" << endl;
    for (int i = 0; i < apartmentCount; i++) {
        apartments[i].print();
        cout << endl;
    }
}

House& House::operator=(const House& other) {
    if (this == &other) return *this;

    delete[] apartments;
    address = other.address;
    apartmentCount = other.apartmentCount;
    capacity = other.capacity;
    apartments = new Apartment[capacity];
    for (int i = 0; i < apartmentCount; i++) {
        apartments[i] = other.apartments[i];
    }
    return *this;
}