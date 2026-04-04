#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0);
    Complex(const Complex& other);
    ~Complex();

    // Вспомогательные функции (в public)
    double getModulus() const;

    // Операторы (дружественная перегрузка)
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);

    // Оператор () 
    Complex operator()(double r, double i) const;

    friend ostream& operator<<(ostream& output, const Complex& c);
    friend istream& operator>>(istream& input, Complex& c);
};

#endif