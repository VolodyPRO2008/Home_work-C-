#define _CRT_SECURE_NO_WARNINGS

#include "BankAccount.h"

BankAccount::BankAccount(const string& name, double initialBalance)
    : ownerName(name), balance(initialBalance) {

    if (initialBalance < 0) {
        throw invalid_argument("Ошибка: начальный баланс не может быть отрицательным!");
    }

    cout << "[BankAccount] Создан счёт для " << ownerName
        << " с балансом " << balance << " руб." << endl;
}

BankAccount::~BankAccount() {
    cout << "[BankAccount] Закрыт счёт для " << ownerName << endl;
}

void BankAccount::withdraw(double amount) {
    if (amount < 0) {
        throw invalid_argument("Ошибка: сумма снятия не может быть отрицательной!");
    }

    if (amount > balance) {
        throw runtime_error("Ошибка: недостаточно средств на счету!");
    }

    balance -= amount;
    cout << "[BankAccount] Снято " << amount << " руб. Остаток: " << balance << " руб." << endl;
}

void BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw invalid_argument("Ошибка: сумма пополнения не может быть отрицательной!");
    }

    balance += amount;
    cout << "[BankAccount] Пополнено " << amount << " руб. Баланс: " << balance << " руб." << endl;
}

string BankAccount::getOwnerName() const {
    return ownerName;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::print() const {
    cout << "Счёт: " << ownerName << ", баланс: " << balance << " руб." << endl;
}