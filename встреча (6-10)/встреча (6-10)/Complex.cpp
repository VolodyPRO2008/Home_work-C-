#include "Complex.h"
#include <cmath>

Complex::Complex(double r, double i) : real(r), imag(i) {
    cout << "—оздано комплексное число: " << *this << endl;
}

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {
    cout << "—оздана копи€ комплексного числа" << endl;
}

Complex::~Complex() {
    cout << "”ничтожено комплексное число: " << *this << endl;
}

double Complex::getModulus() const {
    return sqrt(real * real + imag * imag);
}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

bool operator==(const Complex& a, const Complex& b) {
    return (a.real == b.real && a.imag == b.imag);
}

bool operator!=(const Complex& a, const Complex& b) {
    return !(a == b);
}

Complex Complex::operator()(double r, double i) const {
    return Complex(r, i);
}

ostream& operator<<(ostream& output, const Complex& c) {
    output << c.real;
    if (c.imag >= 0) output << "+" << c.imag << "i";
    else output << c.imag << "i";
    return output;
}

istream& operator>>(istream& input, Complex& c) {
    cout << "¬ведите действительную часть: ";
    input >> c.real;
    cout << "¬ведите мнимую часть: ";
    input >> c.imag;
    return input;
}