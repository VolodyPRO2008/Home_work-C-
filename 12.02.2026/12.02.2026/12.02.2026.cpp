#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "Elevator.h"
#include "Apartment.h"
#include "Group.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");





    // Создание лифта
    cout << "\n 1. Создание лифта " << endl;
    Elevator elevator(1, 9);
    elevator.display();

    // Вызов лифта
    cout << "\n 2. Вызов лифта " << endl;
    elevator.call(5);
    elevator.call(5);
    elevator.call(9);
    elevator.call(1);

    // Попытка вызова на несуществующий этаж
    cout << "\n 3. Ошибка: вызов на несуществующий этаж " << endl;
    elevator.call(15);

    // Изменение диапазона
    cout << "\n 4. Изменение диапазона этажей " << endl;
    elevator.setRange(3, 7);
    elevator.display();

    // Выключение лифта
    cout << "\n 5. Выключение лифта " << endl;
    elevator.turnOff();
    elevator.call(5);

    // Включение лифта
    cout << "\n 6. Включение лифта " << endl;
    elevator.turnOn();
    elevator.call(5);

    // Демонстрация конструктора копирования
    cout << "\n 7. Копирование лифта " << endl;
    Elevator elevator2 = elevator;
    elevator2.display();


    // ЗАДАНИЕ 2: ТЕСТИРОВАНИЕ ПРОГРАММЫ «СТОИМОСТЬ ОБОЕВ»

    cout << endl;
    cout << "ПРОГРАММА «СТОИМОСТЬ ОБОЕВ»" << endl;


    // Создание квартиры
    Apartment apartment;

    // Добавление комнат
    cout << "\n--- Добавление комнат ---" << endl;
    apartment.addRoom("Гостиная", 5.0, 6.0, 2.7, false);
    apartment.addRoom("Спальня", 4.0, 4.5, 2.5, true);
    apartment.addRoom("Кухня", 3.0, 4.0, 2.5, false);
    apartment.addRoom("Прихожая", 2.0, 3.0, 2.5, true);

    // Вывод списка комнат
    apartment.displayRooms();

    // Добавление типов обоев
    cout << "\n--- Добавление типов обоев ---" << endl;
    apartment.addWallpaperType("Виниловые (стандарт)", 0.53, 10.05, 1200);
    apartment.addWallpaperType("Флизелиновые (широкие)", 1.06, 10.05, 2500);
    apartment.addWallpaperType("Бумажные (эконом)", 0.53, 10.05, 500);

    // Вывод типов обоев
    apartment.displayWallpaperTypes();

    // Расчёт стоимости
    apartment.calculateAll();

    // ============================================
    // ЗАДАНИЕ 3: ТЕСТИРОВАНИЕ ПРОГРАММЫ «ГРУППА СТУДЕНТОВ»
    // ============================================
    cout << endl;
    cout << "ПРОГРАММА «ГРУППА СТУДЕНТОВ»" << endl;


    // Создание группы
    Group group("ИС-21");

    // Загрузка данных из файлов
    cout << "\n--- Загрузка данных ---" << endl;

    // Создаём файлы с данными, если их нет
    ofstream studentsFile("students.txt");
    if (studentsFile.is_open()) {
        studentsFile << "Иванов Иван" << endl;
        studentsFile << "Петров Пётр" << endl;
        studentsFile << "Сидорова Анна" << endl;
        studentsFile << "Козлов Дмитрий" << endl;
        studentsFile << "Смирнова Елена" << endl;
        studentsFile.close();
        cout << "Создан файл students.txt" << endl;
    }

    ofstream subjectsFile("subjects.txt");
    if (subjectsFile.is_open()) {
        subjectsFile << "Математика" << endl;
        subjectsFile << "Физика" << endl;
        subjectsFile << "Информатика" << endl;
        subjectsFile << "Русский язык" << endl;
        subjectsFile.close();
        cout << "Создан файл subjects.txt" << endl;
    }

    ofstream gradesFile("grades.txt");
    if (gradesFile.is_open()) {
        gradesFile << "5 4 5 4" << endl;
        gradesFile << "4 5 4 5" << endl;
        gradesFile << "5 5 5 5" << endl;
        gradesFile << "4 4 5 4" << endl;
        gradesFile << "5 4 4 5" << endl;
        gradesFile.close();
        cout << "Создан файл grades.txt" << endl;
    }

    group.loadStudentsFromFile("students.txt");
    group.loadSubjectsFromFile("subjects.txt");
    group.loadGradesFromFile("grades.txt");

    // Вывод всех данных
    group.displayAll();



    return 0;
}