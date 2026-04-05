#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

// Базовый класс Shape
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual std::string getType() const = 0;
};

// Производный класс Circle
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r);
    void draw() const override;
    std::string getType() const override;
    double getRadius() const;
};

// Производный класс Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    void draw() const override;
    std::string getType() const override;
    double getWidth() const;
    double getHeight() const;
};

#endif