#define _CRT_SECURE_NO_WARNINGS

#include "Elevator.h"

Elevator::Elevator(int min, int max) {
    if (min < max) {
        minFloor = min;
        maxFloor = max;
    }
    else {
        minFloor = 1;
        maxFloor = 10;
    }
    currentFloor = minFloor;
    isWorking = true;
    cout << "Создан лифт (этажи: " << minFloor << "-" << maxFloor << ")" << endl;
}

Elevator::Elevator(const Elevator& other) {
    minFloor = other.minFloor;
    maxFloor = other.maxFloor;
    currentFloor = other.currentFloor;
    isWorking = other.isWorking;
    cout << "Создана копия лифта" << endl;
}

Elevator::~Elevator() {
    cout << "Лифт уничтожен" << endl;
}

void Elevator::setRange(int min, int max) {
    if (min < max) {
        minFloor = min;
        maxFloor = max;
        if (currentFloor < minFloor) currentFloor = minFloor;
        if (currentFloor > maxFloor) currentFloor = maxFloor;
        cout << "Установлен диапазон этажей: " << minFloor << "-" << maxFloor << endl;
    }
    else {
        cout << "Ошибка: нижний этаж должен быть меньше верхнего" << endl;
    }
}

void Elevator::turnOn() {
    isWorking = true;
    cout << "Лифт включён" << endl;
}

void Elevator::turnOff() {
    isWorking = false;
    cout << "Лифт выключен" << endl;
}

bool Elevator::getIsWorking() const {
    return isWorking;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getMinFloor() const {
    return minFloor;
}

int Elevator::getMaxFloor() const {
    return maxFloor;
}

bool Elevator::call(int floor) {
    if (!isWorking) {
        cout << "Лифт не работает!" << endl;
        return false;
    }

    if (floor < minFloor || floor > maxFloor) {
        cout << "Ошибка: этаж " << floor << " вне диапазона ("
            << minFloor << "-" << maxFloor << ")" << endl;
        return false;
    }

    if (floor == currentFloor) {
        cout << "Лифт уже на этаже " << floor << endl;
        return true;
    }

    cout << "Лифт едет с " << currentFloor << " этажа на " << floor << " этаж...";
    currentFloor = floor;
    cout << " прибыл" << endl;
    return true;
}

void Elevator::display() const {
    cout << "=== Состояние лифта ===" << endl;
    cout << "Диапазон этажей: " << minFloor << "-" << maxFloor << endl;
    cout << "Текущий этаж: " << currentFloor << endl;
    cout << "Состояние: " << (isWorking ? "РАБОТАЕТ" : "НЕ РАБОТАЕТ") << endl;
}