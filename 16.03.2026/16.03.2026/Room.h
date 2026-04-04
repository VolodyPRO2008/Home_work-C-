#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string name;
    double area;
    int windowsCount;

public:
    Room(const string& n = "Комната", double a = 0.0, int windows = 0);
    Room(const Room& other);
    ~Room();

    string getName() const;
    double getArea() const;
    int getWindowsCount() const;

    void setName(const string& n);
    void setArea(double a);
    void setWindowsCount(int windows);

    void print() const;

    Room& operator=(const Room& other);
};

#endif