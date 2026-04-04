#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include <string>

using namespace std;

class Elevator {
private:
    int minFloor;      // Нижний этаж
    int maxFloor;      // Верхний этаж
    int currentFloor;  // Текущий этаж
    bool isWorking;    // Состояние (работает/не работает)

public:
    // Конструкторы
    Elevator(int min = 1, int max = 10);
    Elevator(const Elevator& other);
    ~Elevator();

    // Установка диапазона
    void setRange(int min, int max);

    // Включение/выключение
    void turnOn();
    void turnOff();

    // Получение состояния
    bool getIsWorking() const;
    int getCurrentFloor() const;
    int getMinFloor() const;
    int getMaxFloor() const;

    // Обработка вызова
    bool call(int floor);

    // Вывод информации
    void display() const;
};

#endif