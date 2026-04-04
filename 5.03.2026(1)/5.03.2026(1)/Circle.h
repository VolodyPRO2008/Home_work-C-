#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

using namespace std;

class Circle {
private:
    double radius;  // Радиус окружности

public:
    // Конструкторы
    Circle(double r = 0.0);
    Circle(const Circle& other);
    ~Circle();

    // Геттеры
    double getRadius() const;
    double getLength() const;  // Длина окружности

    // Сеттеры
    void setRadius(double r);

    // Операторы сравнения
    bool operator==(const Circle& other) const;  // Сравнение радиусов
    bool operator>(const Circle& other) const;    // Сравнение длин окружностей
    bool operator<(const Circle& other) const;
    bool operator!=(const Circle& other) const;

    // Операторы изменения размера
    Circle& operator+=(double value);   // Увеличение радиуса
    Circle& operator-=(double value);   // Уменьшение радиуса

    // Операторы для удобства (создают новую окружность)
    Circle operator+(double value) const;
    Circle operator-(double value) const;

    // Операторы ввода-вывода
    friend ostream& operator<<(ostream& output, const Circle& c);
    friend istream& operator>>(istream& input, Circle& c);
};

#endif