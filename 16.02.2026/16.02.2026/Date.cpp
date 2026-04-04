#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    cout << "[Дата] Создана дата: " << day << "." << month << "." << year << endl;
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {
    cout << "[Дата] Создана копия даты" << endl;
}

Date::~Date() {
    cout << "[Дата] Уничтожена дата: " << day << "." << month << "." << year << endl;
}

void Date::print() const {
    cout << day << "." << month << "." << year;
}