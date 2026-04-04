#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>

using namespace std;

class Airplane {
public:
    string type;
    int currentPassengers;
    int maxPassengers;

    Airplane(const string& t = "Боинг", int max = 150, int current = 0);
    Airplane(const Airplane& other);
    ~Airplane();

    // Вспомогательные функции (в public)
    bool canAddPassenger() const;
    bool canRemovePassenger() const;

    // Операторы
    bool operator==(const Airplane& other) const;
    bool operator>(const Airplane& other) const;
    Airplane& operator++();    // Префиксный инкремент
    Airplane& operator--();    // Префиксный декремент
    Airplane& operator=(const Airplane& other);

    friend ostream& operator<<(ostream& output, const Airplane& a);
    friend istream& operator>>(istream& input, Airplane& a);
};

#endif