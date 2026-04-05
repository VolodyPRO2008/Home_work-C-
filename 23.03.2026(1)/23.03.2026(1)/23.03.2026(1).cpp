#include "Geometry.h"
#include "Logger.h"
#include "Utils.h"
#include <iostream>

// Прототип функции для получения счётчика
int getNormalizeCounter();

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << " Задание 1: Геометрические фигуры " << std::endl;

    // Полная квалификация
    double circleArea = Geometry::circleArea(5.0);
    std::cout << "Площадь круга (радиус 5): " << circleArea << std::endl;

    double rectArea = Geometry::rectangleArea(4.0, 6.0);
    std::cout << "Площадь прямоугольника (4x6): " << rectArea << std::endl;

    // Использование класса из вложенного пространства имён
    Geometry::Shapes::Circle circle(3.0);
    std::cout << "Площадь круга через класс Circle (радиус 3): " << circle.area() << std::endl;

    // Использование using-объявления
    using Geometry::rectangleArea;
    std::cout << "Площадь прямоугольника через using-объявление (3x7): " << rectangleArea(3.0, 7.0) << std::endl;

    std::cout << "\n Задание 2: Логирование " << std::endl;

    // Использование using namespace внутри функции
    {
        using namespace Logger;
        log(LogLevel::INFO, "Программа успешно запущена");
        log(LogLevel::WARNING, "Обнаружено подозрительное значение");
        log(LogLevel::ERROR, "Критическая ошибка в вычислениях");

        FileLogger::logToFile("log.txt", "Это тестовое сообщение в файл");
        std::cout << "Сообщение записано в файл log.txt" << std::endl;
    }

    std::cout << "\n Задание 3: Псевдонимы и анонимные пространства " << std::endl;

    // Демонстрация работы Utils::clamp
    double testValues[] = { -0.5, 0.3, 1.5, 0.7, -1.2 };

    std::cout << "Работа функции clamp:" << std::endl;
    for (double val : testValues) {
        double result = Utils::clamp(val, 0.0, 1.0);
        std::cout << "  clamp(" << val << ", 0, 1) = " << result << std::endl;
    }

    // Вызов clamp несколько раз, чтобы увеличить counter
    Utils::clamp(0.5, 0.0, 1.0);
    Utils::clamp(2.0, 0.0, 1.0);
    Utils::clamp(-0.3, 0.0, 1.0);

    std::cout << "\nКоличество вызовов normalize (через clamp): " << getNormalizeCounter() << std::endl;
    std::cout << "Функция normalize и переменная counter недоступны из main (компилятор выдаст ошибку при попытке доступа)" << std::endl;



    return 0;
}