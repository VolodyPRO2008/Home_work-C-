#define _CRT_SECURE_NO_WARNINGS

#include "Person.h"

int Person::totalCount = 0;

void Person::copyString(char*& dest, const char* src) {
    if (src != nullptr) {
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    }
    else {
        dest = nullptr;
    }
}

void Person::freeMemory() {
    delete[] lastName;
    delete[] firstName;
    delete[] patronymic;
    lastName = nullptr;
    firstName = nullptr;
    patronymic = nullptr;
}

void Person::copyFrom(const Person& other) {
    id = other.id;
    birthDate = other.birthDate;
    copyString(lastName, other.lastName);
    copyString(firstName, other.firstName);
    copyString(patronymic, other.patronymic);
}

Person::Person(int idP, const char* lastP, const char* firstP, const char* patronP, const Date& birth)
    : id(idP), birthDate(birth) {
    copyString(lastName, lastP);
    copyString(firstName, firstP);
    copyString(patronymic, patronP);
    totalCount++;
    cout << "[Человек] Создан человек: " << (lastName ? lastName : "") << " "
        << (firstName ? firstName : "") << " (ID: " << id << ")" << endl;
}

Person::Person() : Person(0, nullptr, nullptr, nullptr, Date()) {}

// ПРАВИЛЬНЫЙ конструктор копирования
Person::Person(const Person& other) {
    copyFrom(other);
    totalCount++;
    cout << "[Человек] Создана КОПИЯ человека: " << (lastName ? lastName : "") << endl;
}

// ПРАВИЛЬНЫЙ деструктор
Person::~Person() {
    totalCount--;
    cout << "[Человек] Уничтожен человек (осталось: " << totalCount << ")" << endl;
    freeMemory();
}

int Person::getTotalCount() {
    return totalCount;
}

void Person::setLastName(const char* lastP) {
    delete[] lastName;
    copyString(lastName, lastP);
}

void Person::setFirstName(const char* firstP) {
    delete[] firstName;
    copyString(firstName, firstP);
}

void Person::setPatronymic(const char* patronP) {
    delete[] patronymic;
    copyString(patronymic, patronP);
}

void Person::setBirthDate(const Date& birth) {
    birthDate = birth;
}

void Person::print() const {
    cout << "=== Человек ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Фамилия: " << (lastName ? lastName : "не указана") << endl;
    cout << "Имя: " << (firstName ? firstName : "не указано") << endl;
    cout << "Отчество: " << (patronymic ? patronymic : "не указано") << endl;
    cout << "Дата рождения: ";
    birthDate.print();
    cout << endl;
}

// ПРАВИЛЬНЫЙ оператор присваивания
Person& Person::operator=(const Person& other) {
    if (this == &other) return *this;

    freeMemory();
    copyFrom(other);

    cout << "[Человек] Оператор присваивания" << endl;
    return *this;
}