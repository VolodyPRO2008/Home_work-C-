#define _CRT_SECURE_NO_WARNINGS
#include "PhoneBook.h"
#include <iostream>
#include <fstream>
using namespace std;

// Реализация класса Abonent
Abonent::Abonent() : fullName(""), homePhone(""), workPhone(""), mobilePhone(""), additionalInfo("") {}

Abonent::Abonent(const string& name, const string& home, const string& work, const string& mobile, const string& info)
    : fullName(name), homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(info) {
}

string Abonent::getFullName() const {
    return fullName;
}

void Abonent::display() const {
    cout << "ФИО: " << fullName << endl;
    cout << "Домашний телефон: " << homePhone << endl;
    cout << "Рабочий телефон: " << workPhone << endl;
    cout << "Мобильный телефон: " << mobilePhone << endl;
    cout << "Дополнительная информация: " << additionalInfo << endl;
    cout << "------------------------" << endl;
}

// Реализация класса PhoneBook
PhoneBook::PhoneBook() : count(0), capacity(5) {
    abonents = new Abonent[capacity];
}

PhoneBook::~PhoneBook() {
    delete[] abonents;
}

void PhoneBook::resize() {
    capacity *= 2;
    Abonent* newArray = new Abonent[capacity];
    for (int i = 0; i < count; i++) {
        newArray[i] = abonents[i];
    }
    delete[] abonents;
    abonents = newArray;
}

void PhoneBook::addAbonent() {
    string name, home, work, mobile, info;

    cout << "Введите ФИО: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введите домашний телефон: ";
    getline(cin, home);

    cout << "Введите рабочий телефон: ";
    getline(cin, work);

    cout << "Введите мобильный телефон: ";
    getline(cin, mobile);

    cout << "Введите дополнительную информацию: ";
    getline(cin, info);

    if (count == capacity) {
        resize();
    }

    abonents[count++] = Abonent(name, home, work, mobile, info);
    cout << "Абонент успешно добавлен!\n";
}

void PhoneBook::removeAbonent(const string& name) {
    for (int i = 0; i < count; i++) {
        if (abonents[i].getFullName() == name) {
            for (int j = i; j < count - 1; j++) {
                abonents[j] = abonents[j + 1];
            }
            count--;
            cout << "Абонент удалён.\n";
            return;
        }
    }
    cout << "Абонент не найден.\n";
}

void PhoneBook::searchByName(const string& name) const {
    for (int i = 0; i < count; i++) {
        if (abonents[i].getFullName() == name) {
            abonents[i].display();
            return;
        }
    }
    cout << "Абонент не найден.\n";
}

void PhoneBook::showAll() const {
    if (count == 0) {
        cout << "Телефонная книга пуста.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        abonents[i].display();
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла для записи.\n";
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << abonents[i].fullName << endl;
        file << abonents[i].homePhone << endl;
        file << abonents[i].workPhone << endl;
        file << abonents[i].mobilePhone << endl;
        file << abonents[i].additionalInfo << endl;
    }

    file.close();
    cout << "Данные сохранены.\n";
}

void PhoneBook::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла для чтения.\n";
        return;
    }

    delete[] abonents;
    count = 0;

    int newCount;
    file >> newCount;
    file.ignore();

    capacity = newCount + 5;
    abonents = new Abonent[capacity];

    for (int i = 0; i < newCount; i++) {
        string name, home, work, mobile, info;

        getline(file, name);
        getline(file, home);
        getline(file, work);
        getline(file, mobile);
        getline(file, info);

        abonents[count++] = Abonent(name, home, work, mobile, info);
    }

    file.close();
    cout << "Данные загружены.\n";
}