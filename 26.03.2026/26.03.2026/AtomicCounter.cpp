#include "AtomicCounter.h"
#include <iostream>

AtomicCounter::AtomicCounter(int initialValue) : m_value(initialValue) {
}

void AtomicCounter::increment() {
    std::lock_guard<std::mutex> lock(m_mutex);
    ++m_value;
}

void AtomicCounter::decrement() {
    std::lock_guard<std::mutex> lock(m_mutex);
    --m_value;
}

int AtomicCounter::get() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_value;
}