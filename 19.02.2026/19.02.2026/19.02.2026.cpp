#define WIN32_LEAN_AND_MEAN  // исключает редко используемые части Windows API
#define NOGDI                 // исключает GDI (графику)

#include "include.h"
#include "Student.h"
#include "Point.h"
#include "fraction.h"
#include "ShapeArea.h"
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);      // установка кодировки ввода
    SetConsoleOutputCP(1251);


    Student s1;
    Student s2("Иванов Иван", "01.01.2000", "123-456", "Москва",
        "Россия", "МГУ", "Москва", "Россия", "ИС-41");

    cout << "Студент 2:" << endl;
    s2.output();

    cout << "Введите данные студента 1:" << endl;
    s1.input();
    s1.output();


    Point p1;
    Point p2(5, 10, 15);

    cout << "Точка 2: ";
    p2.output();

    cout << "Введите точку 1:" << endl;
    p1.input();
    cout << "Точка 1: ";
    p1.output();

    // Сохранение и загрузка из файла
    p2.saveToFile("point.txt");
    p1.loadFromFile("point.txt");
    cout << "Загружено из файла: ";
    p1.output();



    Point p3;                    // конструктор по умолчанию
    Point p4(1, 2, 3);          // конструктор с параметрами
    Point p5 = p4;               // конструктор копирования

    cout << "Создано точек: " << Point::getCount() << endl;

    // Задание №4: Конструкторы и деструктор Student
    cout << "\n--- Задание 4: Конструкторы и деструктор Student ---" << endl;
    Student s3;                  // конструктор по умолчанию
    Student s4("Сидоров Сидор", "02.02.2000", "789-123", "Киев",
        "Украина", "КНУ", "Киев", "Украина", "ИС-42");
    Student s5 = s4;             // конструктор копирования

    cout << "Создано студентов: " << Student::getCount() << endl<< endl;



    cout << "Задание 1: Класс ShapeArea " << endl;

    ShapeArea::resetCount();

    cout << "Площадь треугольника (3,4,5): "
        << ShapeArea::triangleHeron(3, 4, 5) << endl;
    cout << "Площадь прямоугольника (5x3): "
        << ShapeArea::rectangle(5, 3) << endl;
    cout << "Площадь квадрата (4): "
        << ShapeArea::square(4) << endl;
    cout << "Площадь ромба (диагонали 6 и 8): "
        << ShapeArea::rhombus(6, 8) << endl;

    cout << "Всего вычислений: " << ShapeArea::getCount() << endl;

    cout << "Задание 2: Количество созданных объектов" << endl;
    cout << "Студентов создано: " << Student::getCount() << endl;
    cout << "Точек создано: " << Point::getCount() << endl;
    cout << "Дробей создано: " << Fraction::getCount() << endl;


    cout << "\n--- Класс Fraction (дробь) ---" << endl;

    double num, den;
    cout << "Введите числитель и знаменатель: ";
    cin >> num >> den;

    Fraction f1(num, den);
    cout << "Результат: ";
    f1.display();

    cout << "\nВсего дробей: " << Fraction::getCount() << endl;


    return 0;
}