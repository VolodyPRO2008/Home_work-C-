#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>

using namespace std;

// Абстрактный базовый класс Shape
class Shape {
public:
    // Чисто виртуальные методы (абстрактный класс)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;

    // Виртуальный деструктор (обязателен для полиморфизма)
    virtual ~Shape() = default;
};

// Производный класс Circle (круг)
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    ~Circle();

    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};

// Производный класс Rectangle (прямоугольник)
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    ~Rectangle();

    double area() const override;
    double perimeter() const override;
    void printInfo() const override;
};

// Производный класс Triangle (треугольник)
class Triangle : public Shape {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c);
    ~Triangle();

    double area() const override;      // Формула Герона
    double perimeter() const override;
    void printInfo() const override;

    // Проверка существования треугольника
    bool isValid() const;
};

#endif