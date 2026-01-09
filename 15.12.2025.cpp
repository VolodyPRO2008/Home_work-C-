#include <iostream>
using namespace std;
// Вычисление квадратного корня методом Ньютона
double m_sqrt(double v) {
    if (v <= 0) return 0;
    double x = v, p;
    do {
        p = x;
        x = 0.5 * (x + v / x);
    } while (p - x > 1e-10 || x - p > 1e-10);
    return x;
}

// Вычисление синуса через ряд Тейлора
double m_sin(double v) {
    double r = v, t = v, v2 = v * v;
    int s = 1;
    for (int i = 3; i < 20; i += 2) {
        t *= -v2 / ((i - 1) * i);
        r += t;
    }
    return r;
}

// Вычисление степени
double m_pow(double b, int e) {
    double r = 1;
    for (int i = 0; i < e; ++i) r *= b;
    return r;
}

// Главная функция
int main() {
    const int n = 10;
    double x[n], y[n];
    double* px = x;
    double* py = y;

    for (int i = 0; i < n; ++i) {
        *(px + i) = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        double v = *(px + i);
        if (v < 5) {
            *(py + i) = m_pow(v, 2) + m_sin(v);
        }
        else if (v <= 10) {
            *(py + i) = m_sqrt(v - 4);
        }
        else {
            *(py + i) = 3 * v;
        }
    }

    cout << "X:\tY:\n";
    for (int i = 0; i < n; ++i) {
        cout << *(px + i) << "\t" << *(py + i) << "\n";
    }

    return 0;
}