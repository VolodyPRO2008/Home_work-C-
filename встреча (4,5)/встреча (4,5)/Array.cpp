#include "Array.h"
#include <cstdlib>
#include <ctime>

// Конструктор по умолчанию
Array::Array() {
    capacity = 10;
    size = 0;
    data = new int[capacity];
    cout << "Создан массив по умолчанию (вместимость: " << capacity << ")" << endl;
}

// Конструктор с заданным размером
Array::Array(int initialCapacity) {
    if (initialCapacity > 0) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
        cout << "Создан массив с вместимостью: " << capacity << endl;
    }
    else {
        capacity = 10;
        size = 0;
        data = new int[capacity];
        cout << "Некорректный размер. Создан массив по умолчанию (вместимость: 10)" << endl;
    }
}

// Конструктор копирования
Array::Array(const Array& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    cout << "Создана копия массива (размер: " << size << ", вместимость: " << capacity << ")" << endl;
}

// Деструктор
Array::~Array() {
    cout << "Удалён массив (размер: " << size << ", вместимость: " << capacity << ")" << endl;
    delete[] data;
}

// Оператор присваивания
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Выполнено присваивание массива" << endl;
    }
    return *this;
}

// Заполнение с клавиатуры
void Array::fillFromKeyboard() {
    cout << "Введите количество элементов (не более " << capacity << "): ";
    int n;
    cin >> n;

    if (n > capacity) {
        cout << "Превышена вместимость. Будет введено " << capacity << " элементов" << endl;
        n = capacity;
    }

    size = n;
    cout << "Введите " << size << " целых чисел:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> data[i];
    }
    cout << "Массив успешно заполнен" << endl;
}

// Заполнение случайными числами
void Array::fillRandom(int minVal, int maxVal) {
    srand(static_cast<unsigned int>(time(nullptr)));  // Явное преобразование time_t -> unsigned int
    for (int i = 0; i < size; i++) {
        data[i] = minVal + rand() % (maxVal - minVal + 1);
    }
    cout << "Массив заполнен случайными числами от " << minVal << " до " << maxVal << endl;
}

// Отображение содержимого
void Array::display() const {
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return;
    }

    cout << "Содержимое массива (размер: " << size << "): ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Изменение размера
void Array::resize(int newCapacity) {
    if (newCapacity <= 0) {
        cout << "Некорректный размер" << endl;
        return;
    }

    int* newData = new int[newCapacity];
    int newSize = (size < newCapacity) ? size : newCapacity;

    for (int i = 0; i < newSize; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    size = newSize;

    cout << "Массив изменён: новая вместимость = " << capacity << ", новый размер = " << size << endl;
}

// Сортировка массива
void Array::sort() {
    if (size <= 1) {
        cout << "Массив слишком мал для сортировки" << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Массив отсортирован по возрастанию" << endl;
}

// Минимальное значение
int Array::getMin() const {
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return 0;
    }

    int minVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < minVal) {
            minVal = data[i];
        }
    }
    return minVal;
}

// Максимальное значение
int Array::getMax() const {
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return 0;
    }

    int maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

// Добавление элемента
void Array::addElement(int value) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size] = value;
    size++;
    cout << "Добавлен элемент: " << value << endl;
}