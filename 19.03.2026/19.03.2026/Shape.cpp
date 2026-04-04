#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"

const double PI = 3.141592653589793;


Circle::Circle(double r) : radius(r) {
    if (radius < 0) radius = 0;
    cout << "Создан круг с радиусом " << radius << endl;
}

Circle::~Circle() {
    cout << "Уничтожен круг с радиусом " << radius << endl;
}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::printInfo() const {
    cout << "Круг (радиус = " << radius << ")" << endl;
}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    if (width < 0) width = 0;
    if (height < 0) height = 0;
    cout << "Создан прямоугольник " << width << "x" << height << endl;
}

Rectangle::~Rectangle() {
    cout << "Уничтожен прямоугольник " << width << "x" << height << endl;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::printInfo() const {
    cout << "Прямоугольник (ширина = " << width << ", высота = " << height << ")" << endl;
}


Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
    if (!isValid()) {
        cout << "Предупреждение: треугольник со сторонами " << a << ", " << b << ", " << c << " не существует!" << endl;
        sideA = sideB = sideC = 0;
    }
    cout << "Создан треугольник со сторонами " << sideA << ", " << sideB << ", " << sideC << endl;
}

Triangle::~Triangle() {
    cout << "Уничтожен треугольник со сторонами " << sideA << ", " << sideB << ", " << sideC << endl;
}

bool Triangle::isValid() const {
    return (sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA);
}

double Triangle::area() const {
    if (!isValid()) return 0;
    double p = perimeter() / 2;  // Полупериметр
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double Triangle::perimeter() const {
    return sideA + sideB + sideC;
}

void Triangle::printInfo() const {
    cout << "Треугольник (стороны = " << sideA << ", " << sideB << ", " << sideC << ")" << endl;
}