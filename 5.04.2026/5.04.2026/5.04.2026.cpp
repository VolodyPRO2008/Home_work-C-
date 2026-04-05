#include "Shape.h"
#include "DataHolder.h"
#include <iostream>
#include <vector>
#include <memory>

// Функция для задания 1.1 - идентификация и рисование фигуры
void identifyAndDraw(Shape* s) {
    if (!s) {
        std::cout << "Ошибка: нулевой указатель!" << std::endl;
        return;
    }

    std::cout << "Обработка фигуры " << std::endl;

    // Пытаемся привести к Circle
    Circle* circle = dynamic_cast<Circle*>(s);
    if (circle) {
        std::cout << "Обнаружен тип: " << circle->getType() << std::endl;
        circle->draw();
        std::cout << "Радиус круга: " << circle->getRadius() << std::endl;
        return;
    }

    // Пытаемся привести к Rectangle
    Rectangle* rectangle = dynamic_cast<Rectangle*>(s);
    if (rectangle) {
        std::cout << "Обнаружен тип: " << rectangle->getType() << std::endl;
        rectangle->draw();
        std::cout << "Ширина: " << rectangle->getWidth() << ", Высота: " << rectangle->getHeight() << std::endl;
        return;
    }

    // Если ни один тип не подошёл
    std::cout << "Неизвестный тип фигуры!" << std::endl;
    s->draw();
}

// Функция для задания 1.2 - модификация данных через const_cast
void modifyData(const DataHolder& dh) {
    std::cout << "\n modifyData: изменяем данные через const_cast " << std::endl;

    // Показываем исходные данные
    std::cout << "Исходные данные: ";
    dh.display();

    // Используем const_cast для удаления константности
    // ВНИМАНИЕ: это безопасно только если объект изначально не был const!
    DataHolder& nonConstDh = const_cast<DataHolder&>(dh);

    // Получаем неконстантную ссылку на данные
    std::vector<int>& data = const_cast<std::vector<int>&>(dh.getData());

    // Изменяем первый элемент, если массив не пуст
    if (!data.empty()) {
        int oldValue = data[0];
        data[0] = 999;
        std::cout << "Изменён первый элемент: " << oldValue << " -> " << data[0] << std::endl;
    }
    else {
        std::cout << "Массив пуст, нечего изменять!" << std::endl;
    }

    // Добавляем новый элемент для демонстрации
    data.push_back(777);
    std::cout << "Добавлен новый элемент: 777" << std::endl;

    std::cout << "Данные после изменения: ";
    nonConstDh.display();
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Задание 1.1: Безопасное приведение с dynamic_cast " << std::endl;
    std::cout << std::endl;

    // Создаём массив указателей Shape*
    std::vector<Shape*> shapes;

    // Добавляем объекты разных типов
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(10.0, 3.0));
    shapes.push_back(new Circle(7.0));

    std::cout << "Создано " << shapes.size() << " фигур:" << std::endl;
    std::cout << std::endl;

    // Обрабатываем каждую фигуру
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        identifyAndDraw(shapes[i]);
        std::cout << std::endl;
    }

    // Очищаем память
    for (Shape* shape : shapes) {
        delete shape;
    }

    std::cout << std::endl;
    std::cout <<  "Задание 1.2: Исправление устаревшего кода с const_cast " << std::endl;
    std::cout << std::endl;

    // Создаём объект DataHolder (НЕ const!)
    std::vector<int> initialData = { 10, 20, 30, 40, 50 };
    DataHolder dh(initialData);

    std::cout << "Создан объект DataHolder (неконстантный):" << std::endl;
    dh.display();
    std::cout << std::endl;

    // Передаём в функцию, которая ожидает const DataHolder&
    // Это безопасно, так как объект изначально не был const
    modifyData(dh);

    std::cout << std::endl;
    std::cout << "Финальное состояние объекта:" << std::endl;
    dh.display();

    std::cout << std::endl;
    std::cout << "Дополнительная демонстрация " << std::endl;
    std::cout << std::endl;



    const DataHolder constDh(std::vector<int>{1, 2, 3});
    std::cout << "Создан КОНСТАНТНЫЙ объект: ";
    constDh.display();



    return 0;
}