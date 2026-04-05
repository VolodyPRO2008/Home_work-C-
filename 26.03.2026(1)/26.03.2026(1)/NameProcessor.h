#ifndef NAME_PROCESSOR_H
#define NAME_PROCESSOR_H

#include <vector>
#include <string>

class NameProcessor {
private:
    std::vector<std::string> m_names;

public:
    // Конструктор
    explicit NameProcessor(const std::vector<std::string>& names);

    // Основной метод обработки
    void process();

    // Вывод текущего списка
    void display() const;

    // Сортировка по длине имени
    void sortByLength();

    // Удаление имён короче 4 символов
    void removeShortNames(int minLength = 4);

    // Преобразование в верхний регистр
    void toUpperCase();
};

#endif