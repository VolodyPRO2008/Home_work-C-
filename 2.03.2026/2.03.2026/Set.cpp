#include "Set.h"
#include <cstring>

// Конструктор по умолчанию
Set::Set() {
    capacity = 10;
    size = 0;
    elements = new int[capacity];
    cout << "Создано пустое множество (вместимость: " << capacity << ")" << endl;
}

// Конструктор с параметром
Set::Set(int initialCapacity) {
    if (initialCapacity > 0) {
        capacity = initialCapacity;
    }
    else {
        capacity = 10;
    }
    size = 0;
    elements = new int[capacity];
    cout << "Создано пустое множество с вместимостью: " << capacity << endl;
}

// Конструктор копирования
Set::Set(const Set& other) {
    capacity = other.capacity;
    size = other.size;
    elements = new int[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
    cout << "Создана копия множества (размер: " << size << ")" << endl;
}

// Деструктор
Set::~Set() {
    cout << "Уничтожено множество (размер: " << size << ")" << endl;
    delete[] elements;
}

// Увеличение размера массива
void Set::resize() {
    int newCapacity = capacity * 2;
    int* newElements = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
    cout << "Вместимость множества увеличена до: " << capacity << endl;
}

// Поиск индекса элемента
int Set::findIndex(int value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}

// Проверка принадлежности элемента
bool Set::contains(int value) const {
    return findIndex(value) != -1;
}

// Добавление элемента
void Set::add(int value) {
    if (contains(value)) {
        cout << "Элемент " << value << " уже есть в множестве" << endl;
        return;
    }

    if (size >= capacity) {
        resize();
    }

    elements[size] = value;
    size++;
    cout << "Элемент " << value << " добавлен в множество" << endl;
}

// Удаление элемента
void Set::remove(int value) {
    int index = findIndex(value);
    if (index == -1) {
        cout << "Элемент " << value << " не найден в множестве" << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
    cout << "Элемент " << value << " удалён из множества" << endl;
}

// Вывод множества
void Set::display() const {
    if (size == 0) {
        cout << "Множество пусто" << endl;
        return;
    }

    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << elements[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

// Оператор присваивания
Set& Set::operator=(const Set& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new int[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
        cout << "Выполнено присваивание множеств" << endl;
    }
    return *this;
}

// Добавление элемента (+=)
Set& Set::operator+=(int value) {
    add(value);
    return *this;
}

// Добавление элемента (+)
Set Set::operator+(int value) const {
    Set result(*this);
    result.add(value);
    return result;
}

// Объединение множеств (+=)
Set& Set::operator+=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        add(other.elements[i]);
    }
    cout << "Выполнено объединение множеств (+=)" << endl;
    return *this;
}

// Объединение множеств (+)
Set Set::operator+(const Set& other) const {
    Set result(*this);
    result += other;
    cout << "Выполнено объединение множеств (+)" << endl;
    return result;
}

// Удаление элемента (-=)
Set& Set::operator-=(int value) {
    remove(value);
    return *this;
}

// Удаление элемента (-)
Set Set::operator-(int value) const {
    Set result(*this);
    result.remove(value);
    return result;
}

// Разность множеств (-=)
Set& Set::operator-=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        remove(other.elements[i]);
    }
    cout << "Выполнена разность множеств (-=)" << endl;
    return *this;
}

// Разность множеств (-)
Set Set::operator-(const Set& other) const {
    Set result(*this);
    result -= other;
    cout << "Выполнена разность множеств (-)" << endl;
    return result;
}

// Пересечение множеств (*=)
Set& Set::operator*=(const Set& other) {
    Set temp;
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            temp.add(elements[i]);
        }
    }
    *this = temp;
    cout << "Выполнено пересечение множеств (*=)" << endl;
    return *this;
}

// Пересечение множеств (*)
Set Set::operator*(const Set& other) const {
    Set result;
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    cout << "Выполнено пересечение множеств (*)" << endl;
    return result;
}

// Сравнение множеств (==)
bool Set::operator==(const Set& other) const {
    if (size != other.size) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) {
            return false;
        }
    }
    return true;
}

// Оператор вывода (<<)
ostream& operator<<(ostream& output, const Set& set) {
    if (set.size == 0) {
        output << "{ }";
    }
    else {
        output << "{ ";
        for (int i = 0; i < set.size; i++) {
            output << set.elements[i];
            if (i < set.size - 1) {
                output << ", ";
            }
        }
        output << " }";
    }
    return output;
}

// Оператор ввода (>>)
istream& operator>>(istream& input, Set& set) {
    int count;
    cout << "Введите количество элементов для добавления: ";
    input >> count;

    cout << "Введите " << count << " целых чисел:" << endl;
    for (int i = 0; i < count; i++) {
        int value;
        input >> value;
        set.add(value);
    }
    return input;
}