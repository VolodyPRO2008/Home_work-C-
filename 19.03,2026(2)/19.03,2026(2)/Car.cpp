#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"

// Конструктор с параметрами (список инициализации)
Car::Car(const string& m, int y, const Point& pos, int d)
    : Vehicle(m, y, pos), doors(d) {
    cout << "[Car] Создан автомобиль " << m << ", дверей: " << doors << endl;
}

// Конструктор копирования
Car::Car(const Car& other) : Vehicle(other), doors(other.doors) {
    cout << "[Car] Создана копия автомобиля " << model << endl;
}

// Деструктор
Car::~Car() {
    cout << "[Car] Уничтожен автомобиль " << model << endl;
}

// Максимальная скорость
double Car::getMaxSpeed() const {
    return 180.0;
}

// Вывод информации
void Car::print() const {
    cout << "Автомобиль: " << model << ", " << year << " г.в., позиция: " << position
        << ", дверей: " << doors << ", макс. скорость: " << getMaxSpeed() << " км/ч" << endl;
}

// Префиксный инкремент (++car)
Car& Car::operator++() {
    doors++;
    cout << "[Car] ++" << model << ": дверей стало " << doors << endl;
    return *this;
}

// Постфиксный инкремент (car++)
Car Car::operator++(int) {
    Car temp(*this);
    doors++;
    cout << "[Car] " << model << "++: дверей стало " << doors << endl;
    return temp;
}

int Car::getDoors() const {
    return doors;
}