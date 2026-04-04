#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;      // Числитель
    int denominator;    // Знаменатель

    // Вспомогательная функция для нахождения НОД
    int gcd(int a, int b) const;

    // Сокращение дроби
    void reduce();

public:
    // Конструктор с параметрами (использует список инициализации)
    Fraction(int num, int denom);

    // Конструктор по умолчанию (делегирование)
    Fraction();

    // Деструктор
    ~Fraction();

    // Геттеры
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Арифметические операции с дробью
    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;

    // Арифметические операции с целым числом
    Fraction add(int value) const;
    Fraction subtract(int value) const;
    Fraction multiply(int value) const;

    // Операции с возвратом ссылки для цепочек (используя this)
    Fraction& addToThis(const Fraction& other);
    Fraction& subtractFromThis(const Fraction& other);
    Fraction& multiplyByThis(const Fraction& other);
    Fraction& addToThis(int value);
    Fraction& subtractFromThis(int value);
    Fraction& multiplyByThis(int value);

    // Вывод дроби на экран
    void print() const;
};

#endif