#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string name;
    double width;      // Ширина (м)
    double height;     // Высота (м)
    double length;     // Длина (м)
    bool glueCeiling;  // Клеить потолок?

public:
    Room(const string& n = "", double w = 0, double l = 0, double h = 0, bool ceil = false);
    Room(const Room& other);
    ~Room();

    // Геттеры
    string getName() const;
    double getWidth() const;
    double getLength() const;
    double getHeight() const;
    bool getGlueCeiling() const;

    // Сеттеры
    void setName(const string& n);
    void setDimensions(double w, double l, double h);
    void setGlueCeiling(bool ceil);

    // Вычисление площади стен
    double getWallArea() const;

    // Вычисление площади потолка (если нужно)
    double getCeilingArea() const;

    // Общая площадь для оклейки
    double getTotalArea() const;

    void display() const;
};

#endif