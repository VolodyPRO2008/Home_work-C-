#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include "Person.h"

using namespace std;

class Apartment {
private:
    Person* residents;   // Динамический массив жильцов
    int residentCount;   // Количество жильцов
    int capacity;        // Вместимость массива
    int apartmentNumber; // Номер квартиры

    void resize();
    void copyFrom(const Apartment& other);  // Вспомогательная функция для копирования
    void freeMemory();                       // Вспомогательная функция для освобождения памяти

public:
    Apartment(int num = 0);
    Apartment(const Apartment& other);
    ~Apartment();

    void addResident(const Person& person);
    void removeResident(int index);
    int getResidentCount() const { return residentCount; }
    int getApartmentNumber() const { return apartmentNumber; }
    void setApartmentNumber(int num) { apartmentNumber = num; }

    void print() const;

    Apartment& operator=(const Apartment& other);
};

#endif