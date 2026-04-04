#define _CRT_SECURE_NO_WARNINGS

#include "Employee.h"

// ========== Employee ==========
Employee::Employee(const string& n) : name(n) {
    cout << "Создан сотрудник: " << name << endl;
}

Employee::~Employee() {
    cout << "Уничтожен сотрудник: " << name << endl;
}

void Employee::displayInfo() const {
    cout << "Сотрудник: " << name << endl;
}

string Employee::getName() const {
    return name;
}

// ========== Manager ==========
Manager::Manager(const string& n, double salary) : Employee(n), fixedSalary(salary) {
    cout << "Фиксированная зарплата: " << fixedSalary << endl;
}

Manager::~Manager() {
    cout << "Уничтожен менеджер: " << name << endl;
}

double Manager::calculateSalary() const {
    return fixedSalary;
}

void Manager::displayInfo() const {
    cout << "Менеджер: " << name << ", фиксированная зарплата: " << fixedSalary << " руб." << endl;
}

// ========== Engineer ==========
Engineer::Engineer(const string& n, double rate, int hrs) : Employee(n), hourlyRate(rate), hours(hrs) {
    cout << "Ставка: " << hourlyRate << " руб/час, часы: " << hours << endl;
}

Engineer::~Engineer() {
    cout << "Уничтожен инженер: " << name << endl;
}

double Engineer::calculateSalary() const {
    return hourlyRate * hours;
}

void Engineer::displayInfo() const {
    cout << "Инженер: " << name << " (" << hours << " часов по " << hourlyRate << " руб/час)" << endl;
}

// ========== SalesPerson ==========
SalesPerson::SalesPerson(const string& n, double base, double sales, double commission)
    : Employee(n), baseSalary(base), salesAmount(sales), commissionRate(commission) {
    cout << "Базовый оклад: " << baseSalary << ", продажи: " << salesAmount
        << ", комиссия: " << commissionRate << "%" << endl;
}

SalesPerson::~SalesPerson() {
    cout << "Уничтожен менеджер по продажам: " << name << endl;
}

double SalesPerson::calculateSalary() const {
    return baseSalary + salesAmount * (commissionRate / 100.0);
}

void SalesPerson::displayInfo() const {
    cout << "Менеджер по продажам: " << name << " (база " << baseSalary
        << " руб. + " << commissionRate << "% от " << salesAmount << " руб.)" << endl;
}