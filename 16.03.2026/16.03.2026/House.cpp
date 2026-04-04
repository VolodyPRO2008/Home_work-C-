#define _CRT_SECURE_NO_WARNINGS

#include "House.h"

House::House(const string& addr) : address(addr) {
    cout << "[Дом] Создан дом по адресу: " << address << endl;
}

// Конструктор копирования - глубокое копирование (композиция)
House::House(const House& other) : address(other.address), rooms(other.rooms) {
    cout << "[Дом] Создана копия дома по адресу: " << address << endl;
}

House::~House() {
    cout << "[Дом] Уничтожен дом по адресу: " << address << endl;
    // rooms уничтожатся автоматически (композиция)
}

void House::addRoom(const string& name, double area, int windows) {
    rooms.push_back(Room(name, area, windows));
    cout << "[Дом] В дом добавлена комната: " << name << endl;
}

void House::addRoom(const Room& room) {
    rooms.push_back(room);
    cout << "[Дом] В дом добавлена комната: " << room.getName() << endl;
}

void House::removeRoom(int index) {
    if (index >= 0 && index < (int)rooms.size()) {
        cout << "[Дом] Удаляется комната: " << rooms[index].getName() << endl;
        rooms.erase(rooms.begin() + index);
    }
    else {
        cout << "Ошибка: неверный индекс комнаты" << endl;
    }
}

int House::getRoomCount() const {
    return rooms.size();
}

Room& House::getRoom(int index) {
    return rooms[index];
}

const Room& House::getRoom(int index) const {
    return rooms[index];
}

void House::print() const {
    cout << "\n=== ДОМ по адресу: " << address << " ===" << endl;
    cout << "Количество комнат: " << rooms.size() << endl;
    for (size_t i = 0; i < rooms.size(); i++) {
        cout << "  " << i + 1 << ". ";
        rooms[i].print();
    }
}

House& House::operator=(const House& other) {
    if (this != &other) {
        address = other.address;
        rooms = other.rooms;
    }
    return *this;
}