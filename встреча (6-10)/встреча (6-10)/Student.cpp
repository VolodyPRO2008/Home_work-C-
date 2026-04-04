#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"

Student::Student() {
    name = new char[1];
    name[0] = '\0';
    age = 0;
    grade = 0.0;
    cout << "Создан пустой студент" << endl;
}

Student::Student(const char* n, int a, double g) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    age = a;
    grade = g;
    cout << "Создан студент: " << name << endl;
}

Student::Student(const Student& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
    grade = other.grade;
    cout << "Создана копия студента: " << name << endl;
}

Student::Student(Student&& other) noexcept {
    name = other.name;
    age = other.age;
    grade = other.grade;
    other.name = nullptr;
    other.age = 0;
    other.grade = 0.0;
    cout << "КОНСТРУКТОР ПЕРЕНОСА: данные перемещены" << endl;
}

Student::~Student() {
    cout << "Уничтожен студент: " << (name ? name : "nullptr") << endl;
    delete[] name;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        grade = other.grade;
        cout << "Оператор копирования: " << name << endl;
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        delete[] name;
        name = other.name;
        age = other.age;
        grade = other.grade;
        other.name = nullptr;
        other.age = 0;
        other.grade = 0.0;
        cout << "ОПЕРАТОР ПЕРЕНОСА: данные перемещены" << endl;
    }
    return *this;
}

ostream& operator<<(ostream& output, const Student& s) {
    output << "Студент: " << s.name << ", возраст: " << s.age << ", оценка: " << s.grade;
    return output;
}

istream& operator>>(istream& input, Student& s) {
    char buffer[100];
    cout << "Введите имя: ";
    input >> buffer;
    delete[] s.name;
    s.name = new char[strlen(buffer) + 1];
    strcpy(s.name, buffer);
    cout << "Введите возраст: ";
    input >> s.age;
    cout << "Введите оценку: ";
    input >> s.grade;
    return input;
}