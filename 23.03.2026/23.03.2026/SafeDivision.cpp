#define _CRT_SECURE_NO_WARNINGS

#include "SafeDivision.h"

double SafeDivision::divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException("Ошибка: деление на ноль невозможно!");
    }
    return a / b;
}