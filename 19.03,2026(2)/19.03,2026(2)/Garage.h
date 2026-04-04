#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Garage {
private:
    T* items;        // Динамический массив элементов
    int count;       // Текущее количество элементов
    int capacity;    // Вместимость массива

    static int garageCount;  // Количество созданных гаражей

    void resize();   // Увеличение вместимости

public:
    // Конструктор по умолчанию
    Garage();

    // Явный конструктор от size_t
    explicit Garage(size_t reserveSize);

    // Конструктор копирования (глубокое копирование)
    Garage(const Garage<T>& other);

    // Деструктор
    ~Garage();

    // Оператор присваивания (глубокое копирование)
    Garage<T>& operator=(const Garage<T>& other);

    // Добавление элемента (возвращает ссылку для цепочки вызовов)
    Garage<T>& add(const T& item);

    // Количество элементов
    int getCount() const;

    // Оператор доступа по индексу (с проверкой границ)
    T& operator[](int index);
    const T& operator[](int index) const;

    // Объединение двух гаражей
    Garage<T> operator+(const Garage<T>& other) const;

    // Статический метод
    static int getTotalGarages();
};

// Инициализация статического поля для шаблона
template<typename T>
int Garage<T>::garageCount = 0;

// Конструктор по умолчанию
template<typename T>
Garage<T>::Garage() : count(0), capacity(5) {
    items = new T[capacity];
    garageCount++;
    cout << "[Garage] Создан пустой гараж (вместимость: " << capacity << ", всего гаражей: " << garageCount << ")" << endl;
}

// Явный конструктор от size_t
template<typename T>
Garage<T>::Garage(size_t reserveSize) : count(0), capacity(reserveSize) {
    if (capacity < 1) capacity = 1;
    items = new T[capacity];
    garageCount++;
    cout << "[Garage] Создан гараж с резервом " << capacity << " (всего гаражей: " << garageCount << ")" << endl;
}

// Конструктор копирования (глубокое копирование)
template<typename T>
Garage<T>::Garage(const Garage<T>& other) : count(other.count), capacity(other.capacity) {
    items = new T[capacity];
    for (int i = 0; i < count; i++) {
        items[i] = other.items[i];
    }
    garageCount++;
    cout << "[Garage] Создана КОПИЯ гаража (глубокое копирование, всего гаражей: " << garageCount << ")" << endl;
}

// Деструктор
template<typename T>
Garage<T>::~Garage() {
    delete[] items;
    garageCount--;
    cout << "[Garage] Уничтожен гараж (осталось: " << garageCount << ")" << endl;
}

// Оператор присваивания (глубокое копирование)
template<typename T>
Garage<T>& Garage<T>::operator=(const Garage<T>& other) {
    if (this != &other) {
        delete[] items;
        count = other.count;
        capacity = other.capacity;
        items = new T[capacity];
        for (int i = 0; i < count; i++) {
            items[i] = other.items[i];
        }
        cout << "[Garage] Оператор присваивания (глубокое копирование)" << endl;
    }
    return *this;
}

// Увеличение вместимости
template<typename T>
void Garage<T>::resize() {
    int newCapacity = capacity * 2;
    T* newItems = new T[newCapacity];
    for (int i = 0; i < count; i++) {
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
    capacity = newCapacity;
    cout << "[Garage] Расширение гаража: новая вместимость " << capacity << endl;
}

// Добавление элемента (возвращает ссылку для цепочки вызовов)
template<typename T>
Garage<T>& Garage<T>::add(const T& item) {
    if (count >= capacity) {
        resize();
    }
    items[count] = item;
    count++;
    cout << "[Garage] Добавлен элемент, теперь в гараже " << count << " транспортных средств" << endl;
    return *this;  // Возврат ссылки на текущий объект для цепочки вызовов
}

// Количество элементов
template<typename T>
int Garage<T>::getCount() const {
    return count;
}

// Оператор доступа по индексу (неконстантный)
template<typename T>
T& Garage<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Индекс вне диапазона гаража");
    }
    return items[index];
}

// Оператор доступа по индексу (константный)
template<typename T>
const T& Garage<T>::operator[](int index) const {
    if (index < 0 || index >= count) {
        throw out_of_range("Индекс вне диапазона гаража");
    }
    return items[index];
}

// Объединение двух гаражей
template<typename T>
Garage<T> Garage<T>::operator+(const Garage<T>& other) const {
    Garage<T> result;
    for (int i = 0; i < count; i++) {
        result.add(items[i]);
    }
    for (int i = 0; i < other.count; i++) {
        result.add(other.items[i]);
    }
    cout << "[Garage] Объединение гаражей: " << count << " + " << other.count << " = " << result.count << endl;
    return result;
}

// Статический метод
template<typename T>
int Garage<T>::getTotalGarages() {
    return garageCount;
}

#endif