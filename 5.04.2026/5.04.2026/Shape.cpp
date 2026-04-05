#include "Shape.h"
#include <iostream>

// Реализация Circle
Circle::Circle(double r) : radius(r) {}

void Circle::draw() const {
    std::cout << "Рисую круг радиусом " << radius << std::endl;
}

std::string Circle::getType() const {
    return "Круг";
}

double Circle::getRadius() const {
    return radius;
}

// Реализация Rectangle
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

void Rectangle::draw() const {
    std::cout << "Рисую прямоугольник " << width << " x " << height << std::endl;
}

std::string Rectangle::getType() const {
    return "Прямоугольник";
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}