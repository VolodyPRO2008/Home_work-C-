#include "Timer.h"
#include <iostream>

Timer::Timer(const std::string& name) : m_name(name) {
    m_startTime = std::chrono::steady_clock::now();
    std::cout << "[" << m_name << "] Создан в "
        << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
        << std::endl;
}

Timer::~Timer() {
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_startTime);
    std::cout << "[" << m_name << "] Уничтожен. Прошло времени: "
        << duration.count() << " мс (" << duration.count() / 1000.0 << " сек)"
        << std::endl;
}

Timer::Timer(Timer&& other) noexcept
    : m_startTime(other.m_startTime), m_name(std::move(other.m_name)) {
    // Обнуляем исходный объект
    other.m_startTime = std::chrono::steady_clock::time_point();
}

Timer& Timer::operator=(Timer&& other) noexcept {
    if (this != &other) {
        m_startTime = other.m_startTime;
        m_name = std::move(other.m_name);
        other.m_startTime = std::chrono::steady_clock::time_point();
    }
    return *this;
}

double Timer::elapsed() const {
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_startTime);
    return duration.count();
}

void Timer::reset() {
    m_startTime = std::chrono::steady_clock::now();
    std::cout << "[" << m_name << "] Таймер сброшен" << std::endl;
}