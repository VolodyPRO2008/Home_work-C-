#ifndef ATOMIC_COUNTER_H
#define ATOMIC_COUNTER_H

#include <mutex>

class AtomicCounter {
private:
    int m_value;
    mutable std::mutex m_mutex;  // mutable позволяет использовать в const-методах

public:
    // Конструктор с начальным значением (по умолчанию 0)
    explicit AtomicCounter(int initialValue = 0);

    // Увеличивает значение на 1
    void increment();

    // Уменьшает значение на 1
    void decrement();

    // Возвращает текущее значение (потокобезопасно)
    int get() const;

    // Блокировка на время операции (для сложных операций)
    template<typename Func>
    int modify(Func operation);
};

// Реализация шаблонного метода
template<typename Func>
int AtomicCounter::modify(Func operation) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_value = operation(m_value);
    return m_value;
}

#endif