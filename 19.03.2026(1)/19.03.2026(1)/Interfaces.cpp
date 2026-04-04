#define _CRT_SECURE_NO_WARNINGS

#include "Interfaces.h"

// ========== Circle ==========
Circle::Circle(double cx, double cy, double r) : x(cx), y(cy), radius(r) {
    cout << "Создан круг с центром (" << x << ", " << y << ") и радиусом " << radius << endl;
}

Circle::~Circle() {
    cout << "Уничтожен круг" << endl;
}

void Circle::draw() const {
    cout << "Рисую круг в точке (" << x << ", " << y << ") с радиусом " << radius << endl;
}

string Circle::serialize() const {
    stringstream ss;
    ss << "Круг " << x << " " << y << " " << radius;
    return ss.str();
}

// ========== Rectangle ==========
Rectangle::Rectangle(double cx, double cy, double w, double h) : x(cx), y(cy), width(w), height(h) {
    cout << "Создан прямоугольник с углом (" << x << ", " << y << "), шириной " << width << ", высотой " << height << endl;
}

Rectangle::~Rectangle() {
    cout << "Уничтожен прямоугольник" << endl;
}

void Rectangle::draw() const {
    cout << "Рисую прямоугольник в точке (" << x << ", " << y << "), ширина = " << width << ", высота = " << height << endl;
}

string Rectangle::serialize() const {
    stringstream ss;
    ss << "Прямоугольник " << x << " " << y << " " << width << " " << height;
    return ss.str();
}