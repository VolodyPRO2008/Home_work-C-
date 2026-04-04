#include "Circle.h"

Circle::Circle(double r) : radius(r) {
    cout << "Создана окружность с радиусом " << radius << endl;
}

Circle::Circle(const Circle& other) : radius(other.radius) {
    cout << "Создана копия окружности" << endl;
}

Circle::~Circle() {
    cout << "Уничтожена окружность с радиусом " << radius << endl;
}

double Circle::getLength() const {
    return 2 * 3.14159 * radius;
}

bool Circle::operator==(const Circle& other) const {
    return radius == other.radius;
}

bool Circle::operator>(const Circle& other) const {
    return getLength() > other.getLength();
}

Circle& Circle::operator+=(double value) {
    radius += value;
    cout << "Радиус увеличен на " << value << ", новый радиус = " << radius << endl;
    return *this;
}

Circle& Circle::operator-=(double value) {
    radius -= value;
    cout << "Радиус уменьшен на " << value << ", новый радиус = " << radius << endl;
    return *this;
}

Circle Circle::operator+(double value) const {
    Circle result(*this);
    result += value;
    return result;
}

Circle Circle::operator-(double value) const {
    Circle result(*this);
    result -= value;
    return result;
}

ostream& operator<<(ostream& output, const Circle& c) {
    output << "Окружность (радиус = " << c.radius << ", длина = " << c.getLength() << ")";
    return output;
}

istream& operator>>(istream& input, Circle& c) {
    cout << "Введите радиус окружности: ";
    input >> c.radius;
    return input;
}