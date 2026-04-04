#define _CRT_SECURE_NO_WARNINGS

#include "Vehicles.h"

// ========== Vehicle ==========
void Vehicle::startEngine() const {
    cout << "Двигатель запущен" << endl;
}

double Vehicle::getMaxSpeed() const {
    return 0;
}

void Vehicle::info() const {
    cout << "Транспортное средство" << endl;
}

// ========== Car ==========
void Car::startEngine() const {
    cout << "Автомобильный двигатель запущен" << endl;
}

double Car::getMaxSpeed() const {
    return 180;
}

void Car::info() const {
    cout << "Я - автомобиль" << endl;
}

// ========== ElectricCar ==========
void ElectricCar::startEngine() const {
    cout << "Электромотор бесшумно запущен" << endl;
}

double ElectricCar::getMaxSpeed() const {
    return 180;  // final метод
}

void ElectricCar::info() const {
    cout << "Я - электромобиль" << endl;
}

// ========== SportsCar ==========
void SportsCar::startEngine() const {
    cout << "Спортивный автомобильный двигатель запущен с рёвом!" << endl;
}

// double SportsCar::getMaxSpeed() const { return 300; }  // ОШИБКА!

void SportsCar::info() const {
    cout << "Я - спортивный автомобиль" << endl;
}

// ========== Bicycle ==========
void Bicycle::startEngine() const {
    cout << "У велосипеда нет двигателя!" << endl;
}

double Bicycle::getMaxSpeed() const {
    return 30;
}

void Bicycle::info() const {
    cout << "Я - велосипед" << endl;
}