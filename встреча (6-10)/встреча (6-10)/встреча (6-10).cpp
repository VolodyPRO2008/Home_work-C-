#include <iostream>
#include "Data.h"
#include "MyString.h"
#include "Circle.h"
#include "Airplane.h"
#include "Student.h"
#include "Array.h"
#include "Complex.h"
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");



    // ========== Date ==========
    cout << "\n========== 1. КЛАСС DATE ==========" << endl;
    Date d1(15, 3, 2024);
    Date d2(20, 3, 2024);
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    cout << "Разность: " << (d2 - d1) << " дней" << endl;
    cout << "d1 + 10 дней = " << (d1 + 10) << endl;
    cout << "2024 год високосный? " << (d1.isLeapYear(2024) ? "Да" : "Нет") << endl;

    // ========== MyString ==========
    cout << "\n========== 2. КЛАСС MYSTRING ==========" << endl;
    MyString s1("sdqcg");
    MyString s2("rgfas34");
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
    cout << "Пересечение (s1 * s2) = " << (s1 * s2) << endl;

    // ========== Circle ==========
    cout << "\n========== 3. КЛАСС CIRCLE ==========" << endl;
    Circle c1(5);
    Circle c2(5);
    Circle c3(7);
    cout << "c1 == c2? " << ((c1 == c2) ? "Да" : "Нет") << endl;
    cout << "c3 > c1? " << ((c3 > c1) ? "Да" : "Нет") << endl;
    c1 += 2;
    cout << "c1 после +=2: " << c1 << endl;

    // ========== Airplane ==========
    cout << "\n========== 4. КЛАСС AIRPLANE ==========" << endl;
    Airplane a1("Боинг 747", 300, 250);
    Airplane a2("Airbus A380", 500, 400);
    cout << a1 << endl;
    cout << a2 << endl;
    ++a1;
    --a2;
    cout << "Типы равны? " << ((a1 == a2) ? "Да" : "Нет") << endl;
    cout << "a2 > a1? " << ((a2 > a1) ? "Да" : "Нет") << endl;

    // ========== Student ==========
    cout << "\n========== 5. КЛАСС STUDENT (с конструктором переноса) ==========" << endl;
    Student st1("Иван Петров", 20, 4.8);
    Student st2(move(st1));  // Вызов конструктора переноса
    cout << "st2 = " << st2 << endl;

    // ========== Array ==========
    cout << "\n========== 6. КЛАСС ARRAY ==========" << endl;
    Array arr(5);
    for (int i = 0; i < 5; i++) arr[i] = i + 1;
    cout << "Массив: " << arr << endl;
    arr(5);  // Увеличиваем все элементы на 5
    cout << "После увеличения: " << arr << endl;
    cout << "Сумма элементов (преобразование в int): " << (int)arr << endl;

    // ========== Complex ==========
    cout << "\n========== 7. КЛАСС COMPLEX ==========" << endl;
    Complex comp1(3, 4);
    Complex comp2(1, 2);
    cout << "comp1 = " << comp1 << ", comp2 = " << comp2 << endl;
    cout << "comp1 + comp2 = " << (comp1 + comp2) << endl;
    cout << "comp1 - comp2 = " << (comp1 - comp2) << endl;

    // ========== Time ==========
    cout << "\n========== 8. КЛАСС TIME ==========" << endl;
    Time t1(10, 30, 0);
    Time t2(12, 0, 0);
    cout << "t1 = " << t1 << ", t2 = " << t2 << endl;
    ++t1;
    cout << "После ++t1: " << t1 << endl;
    t1 += 3600;
    cout << "После t1 += 3600: " << t1 << endl;
    cout << "t1 < t2? " << ((t1 < t2) ? "Да" : "Нет") << endl;


    return 0;
}