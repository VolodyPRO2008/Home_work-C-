#include "DataHolder.h"
#include <iostream>

DataHolder::DataHolder(const std::vector<int>& initialData) : data(initialData) {}

const std::vector<int>& DataHolder::getData() const {
    return data;
}

void DataHolder::display() const {
    std::cout << "Данные: ";
    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

size_t DataHolder::size() const {
    return data.size();
}