#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>

using namespace std;

class Worker {
private:
    string fullName;
    string position;
    int startYear;
    double salary;

public:
    // explicit конструктор
    explicit Worker(double salary = 0.0);

    // Полный конструктор
    Worker(const string& fullName, const string& position, int startYear, double salary);

    // Конструктор копирования
    Worker(const Worker& other);

    // Константные методы для отображения информации
    void display() const;

    // Геттеры (константные методы)
    string getFullName() const { return fullName; }
    string getPosition() const { return position; }
    int getStartYear() const { return startYear; }
    double getSalary() const { return salary; }

    // Сеттеры
    void setFullName(const string& fullName) { this->fullName = fullName; }
    void setPosition(const string& position) { this->position = position; }
    void setStartYear(int startYear) { this->startYear = startYear; }
    void setSalary(double salary) { this->salary = salary; }

    // Метод для вычисления стажа
    int getExperience(int currentYear) const;
};

#endif