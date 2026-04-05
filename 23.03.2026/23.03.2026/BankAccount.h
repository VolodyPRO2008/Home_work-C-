#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    // Конструктор (выбрасывает исключение при отрицательном балансе)
    BankAccount(const string& name, double initialBalance);

    // Деструктор
    ~BankAccount();

    // Метод снятия денег
    void withdraw(double amount);

    // Метод пополнения
    void deposit(double amount);

    // Геттеры
    string getOwnerName() const;
    double getBalance() const;

    // Вывод информации
    void print() const;
};

#endif