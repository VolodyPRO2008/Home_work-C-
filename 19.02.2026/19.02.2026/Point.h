#pragma once
#include "include.h"

class Point {
private:
    double x, y, z;
    static int count;

public:
    Point();
    Point(double x, double y, double z);
    ~Point();

    inline double getX() { return x; }
    inline double getY() { return y; }
    inline double getZ() { return z; }

    inline void setX(double val) { x = val; }
    inline void setY(double val) { y = val; }
    inline void setZ(double val) { z = val; }

    void input();
    void output();
    void saveToFile(string filename);
    void loadFromFile(string filename);

    static int getCount() { return count; }
};