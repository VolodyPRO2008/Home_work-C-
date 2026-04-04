#include "Data.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    cout << "—оздана дата: " << day << "." << month << "." << year << endl;
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {
    cout << "—оздана копи€ даты" << endl;
}

Date::~Date() {
    cout << "”ничтожена дата: " << day << "." << month << "." << year << endl;
}

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
    switch (m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(y) ? 29 : 28;
    default: return 0;
    }
}

long long Date::toDays() const {
    long long days = 0;
    for (int y = 1; y < year; y++) days += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < month; m++) days += daysInMonth(m, year);
    days += day;
    return days;
}

void Date::fromDays(long long days) {
    year = 1;
    while (true) {
        int daysInYear = isLeapYear(year) ? 366 : 365;
        if (days > daysInYear) { days -= daysInYear; year++; }
        else break;
    }
    month = 1;
    while (true) {
        int daysInCurrMonth = daysInMonth(month, year);
        if (days > daysInCurrMonth) { days -= daysInCurrMonth; month++; }
        else break;
    }
    day = static_cast<int>(days);
}

long long Date::operator-(const Date& other) const { return toDays() - other.toDays(); }
Date Date::operator+(int days) const { Date result(*this); result += days; return result; }
Date& Date::operator+=(int days) { long long totalDays = toDays() + days; fromDays(totalDays); return *this; }
bool Date::operator==(const Date& other) const { return (day == other.day && month == other.month && year == other.year); }
bool Date::operator!=(const Date& other) const { return !(*this == other); }
bool Date::operator<(const Date& other) const { return toDays() < other.toDays(); }
bool Date::operator>(const Date& other) const { return toDays() > other.toDays(); }

ostream& operator<<(ostream& output, const Date& date) {
    output << date.day << "." << date.month << "." << date.year;
    return output;
}

istream& operator>>(istream& input, Date& date) {
    cout << "¬ведите день: "; input >> date.day;
    cout << "¬ведите мес€ц: "; input >> date.month;
    cout << "¬ведите год: "; input >> date.year;
    return input;
}