#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    double averageGrade;

public:
    Student(int idNum = 0, const string& n = "Unknown", double grade = 0.0);
    Student(const Student& other);
    ~Student();

    int getId() const;
    string getName() const;
    double getAverageGrade() const;

    void setId(int idNum);
    void setName(const string& n);
    void setAverageGrade(double grade);

    void print() const;

    Student& operator=(const Student& other);
};

#endif