#include <iostream>
#include <vector>
#include "String.h"
#include "Array.h"
#include "Book.h"
#include "Worker.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");



    //  ДЕМОНСТРАЦИЯ РАБОТЫ С КЛАССОМ STRING 


    // Демонстрация конструкторов
    cout << "1. Конструктор по умолчанию:" << endl;
    String s1;
    s1.display();

    cout << "\n2. Конструктор с размером 30:" << endl;
    String s2(30);
    s2.display();

    cout << "\n3. Конструктор с инициализацией:" << endl;
    String s3("Привет, мир!");
    s3.display();

    cout << "\n4. Конструктор копирования:" << endl;
    String s4(s3);
    s4.display();

    // Демонстрация ввода с клавиатуры
    cout << "\n5. Ввод строки с клавиатуры:" << endl;
    cin.ignore(); // Очистка буфера
    String s5;
    s5.inputFromKeyboard();
    s5.display();

    //  ДЕМОНСТРАЦИЯ РАБОТЫ С КЛАССОМ ARRAY 

    // Создание массива
    cout << "1. Создание массива:" << endl;
    Array arr1(5);

    // Заполнение массива
    cout << "\n2. Заполнение массива:" << endl;
    arr1.fillFromKeyboard();
    arr1.display();

    // Демонстрация добавления элементов
    cout << "\n3. Добавление элементов:" << endl;
    arr1.addElement(100);
    arr1.addElement(200);
    arr1.display();

    // Поиск минимального и максимального значения
    cout << "\n4. Поиск min и max:" << endl;
    cout << "Минимальное значение: " << arr1.getMin() << endl;
    cout << "Максимальное значение: " << arr1.getMax() << endl;

    // Сортировка
    cout << "\n5. Сортировка массива:" << endl;
    arr1.sort();
    arr1.display();

    // Демонстрация конструктора копирования
    cout << "\n6. Конструктор копирования:" << endl;
    Array arr2 = arr1;
    arr2.display();

    // Демонстрация изменения размера
    cout << "\n7. Изменение размера массива:" << endl;
    arr1.resize(10);
    arr1.display();

    // Заполнение случайными числами
    cout << "\n8. Демонстрация со случайными числами:" << endl;
    Array arr3(8);
    // Заполняем массив значениями вручную, чтобы потом заполнить случайными
    for (int i = 0; i < 8; i++) {
        arr3.addElement(0);
    }
    arr3.fillRandom(1, 100);
    arr3.display();
    cout << "Минимум: " << arr3.getMin() << ", Максимум: " << arr3.getMax() << endl;
    arr3.sort();
    cout << "После сортировки: ";
    arr3.display();

    //  ДЕМОНСТРАЦИЯ РАБОТЫ С КЛАССОМ BOOK 

    // Создание массива книг
    vector<Book> library;

    // Добавление книг
    library.push_back(Book("Лев Толстой", "Война и мир", "Эксмо", 1869, 1300));
    library.push_back(Book("Фёдор Достоевский", "Преступление и наказание", "АСТ", 1866, 672));
    library.push_back(Book("Михаил Булгаков", "Мастер и Маргарита", "Вагриус", 1967, 480));
    library.push_back(Book("Александр Пушкин", "Евгений Онегин", "Наука", 1833, 352));
    library.push_back(Book("Николай Гоголь", "Мёртвые души", "Худлит", 1842, 432));

    cout << "\n--- Все книги в библиотеке ---" << endl;
    for (const auto& book : library) {
        book.display();
        cout << endl;
    }

    // Список книг заданного автора
    string targetAuthor = "Михаил Булгаков";
    cout << "\n--- Книги автора: " << targetAuthor << " ---" << endl;
    for (const auto& book : library) {
        if (book.getAuthor() == targetAuthor) {
            book.display();
            cout << endl;
        }
    }

    // Список книг, выпущенных заданным издательством
    string targetPublisher = "Эксмо";
    cout << "\n--- Книги издательства: " << targetPublisher << " ---" << endl;
    for (const auto& book : library) {
        if (book.getPublisher() == targetPublisher) {
            book.display();
            cout << endl;
        }
    }

    // Список книг, выпущенных после заданного года
    int targetYear = 1900;
    cout << "\n--- Книги, выпущенные после " << targetYear << " года ---" << endl;
    for (const auto& book : library) {
        if (book.getYear() > targetYear) {
            book.display();
            cout << endl;
        }
    }

    // Демонстрация explicit конструктора
    // 
    // Book b = 2000; // Ошибка! explicit запрещает неявное преобразование
    Book b(2000); // Правильный способ вызова explicit конструктора
    b.display();

    //  ДЕМОНСТРАЦИЯ РАБОТЫ С КЛАССОМ WORKER 


    // Создание массива работников
    vector<Worker> staff;

    // Добавление работников
    staff.push_back(Worker("Иванов Иван Иванович", "Программист", 2018, 80000));
    staff.push_back(Worker("Петров Пётр Петрович", "Менеджер", 2015, 95000));
    staff.push_back(Worker("Сидорова Анна Сергеевна", "Аналитик", 2020, 70000));
    staff.push_back(Worker("Козлов Дмитрий Алексеевич", "Программист", 2019, 85000));
    staff.push_back(Worker("Смирнова Елена Владимировна", "Тестировщик", 2021, 60000));

    cout << "\n--- Все работники ---" << endl;
    for (const auto& worker : staff) {
        worker.display();
        cout << endl;
    }

    int currentYear = 2026;
    int targetExperience = 5;

    // Список работников со стажем более targetExperience лет
    cout << "\n--- Работники со стажем более " << targetExperience << " лет ---" << endl;
    for (const auto& worker : staff) {
        if (worker.getExperience(currentYear) > targetExperience) {
            worker.display();
            cout << "Стаж: " << worker.getExperience(currentYear) << " лет" << endl << endl;
        }
    }

    // Список работников с зарплатой выше заданной
    double targetSalary = 75000;
    cout << "\n--- Работники с зарплатой выше " << targetSalary << " руб. ---" << endl;
    for (const auto& worker : staff) {
        if (worker.getSalary() > targetSalary) {
            worker.display();
            cout << endl;
        }
    }

    // Список работников с заданной должностью
    string targetPosition = "Программист";
    cout << "\n--- Работники с должностью: " << targetPosition << " ---" << endl;
    for (const auto& worker : staff) {
        if (worker.getPosition() == targetPosition) {
            worker.display();
            cout << endl;
        }
    }

    // Демонстрация explicit конструктора

    // Worker w = 50000; // Ошибка! explicit запрещает неявное преобразование
    Worker w(50000); // Правильный способ вызова explicit конструктора
    w.display();


    return 0;
}