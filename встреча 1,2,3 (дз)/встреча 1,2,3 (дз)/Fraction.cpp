#define _CRT_SECURE_NO_WARNINGS
#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

void Fraction::input() {
    cout << "¬ведите числитель: ";
    cin >> numerator;
    cout << "¬ведите знаминатель: ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "«наменатель не должен быть равен 0: ";
        cin >> denominator;
    }
}

void Fraction::output() const {
    cout << numerator << "/" << denominator;
}

Fraction Fraction::add(const Fraction& other) const {
    Fraction result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::subtract(const Fraction& other) const {
    Fraction result;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::multiply(const Fraction& other) const {
    Fraction result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::divide(const Fraction& other) const {
    Fraction result;
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    return result;
}