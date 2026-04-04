#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

// Базовый абстрактный класс Employee
class Employee {
protected:
    string name;

public:
    Employee(const string& n);
    virtual ~Employee();

    virtual double calculateSalary() const = 0;  // Чисто виртуальная
    virtual void displayInfo() const;

    string getName() const;
};

// ========== Manager (фиксированный оклад) ==========
class Manager : public Employee {
private:
    double fixedSalary;

public:
    Manager(const string& n, double salary);
    ~Manager();

    double calculateSalary() const override;
    void displayInfo() const override;
};

// ========== Engineer (почасовая ставка) ==========
class Engineer : public Employee {
private:
    double hourlyRate;
    int hours;

public:
    Engineer(const string& n, double rate, int hrs);
    ~Engineer();

    double calculateSalary() const override;
    void displayInfo() const override;
};

// ========== SalesPerson (базовый оклад + процент от продаж) ==========
class SalesPerson : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;  // в процентах (например, 5 = 5%)

public:
    SalesPerson(const string& n, double base, double sales, double commission);
    ~SalesPerson();

    double calculateSalary() const override;
    void displayInfo() const override;
};

#endif