#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "include.h"



int Student::count = 0;

Student::Student() {
    fullName = new char[1];
    fullName[0] = '\0';
    count++;
}

Student::Student(const char* name, string birth, string phone, string city,
    string country, string uni, string univCity, string univCountry, string group) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    birthDate = birth;
    this->phone = phone;
    this->city = city;
    this->country = country;
    university = uni;
    this->univCity = univCity;
    this->univCountry = univCountry;
    this->group = group;
    count++;
}

Student::Student(const Student& other) {
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    birthDate = other.birthDate;
    phone = other.phone;
    city = other.city;
    country = other.country;
    university = other.university;
    univCity = other.univCity;
    univCountry = other.univCountry;
    group = other.group;
    count++;
}

Student::~Student() {
    delete[] fullName;
    count--;
}

void Student::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void Student::input() {
    char buffer[100];

    cout << "Введите ФИО: ";
    cin.getline(buffer, 100);
    setFullName(buffer);

    cout << "Дата рождения: ";
    getline(cin, birthDate);

    cout << "Телефон: ";
    getline(cin, phone);

    cout << "Город: ";
    getline(cin, city);

    cout << "Страна: ";
    getline(cin, country);

    cout << "Учебное заведение: ";
    getline(cin, university);

    cout << "Город учебы: ";
    getline(cin, univCity);

    cout << "Страна учебы: ";
    getline(cin, univCountry);

    cout << "Группа: ";
    getline(cin, group);
}

void Student::output() {
    cout << "\n--- Студент ---" << endl;
    cout << "ФИО: " << fullName << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Город: " << city << endl;
    cout << "Страна: " << country << endl;
    cout << "Учебное заведение: " << university << endl;
    cout << "Город учебы: " << univCity << endl;
    cout << "Страна учебы: " << univCountry << endl;
    cout << "Группа: " << group << endl;
}