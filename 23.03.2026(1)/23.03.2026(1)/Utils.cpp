#include "Utils.h"
#include <iostream>

namespace {
    // Анонимное пространство имён
    int counter = 0;

    void normalize(double& value) {
        counter++;
        if (value < 0) value = 0;
        if (value > 1) value = 1;
    }

    // Для демонстрации работы counter
    int getCounter() {
        return counter;
    }
}

namespace Utils {
    double clamp(double val, double min, double max) {
        // Используем normalize для внутренней логики
        if (val < min) val = min;
        if (val > max) val = max;

        // Нормализуем значение в диапазон [0,1] для демонстрации
        double normalized = val;
        ::normalize(normalized); // Вызов функции из анонимного пространства

        return val;
    }
}

// Функция для демонстрации counter из main
int getNormalizeCounter() {
    return getCounter();
}