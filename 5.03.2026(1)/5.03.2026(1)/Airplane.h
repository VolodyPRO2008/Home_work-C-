#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string type;            // Тип самолёта
    int currentPassengers;  // Текущее количество пассажиров
    int maxPassengers;      // Максимальное количество пассажиров

public:
    // Конструкторы
    Airplane(const string& t = "Боинг", int max = 150, int current = 0);
    Airplane(const Airplane& other);
    ~Airplane();

    // Геттеры
    string getType() const;
    int getCurrentPassengers() const;
    int getMaxPassengers() const;

    // Сеттеры
    void setType(const string& t);
    void setCurrentPassengers(int count);
    void setMaxPassengers(int max);

    // Операторы сравнения
    bool operator==(const Airplane& other) const;  // Равенство типов
    bool operator>(const Airplane& other) const;   // Сравнение по макс. пассажирам
    bool operator<(const Airplane& other) const;
    bool operator!=(const Airplane& other) const;

    // Префиксный инкремент (увеличение пассажиров)
    Airplane& operator++();

    // Префиксный декремент (уменьшение пассажиров)
    Airplane& operator--();

    // Оператор присваивания
    Airplane& operator=(const Airplane& other);

    // Операторы ввода-вывода
    friend ostream& operator<<(ostream& output, const Airplane& a);
    friend istream& operator>>(istream& input, Airplane& a);
};

#endif