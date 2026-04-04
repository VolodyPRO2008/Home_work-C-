#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

using namespace std;

class Circle {
public:
    double radius;

    Circle(double r = 0);
    Circle(const Circle& other);
    ~Circle();

    // Вспомогательные функции (в public)
    double getLength() const;

    // Операторы
    bool operator==(const Circle& other) const;
    bool operator>(const Circle& other) const;
    Circle& operator+=(double value);
    Circle& operator-=(double value);
    Circle operator+(double value) const;
    Circle operator-(double value) const;

    friend ostream& operator<<(ostream& output, const Circle& c);
    friend istream& operator>>(istream& input, Circle& c);
};

#endif