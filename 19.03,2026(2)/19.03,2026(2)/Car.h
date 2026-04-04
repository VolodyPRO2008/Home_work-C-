#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int doors;  // Количество дверей

public:
    // Конструктор с параметрами
    Car(const string& m, int y, const Point& pos, int d);

    // Конструктор копирования
    Car(const Car& other);

    // Деструктор
    ~Car();

    // Переопределение чисто виртуальных методов
    double getMaxSpeed() const override;
    void print() const override;

    // Префиксный инкремент (увеличивает количество дверей)
    Car& operator++();

    // Постфиксный инкремент
    Car operator++(int);

    // Геттер
    int getDoors() const;
};

#endif