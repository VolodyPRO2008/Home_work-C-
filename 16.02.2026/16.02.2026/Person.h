#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include "Date.h"

using namespace std;

class Person {
private:
    int id;                 // Идентификационный номер
    char* lastName;         // Фамилия (динамическая память)
    char* firstName;        // Имя (динамическая память)
    char* patronymic;       // Отчество (динамическая память)
    Date birthDate;         // Дата рождения

    static int totalCount;  // Статический счётчик

    // Вспомогательные функции
    void copyString(char*& dest, const char* src);
    void copyFrom(const Person& other);
    void freeMemory();

public:
    Person(int idP, const char* lastP, const char* firstP, const char* patronP, const Date& birth);
    Person();
    Person(const Person& other);
    ~Person();

    static int getTotalCount();

    void setId(int idP) { id = idP; }
    void setLastName(const char* lastP);
    void setFirstName(const char* firstP);
    void setPatronymic(const char* patronP);
    void setBirthDate(const Date& birth);

    int getId() const { return id; }
    const char* getLastName() const { return lastName; }
    const char* getFirstName() const { return firstName; }
    const char* getPatronymic() const { return patronymic; }
    Date getBirthDate() const { return birthDate; }

    void print() const;

    Person& operator=(const Person& other);
};

#endif