#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    // Конструкторы
    Date(int d = 1, int m = 1, int y = 2000);
    Date(const Date& other);
    ~Date();

    // Вспомогательные функции (в public)
    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    long long toDays() const;
    void fromDays(long long days);

    // Операторы
    long long operator-(const Date& other) const;
    Date operator+(int days) const;
    Date& operator+=(int days);
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    friend ostream& operator<<(ostream& output, const Date& date);
    friend istream& operator>>(istream& input, Date& date);
};

#endif