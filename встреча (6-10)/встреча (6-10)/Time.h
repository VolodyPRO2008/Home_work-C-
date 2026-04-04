#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h = 0, int m = 0, int s = 0);
    Time(const Time& other);
    ~Time();

    // Вспомогательные функции (в public)
    int toSeconds() const;
    void fromSeconds(int totalSeconds);
    void addOneSecond();

    // Операторы (дружественная перегрузка)
    friend Time operator+(const Time& t, int seconds);
    friend Time operator-(const Time& t, int seconds);

    // Операторы-члены класса
    Time& operator++();      // Префиксный инкремент
    Time operator++(int);    // Постфиксный инкремент
    Time& operator--();      // Префиксный декремент
    Time operator--(int);    // Постфиксный декремент
    Time& operator+=(int seconds);
    Time& operator-=(int seconds);
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    Time& operator=(const Time& other);
    Time operator()(int h, int m, int s) const;

    friend ostream& operator<<(ostream& output, const Time& t);
    friend istream& operator>>(istream& input, Time& t);
};

#endif