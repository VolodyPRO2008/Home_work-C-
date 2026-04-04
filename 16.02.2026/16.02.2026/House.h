#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Apartment.h"

using namespace std;

class House {
private:
    Apartment* apartments;  // Динамический массив квартир
    int apartmentCount;     // Количество квартир
    int capacity;           // Вместимость массива
    string address;         // Адрес дома

    void resize();

public:
    House(const string& addr = "Не указан");
    House(const House& other);
    ~House();

    void addApartment(const Apartment& apt);
    void removeApartment(int index);
    int getApartmentCount() const { return apartmentCount; }
    string getAddress() const { return address; }

    Apartment& getApartment(int index);

    void print() const;

    House& operator=(const House& other);
};

#endif