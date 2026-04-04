#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle {
private:
    string type;  // Тип велосипеда ("sport" или "mountain")

public:
    // Конструктор с параметрами
    Bike(const string& m, int y, const Point& pos, const string& t);

    // Конструктор копирования
    Bike(const Bike& other);

    // Деструктор
    ~Bike();

    // Переопределение чисто виртуальных методов
    double getMaxSpeed() const override;
    void print() const override;

    // Геттер
    string getType() const;
};

#endif