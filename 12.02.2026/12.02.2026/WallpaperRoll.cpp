#define _CRT_SECURE_NO_WARNINGS

#include "WallpaperRoll.h"
#include <cmath>

WallpaperRoll::WallpaperRoll(const string& n, double w, double l, double p)
    : name(n), width(w), length(l), price(p) {
    cout << "Создан рулон обоев: " << name << endl;
}

WallpaperRoll::WallpaperRoll(const WallpaperRoll& other)
    : name(other.name), width(other.width), length(other.length), price(other.price) {
    cout << "Создана копия рулона обоев" << endl;
}

WallpaperRoll::~WallpaperRoll() {
    cout << "Уничтожен рулон обоев: " << name << endl;
}

string WallpaperRoll::getName() const { return name; }
double WallpaperRoll::getWidth() const { return width; }
double WallpaperRoll::getLength() const { return length; }
double WallpaperRoll::getPrice() const { return price; }

void WallpaperRoll::setName(const string& n) { name = n; }
void WallpaperRoll::setDimensions(double w, double l) {
    width = w;
    length = l;
}
void WallpaperRoll::setPrice(double p) { price = p; }

double WallpaperRoll::getArea() const {
    return width * length;
}

int WallpaperRoll::calculateRolls(double area) const {
    double rollArea = getArea();
    if (rollArea <= 0) return 0;
    return static_cast<int>(ceil(area / rollArea));
}

void WallpaperRoll::display() const {
    cout << "Рулон \"" << name << "\": "
        << width << "м x " << length << "м, площадь: "
        << getArea() << " кв.м, цена: " << price << " руб." << endl;
}