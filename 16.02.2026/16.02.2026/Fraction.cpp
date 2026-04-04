#define _CRT_SECURE_NO_WARNINGS

#include "Fraction.h"
#include <cmath>

// Конструктор с параметрами (список инициализации)
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        denominator = 1;
    }
    reduce();
    cout << "[Дробь] Создана дробь: " << numerator << "/" << denominator << endl;
}

// Конструктор по умолчанию (делегирование конструктору с параметрами)
Fraction::Fraction() : Fraction(0, 1) {}

// Деструктор
Fraction::~Fraction() {
    cout << "[Дробь] Уничтожена дробь: " << numerator << "/" << denominator << endl;
}

// Нахождение НОД
int Fraction::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение дроби
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int divisor = gcd(numerator, denominator);
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// Сложение дробей
Fraction Fraction::add(const Fraction& other) const {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen);
}

// Вычитание дробей
Fraction Fraction::subtract(const Fraction& other) const {
    int newNum = numerator * other.denominator - other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen);
}

// Умножение дробей
Fraction Fraction::multiply(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

// Сложение с целым числом
Fraction Fraction::add(int value) const {
    return add(Fraction(value, 1));
}

// Вычитание целого числа
Fraction Fraction::subtract(int value) const {
    return subtract(Fraction(value, 1));
}

// Умножение на целое число
Fraction Fraction::multiply(int value) const {
    return multiply(Fraction(value, 1));
}

// Сложение с присваиванием (для цепочек)
Fraction& Fraction::addToThis(const Fraction& other) {
    *this = add(other);
    return *this;
}

// Вычитание с присваиванием
Fraction& Fraction::subtractFromThis(const Fraction& other) {
    *this = subtract(other);
    return *this;
}

// Умножение с присваиванием
Fraction& Fraction::multiplyByThis(const Fraction& other) {
    *this = multiply(other);
    return *this;
}

// Сложение с целым числом с присваиванием
Fraction& Fraction::addToThis(int value) {
    *this = add(value);
    return *this;
}

// Вычитание целого числа с присваиванием
Fraction& Fraction::subtractFromThis(int value) {
    *this = subtract(value);
    return *this;
}

// Умножение на целое число с присваиванием
Fraction& Fraction::multiplyByThis(int value) {
    *this = multiply(value);
    return *this;
}

// Вывод дроби
void Fraction::print() const {
    cout << numerator << "/" << denominator;
}