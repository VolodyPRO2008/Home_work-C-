#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

template<typename T>
class Array {
private:
    T* data;           // Указатель на данные
    int size;          // Текущий размер массива (выделенная память)
    int count;         // Количество фактически добавленных элементов
    int grow;          // Шаг роста при расширении

public:
    // Конструкторы и деструктор
    Array();
    explicit Array(int initialSize, int growStep = 1);
    Array(const Array<T>& other);
    ~Array();

    // Основные методы
    int GetSize() const;           // Получение размера массива
    void SetSize(int newSize, int growStep = 1);  // Установка размера
    int GetUpperBound() const;     // Последний допустимый индекс
    bool IsEmpty() const;          // Массив пуст?
    void FreeExtra();              // Удалить лишнюю память
    void RemoveAll();              // Удалить все элементы

    // Доступ к элементам
    T GetAt(int index) const;      // Получение элемента
    void SetAt(int index, const T& value);  // Установка элемента
    T& operator[](int index);      // Оператор индексации
    const T& operator[](int index) const;

    // Добавление и удаление
    int Add(const T& value);       // Добавление элемента
    void Append(const Array<T>& other);  // Сложение массивов
    void InsertAt(int index, const T& value);  // Вставка элемента
    void InsertAt(int index, const T* values, int numValues);  // Вставка нескольких
    void RemoveAt(int index, int numElements = 1);  // Удаление элементов

    // Операторы
    Array<T>& operator=(const Array<T>& other);

    // Получение адреса массива
    T* GetData() const;

    // Вывод (для отладки)
    void Print() const;
};



template<typename T>
Array<T>::Array() : data(nullptr), size(0), count(0), grow(1) {
    cout << "[Array] Создан пустой массив" << endl;
}

template<typename T>
Array<T>::Array(int initialSize, int growStep)
    : size(initialSize), count(0), grow(growStep) {
    if (size < 0) size = 0;
    if (grow < 1) grow = 1;
    data = (size > 0) ? new T[size] : nullptr;
    cout << "[Array] Создан массив с размером " << size << ", шаг роста = " << grow << endl;
}

template<typename T>
Array<T>::Array(const Array<T>& other)
    : size(other.size), count(other.count), grow(other.grow) {
    data = new T[size];
    for (int i = 0; i < count; i++) {
        data[i] = other.data[i];
    }
    cout << "[Array] Конструктор копирования" << endl;
}

template<typename T>
Array<T>::~Array() {
    delete[] data;
    cout << "[Array] Массив уничтожен" << endl;
}

template<typename T>
int Array<T>::GetSize() const {
    return size;
}

template<typename T>
void Array<T>::SetSize(int newSize, int growStep) {
    if (newSize < 0) return;
    if (growStep > 0) grow = growStep;

    if (newSize == size) return;

    T* newData = (newSize > 0) ? new T[newSize] : nullptr;

    // Копируем существующие данные
    int elementsToCopy = (count < newSize) ? count : newSize;
    for (int i = 0; i < elementsToCopy; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;

    if (newSize < count) {
        count = newSize;  // Потеря элементов
    }

    size = newSize;
    cout << "[Array] Размер изменён на " << size << ", шаг роста = " << grow << endl;
}

template<typename T>
int Array<T>::GetUpperBound() const {
    return count - 1;
}

template<typename T>
bool Array<T>::IsEmpty() const {
    return count == 0;
}

template<typename T>
void Array<T>::FreeExtra() {
    if (size > count) {
        SetSize(count, grow);
    }
}

template<typename T>
void Array<T>::RemoveAll() {
    delete[] data;
    data = nullptr;
    size = 0;
    count = 0;
    cout << "[Array] Все элементы удалены" << endl;
}

template<typename T>
T Array<T>::GetAt(int index) const {
    if (index < 0 || index >= count) {
        cout << "Ошибка: индекс вне диапазона" << endl;
        return T();
    }
    return data[index];
}

template<typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index < 0 || index >= count) {
        cout << "Ошибка: индекс вне диапазона" << endl;
        return;
    }
    data[index] = value;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        cout << "Ошибка: индекс вне диапазона" << endl;
        static T dummy;
        return dummy;
    }
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= count) {
        cout << "Ошибка: индекс вне диапазона" << endl;
        static T dummy;
        return dummy;
    }
    return data[index];
}

template<typename T>
int Array<T>::Add(const T& value) {
    if (count >= size) {
        SetSize(size + grow, grow);
    }
    data[count] = value;
    count++;
    return count - 1;
}

template<typename T>
void Array<T>::Append(const Array<T>& other) {
    for (int i = 0; i < other.count; i++) {
        Add(other.data[i]);
    }
    cout << "[Array] Добавлено " << other.count << " элементов из другого массива" << endl;
}

template<typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > count) {
        cout << "Ошибка: индекс вне диапазона" << endl;
        return;
    }

    // Увеличиваем размер при необходимости
    if (count >= size) {
        SetSize(size + grow, grow);
    }

    // Сдвигаем элементы вправо
    for (int i = count; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    count++;
    cout << "[Array] Вставлен элемент на позицию " << index << endl;
}

template<typename T>
void Array<T>::InsertAt(int index, const T* values, int numValues) {
    if (index < 0 || index > count || numValues <= 0) return;

    // Увеличиваем размер при необходимости
    int neededSize = count + numValues;
    while (neededSize > size) {
        SetSize(size + grow, grow);
    }

    // Сдвигаем элементы вправо
    for (int i = count - 1; i >= index; i--) {
        data[i + numValues] = data[i];
    }

    // Вставляем новые элементы
    for (int i = 0; i < numValues; i++) {
        data[index + i] = values[i];
    }

    count += numValues;
    cout << "[Array] Вставлено " << numValues << " элементов на позицию " << index << endl;
}

template<typename T>
void Array<T>::RemoveAt(int index, int numElements) {
    if (index < 0 || index >= count || numElements <= 0) return;

    int elementsToRemove = numElements;
    if (index + elementsToRemove > count) {
        elementsToRemove = count - index;
    }

    // Сдвигаем элементы влево
    for (int i = index; i + elementsToRemove < count; i++) {
        data[i] = data[i + elementsToRemove];
    }

    count -= elementsToRemove;
    cout << "[Array] Удалено " << elementsToRemove << " элементов с позиции " << index << endl;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other) return *this;

    delete[] data;

    size = other.size;
    count = other.count;
    grow = other.grow;
    data = new T[size];

    for (int i = 0; i < count; i++) {
        data[i] = other.data[i];
    }

    cout << "[Array] Оператор присваивания" << endl;
    return *this;
}

template<typename T>
T* Array<T>::GetData() const {
    return data;
}

template<typename T>
void Array<T>::Print() const {
    if (IsEmpty()) {
        cout << "Массив пуст" << endl;
        return;
    }

    cout << "Массив (" << count << "/" << size << " элементов): [ ";
    for (int i = 0; i < count; i++) {
        cout << data[i];
        if (i < count - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

#endif