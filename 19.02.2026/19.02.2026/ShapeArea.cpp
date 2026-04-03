#include "ShapeArea.h"

int ShapeArea::count = 0;

double ShapeArea::triangleHeron(double a, double b, double c) {
    count++;
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double ShapeArea::triangleBaseHeight(double base, double h) {
    count++;
    return 0.5 * base * h;
}

double ShapeArea::rectangle(double a, double b) {
    count++;
    return a * b;
}

double ShapeArea::square(double a) {
    count++;
    return a * a;
}

double ShapeArea::rhombus(double d1, double d2) {
    count++;
    return (d1 * d2) / 2;
}