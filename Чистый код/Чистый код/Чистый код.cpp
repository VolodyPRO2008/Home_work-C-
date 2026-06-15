#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Константы
const int MIN_PRIORITY = 1;
const int MAX_PRIORITY = 5;
const int TOP_COUNT = 3;

// Структура задачи
struct Task {
    string description;
    int priority;
    bool isCompleted;

    Task(const string& desc, int prio)
        : description(desc), priority(prio), isCompleted(false) {
    }
};

// Проверка приоритета
bool isValidPriority(int p) {
    return p >= MIN_PRIORITY && p <= MAX_PRIORITY;
}

// Очистка буфера
void clearCin() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// Ввод числа
int inputNumber(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cout << "Ошибка! Введите число от " << minVal << " до " << maxVal << endl;
            clearCin();
        }
        else {
            clearCin();
            return value;
        }
    }
}

// Ввод строки
string inputString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// Ввод всех задач
vector<Task> inputTasks() {
    int count = inputNumber("Количество задач (1-100): ", 1, 100);
    vector<Task> tasks;

    for (int i = 0; i < count; i++) {
        cout << "\nЗадача " << i + 1 << ":\n";
        string desc = inputString("  Описание: ");
        if (desc.empty()) desc = "Без описания";

        int priority = inputNumber("  Приоритет (1-5): ", MIN_PRIORITY, MAX_PRIORITY);
        tasks.push_back(Task(desc, priority));
    }

    return tasks;
}

// Сортировка по приоритету (убывание)
void sortByPriority(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(),
        [](const Task& a, const Task& b) {
            return a.priority > b.priority;
        });
}

// Вывод задач
void printTasks(const vector<Task>& tasks, const string& title, int limit = -1) {
    cout << "\n=== " << title << " ===\n";

    if (tasks.empty()) {
        cout << "Нет задач.\n";
        return;
    }

    int count = (limit > 0 && limit < (int)tasks.size()) ? limit : tasks.size();

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i].description
            << " (приоритет: " << tasks[i].priority << ")\n";
    }
}

// Основная функция
int main() {
    setlocale(LC_ALL, "Russian");


    vector<Task> tasks = inputTasks();

    if (tasks.empty()) {
        cout << "Нет задач для отображения.\n";
        return 0;
    }

    printTasks(tasks, "Все задачи");

    sortByPriority(tasks);
    printTasks(tasks, "Топ-" + to_string(TOP_COUNT), TOP_COUNT);

    return 0;
}