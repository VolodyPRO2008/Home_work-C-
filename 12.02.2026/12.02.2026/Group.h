#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include <vector>
#include "StudentGrade.h"
#include "Subject.h"

using namespace std;

class Group {
private:
    string name;
    vector<StudentGrade> students;
    vector<Subject> subjects;
    vector<vector<int>> gradeTable;  // Таблица оценок [студент][предмет]

public:
    Group(const string& n = "");
    Group(const Group& other);
    ~Group();

    // Добавление данных
    void addStudent(const StudentGrade& student);
    void addSubject(const Subject& subject);
    void setGrade(int studentIndex, int subjectIndex, int grade);

    // Загрузка из файлов
    bool loadStudentsFromFile(const string& filename);
    bool loadSubjectsFromFile(const string& filename);
    bool loadGradesFromFile(const string& filename);

    // Расчёты
    double getStudentAverage(int studentIndex) const;
    double getSubjectAverage(int subjectIndex) const;
    double getGroupAverage() const;

    int getMaxGradeForSubject(int subjectIndex, int& studentIndex) const;
    int getMinGradeForSubject(int subjectIndex, int& studentIndex) const;

    // Вывод
    void displayGradeTable() const;
    void displayStudentAverages() const;
    void displaySubjectAverages() const;
    void displaySubjectExtremes() const;
    void displayAll() const;

    // Геттеры
    string getName() const;
    int getStudentCount() const;
    int getSubjectCount() const;
};

#endif