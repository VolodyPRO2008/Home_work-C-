#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

// Константы
const int TOP_STUDENTS_COUNT = 3;


class Student {
private:
    string name;
    vector<int> grades;
    double average;

public:
    // Конструктор
    Student(const string& studentName, const vector<int>& studentGrades)
        : name(studentName)
        , grades(studentGrades)
    {
        calculateAverage();
    }

    // Получение имени
    string getName() const {
        return name;
    }

    // Получение оценок
    const vector<int>& getGrades() const {
        return grades;
    }

    // Получение среднего балла
    double getAverage() const {
        return average;
    }

    // Вычисление среднего балла
    void calculateAverage() {
        if (grades.empty()) {
            average = 0.0;
            return;
        }

        int sum = accumulate(grades.begin(), grades.end(), 0);
        average = static_cast<double>(sum) / grades.size();
    }

    // Добавление оценки
    void addGrade(int grade) {
        grades.push_back(grade);
        calculateAverage();
    }

    // Вывод информации о студенте
    void print() const {
        cout << name << " - средний балл: " << average;
    }
};



// Ввод целого числа с проверкой
int inputInt(const string& prompt, int minValue = 1, int maxValue = 1000)
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < minValue || value > maxValue) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число от " << minValue << " до " << maxValue << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Ввод строки (с поддержкой пробелов)
string inputString(const string& prompt)
{
    string value;
    cout << prompt;
    getline(cin, value);

    // Удаляем лишние пробелы в начале и конце
    size_t start = value.find_first_not_of(" \t");
    size_t end = value.find_last_not_of(" \t");

    if (start == string::npos) {
        return "";
    }

    return value.substr(start, end - start + 1);
}

// Ввод оценок
vector<int> inputGrades(int count)
{
    vector<int> grades;

    for (int i = 0; i < count; i++) {
        int grade = inputInt("  Оценка " + to_string(i + 1) + " (2-5): ", 2, 5);
        grades.push_back(grade);
    }

    return grades;
}

// Ввод одного студента
Student inputStudent()
{
    cout << "\n--- Новый студент ---\n";
    string name = inputString("Введите имя студента: ");

    int gradesCount = inputInt("Введите количество оценок (1-20): ", 1, 20);
    vector<int> grades = inputGrades(gradesCount);

    return Student(name, grades);
}

// Ввод всех студентов
vector<Student> inputStudents()
{
    int studentCount = inputInt("\nВведите количество студентов (1-50): ", 1, 50);

    vector<Student> students;
    students.reserve(studentCount);  // Зарезервируем память заранее

    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент " << i + 1 << " из " << studentCount << endl;
        students.push_back(inputStudent());
    }

    return students;
}


// Вывод всех студентов
void printAllStudents(const vector<Student>& students)
{

    cout << "Список всех студентов:\n";


    for (const auto& student : students) {
        cout << "  ";
        student.print();
        cout << endl;
    }
}

// Вывод топ N студентов
void printTopStudents(const vector<Student>& students, int topCount)
{

    cout << "Топ " << topCount << " студентов:\n";


    int actualCount = min(topCount, static_cast<int>(students.size()));

    for (int i = 0; i < actualCount; i++) {
        cout << "  " << i + 1 << ". ";
        students[i].print();
        cout << endl;
    }

    if (students.size() < topCount) {
        cout << "  (Всего студентов: " << students.size() << ")\n";
    }
}

// ОБРАБОТКА ДАННЫХ


// Сортировка студентов по среднему баллу (по убыванию)
vector<Student> sortByAverage(const vector<Student>& students)
{
    vector<Student> sorted = students;  // Копируем

    sort(sorted.begin(), sorted.end(),
        [](const Student& a, const Student& b) {
            return a.getAverage() > b.getAverage();
        });

    return sorted;
}

// Нахождение топ N студентов без полной сортировки (эффективнее)
vector<Student> getTopStudents(const vector<Student>& students, int topCount)
{
    if (students.size() <= topCount) {
        return sortByAverage(students);
    }

    // Копируем и частично сортируем
    vector<Student> result = students;

    // nth_element ставит топ N элементов в начало, но не сортирует их
    nth_element(result.begin(),
        result.begin() + topCount,
        result.end(),
        [](const Student& a, const Student& b) {
            return a.getAverage() > b.getAverage();
        });

    // Сортируем только топ N
    sort(result.begin(), result.begin() + topCount,
        [](const Student& a, const Student& b) {
            return a.getAverage() > b.getAverage();
        });

    return result;
}



int main()
{
    setlocale(LC_ALL, "Russian");


    cout << "Система учета успеваемоси\n";


    // Ввод данных
    vector<Student> students = inputStudents();

    if (students.empty()) {
        cout << "Нет данных для отображения!\n";
        return 1;
    }

    // Вывод исходного списка
    printAllStudents(students);

    // Сортировка
    vector<Student> sortedStudents = sortByAverage(students);

    // Вывод топ студентов (более эффективный способ)
    vector<Student> topStudents = getTopStudents(sortedStudents, TOP_STUDENTS_COUNT);
    printTopStudents(topStudents, TOP_STUDENTS_COUNT);

    // Вывод отсортированного списка

    cout << "Отсортированный список (по убыванию):\n";


    for (const auto& student : sortedStudents) {
        cout << "  ";
        student.print();
        cout << endl;
    }

    // Статистика

    cout << "Статистика:\n";

    cout << "  Всего студентов: " << students.size() << endl;

    // Общий средний балл
    double totalAverage = 0.0;
    for (const auto& student : sortedStudents) {
        totalAverage += student.getAverage();
    }
    totalAverage /= students.size();
    cout << "  Общий средний балл: " << totalAverage << endl;

    // Максимальный и минимальный балл
    double maxAverage = sortedStudents.front().getAverage();
    double minAverage = sortedStudents.back().getAverage();
    cout << "  Максимальный средний балл: " << maxAverage << endl;
    cout << "  Минимальный средний балл: " << minAverage << endl;

    cout << "\nПрограмма завершена успешно!\n";

    return 0;
}