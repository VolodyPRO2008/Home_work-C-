#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer {
private:
    std::chrono::steady_clock::time_point m_startTime;
    std::string m_name;

public:
    // Конструктор с именем таймера
    explicit Timer(const std::string& name = "Таймер");

    // Деструктор - выводит прошедшее время
    ~Timer();

    // Запрещаем копирование (unique_ptr требует этого)
    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    // Разрешаем перемещение
    Timer(Timer&& other) noexcept;
    Timer& operator=(Timer&& other) noexcept;

    // Метод для получения прошедшего времени в миллисекундах
    double elapsed() const;

    // Метод для сброса таймера
    void reset();
};

#endif