#ifndef WALLPAPER_ROLL_H
#define WALLPAPER_ROLL_H

#include <iostream>
#include <string>

using namespace std;

class WallpaperRoll {
private:
    string name;
    double width;      // Ширина рулона (м)
    double length;     // Длина рулона (м)
    double price;      // Цена за рулон

public:
    WallpaperRoll(const string& n = "", double w = 0, double l = 0, double p = 0);
    WallpaperRoll(const WallpaperRoll& other);
    ~WallpaperRoll();

    // Геттеры
    string getName() const;
    double getWidth() const;
    double getLength() const;
    double getPrice() const;

    // Сеттеры
    void setName(const string& n);
    void setDimensions(double w, double l);
    void setPrice(double p);

    // Вычисление площади одного рулона
    double getArea() const;

    // Вычисление количества рулонов для заданной площади
    int calculateRolls(double area) const;

    void display() const;
};

#endif