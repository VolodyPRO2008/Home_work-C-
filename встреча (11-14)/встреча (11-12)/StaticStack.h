#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>

using namespace std;

template<typename T, int MAX_SIZE = 100>
class StaticStack {
private:
    T data[MAX_SIZE];
    int topIndex;

public:
    StaticStack();
    ~StaticStack();

    // Основные операции
    void Push(const T& value);     // Помещение символа в стек
    T Pop();                        // Выталкивание символа из стека
    T Peek() const;                 // Получение верхнего символа без выталкивания
    int GetCount() const;           // Подсчёт количества символов
    bool IsEmpty() const;           // Проверка пустой ли стек
    bool IsFull() const;            // Проверка полный ли стек
    void Clear();                   // Очистка стека

    void Print() const;             // Вывод стека (для отладки)
};

template<typename T, int MAX_SIZE>
StaticStack<T, MAX_SIZE>::StaticStack() : topIndex(-1) {
    cout << "[StaticStack] Создан стек, макс. размер = " << MAX_SIZE << endl;
}

template<typename T, int MAX_SIZE>
StaticStack<T, MAX_SIZE>::~StaticStack() {
    cout << "[StaticStack] Стек уничтожен" << endl;
}

template<typename T, int MAX_SIZE>
void StaticStack<T, MAX_SIZE>::Push(const T& value) {
    if (IsFull()) {
        cout << "Ошибка: стек полон, нельзя добавить " << value << endl;
        return;
    }
    topIndex++;
    data[topIndex] = value;
    cout << "Добавлен элемент: " << value << " (теперь в стеке " << GetCount() << " элементов)" << endl;
}

template<typename T, int MAX_SIZE>
T StaticStack<T, MAX_SIZE>::Pop() {
    if (IsEmpty()) {
        cout << "Ошибка: стек пуст" << endl;
        return T();
    }
    T value = data[topIndex];
    topIndex--;
    cout << "Удалён элемент: " << value << " (осталось " << GetCount() << " элементов)" << endl;
    return value;
}

template<typename T, int MAX_SIZE>
T StaticStack<T, MAX_SIZE>::Peek() const {
    if (IsEmpty()) {
        cout << "Стек пуст" << endl;
        return T();
    }
    return data[topIndex];
}

template<typename T, int MAX_SIZE>
int StaticStack<T, MAX_SIZE>::GetCount() const {
    return topIndex + 1;
}

template<typename T, int MAX_SIZE>
bool StaticStack<T, MAX_SIZE>::IsEmpty() const {
    return topIndex == -1;
}

template<typename T, int MAX_SIZE>
bool StaticStack<T, MAX_SIZE>::IsFull() const {
    return topIndex == MAX_SIZE - 1;
}

template<typename T, int MAX_SIZE>
void StaticStack<T, MAX_SIZE>::Clear() {
    topIndex = -1;
    cout << "Стек очищен" << endl;
}

template<typename T, int MAX_SIZE>
void StaticStack<T, MAX_SIZE>::Print() const {
    if (IsEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }

    cout << "Стек (сверху вниз): ";
    for (int i = topIndex; i >= 0; i--) {
        cout << data[i];
        if (i > 0) cout << " <- ";
    }
    cout << " (всего: " << GetCount() << ")" << endl;
}

#endif