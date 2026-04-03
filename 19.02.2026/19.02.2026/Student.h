#pragma once
#include "include.h"

class Student {
private:
    char* fullName;
    string birthDate;
    string phone;
    string city;
    string country;
    string university;
    string univCity;
    string univCountry;
    string group;

    static int count;

public:
    Student();
    Student(const char* name, string birth, string phone, string city,
        string country, string uni, string univCity, string univCountry, string group);
    Student(const Student& other);
    ~Student();

    inline const char* getFullName() { return fullName; }
    inline string getBirthDate() { return birthDate; }
    inline string getPhone() { return phone; }
    inline string getGroup() { return group; }

    inline void setBirthDate(string d) { birthDate = d; }
    inline void setPhone(string p) { phone = p; }
    inline void setGroup(string g) { group = g; }

    void setFullName(const char* name);
    void input();
    void output();

    static int getCount() { return count; }
};