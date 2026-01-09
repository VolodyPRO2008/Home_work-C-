#include <iostream>

using namespace std;

// Задание 1
void task1() {
    cout << "\tЗадание 1" << endl;
    cout << "Копирование массива" << endl;

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int source[n];
    int dest[n];

    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(source + i);
    }

    // Копирование с использованием арифметики указателей
    int* src_ptr = source;
    int* dst_ptr = dest;

    for (int i = 0; i < n; i++) {
        *(dst_ptr + i) = *(src_ptr + i);
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << *(source + i) << " ";
    }

    cout << "\nСкопированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << *(dest + i) << " ";
    }
    cout << endl;
}

// Задание 2
void task2() {
    cout << "\n\tЗадание 2" << endl;
    cout << "Разворот массива" << endl;

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[n];

    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }

    // Разворот массива
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    cout << "\nМассив после разворота: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Задание 3
void task3() {
    cout << "\n\tЗадание 3" << endl;
    cout << "Копирование с разворотом" << endl;

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int source[n];
    int dest[n];

    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(source + i);
    }

    // Копирование с разворотом через указатели
    int* src_ptr = source;
    int* dst_ptr = dest + n - 1;

    for (int i = 0; i < n; i++) {
        *(dst_ptr - i) = *(src_ptr + i);
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << *(source + i) << " ";
    }

    cout << "\nСкопированный массив в обратном порядке: ";
    for (int i = 0; i < n; i++) {
        cout << *(dest + i) << " ";
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "Выберите задание:" << endl;
        cout << "1. Копирование массива" << endl;
        cout << "2. Разворот массива" << endl;
        cout << "3. Копирование с разворотом" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}