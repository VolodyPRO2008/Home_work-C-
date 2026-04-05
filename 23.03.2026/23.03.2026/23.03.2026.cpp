#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "BankAccount.h"
#include "SafeDivision.h"
#include "DivisionByZeroException.h"
#include "IntArray.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");



    cout << "\n\n ЗАДАНИЕ 1: КЛАСС BANKACCOUNT " << endl;

    // 1.1 Создание счёта с положительным балансом
    cout << "\n 1.1 Создание счёта с положительным балансом " << endl;
    try {
        BankAccount account1("Иван Петров", 5000);
        account1.print();
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 1.2 Попытка создать счёт с отрицательным балансом (выбросит исключение)
    cout << "\n 1.2 Попытка создать счёт с отрицательным балансом " << endl;
    try {
        BankAccount account2("Анна Сидорова", -1000);
        account2.print();
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 1.3 Работа со счётом (пополнение и снятие)
    cout << "\n 1.3 Работа со счётом (пополнение и снятие) " << endl;
    try {
        BankAccount account3("Пётр Иванов", 10000);
        account3.print();

        // Пополнение
        account3.deposit(2000);

        // Снятие (в пределах баланса)
        account3.withdraw(3000);

        // Попытка снять больше, чем есть (выбросит исключение)
        account3.withdraw(15000);

    }
    catch (const invalid_argument& e) {
        cout << "Ошибка аргумента: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Ошибка выполнения: " << e.what() << endl;
    }

    // 1.4 Попытка снять отрицательную сумму
    cout << "\n 1.4 Попытка снять отрицательную сумму " << endl;
    try {
        BankAccount account4("Мария Петрова", 5000);
        account4.withdraw(-500);
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }


    cout << "\n\n ЗАДАНИЕ 2: КЛАСС SAFEDIVISION " << endl;

    // 2.1 Деление на ненулевое число
    cout << "\n 2.1 Деление на ненулевое число " << endl;
    try {
        double result = SafeDivision::divide(10.0, 2.0);
        cout << "10 / 2 = " << result << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 2.2 Деление на ноль (выбросит исключение)
    cout << "\n 2.2 Деление на ноль " << endl;
    try {
        double result = SafeDivision::divide(10.0, 0.0);
        cout << "10 / 0 = " << result << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 2.3 Деление с отрицательными числами
    cout << "\n 2.3 Деление с отрицательными числами " << endl;
    try {
        double result1 = SafeDivision::divide(-10.0, 2.0);
        cout << "-10 / 2 = " << result1 << endl;

        double result2 = SafeDivision::divide(10.0, -2.0);
        cout << "10 / -2 = " << result2 << endl;

        double result3 = SafeDivision::divide(-10.0, -2.0);
        cout << "-10 / -2 = " << result3 << endl;

    }
    catch (const DivisionByZeroException& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 2.4 Несколько делений подряд
    cout << "\n 2.4 Несколько делений подряд " << endl;
    double numbers[] = { 100, 50, 25, 12.5, 0, 6.25 };

    for (int i = 0; i < 5; i++) {
        try {
            double result = SafeDivision::divide(numbers[i], numbers[i + 1]);
            cout << numbers[i] << " / " << numbers[i + 1] << " = " << result << endl;
        }
        catch (const DivisionByZeroException& e) {
            cout << "Ошибка при делении " << numbers[i] << " / " << numbers[i + 1]
                << ": " << e.what() << endl;
        }
    }


    cout << "\n\n ЗАДАНИЕ 3: КЛАСС INTARRAY " << endl;

    // 3.1 Создание массива и работа с ним
    cout << "\n 3.1 Создание массива и работа с ним " << endl;
    try {
        IntArray arr(5);
        arr.fill(10);
        arr.print();

        // Заполнение через оператор []
        for (int i = 0; i < arr.getSize(); i++) {
            arr[i] = (i + 1) * 10;
        }
        arr.print();

        // Доступ через метод at (в пределах границ)
        cout << "arr.at(2) = " << arr.at(2) << endl;
        arr.at(2) = 100;
        cout << "После arr.at(2) = 100: ";
        arr.print();

    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    // 3.2 Попытка создать массив с неверным размером
    cout << "\n 3.2 Попытка создать массив с неверным размером " << endl;
    try {
        IntArray arr(-5);
    }
    catch (const invalid_argument& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 3.3 Попытка доступа по неверному индексу
    cout << "\n 3.3 Попытка доступа по неверному индексу " << endl;
    try {
        IntArray arr(3);
        arr.fill(5);
        arr.print();

        // Доступ по индексу вне границ (выбросит исключение)
        cout << "Попытка доступа к arr.at(5)..." << endl;
        int value = arr.at(5);
        cout << "Значение: " << value << endl;

    }
    catch (const out_of_range& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    // 3.4 Демонстрация обработки нескольких исключений
    cout << "\n 3.4 Демонстрация обработки нескольких исключений " << endl;

    int indices[] = { -1, 0, 2, 5, 10 };

    try {
        IntArray arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr.print();

        for (int i = 0; i < 5; i++) {
            try {
                cout << "Попытка доступа к индексу " << indices[i] << ": ";
                int value = arr.at(indices[i]);
                cout << "значение = " << value << endl;
            }
            catch (const out_of_range& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
        }

    }
    catch (const invalid_argument& e) {
        cout << "Ошибка создания массива: " << e.what() << endl;
    }

    // 3.5 Демонстрация конструктора копирования и оператора присваивания
    cout << "\n 3.5 Конструктор копирования и оператор присваивания " << endl;
    try {
        IntArray arr1(4);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr1[3] = 4;

        cout << "arr1: ";
        arr1.print();

        // Конструктор копирования
        IntArray arr2 = arr1;
        cout << "arr2 (копия arr1): ";
        arr2.print();

        // Оператор присваивания
        IntArray arr3(2);
        arr3 = arr1;
        cout << "arr3 (после присваивания arr1): ";
        arr3.print();

    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }


  

    cout << "\n Демонстрация перехвата всех исключений (...) " << endl;
    try {
        // Любой код, который может выбросить исключение
        IntArray arr(3);
        arr.at(10);  // Выбросит out_of_range
    }
    catch (const out_of_range& e) {
        cout << "Перехвачено out_of_range: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Перехвачено invalid_argument: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Перехвачено runtime_error: " << e.what() << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << "Перехвачено DivisionByZeroException: " << e.what() << endl;
    }
    catch (...) {
        cout << "Перехвачено неизвестное исключение" << endl;
    }


    return 0;
}