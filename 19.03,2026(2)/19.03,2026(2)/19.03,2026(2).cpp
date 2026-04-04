#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Point.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Garage.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "\n\n ЧАСТЬ 1: КЛАСС POINT " << endl;

    cout << "\n--- Создание точек ---" << endl;
    Point p1;                    // Конструктор по умолчанию
    Point p2(3.5, 4.5);          // Конструктор с параметрами
    Point p3(p2);                // Конструктор копирования

    cout << "\n--- Вывод точек ---" << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;

    cout << "\n--- Расстояние от начала координат ---" << endl;
    cout << "Расстояние p2 от (0,0): " << p2.distance() << endl;

    cout << "\n--- Сравнение точек (== и !=) ---" << endl;
    if (p2 == p3) {
        cout << "p2 и p3 равны" << endl;
    }
    else {
        cout << "p2 и p3 не равны" << endl;
    }

    if (p1 != p2) {
        cout << "p1 и p2 не равны" << endl;
    }

    cout << "\n--- Ввод точки с клавиатуры ---" << endl;
    Point p4;
    cin >> p4;
    cout << "Вы ввели: " << p4 << endl;

    cout << "\n--- Статический счётчик точек ---" << endl;
    cout << "Всего создано точек: " << Point::getPointCount() << endl;


    cout << "\n\n ЧАСТЬ 2: КЛАССЫ VEHICLE, CAR, BIKE " << endl;

    cout << "\n--- Создание транспортных средств ---" << endl;
    Car car1("Toyota Camry", 2022, Point(10, 20), 4);
    Car car2("BMW X5", 2023, Point(30, 40), 5);
    Bike bike1("Trek", 2021, Point(5, 10), "sport");
    Bike bike2("Giant", 2020, Point(15, 25), "mountain");


    Vehicle* v1 = new Car("Tesla Model 3", 2024, Point(0, 0), 4);


    car1.print();
    car2.print();
    bike1.print();
    bike2.print();

    cout << "\n Максимальная скорость  " << endl;
    cout << car1.getModel() << " макс. скорость: " << car1.getMaxSpeed() << " км/ч" << endl;
    cout << bike1.getModel() << " макс. скорость: " << bike1.getMaxSpeed() << " км/ч" << endl;

    cout << "\n Перемещение " << endl;
    car1.move(Point(100, 50));
    bike1.move(Point(200, 80));

    cout << "\n Префиксный и постфиксный инкремент для Car (++doors) " << endl;
    cout << "До ++car1: " << car1.getDoors() << " дверей" << endl;
    ++car1;
    cout << "После ++car1: " << car1.getDoors() << " дверей" << endl;

    car2++;
    cout << "После car2++: " << car2.getDoors() << " дверей" << endl;

    cout << "\n Статический счётчик транспортных средств " << endl;
    cout << "Всего создано ТС: " << Vehicle::getTotalVehicles() << endl;


    cout << "\n\n ЧАСТЬ 3: ШАБЛОННЫЙ КЛАСС GARAGE " << endl;

    cout << "\n Создание гаража и добавление ТС (цепочка вызовов add) " << endl;
    Garage<Vehicle*> garage;

    // Цепочка вызовов add (метод возвращает ссылку на *this)
    garage.add(&car1).add(&car2).add(&bike1).add(&bike2);


    for (int i = 0; i < garage.getCount(); i++) {
        garage[i]->print();
    }
    cout << "========================================" << endl;

    cout << "\n Конструктор копирования Garage " << endl;
    Garage<Vehicle*> garageCopy = garage;

    cout << "\n Изменение оригинала (перемещение car1) " << endl;
    car1.move(Point(999, 999));

    cout << "\n Оригинальный гараж после изменения " << endl;
    garage[0]->print();

    cout << "\n Копия гаража  " << endl;
    garageCopy[0]->print();

    cout << "\n Оператор + (объединение гаражей) " << endl;
    Garage<Vehicle*> garage2;
    garage2.add(&car1);
    Garage<Vehicle*> garage3 = garage + garage2;
    cout << "Размер объединённого гаража: " << garage3.getCount() << endl;

    cout << "\n Статический счётчик гаражей " << endl;
    cout << "Всего создано гаражей: " << Garage<Vehicle*>::getTotalGarages() << endl;


    cout << "\n\n ЧАСТЬ 4: ОБРАБОТКА ИСКЛЮЧЕНИЙ " << endl;

    cout << "\n Попытка доступа к несуществующему индексу " << endl;
    try {
        garage[100]->print();  // Несуществующий индекс
    }
    catch (const out_of_range& e) {
        cout << "Исключение: " << e.what() << endl;
    }


    cout << "\n\n ОСВОБОЖДЕНИЕ ПАМЯТИ " << endl;

    delete v1;  // Удаляем объект, созданный через new

    cout << "\n--- Удаление гаража (уничтожаются только указатели, не объекты) ---" << endl;

    cout << "\n--- Итоговые статические счётчики ---" << endl;
    cout << "Точек осталось: " << Point::getPointCount() << endl;
    cout << "ТС осталось: " << Vehicle::getTotalVehicles() << endl;
    cout << "Гаражей осталось: " << Garage<Vehicle*>::getTotalGarages() << endl;



    return 0;
}