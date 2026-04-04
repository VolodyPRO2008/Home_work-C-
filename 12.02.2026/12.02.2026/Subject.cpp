#define _CRT_SECURE_NO_WARNINGS

#include "Subject.h"

Subject::Subject(const string& n) : name(n) {
    cout << "Создан предмет: " << (name.empty() ? "без названия" : name) << endl;
}

Subject::Subject(const Subject& other) : name(other.name) {
    cout << "Создана копия предмета" << endl;
}

Subject::~Subject() {
    cout << "Уничтожен предмет: " << name << endl;
}

string Subject::getName() const { return name; }
void Subject::setName(const string& n) { name = n; }

void Subject::display() const {
    cout << name;
}