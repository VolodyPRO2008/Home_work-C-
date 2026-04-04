#include <iostream>
#include "Set.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");



    // 1. Демонстрация конструкторов
    cout << "\n 1. СОЗДАНИЕ МАССИВОВ "<< endl;

    Set set1;
    cout << "Массив set1: " << set1 << endl;

    Set set2(5);
    cout << "Массив set2: " << set2 << endl;

    // 2. Демонстрация добавления элементов
    cout << "\n 2. ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ" << endl;

    set1.add(3);
    set1.add(8);
    set1.add(46);
    set1.add(5);
    set1.add(11);
    set1.add(3);  // Попытка добавить дубликат

    cout << "Массив set1 после добавления: " << set1 << endl;

    // 3. Демонстрация оператора += и + для элементов
    cout << "\n 3. ОПЕРАТОРЫ ДОБАВЛЕНИЯ (+=, +) " << endl;

    set2 += 18;
    set2 += 8;
    set2 += 90;
    set2 += 11;
    set2 += 2;

    cout << "Массив set2 (через +=): " << set2 << endl;

    Set set3 = set1 + 99;
    cout << "set1 + 99 = " << set3 << endl;

    // 4. Демонстрация оператора удаления
    cout << "\n 4. ОПЕРАТОРЫ УДАЛЕНИЯ (-=, -) " << endl;

    set1 -= 46;
    cout << "set1 после удаления 46: " << set1 << endl;

    Set set4 = set2 - 90;
    cout << "set2 - 90 = " << set4 << endl;

    // 5. Демонстрация объединения массивов
    cout << "\n 5. ОБЪЕДИНЕНИЕ МАССИВОВ (+, +=) " << endl;

    cout << "set1 = " << set1 << endl;
    cout << "set2 = " << set2 << endl;

    Set unionSet = set1 + set2;
    cout << "set1 + set2 (объединение) = " << unionSet << endl;

    // 6. Демонстрация пересечения масива
    cout << "\n 6. ПЕРЕСЕЧЕНИЕ МАССИВОВ (*, *=) " << endl;

    Set intersectSet = set1 * set2;
    cout << "set1 * set2 (пересечение) = " << intersectSet << endl;

    // 7. Демонстрация разности массива
    cout << "\n 7. РАЗНОСТЬ МАССИВОВ (-, -=) " << endl;

    Set diffSet = set1 - set2;
    cout << "set1 - set2 (разность) = " << diffSet << endl;

    // 8. Демонстрация сравнения массивов
    cout << "\n--- 8. СРАВНЕНИЕ МАССИВОВ (==, !=) ---" << endl;

    Set set5;
    set5.add(3);
    set5.add(8);
    set5.add(5);
    set5.add(11);

    cout << "set1 = " << set1 << endl;
    cout << "set5 = " << set5 << endl;

    if (set1 == set5) {
        cout << "set1 и set5 равны" << endl;
    }
    else {
        cout << "set1 и set5 не равны" << endl;
    }

    // 9. Демонстрация конструктора копирования
    cout << "\n 9. КОНСТРУКТОР КОПИРОВАНИЯ " << endl;

    Set set6(set1);
    cout << "Копия set1 (set6) = " << set6 << endl;

    // 10. Демонстрация оператора присваивания
    cout << "\n 10. ОПЕРАТОР ПРИСВАИВАНИЯ (=) " << endl;

    Set set7;
    set7 = set2;
    cout << "set7 после присваивания set2: " << set7 << endl;

    // 11. Демонстрация проверки принадлежности элемента
    cout << "\n 11. ПРОВЕРКА ПРИНАДЛЕЖНОСТИ ЭЛЕМЕНТА " << endl;

    int testValue = 8;
    if (set1.contains(testValue)) {
        cout << "Элемент " << testValue << " принадлежит массиву set1" << endl;
    }
    else {
        cout << "Элемент " << testValue << " не принадлежит массиву set1" << endl;
    }

    testValue = 100;
    if (set1.contains(testValue)) {
        cout << "Элемент " << testValue << " принадлежит массиву set1" << endl;
    }
    else {
        cout << "Элемент " << testValue << " не принадлежит массиву set1" << endl;
    }

    // 12. Демонстрация сложных операций
    cout << "\n 12. СЛОЖНЫЕ ОПЕРАЦИИ С МАССИВАМИ " << endl;

    Set A, B;
    A += 1; A += 2; A += 3; A += 4; A += 5;
    B += 3; B += 4; B += 5; B += 6; B += 7;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A ∪ B = " << (A + B) << endl;
    cout << "A ∩ B = " << (A * B) << endl;
    cout << "A \\ B = " << (A - B) << endl;
    cout << "B \\ A = " << (B - A) << endl;

    // 13. Демонстрация ввода с клавиатуры
    cout << "\n--- 13. ВВОД МАССИВА С КЛАВИАТУРЫ ---" << endl;

    Set set8;
    cin >> set8;
    cout << "Введённое множество: " << set8 << endl;


    return 0;
}