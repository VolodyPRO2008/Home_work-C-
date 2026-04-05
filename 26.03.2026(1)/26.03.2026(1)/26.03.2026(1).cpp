#include "Timer.h"
#include "NameProcessor.h"
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <algorithm>

// Функция, возвращающая unique_ptr<Timer>
std::unique_ptr<Timer> createTimer(const std::string& name = "Таймер") {
    return std::make_unique<Timer>(name);
}

// Демонстрация работы с unique_ptr
void demonstrateUniquePtr() {
    std::cout << "=== Демонстрация работы unique_ptr ===" << std::endl;
    std::cout << std::endl;

    {
        std::cout << "Создаём unique_ptr с помощью createTimer():" << std::endl;
        auto timer1 = createTimer("Таймер 1");

        std::cout << "\nИмитируем работу в течение 1 секунды..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "\nСоздаём второй таймер и перемещаем владение:" << std::endl;
        auto timer2 = createTimer("Таймер 2");

        std::cout << "\nПеремещаем владение от timer2 к timer3:" << std::endl;
        std::unique_ptr<Timer> timer3 = std::move(timer2);

        std::cout << "\nИмитируем работу ещё 0.5 секунды..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout << "\nВыходим из области видимости..." << std::endl;
        std::cout << "Деструкторы unique_ptr автоматически вызовут деструкторы Timer" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Все таймеры автоматически уничтожены при выходе из области видимости!" << std::endl;
    std::cout << std::endl;
}

// Демонстрация использования в контейнере
void demonstrateVectorOfUniquePtr() {
    std::cout << "=== Демонстрация вектора unique_ptr ===" << std::endl;
    std::cout << std::endl;

    std::vector<std::unique_ptr<Timer>> timers;

    std::cout << "Добавляем таймеры в вектор:" << std::endl;
    for (int i = 1; i <= 3; ++i) {
        timers.push_back(createTimer("Векторный таймер " + std::to_string(i)));
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "\nУдаляем второй таймер из вектора:" << std::endl;
    timers.erase(timers.begin() + 1);

    std::cout << "\nВыходим из области видимости - все таймеры будут автоматически удалены" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "========== Задание 3.1: Управление динамическими объектами с помощью unique_ptr ==========" << std::endl;
    std::cout << std::endl;

    demonstrateUniquePtr();

    std::cout << std::endl;
    demonstrateVectorOfUniquePtr();

    std::cout << std::endl;
    std::cout << "========== Задание 3.2: Применение STL и лямбды для обработки коллекции ==========" << std::endl;
    std::cout << std::endl;

    // Исходный список имён
    std::vector<std::string> names = {
        "Александр",
        "Анна",
        "Борис",
        "Владимир",
        "Дмитрий",
        "Елена",
        "Иван",
        "Ксения",
        "Максим",
        "Ольга",
        "Петр",
        "Сергей",
        "Тимур",
        "Юлия",
        "Ян"
    };

    // Создаём объект для обработки
    NameProcessor processor(names);

    // Выполняем обработку
    processor.process();



    // Демонстрация работы с разными лямбдами
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Исходный массив чисел: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // Используем лямбду для фильтрации
    auto it = std::remove_if(numbers.begin(), numbers.end(),
        [](int x) { return x % 2 == 0; }); // Удаляем чётные числа
    numbers.erase(it, numbers.end());

    std::cout << "После удаления чётных чисел: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // Используем лямбду для преобразования
    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
        [](int x) { return x * x; });

    std::cout << "После возведения в квадрат: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // Используем лямбду для накопления
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&sum](int x) { sum += x; });

    std::cout << "Сумма всех элементов: " << sum << std::endl;


    return 0;
}