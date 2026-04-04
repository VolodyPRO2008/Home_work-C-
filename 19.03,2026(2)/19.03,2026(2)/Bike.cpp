#define _CRT_SECURE_NO_WARNINGS

#include "Bike.h"

// Конструктор с параметрами (список инициализации)
Bike::Bike(const string& m, int y, const Point& pos, const string& t)
    : Vehicle(m, y, pos), type(t) {
    cout << "[Bike] Создан велосипед " << m << ", тип: " << type << endl;
}

// Конструктор копирования
Bike::Bike(const Bike& other) : Vehicle(other), type(other.type) {
    cout << "[Bike] Создана копия велосипеда " << model << endl;
}

// Деструктор
Bike::~Bike() {
    cout << "[Bike] Уничтожен велосипед " << model << endl;
}

// Максимальная скорость
double Bike::getMaxSpeed() const {
    if (type == "sport") return 60.0;
    if (type == "mountain") return 45.0;
    return 30.0;
}

// Вывод информации
void Bike::print() const {
    cout << "Велосипед: " << model << ", " << year << " г.в., позиция: " << position
        << ", тип: " << type << ", макс. скорость: " << getMaxSpeed() << " км/ч" << endl;
}

string Bike::getType() const {
    return type;
}