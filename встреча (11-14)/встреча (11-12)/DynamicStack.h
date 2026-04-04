#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>

using namespace std;

template<typename T>
class DynamicStack {
private:
    T* data;
    int capacity;    // Вместимость
    int topIndex;    // Индекс вершины
    int growStep;    // Шаг роста

public:
    DynamicStack(int initialCapacity = 10, int grow = 5);
    DynamicStack(const DynamicStack<T>& other);
    ~DynamicStack();

    // Основные операции
    void Push(const T& value);
    T Pop();
    T Peek() const;
    int GetCount() const;
    bool IsEmpty() const;
    void Clear();

    // Управление памятью
    void SetCapacity(int newCapacity);
    int GetCapacity() const;

    void Print() const;

    // Операторы
    DynamicStack<T>& operator=(const DynamicStack<T>& other);
};

template<typename T>
DynamicStack<T>::DynamicStack(int initialCapacity, int grow)
    : capacity(initialCapacity), topIndex(-1), growStep(grow) {
    if (capacity < 1) capacity = 1;
    if (growStep < 1) growStep = 1;
    data = new T[capacity];
    cout << "[DynamicStack] Создан стек, вместимость = " << capacity << ", шаг роста = " << growStep << endl;
}

template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack<T>& other)
    : capacity(other.capacity), topIndex(other.topIndex), growStep(other.growStep) {
    data = new T[capacity];
    for (int i = 0; i <= topIndex; i++) {
        data[i] = other.data[i];
    }
    cout << "[DynamicStack] Конструктор копирования" << endl;
}

template<typename T>
DynamicStack<T>::~DynamicStack() {
    delete[] data;
    cout << "[DynamicStack] Стек уничтожен" << endl;
}

template<typename T>
void DynamicStack<T>::SetCapacity(int newCapacity) {
    if (newCapacity <= topIndex) {
        newCapacity = topIndex + 1;
    }
    if (newCapacity == capacity) return;

    T* newData = new T[newCapacity];
    for (int i = 0; i <= topIndex; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    cout << "[DynamicStack] Вместимость изменена на " << capacity << endl;
}

template<typename T>
int DynamicStack<T>::GetCapacity() const {
    return capacity;
}

template<typename T>
void DynamicStack<T>::Push(const T& value) {
    if (topIndex + 1 >= capacity) {
        SetCapacity(capacity + growStep);
    }
    topIndex++;
    data[topIndex] = value;
    cout << "Добавлен элемент: " << value << " (теперь в стеке " << GetCount() << " элементов)" << endl;
}

template<typename T>
T DynamicStack<T>::Pop() {
    if (IsEmpty()) {
        cout << "Ошибка: стек пуст" << endl;
        return T();
    }
    T value = data[topIndex];
    topIndex--;
    cout << "Удалён элемент: " << value << " (осталось " << GetCount() << " элементов)" << endl;
    return value;
}

template<typename T>
T DynamicStack<T>::Peek() const {
    if (IsEmpty()) {
        cout << "Стек пуст" << endl;
        return T();
    }
    return data[topIndex];
}

template<typename T>
int DynamicStack<T>::GetCount() const {
    return topIndex + 1;
}

template<typename T>
bool DynamicStack<T>::IsEmpty() const {
    return topIndex == -1;
}

template<typename T>
void DynamicStack<T>::Clear() {
    topIndex = -1;
    cout << "Стек очищен" << endl;
}

template<typename T>
void DynamicStack<T>::Print() const {
    if (IsEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }

    cout << "Стек (сверху вниз, вместимость: " << capacity << "): ";
    for (int i = topIndex; i >= 0; i--) {
        cout << data[i];
        if (i > 0) cout << " <- ";
    }
    cout << " (всего: " << GetCount() << ")" << endl;
}

template<typename T>
DynamicStack<T>& DynamicStack<T>::operator=(const DynamicStack<T>& other) {
    if (this == &other) return *this;

    delete[] data;

    capacity = other.capacity;
    topIndex = other.topIndex;
    growStep = other.growStep;
    data = new T[capacity];

    for (int i = 0; i <= topIndex; i++) {
        data[i] = other.data[i];
    }

    cout << "[DynamicStack] Оператор присваивания" << endl;
    return *this;
}

#endif