#define _CRT_SECURE_NO_WARNINGS

#include "Circle.h"

const double PI = 3.141592653589793;

// Конструктор с параметром
Circle::Circle(double r) : radius(r) {
    cout << "[Окружность] Создана окружность с радиусом " << radius << endl;
}

// Конструктор копирования
Circle::Circle(const Circle& other) : radius(other.radius) {
    cout << "[Окружность] Создана копия окружности с радиусом " << radius << endl;
}

// Деструктор
Circle::~Circle() {
    cout << "[Окружность] Уничтожена окружность с радиусом " << radius << endl;
}

// Получение радиуса
double Circle::getRadius() const {
    return radius;
}

// Получение длины окружности
double Circle::getLength() const {
    return 2 * PI * radius;
}

// Установка радиуса
void Circle::setRadius(double r) {
    radius = r;
}

// Оператор сравнения радиусов (==)
bool Circle::operator==(const Circle& other) const {
    return radius == other.radius;
}

// Оператор сравнения длин окружностей (>)
bool Circle::operator>(const Circle& other) const {
    return getLength() > other.getLength();
}

// Оператор сравнения длин окружностей (<)
bool Circle::operator<(const Circle& other) const {
    return getLength() < other.getLength();
}

// Оператор неравенства
bool Circle::operator!=(const Circle& other) const {
    return !(*this == other);
}

// Оператор увеличения радиуса (+=)
Circle& Circle::operator+=(double value) {
    radius += value;
    cout << "[Окружность] Радиус увеличен на " << value
        << ", новый радиус = " << radius << endl;
    return *this;
}

// Оператор уменьшения радиуса (-=)
Circle& Circle::operator-=(double value) {
    radius -= value;
    if (radius < 0) radius = 0;
    cout << "[Окружность] Радиус уменьшен на " << value
        << ", новый радиус = " << radius << endl;
    return *this;
}

// Оператор сложения (создаёт новую окружность)
Circle Circle::operator+(double value) const {
    Circle result(*this);
    result += value;
    return result;
}

// Оператор вычитания (создаёт новую окружность)
Circle Circle::operator-(double value) const {
    Circle result(*this);
    result -= value;
    return result;
}

// Оператор вывода (<<)
ostream& operator<<(ostream& output, const Circle& c) {
    output << "Окружность (радиус = " << c.radius
        << ", длина = " << c.getLength() << ")";
    return output;
}

// Оператор ввода (>>)
istream& operator>>(istream& input, Circle& c) {
    cout << "Введите радиус окружности: ";
    input >> c.radius;
    if (c.radius < 0) c.radius = 0;
    return input;
}