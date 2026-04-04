#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"

// Инициализация статического поля
int Vehicle::totalVehicles = 0;

// Конструктор с параметрами
Vehicle::Vehicle(const string& m, int y, const Point& pos)
    : model(m), year(y), position(pos) {
    totalVehicles++;
    cout << "[Vehicle] Создано ТС: " << model << ", " << year << " г., позиция " << position
        << " (всего: " << totalVehicles << ")" << endl;
}

// Конструктор копирования
Vehicle::Vehicle(const Vehicle& other)
    : model(other.model), year(other.year), position(other.position) {
    totalVehicles++;
    cout << "[Vehicle] Создана копия ТС: " << model << " (всего: " << totalVehicles << ")" << endl;
}

// Виртуальный деструктор
Vehicle::~Vehicle() {
    totalVehicles--;
    cout << "[Vehicle] Уничтожено ТС: " << model << " (осталось: " << totalVehicles << ")" << endl;
}

// explicit конструктор от строки (должен быть определён ЗДЕСЬ, а не в классе)
Vehicle::Vehicle(const string& m) : model(m), year(2020), position(Point(0, 0)) {
    totalVehicles++;
    cout << "[Vehicle] explicit конструктор: создано ТС " << model << " (год по умолчанию: 2020)" << endl;
}

// Статический метод
int Vehicle::getTotalVehicles() {
    return totalVehicles;
}

// Перемещение
void Vehicle::move(const Point& newPos) {
    cout << "[Vehicle] " << model << " перемещается из " << position << " в " << newPos << endl;
    position = newPos;
}

string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

Point Vehicle::getPosition() const {
    return position;
}