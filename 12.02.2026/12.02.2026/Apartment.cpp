#define _CRT_SECURE_NO_WARNINGS

#include "Apartment.h"
#include <iomanip>

Apartment::Apartment() {
    cout << "Создана квартира" << endl;
}

Apartment::Apartment(const Apartment& other)
    : rooms(other.rooms), wallpaperTypes(other.wallpaperTypes) {
    cout << "Создана копия квартиры" << endl;
}

Apartment::~Apartment() {
    cout << "Уничтожена квартира" << endl;
}

void Apartment::addRoom(const Room& room) {
    rooms.push_back(room);
}

void Apartment::addRoom(const string& name, double w, double l, double h, bool ceil) {
    rooms.push_back(Room(name, w, l, h, ceil));
}

void Apartment::addWallpaperType(const WallpaperRoll& wp) {
    wallpaperTypes.push_back(wp);
}

void Apartment::addWallpaperType(const string& name, double w, double l, double p) {
    wallpaperTypes.push_back(WallpaperRoll(name, w, l, p));
}

int Apartment::getRoomCount() const { return rooms.size(); }
int Apartment::getWallpaperTypeCount() const { return wallpaperTypes.size(); }

void Apartment::calculateForWallpaperType(int typeIndex) {
    if (typeIndex < 0 || typeIndex >= (int)wallpaperTypes.size()) {
        cout << "Ошибка: неверный индекс типа обоев" << endl;
        return;
    }

    WallpaperRoll& wp = wallpaperTypes[typeIndex];

    cout << "\n--- Расчёт для обоев \"" << wp.getName() << "\" ---" << endl;

    double totalArea = 0;
    for (const auto& room : rooms) {
        totalArea += room.getTotalArea();
    }

    cout << "Общая площадь оклейки: " << fixed << setprecision(2) << totalArea << " кв.м" << endl;

    int rollsNeeded = wp.calculateRolls(totalArea);
    double totalCost = rollsNeeded * wp.getPrice();

    cout << "Необходимое количество рулонов: " << rollsNeeded << endl;
    cout << "Общая стоимость: " << fixed << setprecision(2) << totalCost << " руб." << endl;
}

void Apartment::calculateAll() {
    cout << "\n=========================================" << endl;
    cout << "РАСЧЁТ СТОИМОСТИ ОБОЕВ" << endl;
    cout << "=========================================" << endl;

    for (size_t i = 0; i < wallpaperTypes.size(); i++) {
        calculateForWallpaperType(i);
    }
}

void Apartment::displayRooms() const {
    cout << "\n--- Список комнат ---" << endl;
    for (const auto& room : rooms) {
        room.display();
    }
}

void Apartment::displayWallpaperTypes() const {
    cout << "\n--- Типы обоев ---" << endl;
    for (const auto& wp : wallpaperTypes) {
        wp.display();
    }
}