#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class University {
private:
    string name;
    vector<Student*> students;  // Агрегация: хранит указатели, не управляет временем жизни

public:
    University(const string& n = "Неизвестный университет");
    University(const University& other);
    ~University();

    void enrollStudent(Student* student);  // Добавление студента (по указателю)
    void expelStudent(int studentId);
    Student* getStudent(int index);
    int getStudentCount() const;

    void print() const;

    University& operator=(const University& other);
};

#endif