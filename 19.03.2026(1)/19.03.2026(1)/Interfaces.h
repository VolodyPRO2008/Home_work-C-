#ifndef INTERFACES_H
#define INTERFACES_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// ========== Интерфейс Drawable ==========
class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

// ========== Интерфейс Serializable ==========
class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() = default;
};

// ========== Класс Circle (наследует оба интерфейса) ==========
class Circle : public Drawable, public Serializable {
private:
    double x, y;      // Координаты центра
    double radius;

public:
    Circle(double cx, double cy, double r);
    ~Circle();

    void draw() const override;
    string serialize() const override;
};

// ========== Класс Rectangle (наследует оба интерфейса) ==========
class Rectangle : public Drawable, public Serializable {
private:
    double x, y;      // Координаты левого верхнего угла
    double width;
    double height;

public:
    Rectangle(double cx, double cy, double w, double h);
    ~Rectangle();

    void draw() const override;
    string serialize() const override;
};

#endif