#ifndef STUDENT_GRADE_H
#define STUDENT_GRADE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentGrade {
private:
    string name;
    vector<int> grades;

public:
    StudentGrade(const string& n = "");
    StudentGrade(const StudentGrade& other);
    ~StudentGrade();

    string getName() const;
    void setName(const string& n);

    void addGrade(int grade);
    void setGrade(int index, int grade);
    int getGrade(int index) const;
    int getGradeCount() const;

    double getAverage() const;
    int getMaxGrade() const;
    int getMinGrade() const;

    void display() const;
    void displayWithGrades() const;
};

#endif