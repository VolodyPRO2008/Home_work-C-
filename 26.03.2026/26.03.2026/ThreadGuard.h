#ifndef THREAD_GUARD_H
#define THREAD_GUARD_H

#include <thread>
#include <functional>

class ThreadGuard {
private:
    std::thread m_thread;

public:
    // Конструктор - принимает вызываемый объект и запускает поток
    template<typename Callable, typename... Args>
    explicit ThreadGuard(Callable&& func, Args&&... args);

    // Деструктор - автоматически вызывает join()
    ~ThreadGuard();

    // Запрещаем копирование
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;

    // Разрешаем перемещение
    ThreadGuard(ThreadGuard&& other) noexcept;
    ThreadGuard& operator=(ThreadGuard&& other) noexcept;

    // Проверка, запущен ли поток
    bool joinable() const;

    // Явный вызов join (если нужно)
    void join();
};

// Реализация шаблонного конструктора должна быть в заголовочном файле
template<typename Callable, typename... Args>
ThreadGuard::ThreadGuard(Callable&& func, Args&&... args)
    : m_thread(std::forward<Callable>(func), std::forward<Args>(args)...) {
}

#endif