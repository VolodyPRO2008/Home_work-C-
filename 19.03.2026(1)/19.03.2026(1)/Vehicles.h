#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>

using namespace std;

// ========== Базовый класс Vehicle ==========
class Vehicle {
public:
    virtual void startEngine() const;
    virtual double getMaxSpeed() const;
    virtual void info() const;
    virtual ~Vehicle() = default;
};

// ========== Класс Car (наследует Vehicle) ==========
class Car : public Vehicle {
public:
    void startEngine() const override;
    double getMaxSpeed() const override;
    void info() const override;
    virtual ~Car() = default;
};

// ========== Класс ElectricCar (наследует Car) ==========
class ElectricCar : public Car {
public:
    void startEngine() const override;
    double getMaxSpeed() const final;  // final - запрещает дальнейшее переопределение
    void info() const override;
    virtual ~ElectricCar() = default;
};

// ========== Класс SportsCar (пытается переопределить getMaxSpeed) ==========
// Ошибка компиляции: cannot override 'getMaxSpeed' which has been marked 'final'
class SportsCar : public Car {
public:
    void startEngine() const override;
    // double getMaxSpeed() const override;  // РАСКОММЕНТИРОВАТЬ ДЛЯ ОШИБКИ
    void info() const override;
    virtual ~SportsCar() = default;
};

// ========== Класс Bicycle (final - запрещает наследование) ==========
class Bicycle final : public Vehicle {
public:
    void startEngine() const override;
    double getMaxSpeed() const override;
    void info() const override;
    virtual ~Bicycle() = default;
};

// Следующий код вызовет ошибку компиляции (наследование от final класса)
// class MountainBike : public Bicycle {};

#endif