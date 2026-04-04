#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

class Vehicle {
protected:
    string model;   // Модель транспортного средства
    int year;       // Год выпуска
    Point position; // Местоположение

    static int totalVehicles;

public:
    // Конструктор с параметрами
    Vehicle(const string& m, int y, const Point& pos);

    // Конструктор копирования
    Vehicle(const Vehicle& other);

    // Виртуальный деструктор
    virtual ~Vehicle();

    // explicit конструктор от строки (НЕ должен быть определён в классе как explicit с телом)
    explicit Vehicle(const string& m);

    // Статический метод
    static int getTotalVehicles();

    // Константный метод для перемещения
    void move(const Point& newPos);

    // Геттеры
    string getModel() const;
    int getYear() const;
    Point getPosition() const;

    // Чисто виртуальные методы
    virtual double getMaxSpeed() const = 0;
    virtual void print() const = 0;
};

#endif