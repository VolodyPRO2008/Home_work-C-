#include "Time.h"

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    cout << "—оздано врем€: " << *this << endl;
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
    cout << "—оздана копи€ времени" << endl;
}

Time::~Time() {
    cout << "”ничтожено врем€: " << *this << endl;
}

int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::fromSeconds(int totalSeconds) {
    hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

void Time::addOneSecond() {
    fromSeconds(toSeconds() + 1);
}

Time operator+(const Time& t, int seconds) {
    Time result(t);
    result += seconds;
    return result;
}

Time operator-(const Time& t, int seconds) {
    Time result(t);
    result -= seconds;
    return result;
}

Time& Time::operator++() {
    addOneSecond();
    return *this;
}

Time Time::operator++(int) {
    Time temp(*this);
    addOneSecond();
    return temp;
}

Time& Time::operator--() {
    fromSeconds(toSeconds() - 1);
    return *this;
}

Time Time::operator--(int) {
    Time temp(*this);
    fromSeconds(toSeconds() - 1);
    return temp;
}

Time& Time::operator+=(int seconds) {
    fromSeconds(toSeconds() + seconds);
    return *this;
}

Time& Time::operator-=(int seconds) {
    fromSeconds(toSeconds() - seconds);
    return *this;
}

bool Time::operator==(const Time& other) const {
    return toSeconds() == other.toSeconds();
}

bool Time::operator!=(const Time& other) const {
    return toSeconds() != other.toSeconds();
}

bool Time::operator>(const Time& other) const {
    return toSeconds() > other.toSeconds();
}

bool Time::operator<(const Time& other) const {
    return toSeconds() < other.toSeconds();
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time Time::operator()(int h, int m, int s) const {
    return Time(h, m, s);
}

ostream& operator<<(ostream& output, const Time& t) {
    output << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds;
    return output;
}

istream& operator>>(istream& input, Time& t) {
    cout << "¬ведите часы: "; input >> t.hours;
    cout << "¬ведите минуты: "; input >> t.minutes;
    cout << "¬ведите секунды: "; input >> t.seconds;
    return input;
}