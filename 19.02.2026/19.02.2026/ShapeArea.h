#pragma once
#include "include.h"

class ShapeArea {
private:
    static int count;

public:
    static double triangleHeron(double a, double b, double c);
    static double triangleBaseHeight(double base, double h);
    static double rectangle(double a, double b);
    static double square(double a);
    static double rhombus(double d1, double d2);

    static int getCount() { return count; }
    static void resetCount() { count = 0; }
};