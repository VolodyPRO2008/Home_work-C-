#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {
public:
    char* name;
    int age;
    double grade;

    Student();
    Student(const char* n, int a, double g);
    Student(const Student& other);             // Конструктор копирования
    Student(Student&& other) noexcept;         // Конструктор переноса (move)
    ~Student();

    Student& operator=(const Student& other);  // Оператор копирования
    Student& operator=(Student&& other) noexcept; // Оператор переноса

    friend ostream& operator<<(ostream& output, const Student& s);
    friend istream& operator>>(istream& input, Student& s);
};

#endif