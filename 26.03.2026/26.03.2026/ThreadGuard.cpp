#include "ThreadGuard.h"
#include <iostream>

ThreadGuard::~ThreadGuard() {
    if (m_thread.joinable()) {
        m_thread.join();
        std::cout << "Поток успешно завершён (join вызван автоматически)" << std::endl;
    }
}

ThreadGuard::ThreadGuard(ThreadGuard&& other) noexcept
    : m_thread(std::move(other.m_thread)) {
}

ThreadGuard& ThreadGuard::operator=(ThreadGuard&& other) noexcept {
    if (this != &other) {
        if (m_thread.joinable()) {
            m_thread.join();
        }
        m_thread = std::move(other.m_thread);
    }
    return *this;
}

bool ThreadGuard::joinable() const {
    return m_thread.joinable();
}

void ThreadGuard::join() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
}