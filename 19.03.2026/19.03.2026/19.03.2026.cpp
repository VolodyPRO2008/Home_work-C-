#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "Animal.h"
#include "Shape.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "              ЗАДАНИЕ 1: ПОЛИМОРФИЗМ «ГОЛОСА ЖИВОТНЫХ»            " << endl;



    // Создаём вектор указателей на базовый класс Animal
    vector<Animal*> animals;

    // Заполняем вектор объектами производных классов
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());
    animals.push_back(new Bird());  // Дополнительный класс

    cout << "\n--- Вызов speak() для каждого животного ---" << endl;
    cout << "----------------------------------------" << endl;

    // Полиморфный вызов: через указатель на базовый класс вызывается
    // переопределённый метод производного класса
    for (Animal* animal : animals) {
        animal->speak();
    }

    cout << "----------------------------------------" << endl;

    // Освобождаем память
    cout << "\n--- Освобождение памяти ---" << endl;
    for (Animal* animal : animals) {
        delete animal;
    }



    cout << "           ЗАДАНИЕ 2: АБСТРАКТНЫЙ КЛАСС «ФИГУРЫ»                 " << endl;


    // Создаём вектор указателей на абстрактный базовый класс Shape
    vector<Shape*> shapes;

    // Заполняем вектор объектами различных фигур
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));
    shapes.push_back(new Triangle(5.0, 5.0, 5.0));  // Равносторонний
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(3.0, 3.0));      // Квадрат

    cout << "\n--- Информация о фигурах ---" << endl;
    cout << "========================================" << endl;

    // Полиморфный вызов методов для каждой фигуры
    for (Shape* shape : shapes) {
        shape->printInfo();
        cout << "Площадь: " << shape->area() << endl;
        cout << "Периметр: " << shape->perimeter() << endl;
        cout << "----------------------------------------" << endl;
    }

    // Дополнительная демонстрация: некорректный треугольник
    cout << "\n--- Проверка некорректного треугольника ---" << endl;
    Triangle invalidTriangle(1.0, 1.0, 3.0);
    invalidTriangle.printInfo();
    cout << "Площадь: " << invalidTriangle.area() << endl;
    cout << "Периметр: " << invalidTriangle.perimeter() << endl;

    // Освобождаем память
    cout << "\n--- Освобождение памяти ---" << endl;
    for (Shape* shape : shapes) {
        delete shape;
    }


    return 0;
}