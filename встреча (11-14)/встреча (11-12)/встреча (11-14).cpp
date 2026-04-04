#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "TemplateFunctions.h"
#include "Array.h"
#include "StaticStack.h"
#include "DynamicStack.h"
#include "Queue.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "\n\n ВСТРЕЧА 11: ШАБЛОНЫ ФУНКЦИЙ " << endl;

    // Задание 1: Среднее арифметическое
    cout << "\n--- Задание 1: Среднее арифметическое ---" << endl;
    int intArr[] = { 10, 20, 30, 40, 50 };
    double doubleArr[] = { 1.5, 2.5, 3.5, 4.5 };

    cout << "Массив int: [10, 20, 30, 40, 50]" << endl;
    cout << "Среднее = " << arrayAverage(intArr, 5) << endl;
    cout << "Массив double: [1.5, 2.5, 3.5, 4.5]" << endl;
    cout << "Среднее = " << arrayAverage(doubleArr, 4) << endl;

    // Задание 2: Корни уравнений
    cout << "\n--- Задание 2: Корни уравнений ---" << endl;

    cout << "Линейное уравнение: 2*x + 4 = 0" << endl;
    double root;
    if (solveLinear(2, 4, root)) {
        cout << "Корень: x = " << root << endl;
    }

    cout << "\nЛинейное уравнение: 0*x + 5 = 0" << endl;
    if (!solveLinear(0, 5, root)) {
        cout << "Решений нет" << endl;
    }

    cout << "\nКвадратное уравнение: 1*x^2 - 3*x + 2 = 0" << endl;
    double root1, root2;
    int rootsCount = solveQuadratic(1, -3, 2, root1, root2);
    if (rootsCount == 2) {
        cout << "Корни: x1 = " << root1 << ", x2 = " << root2 << endl;
    }
    else if (rootsCount == 1) {
        cout << "Корень: x = " << root1 << endl;
    }

    cout << "\nКвадратное уравнение: 1*x^2 + 2*x + 5 = 0" << endl;
    solveQuadratic(1, 2, 5, root1, root2);

    // Задание 3 и 4: Максимум и минимум
    cout << "\n Задание 3 и 4: Максимум и минимум из двух " << endl;
    cout << "max(10, 20) = " << maxOfTwo(10, 20) << endl;
    cout << "min(10, 20) = " << minOfTwo(10, 20) << endl;
    cout << "max(3.14, 2.71) = " << maxOfTwo(3.14, 2.71) << endl;
    cout << "min(3.14, 2.71) = " << minOfTwo(3.14, 2.71) << endl;
    cout << "max('A', 'Z') = " << maxOfTwo('A', 'Z') << endl;
    cout << "min('A', 'Z') = " << minOfTwo('A', 'Z') << endl;
    cout << "max(Hello, World) = " << maxOfTwo(string("Hello"), string("World")) << endl;


    cout << "\n\n ВСТРЕЧА 12: ШАБЛОННЫЙ КЛАСС ARRAY " << endl;

    Array<int> arr(5, 3);
    arr.Print();

    cout << "\n--- Добавление элементов ---" << endl;
    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);
    arr.Add(50);
    arr.Add(60);  // Должен расшириться
    arr.Print();

    cout << "\n--- Доступ по индексу ---" << endl;
    cout << "Элемент [2]: " << arr[2] << endl;
    arr[2] = 100;
    cout << "После arr[2] = 100: ";
    arr.Print();

    cout << "\n--- GetAt и SetAt ---" << endl;
    cout << "GetAt(1): " << arr.GetAt(1) << endl;
    arr.SetAt(1, 999);
    cout << "После SetAt(1, 999): ";
    arr.Print();

    cout << "\n--- Вставка и удаление ---" << endl;
    arr.InsertAt(2, 888);
    arr.Print();

    int newValues[] = { 777, 666, 555 };
    arr.InsertAt(4, newValues, 3);
    arr.Print();

    arr.RemoveAt(3, 2);
    arr.Print();

    cout << "\n--- Append (сложение массивов) ---" << endl;
    Array<int> arr2;
    arr2.Add(1000);
    arr2.Add(2000);
    arr2.Add(3000);
    arr.Append(arr2);
    arr.Print();

    cout << "\n--- GetUpperBound, IsEmpty, FreeExtra, RemoveAll ---" << endl;
    cout << "GetUpperBound(): " << arr.GetUpperBound() << endl;
    cout << "IsEmpty(): " << (arr.IsEmpty() ? "Да" : "Нет") << endl;
    cout << "GetSize(): " << arr.GetSize() << endl;
    arr.FreeExtra();
    cout << "После FreeExtra размер: " << arr.GetSize() << endl;

    cout << "\n--- RemoveAll ---" << endl;
    arr.RemoveAll();
    arr.Print();


    cout << "\n\n ВСТРЕЧА 13: СТЕК " << endl;

    // Задание 1: Статический стек (символьный)
    cout << "\n Задание 1: Статический стек (символьный) " << endl;
    StaticStack<char, 5> staticStack;

    cout << "IsEmpty(): " << (staticStack.IsEmpty() ? "Да" : "Нет") << endl;

    staticStack.Push('A');
    staticStack.Push('B');
    staticStack.Push('C');
    staticStack.Push('D');
    staticStack.Push('E');
    staticStack.Push('F');  // Попытка добавить в полный стек

    staticStack.Print();

    cout << "Peek(): " << staticStack.Peek() << endl;
    cout << "GetCount(): " << staticStack.GetCount() << endl;
    cout << "IsFull(): " << (staticStack.IsFull() ? "Да" : "Нет") << endl;

    staticStack.Pop();
    staticStack.Pop();
    staticStack.Print();

    staticStack.Clear();
    staticStack.Print();

    // Задание 2: Динамический стек
    cout << "\n Задание 2: Динамический стек (целочисленный) " << endl;
    DynamicStack<int> dynamicStack(3, 2);

    dynamicStack.Push(10);
    dynamicStack.Push(20);
    dynamicStack.Push(30);
    dynamicStack.Push(40);  // Должен расшириться
    dynamicStack.Push(50);
    dynamicStack.Print();

    cout << "Peek(): " << dynamicStack.Peek() << endl;

    dynamicStack.Pop();
    dynamicStack.Pop();
    dynamicStack.Print();

    cout << "GetCount(): " << dynamicStack.GetCount() << endl;
    cout << "GetCapacity(): " << dynamicStack.GetCapacity() << endl;

    dynamicStack.Clear();
    dynamicStack.Print();

    // Демонстрация конструктора копирования и оператора присваивания
    cout << "\n Конструктор копирования и оператор присваивания " << endl;
    DynamicStack<int> dynamicStack2 = dynamicStack;  // Копирование

    DynamicStack<int> dynamicStack3;
    dynamicStack3 = dynamicStack;  // Присваивание


    cout << "\n\n ВСТРЕЧА 14: ОЧЕРЕДЬ " << endl;

    // Задание 1: Обычная очередь
    cout << "\n Задание 1: Обычная очередь (целочисленная) " << endl;
    Queue<int, 10> queue;

    cout << "IsEmpty(): " << (queue.IsEmpty() ? "Да" : "Нет") << endl;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Show();

    cout << "Peek(): " << queue.Peek() << endl;
    cout << "GetCount(): " << queue.GetCount() << endl;

    queue.Dequeue();
    queue.Dequeue();
    queue.Show();

    queue.Enqueue(60);
    queue.Enqueue(70);
    queue.Show();

    queue.Clear();
    queue.Show();

    // Задание 2 и 3: Очередь с приоритетами (шаблонная)
    cout << "\n Задание 2 и 3: Очередь с приоритетами (шаблонная) " << endl;
    PriorityQueue<string, 20> priorityQueue;

    priorityQueue.InsertWithPriority("Задача 1 (низкий)", 1);
    priorityQueue.InsertWithPriority("Срочная задача (высокий)", 10);
    priorityQueue.InsertWithPriority("Обычная задача (средний)", 5);
    priorityQueue.InsertWithPriority("Критическая задача (макс)", 100);
    priorityQueue.InsertWithPriority("Задача 2 (низкий)", 2);

    priorityQueue.Show();

    cout << "\n--- Peek (просмотр без удаления) ---" << endl;
    priorityQueue.Peek();

    cout << "\n--- Извлечение элементов по приоритету ---" << endl;
    while (!priorityQueue.IsEmpty()) {
        priorityQueue.PullHighestPriorityElement();
    }

    priorityQueue.Show();



    return 0;
}