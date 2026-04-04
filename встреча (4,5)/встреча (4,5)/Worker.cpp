#include "Worker.h"

// explicit конструктор
Worker::Worker(double salary) : salary(salary) {
    fullName = "Неизвестен";
    position = "Не указана";
    startYear = 0;
    cout << "Создан работник-заглушка (explicit конструктор)" << endl;
}

// Полный конструктор
Worker::Worker(const string& fullName, const string& position, int startYear, double salary)
    : fullName(fullName), position(position), startYear(startYear), salary(salary) {
    cout << "Создан работник: " << fullName << ", должность: " << position << endl;
}

// Конструктор копирования
Worker::Worker(const Worker& other)
    : fullName(other.fullName), position(other.position),
    startYear(other.startYear), salary(other.salary) {
    cout << "Создана копия работника: " << fullName << endl;
}

// Константный метод для отображения информации
void Worker::display() const {
    cout << "=== Работник ===" << endl;
    cout << "ФИО: " << fullName << endl;
    cout << "Должность: " << position << endl;
    cout << "Год поступления: " << startYear << endl;
    cout << "Зарплата: " << salary << " руб." << endl;
}

// Метод для вычисления стажа
int Worker::getExperience(int currentYear) const {
    return currentYear - startYear;
}