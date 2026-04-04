#define _CRT_SECURE_NO_WARNINGS

#include "Room.h"

Room::Room(const string& n, double a, int windows)
    : name(n), area(a), windowsCount(windows) {
    cout << "[Комната] Создана: " << name << " (площадь: " << area << " кв.м, окна: " << windowsCount << ")" << endl;
}

Room::Room(const Room& other)
    : name(other.name), area(other.area), windowsCount(other.windowsCount) {
    cout << "[Комната] Создана копия: " << name << endl;
}

Room::~Room() {
    cout << "[Комната] Уничтожена: " << name << endl;
}

string Room::getName() const { return name; }
double Room::getArea() const { return area; }
int Room::getWindowsCount() const { return windowsCount; }

void Room::setName(const string& n) { name = n; }
void Room::setArea(double a) { area = a; }
void Room::setWindowsCount(int windows) { windowsCount = windows; }

void Room::print() const {
    cout << "Комната \"" << name << "\": площадь " << area << " кв.м, окон: " << windowsCount << endl;
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        name = other.name;
        area = other.area;
        windowsCount = other.windowsCount;
    }
    return *this;
}