#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H

#include <iostream>
#include <cmath>

using namespace std;

// ЗАДАНИЕ 1: Шаблон для поиска среднего арифметического

template<typename T>
double arrayAverage(const T* arr, int size) {
    if (size <= 0) return 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}


// ЗАДАНИЕ 2: Перегруженные шаблоны для корней уравнений


// Линейное уравнение a*x + b = 0
template<typename T>
bool solveLinear(T a, T b, double& root) {
    if (a == 0) {
        if (b == 0) {
            cout << "Бесконечное количество решений" << endl;
            return false;
        }
        else {
            cout << "Нет решений" << endl;
            return false;
        }
    }
    root = -static_cast<double>(b) / a;
    return true;
}

// Квадратное уравнение a*x^2 + b*x + c = 0
template<typename T>
int solveQuadratic(T a, T b, T c, double& root1, double& root2) {
    if (a == 0) {
        // Вырождается в линейное
        double root;
        if (solveLinear(b, c, root)) {
            root1 = root;
            return 1;
        }
        return 0;
    }

    double discriminant = static_cast<double>(b * b - 4 * a * c);

    if (discriminant < 0) {
        cout << "Нет действительных корней" << endl;
        return 0;
    }
    else if (discriminant == 0) {
        root1 = -static_cast<double>(b) / (2 * a);
        cout << "Один корень (дискриминант = 0)" << endl;
        return 1;
    }
    else {
        root1 = (-static_cast<double>(b) - sqrt(discriminant)) / (2 * a);
        root2 = (-static_cast<double>(b) + sqrt(discriminant)) / (2 * a);
        cout << "Два корня (дискриминант > 0)" << endl;
        return 2;
    }
}


// ЗАДАНИЕ 3: Шаблон для максимума из двух

template<typename T>
T maxOfTwo(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// ЗАДАНИЕ 4: Шаблон для минимума из двух

template<typename T>
T minOfTwo(const T& a, const T& b) {
    return (a < b) ? a : b;
}

#endif