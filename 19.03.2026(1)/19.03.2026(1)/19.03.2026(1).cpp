#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "StringHolder.h"
#include "Interfaces.h"
#include "Vehicles.h"
#include "Employee.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "                    ЗАДАНИЯ 3-6: ПОЛИМОРФИЗМ                      " << endl;



    cout << "\n\n ЗАДАНИЕ 3: ВИРТУАЛЬНЫЙ ДЕСТРУКТОР " << endl;

    cout << "\n Создание объектов через указатели на базовый класс " << endl;
    StringHolder* s1 = new StringHolder("Привет");
    StringHolder* s2 = new ReverseString("Мир");

    cout << "\n Вызов print() " << endl;
    s1->print();
    s2->print();

    cout << "\n Удаление объектов " << endl;
    delete s1;
    delete s2;




    cout << "\n\n ЗАДАНИЕ 4: МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ " << endl;

    vector<Drawable*> drawables;
    drawables.push_back(new Circle(10, 20, 5));
    drawables.push_back(new Rectangle(0, 0, 30, 15));

    cout << "\n Вызов draw() через указатели на Drawable " << endl;
    for (Drawable* d : drawables) {
        d->draw();
    }

    cout << "\n Сериализация через dynamic_cast к Serializable " << endl;
    for (Drawable* d : drawables) {
        // Приведение типа от Drawable к Serializable
        Serializable* s = dynamic_cast<Serializable*>(d);
        if (s) {
            cout << "Сериализовано: " << s->serialize() << endl;
        }
    }

    for (Drawable* d : drawables) {
        delete d;
    }


    cout << "\n\n ЗАДАНИЕ 5: OVERRIDE И FINAL " << endl;

    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car());
    vehicles.push_back(new ElectricCar());
    vehicles.push_back(new SportsCar());
    vehicles.push_back(new Bicycle());

    cout << "\n Полиморфные вызовы " << endl;
    for (Vehicle* v : vehicles) {
        v->startEngine();
        cout << "Максимальная скорость: " << v->getMaxSpeed() << " км/ч" << endl;
        v->info();
        cout << "----------------------------------------" << endl;
    }

    for (Vehicle* v : vehicles) {
        delete v;
    }



    cout << "\n\n ЗАДАНИЕ 6: БАЗА ДАННЫХ СОТРУДНИКОВ " << endl;

    vector<Employee*> employees;

    employees.push_back(new Manager("Иванов Иван", 50000));
    employees.push_back(new Engineer("Петров Пётр", 300, 160));
    employees.push_back(new SalesPerson("Сидорова Анна", 20000, 50000, 5));
    employees.push_back(new Engineer("Козлов Дмитрий", 350, 140));
    employees.push_back(new Manager("Смирнова Елена", 75000));
    employees.push_back(new SalesPerson("Васильев Алексей", 25000, 100000, 8));

    cout << "\n--- Информация о сотрудниках ---" << endl;
    cout << "========================================" << endl;

    double totalSalary = 0;
    for (Employee* e : employees) {
        e->displayInfo();
        double salary = e->calculateSalary();
        cout << "Зарплата: " << salary << " руб." << endl;
        totalSalary += salary;
        cout << "----------------------------------------" << endl;
    }

    cout << "\n--- Общая сумма зарплат ---" << endl;
    cout << "ИТОГО: " << totalSalary << " руб." << endl;

    for (Employee* e : employees) {
        delete e;
    }



    return 0;
}