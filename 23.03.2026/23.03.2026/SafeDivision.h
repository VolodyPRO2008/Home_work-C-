#ifndef SAFE_DIVISION_H
#define SAFE_DIVISION_H

#include "DivisionByZeroException.h"

class SafeDivision {
public:
    // Статический метод деления
    static double divide(double a, double b);
};

#endif