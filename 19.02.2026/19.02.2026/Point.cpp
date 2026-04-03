#include "Point.h"

int Point::count = 0;

Point::Point() : x(0), y(0), z(0) {
    count++;
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {
    count++;
}

Point::~Point() {
    count--;
}

void Point::input() {
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите z: ";
    cin >> z;
    cin.ignore();
}

void Point::output() {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

void Point::saveToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << x << " " << y << " " << z;
        file.close();
        cout << "Сохранено в " << filename << endl;
    }
}

void Point::loadFromFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> x >> y >> z;
        file.close();
        cout << "Загружено из " << filename << endl;
    }
}