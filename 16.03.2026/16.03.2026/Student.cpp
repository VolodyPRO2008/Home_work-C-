#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"

Student::Student(int idNum, const string& n, double grade)
    : id(idNum), name(n), averageGrade(grade) {
    cout << "[Студент] Создан: " << name << " (ID: " << id << ", средний балл: " << averageGrade << ")" << endl;
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), averageGrade(other.averageGrade) {
    cout << "[Студент] Создана копия: " << name << endl;
}

Student::~Student() {
    cout << "[Студент] Уничтожен: " << name << " (ID: " << id << ")" << endl;
}

int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getAverageGrade() const { return averageGrade; }

void Student::setId(int idNum) { id = idNum; }
void Student::setName(const string& n) { name = n; }
void Student::setAverageGrade(double grade) { averageGrade = grade; }

void Student::print() const {
    cout << "Студент: " << name << " (ID: " << id << ", средний балл: " << averageGrade << ")" << endl;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        averageGrade = other.averageGrade;
    }
    return *this;
}