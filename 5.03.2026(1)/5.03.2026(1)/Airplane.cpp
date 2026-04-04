#define _CRT_SECURE_NO_WARNINGS

#include "Airplane.h"

// Конструктор с параметрами
Airplane::Airplane(const string& t, int max, int current)
    : type(t), maxPassengers(max), currentPassengers(current) {
    if (currentPassengers > maxPassengers) {
        currentPassengers = maxPassengers;
    }
    if (currentPassengers < 0) {
        currentPassengers = 0;
    }
    cout << "[Самолёт] Создан самолёт: " << type
        << " (вместимость: " << maxPassengers
        << ", пассажиров: " << currentPassengers << ")" << endl;
}

// Конструктор копирования
Airplane::Airplane(const Airplane& other)
    : type(other.type), maxPassengers(other.maxPassengers),
    currentPassengers(other.currentPassengers) {
    cout << "[Самолёт] Создана КОПИЯ самолёта: " << type << endl;
}

// Деструктор
Airplane::~Airplane() {
    cout << "[Самолёт] Уничтожен самолёт: " << type << endl;
}

// Геттеры
string Airplane::getType() const {
    return type;
}

int Airplane::getCurrentPassengers() const {
    return currentPassengers;
}

int Airplane::getMaxPassengers() const {
    return maxPassengers;
}

// Сеттеры
void Airplane::setType(const string& t) {
    type = t;
}

void Airplane::setCurrentPassengers(int count) {
    if (count > maxPassengers) {
        currentPassengers = maxPassengers;
    }
    else if (count < 0) {
        currentPassengers = 0;
    }
    else {
        currentPassengers = count;
    }
}

void Airplane::setMaxPassengers(int max) {
    maxPassengers = max;
    if (currentPassengers > maxPassengers) {
        currentPassengers = maxPassengers;
    }
}

// Оператор равенства типов (==)
bool Airplane::operator==(const Airplane& other) const {
    return type == other.type;
}

// Оператор сравнения по максимальному количеству пассажиров (>)
bool Airplane::operator>(const Airplane& other) const {
    return maxPassengers > other.maxPassengers;
}

// Оператор сравнения по максимальному количеству пассажиров (<)
bool Airplane::operator<(const Airplane& other) const {
    return maxPassengers < other.maxPassengers;
}

// Оператор неравенства
bool Airplane::operator!=(const Airplane& other) const {
    return !(*this == other);
}

// Префиксный инкремент (++airplane) - увеличение пассажиров
Airplane& Airplane::operator++() {
    if (currentPassengers < maxPassengers) {
        currentPassengers++;
        cout << "[Самолёт] ++" << type << ": пассажиров стало "
            << currentPassengers << " (+1)" << endl;
    }
    else {
        cout << "[Самолёт] ++" << type << ": мест нет! Максимум "
            << maxPassengers << " пассажиров" << endl;
    }
    return *this;
}

// Префиксный декремент (--airplane) - уменьшение пассажиров
Airplane& Airplane::operator--() {
    if (currentPassengers > 0) {
        currentPassengers--;
        cout << "[Самолёт] --" << type << ": пассажиров стало "
            << currentPassengers << " (-1)" << endl;
    }
    else {
        cout << "[Самолёт] --" << type << ": пассажиров нет!" << endl;
    }
    return *this;
}

// Оператор присваивания
Airplane& Airplane::operator=(const Airplane& other) {
    if (this == &other) return *this;

    type = other.type;
    maxPassengers = other.maxPassengers;
    currentPassengers = other.currentPassengers;

    cout << "[Самолёт] Оператор присваивания: " << type << endl;
    return *this;
}

// Оператор вывода (<<)
ostream& operator<<(ostream& output, const Airplane& a) {
    output << "Самолёт \"" << a.type << "\": пассажиров "
        << a.currentPassengers << "/" << a.maxPassengers;
    return output;
}

// Оператор ввода (>>)
istream& operator>>(istream& input, Airplane& a) {
    cout << "Введите тип самолёта: ";
    input >> a.type;
    cout << "Введите максимальное количество пассажиров: ";
    input >> a.maxPassengers;
    cout << "Введите текущее количество пассажиров: ";
    input >> a.currentPassengers;

    if (a.currentPassengers > a.maxPassengers) {
        a.currentPassengers = a.maxPassengers;
    }
    if (a.currentPassengers < 0) {
        a.currentPassengers = 0;
    }
    return input;
}