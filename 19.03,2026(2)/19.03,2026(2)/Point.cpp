#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include <cmath>

// Инициализация статического поля
int Point::pointCount = 0;

// Конструктор по умолчанию
Point::Point() : x(0.0), y(0.0) {
    pointCount++;
    cout << "[Point] Создана точка (" << x << "; " << y << ") (всего: " << pointCount << ")" << endl;
}

// Конструктор с параметрами (список инициализации)
Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {
    pointCount++;
    cout << "[Point] Создана точка (" << x << "; " << y << ") (всего: " << pointCount << ")" << endl;
}

// Конструктор копирования
Point::Point(const Point& other) : x(other.x), y(other.y) {
    pointCount++;
    cout << "[Point] Создана копия точки (" << x << "; " << y << ") (всего: " << pointCount << ")" << endl;
}

// Деструктор
Point::~Point() {
    pointCount--;
    cout << "[Point] Уничтожена точка (" << x << "; " << y << ") (осталось: " << pointCount << ")" << endl;
}

// Геттер X
double Point::getX() const {
    return x;
}

// Геттер Y
double Point::getY() const {
    return y;
}

// Расстояние от начала координат
double Point::distance() const {
    return sqrt(x * x + y * y);
}

// Статический метод
int Point::getPointCount() {
    return pointCount;
}

// Оператор равенства
bool Point::operator==(const Point& other) const {
    return (x == other.x && y == other.y);
}

// Оператор неравенства
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

// Оператор вывода
ostream& operator<<(ostream& output, const Point& p) {
    output << "(" << p.x << "; " << p.y << ")";
    return output;
}

// Оператор ввода
istream& operator>>(istream& input, Point& p) {
    cout << "Введите координату x: ";
    input >> p.x;
    cout << "Введите координату y: ";
    input >> p.y;
    return input;
}