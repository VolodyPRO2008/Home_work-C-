#ifndef DATA_HOLDER_H
#define DATA_HOLDER_H

#include <vector>

class DataHolder {
private:
    std::vector<int> data;

public:
    // Конструктор
    explicit DataHolder(const std::vector<int>& initialData);

    // Константный метод, возвращающий константную ссылку
    const std::vector<int>& getData() const;

    // Метод для вывода данных
    void display() const;

    // Метод для получения размера
    size_t size() const;
};

#endif