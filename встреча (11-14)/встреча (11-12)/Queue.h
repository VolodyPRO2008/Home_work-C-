#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

// ============================================
// ЗАДАНИЕ №1: Обычная очередь (шаблонная)
// ============================================
template<typename T, int MAX_SIZE = 100>
class Queue {
private:
    T data[MAX_SIZE];
    int front;      // Индекс начала очереди
    int rear;       // Индекс конца очереди
    int count;      // Количество элементов

public:
    Queue();
    ~Queue();

    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(const T& value);   // Добавление в очередь
    T Dequeue();                     // Удаление из очереди
    T Peek() const;                  // Просмотр первого элемента
    int GetCount() const;
    void Clear();
    void Show() const;
};

template<typename T, int MAX_SIZE>
Queue<T, MAX_SIZE>::Queue() : front(0), rear(-1), count(0) {
    cout << "[Queue] Создана очередь, макс. размер = " << MAX_SIZE << endl;
}

template<typename T, int MAX_SIZE>
Queue<T, MAX_SIZE>::~Queue() {
    cout << "[Queue] Очередь уничтожена" << endl;
}

template<typename T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::IsEmpty() const {
    return count == 0;
}

template<typename T, int MAX_SIZE>
bool Queue<T, MAX_SIZE>::IsFull() const {
    return count == MAX_SIZE;
}

template<typename T, int MAX_SIZE>
void Queue<T, MAX_SIZE>::Enqueue(const T& value) {
    if (IsFull()) {
        cout << "Ошибка: очередь полна, нельзя добавить " << value << endl;
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = value;
    count++;
    cout << "Добавлен элемент: " << value << " (теперь в очереди " << count << " элементов)" << endl;
}

template<typename T, int MAX_SIZE>
T Queue<T, MAX_SIZE>::Dequeue() {
    if (IsEmpty()) {
        cout << "Ошибка: очередь пуста" << endl;
        return T();
    }
    T value = data[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    cout << "Удалён элемент: " << value << " (осталось " << count << " элементов)" << endl;
    return value;
}

template<typename T, int MAX_SIZE>
T Queue<T, MAX_SIZE>::Peek() const {
    if (IsEmpty()) {
        cout << "Очередь пуста" << endl;
        return T();
    }
    return data[front];
}

template<typename T, int MAX_SIZE>
int Queue<T, MAX_SIZE>::GetCount() const {
    return count;
}

template<typename T, int MAX_SIZE>
void Queue<T, MAX_SIZE>::Clear() {
    front = 0;
    rear = -1;
    count = 0;
    cout << "Очередь очищена" << endl;
}

template<typename T, int MAX_SIZE>
void Queue<T, MAX_SIZE>::Show() const {
    if (IsEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Очередь (с начала к концу): ";
    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX_SIZE;
        cout << data[index];
        if (i < count - 1) cout << " <- ";
    }
    cout << " (всего: " << count << ")" << endl;
}

// ============================================
// ЗАДАНИЕ №2 и №3: Очередь с приоритетами (шаблонная)
// ============================================
template<typename T, int MAX_SIZE = 100>
class PriorityQueue {
private:
    struct PriorityItem {
        T value;
        int priority;
    };

    PriorityItem data[MAX_SIZE];
    int count;
    int growStep;

public:
    PriorityQueue(int grow = 10);
    ~PriorityQueue();

    bool IsEmpty() const;
    bool IsFull() const;
    void InsertWithPriority(const T& value, int priority);  // Добавление с приоритетом
    T PullHighestPriorityElement();                         // Удаление с самым высоким приоритетом
    T Peek() const;                                          // Просмотр элемента с высоким приоритетом
    int GetCount() const;
    void Show() const;
};

template<typename T, int MAX_SIZE>
PriorityQueue<T, MAX_SIZE>::PriorityQueue(int grow) : count(0), growStep(grow) {
    cout << "[PriorityQueue] Создана очередь с приоритетами, макс. размер = " << MAX_SIZE << endl;
}

template<typename T, int MAX_SIZE>
PriorityQueue<T, MAX_SIZE>::~PriorityQueue() {
    cout << "[PriorityQueue] Очередь с приоритетами уничтожена" << endl;
}

template<typename T, int MAX_SIZE>
bool PriorityQueue<T, MAX_SIZE>::IsEmpty() const {
    return count == 0;
}

template<typename T, int MAX_SIZE>
bool PriorityQueue<T, MAX_SIZE>::IsFull() const {
    return count == MAX_SIZE;
}

template<typename T, int MAX_SIZE>
void PriorityQueue<T, MAX_SIZE>::InsertWithPriority(const T& value, int priority) {
    if (IsFull()) {
        cout << "Ошибка: очередь полна" << endl;
        return;
    }

    // Вставляем в конец
    data[count].value = value;
    data[count].priority = priority;
    count++;

    // Сортируем по убыванию приоритета (чем больше число, тем выше приоритет)
    for (int i = count - 1; i > 0; i--) {
        if (data[i].priority > data[i - 1].priority) {
            PriorityItem temp = data[i];
            data[i] = data[i - 1];
            data[i - 1] = temp;
        }
        else {
            break;
        }
    }

    cout << "Добавлен элемент: " << value << " (приоритет = " << priority
        << "), теперь в очереди " << count << " элементов" << endl;
}

template<typename T, int MAX_SIZE>
T PriorityQueue<T, MAX_SIZE>::PullHighestPriorityElement() {
    if (IsEmpty()) {
        cout << "Ошибка: очередь пуста" << endl;
        return T();
    }

    T value = data[0].value;
    int priority = data[0].priority;

    // Сдвигаем элементы влево
    for (int i = 0; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;

    cout << "Удалён элемент с наивысшим приоритетом: " << value
        << " (приоритет = " << priority << "), осталось " << count << " элементов" << endl;
    return value;
}

template<typename T, int MAX_SIZE>
T PriorityQueue<T, MAX_SIZE>::Peek() const {
    if (IsEmpty()) {
        cout << "Очередь пуста" << endl;
        return T();
    }
    cout << "Элемент с наивысшим приоритетом: " << data[0].value
        << " (приоритет = " << data[0].priority << ")" << endl;
    return data[0].value;
}

template<typename T, int MAX_SIZE>
int PriorityQueue<T, MAX_SIZE>::GetCount() const {
    return count;
}

template<typename T, int MAX_SIZE>
void PriorityQueue<T, MAX_SIZE>::Show() const {
    if (IsEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Очередь с приоритетами (от высшего к низшему):" << endl;
    for (int i = 0; i < count; i++) {
        cout << "  " << i + 1 << ". Значение: " << data[i].value
            << ", приоритет: " << data[i].priority << endl;
    }
    cout << "Всего элементов: " << count << endl;
}

#endif