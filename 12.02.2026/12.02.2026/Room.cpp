#define _CRT_SECURE_NO_WARNINGS

#include "Room.h"

Room::Room(const string& n, double w, double l, double h, bool ceil)
    : name(n), width(w), length(l), height(h), glueCeiling(ceil) {
    cout << "Создана комната: " << name << endl;
}

Room::Room(const Room& other)
    : name(other.name), width(other.width), length(other.length),
    height(other.height), glueCeiling(other.glueCeiling) {
    cout << "Создана копия комнаты" << endl;
}

Room::~Room() {
    cout << "Уничтожена комната: " << name << endl;
}

string Room::getName() const { return name; }
double Room::getWidth() const { return width; }
double Room::getLength() const { return length; }
double Room::getHeight() const { return height; }
bool Room::getGlueCeiling() const { return glueCeiling; }

void Room::setName(const string& n) { name = n; }
void Room::setDimensions(double w, double l, double h) {
    width = w;
    length = l;
    height = h;
}
void Room::setGlueCeiling(bool ceil) { glueCeiling = ceil; }

double Room::getWallArea() const {
    // Площадь стен = периметр * высота
    double perimeter = 2 * (width + length);
    return perimeter * height;
}

double Room::getCeilingArea() const {
    return width * length;
}

double Room::getTotalArea() const {
    double area = getWallArea();
    if (glueCeiling) {
        area += getCeilingArea();
    }
    return area;
}

void Room::display() const {
    cout << "Комната \"" << name << "\": "
        << width << "x" << length << "x" << height
        << ", клеить потолок: " << (glueCeiling ? "да" : "нет")
        << ", площадь оклейки: " << getTotalArea() << " кв.м" << endl;
}