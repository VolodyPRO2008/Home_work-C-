#include "ThreadGuard.h"
#include "AtomicCounter.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

// Функция для демонстрации работы потока с задержкой
void delayedFunction(int id, int delayMs) {
    std::cout << "Поток " << id << " начал работу" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    std::cout << "Поток " << id << " завершил работу (задержка " << delayMs << " мс)" << std::endl;
}

// Функция для быстрой работы
void fastFunction(int id, int iterations) {
    std::cout << "Быстрый поток " << id << " начал работу" << std::endl;
    for (int i = 0; i < iterations; ++i) {
        // Имитация работы
        volatile int x = i * i;
    }
    std::cout << "Быстрый поток " << id << " завершил работу" << std::endl;
}

// Функция для работы со счётчиком
void counterWorker(AtomicCounter& counter, int increments, int decrements, int id) {
    std::cout << "Рабочий поток " << id << " начал операции со счётчиком" << std::endl;

    // Выполняем инкременты
    for (int i = 0; i < increments; ++i) {
        counter.increment();
    }

    // Выполняем декременты
    for (int i = 0; i < decrements; ++i) {
        counter.decrement();
    }

    std::cout << "Рабочий поток " << id << " завершил операции (инкрементов: "
        << increments << ", декрементов: " << decrements << ")" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Задание 2.1: Класс ThreadGuard " << std::endl;
    std::cout << std::endl;

    {
        std::cout << "Создаём первый поток с задержкой 2000 мс:" << std::endl;
        ThreadGuard thread1(delayedFunction, 1, 2000);

        std::cout << "Создаём второй быстрый поток:" << std::endl;
        ThreadGuard thread2(fastFunction, 2, 1000000);

        std::cout << "Потоки запущены. Выходим из области видимости..." << std::endl;
        std::cout << "Деструктор ThreadGuard автоматически вызовет join() для каждого потока" << std::endl;

        // Небольшая задержка для демонстрации
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << " Задание 2.2: Потокобезопасный счётчик " << std::endl;
    std::cout << std::endl;

    // Создаём счётчик с начальным значением 100
    AtomicCounter counter(100);
    std::cout << "Создан счётчик с начальным значением: " << counter.get() << std::endl;

    // Параметры теста
    const int NUM_THREADS = 5;
    const int INCREMENTS_PER_THREAD = 1000;
    const int DECREMENTS_PER_THREAD = 1000;

    std::cout << "Запускаем " << NUM_THREADS << " потоков." << std::endl;
    std::cout << "Каждый поток делает " << INCREMENTS_PER_THREAD << " инкрементов и "
        << DECREMENTS_PER_THREAD << " декрементов" << std::endl;
    std::cout << "Общее количество инкрементов: " << NUM_THREADS * INCREMENTS_PER_THREAD << std::endl;
    std::cout << "Общее количество декрементов: " << NUM_THREADS * DECREMENTS_PER_THREAD << std::endl;
    std::cout << std::endl;

    {
        std::vector<ThreadGuard> threads;

        // Запускаем потоки
        for (int i = 0; i < NUM_THREADS; ++i) {
            threads.emplace_back(counterWorker, std::ref(counter),
                INCREMENTS_PER_THREAD, DECREMENTS_PER_THREAD, i + 1);
        }


    }

    std::cout << std::endl;
    int finalValue = counter.get();
    std::cout << "Финальное значение счётчика: " << finalValue << std::endl;

    int expectedValue = 100; // Начальное значение 100, инкременты = декрементам
    std::cout << "Ожидаемое значение: " << expectedValue << std::endl;

    if (finalValue == expectedValue) {
        std::cout << "Счётчик потокобезопасен." << std::endl;
    }
    else {
        std::cout << "Значение не совпадает с ожидаемым." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "========== Дополнительная демонстрация ==========" << std::endl;
    std::cout << std::endl;

    // Демонстрация использования метода modify
    std::cout << "Демонстрация метода modify (сложные операции):" << std::endl;
    AtomicCounter demoCounter(10);
    std::cout << "Начальное значение: " << demoCounter.get() << std::endl;

    // Увеличиваем на 5
    demoCounter.modify([](int val) { return val + 5; });
    std::cout << "После добавления 5: " << demoCounter.get() << std::endl;

    // Умножаем на 2
    demoCounter.modify([](int val) { return val * 2; });
    std::cout << "После умножения на 2: " << demoCounter.get() << std::endl;



    return 0;
}