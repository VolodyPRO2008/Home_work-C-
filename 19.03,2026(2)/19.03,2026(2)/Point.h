#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    double x;
    double y;
    static int pointCount;  // Статический счётчик созданных объектов

public:
    // Конструктор по умолчанию (инициализирует нулями)
    Point();

    // Конструктор с параметрами (список инициализации)
    Point(double xCoord, double yCoord);

    // Конструктор копирования
    Point(const Point& other);

    // Деструктор
    ~Point();

    // Геттеры (константные методы)
    double getX() const;
    double getY() const;

    // Расстояние от начала координат
    double distance() const;

    // Статический метод для получения количества точек
    static int getPointCount();

    // Операторы сравнения
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    // Операторы ввода-вывода
    friend ostream& operator<<(ostream& output, const Point& p);
    friend istream& operator>>(istream& input, Point& p);
};

#endif