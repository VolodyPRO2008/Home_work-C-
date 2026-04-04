#include "Airplane.h"

Airplane::Airplane(const string& t, int max, int current)
    : type(t), maxPassengers(max), currentPassengers(current) {
    cout << "Создан самолёт: " << type << " (макс. " << maxPassengers << " пассажиров)" << endl;
}

Airplane::Airplane(const Airplane& other)
    : type(other.type), maxPassengers(other.maxPassengers), currentPassengers(other.currentPassengers) {
    cout << "Создана копия самолёта" << endl;
}

Airplane::~Airplane() {
    cout << "Уничтожен самолёт: " << type << endl;
}

bool Airplane::canAddPassenger() const {
    return currentPassengers < maxPassengers;
}

bool Airplane::canRemovePassenger() const {
    return currentPassengers > 0;
}

bool Airplane::operator==(const Airplane& other) const {
    return type == other.type;
}

bool Airplane::operator>(const Airplane& other) const {
    return maxPassengers > other.maxPassengers;
}

Airplane& Airplane::operator++() {
    if (canAddPassenger()) {
        currentPassengers++;
        cout << "Пассажир добавлен. Текущее количество: " << currentPassengers << endl;
    }
    else {
        cout << "Нет мест! Максимум: " << maxPassengers << endl;
    }
    return *this;
}

Airplane& Airplane::operator--() {
    if (canRemovePassenger()) {
        currentPassengers--;
        cout << "Пассажир удалён. Текущее количество: " << currentPassengers << endl;
    }
    else {
        cout << "Нет пассажиров для удаления!" << endl;
    }
    return *this;
}

Airplane& Airplane::operator=(const Airplane& other) {
    if (this != &other) {
        type = other.type;
        maxPassengers = other.maxPassengers;
        currentPassengers = other.currentPassengers;
    }
    return *this;
}

ostream& operator<<(ostream& output, const Airplane& a) {
    output << "Самолёт \"" << a.type << "\", пассажиров: " << a.currentPassengers
        << "/" << a.maxPassengers;
    return output;
}

istream& operator>>(istream& input, Airplane& a) {
    cout << "Введите тип самолёта: ";
    input >> a.type;
    cout << "Введите максимальное количество пассажиров: ";
    input >> a.maxPassengers;
    cout << "Введите текущее количество пассажиров: ";
    input >> a.currentPassengers;
    return input;
}