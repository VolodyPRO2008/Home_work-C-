#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "IntArray.h"
#include "Buffer.h"

using namespace std;

// Функция для демонстрации возврата временного объекта
IntArray createTempArray() {
    IntArray temp(5);
    for (size_t i = 0; i < 5; i++) {
        temp[i] = static_cast<int>(i + 1) * 10;
    }
    cout << "  Временный массив создан внутри функции" << endl;
    return temp; // Возвращает временный объект -> move constructor
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "                    ЗАДАНИЕ 1: КЛАСС IntArray                     " << endl;


    cout << "\n 1.1 Конструктор по умолчанию " << endl;
    IntArray arr1;  // Default constructor

    cout << "\n 1.2 Конструктор от размера " << endl;
    IntArray arr2(5);  // Constructor from size
    for (size_t i = 0; i < 5; i++) {
        arr2[i] = static_cast<int>(i + 1);
    }
    arr2.print();

    cout << "\n 2.1 Конструктор копирования " << endl;
    IntArray arr3(arr2);  // Copy constructor
    arr3.print();


    cout << "\n 3.1 Конструктор перемещения из временного объекта " << endl;
    IntArray arr4(createTempArray());  // Move constructor (from temporary)
    arr4.print();


    cout << "\n 4.1 Конструктор перемещения с std::move " << endl;
    IntArray arr5(std::move(arr2));  // Move constructor
    cout << "arr5 после перемещения: ";
    arr5.print();
    cout << "arr2 после перемещения (должен быть пустым): ";
    arr2.print();  // Должен быть пустым


    cout << "\n 5.1 Оператор присваивания копированием " << endl;
    IntArray arr6;
    arr6 = arr3;  // Copy assignment
    arr6.print();


    cout << "\n 6.1 Оператор присваивания перемещением " << endl;
    IntArray arr7;
    arr7 = std::move(arr3);  // Move assignment
    cout << "arr7 после перемещения: ";
    arr7.print();
    cout << "arr3 после перемещения (должен быть пустым): ";
    arr3.print();  // Должен быть пустым


    cout << "\n 7.1 Деструкторы вызовутся автоматически " << endl;



    cout << "                    ЗАДАНИЕ 4: КЛАСС BUFFER                     " << endl;


    // Демонстрация работы Buffer с перемещением
    cout << "\n--- Создание Buffer ---" << endl;
    Buffer buf1(100);

    cout << "\n--- Копирование (МЕДЛЕННО) ---" << endl;
    Buffer buf2 = buf1;  // Copy constructor (медленно)

    cout << "\n--- Перемещение (БЫСТРО) с помощью std::move ---" << endl;
    Buffer buf3 = std::move(buf1);  // Move constructor (быстро)

    cout << "\n--- Оператор присваивания перемещением ---" << endl;
    Buffer buf4;
    buf4 = std::move(buf2);  // Move assignment (быстро)

    cout << "\n--- Состояние объектов после перемещения ---" << endl;
    cout << "buf1: ";
    buf1.print();  // Должен быть пустым
    cout << "buf3: ";
    buf3.print();


    cout << "\n--- Демонстрация важности noexcept для std::vector ---" << endl;
    cout << "При реаллокации vector использует перемещение, если оно noexcept" << endl;

    vector<Buffer> buffers;
    cout << "\nДобавляем элементы в vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\n--- Итерация " << i + 1 << " ---" << endl;
        buffers.push_back(Buffer(10));  // Move constructor (благодаря noexcept)
    }


    return 0;
}