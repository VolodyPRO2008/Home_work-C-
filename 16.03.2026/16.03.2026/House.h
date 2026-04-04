#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

class House {
private:
    string address;
    vector<Room> rooms;  // Композиция: вектор хранит объекты Room по значению

public:
    House(const string& addr = "Не указан");
    House(const House& other);
    ~House();

    void addRoom(const string& name, double area, int windows);
    void addRoom(const Room& room);
    void removeRoom(int index);
    int getRoomCount() const;
    Room& getRoom(int index);
    const Room& getRoom(int index) const;

    void print() const;

    House& operator=(const House& other);
};

#endif