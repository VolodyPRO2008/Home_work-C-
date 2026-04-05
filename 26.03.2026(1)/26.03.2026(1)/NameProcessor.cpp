#include "NameProcessor.h"
#include <iostream>
#include <algorithm>
#include <cctype>

NameProcessor::NameProcessor(const std::vector<std::string>& names) : m_names(names) {
}

void NameProcessor::sortByLength() {
    std::sort(m_names.begin(), m_names.end(),
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    std::cout << "Список отсортирован по длине имени" << std::endl;
}

void NameProcessor::removeShortNames(int minLength) {
    auto it = std::remove_if(m_names.begin(), m_names.end(),
        [minLength](const std::string& name) {
            return name.length() < minLength;
        });
    m_names.erase(it, m_names.end());
    std::cout << "Удалены имена короче " << minLength << " символов" << std::endl;
}

void NameProcessor::toUpperCase() {
    std::for_each(m_names.begin(), m_names.end(),
        [](std::string& name) {
            std::transform(name.begin(), name.end(), name.begin(),
                [](unsigned char c) {
                    return std::toupper(c);
                });
        });
    std::cout << "Имена преобразованы в верхний регистр" << std::endl;
}

void NameProcessor::process() {
    std::cout << "\n--- Начало обработки списка имён ---" << std::endl;
    display();

    std::cout << "\n1. Сортировка по длине имени:" << std::endl;
    sortByLength();
    display();

    std::cout << "\n2. Удаление имён короче 4 символов:" << std::endl;
    removeShortNames();
    display();

    std::cout << "\n3. Преобразование в верхний регистр:" << std::endl;
    toUpperCase();
    display();

    std::cout << "--- Обработка завершена ---\n" << std::endl;
}

void NameProcessor::display() const {
    std::cout << "Текущий список (" << m_names.size() << " имён): ";
    for (const auto& name : m_names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
}