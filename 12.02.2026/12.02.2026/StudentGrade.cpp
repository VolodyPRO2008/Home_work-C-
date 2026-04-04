#define _CRT_SECURE_NO_WARNINGS

#include "StudentGrade.h"
#include <iomanip>

StudentGrade::StudentGrade(const string& n) : name(n) {
    cout << "Создан студент: " << (name.empty() ? "без имени" : name) << endl;
}

StudentGrade::StudentGrade(const StudentGrade& other) : name(other.name), grades(other.grades) {
    cout << "Создана копия студента" << endl;
}

StudentGrade::~StudentGrade() {
    cout << "Уничтожен студент: " << name << endl;
}

string StudentGrade::getName() const { return name; }
void StudentGrade::setName(const string& n) { name = n; }

void StudentGrade::addGrade(int grade) {
    if (grade >= 1 && grade <= 12) {
        grades.push_back(grade);
    }
    else {
        cout << "Ошибка: оценка " << grade << " не в диапазоне 1-12" << endl;
    }
}

void StudentGrade::setGrade(int index, int grade) {
    if (index >= 0 && index < (int)grades.size()) {
        if (grade >= 1 && grade <= 12) {
            grades[index] = grade;
        }
        else {
            cout << "Ошибка: оценка " << grade << " не в диапазоне 1-12" << endl;
        }
    }
    else {
        cout << "Ошибка: индекс " << index << " вне диапазона" << endl;
    }
}

int StudentGrade::getGrade(int index) const {
    if (index >= 0 && index < (int)grades.size()) {
        return grades[index];
    }
    return 0;
}

int StudentGrade::getGradeCount() const { return grades.size(); }

double StudentGrade::getAverage() const {
    if (grades.empty()) return 0;
    double sum = 0;
    for (int g : grades) sum += g;
    return sum / grades.size();
}

int StudentGrade::getMaxGrade() const {
    if (grades.empty()) return 0;
    int max = grades[0];
    for (int g : grades) if (g > max) max = g;
    return max;
}

int StudentGrade::getMinGrade() const {
    if (grades.empty()) return 0;
    int min = grades[0];
    for (int g : grades) if (g < min) min = g;
    return min;
}

void StudentGrade::display() const {
    cout << name << " (средний балл: " << fixed << setprecision(2) << getAverage() << ")";
}

void StudentGrade::displayWithGrades() const {
    cout << name << ": ";
    for (int g : grades) cout << g << " ";
    cout << "| средний: " << fixed << setprecision(2) << getAverage();
    cout << " | макс: " << getMaxGrade() << " | мин: " << getMinGrade();
    cout << endl;
}