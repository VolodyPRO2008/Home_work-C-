#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2000);
    Date(const Date& other);
    ~Date();

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void print() const;
};

#endif