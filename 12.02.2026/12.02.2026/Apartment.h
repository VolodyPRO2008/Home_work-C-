#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <vector>
#include "Room.h"
#include "WallpaperRoll.h"

using namespace std;

class Apartment {
private:
    vector<Room> rooms;
    vector<WallpaperRoll> wallpaperTypes;

public:
    Apartment();
    Apartment(const Apartment& other);
    ~Apartment();

    // Добавление комнаты
    void addRoom(const Room& room);
    void addRoom(const string& name, double w, double l, double h, bool ceil);

    // Добавление типа обоев
    void addWallpaperType(const WallpaperRoll& wp);
    void addWallpaperType(const string& name, double w, double l, double p);

    // Получение данных
    int getRoomCount() const;
    int getWallpaperTypeCount() const;

    // Расчёт для каждого типа обоев
    void calculateForWallpaperType(int typeIndex);
    void calculateAll();

    // Вывод информации
    void displayRooms() const;
    void displayWallpaperTypes() const;
};

#endif