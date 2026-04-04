#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Room.h"
#include "House.h"
#include "Processor.h"
#include "Computer.h"
#include "Student.h"
#include "University.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");




    cout << "\n\n ПРИМЕР 1: КОМПОЗИЦИЯ (ДОМ И КОМНАТЫ) " << endl;
    cout << "\n Создание дома и комнат " << endl;

    House myHouse("ул. Пушкина, д. 10");

    myHouse.addRoom("Гостиная", 25.5, 2);
    myHouse.addRoom("Спальня", 18.0, 1);
    myHouse.addRoom("Кухня", 12.0, 1);
    myHouse.addRoom("Ванная", 6.0, 0);

    myHouse.print();

    cout << "\n Удаление комнаты " << endl;
    myHouse.removeRoom(2);  // Удаляем кухню

    myHouse.print();

    cout << "\n Копирование дома " << endl;
    House houseCopy = myHouse;
    houseCopy.print();


    cout << "\n\n ПРИМЕР 2: КОМПОЗИЦИЯ (КОМПЬЮТЕР И ПРОЦЕССОР) " << endl;
    cout << "\n Создание компьютера " << endl;

    Computer myPC("Dell", "Intel Core i7-12700K", 3.6, 12, 32, 1000);
    myPC.print();

    cout << "\n Копирование компьютера " << endl;
    Computer pcCopy = myPC;
    pcCopy.print();


    cout << "\n\n ПРИМЕР 3: АГРЕГАЦИЯ (УНИВЕРСИТЕТ И СТУДЕНТЫ) " << endl;
    cout << "\n Создание студентов  " << endl;

    Student s1(1001, "Иванов Иван", 4.8);
    Student s2(1002, "Петрова Мария", 5.0);
    Student s3(1003, "Сидоров Алексей", 4.2);

    cout << "\n Создание университета и зачисление студентов " << endl;

    University university("МГУ им. Ломоносова");

    university.enrollStudent(&s1);
    university.enrollStudent(&s2);
    university.enrollStudent(&s3);

    university.print();

    cout << "\n Отчисление студента " << endl;
    university.expelStudent(1002);

    university.print();

    cout << "\n Копирование университета (копируются только ссылки) " << endl;
    University uniCopy = university;
    uniCopy.print();

    // Студенты существуют независимо от университета
    cout << "\n Студенты продолжают существовать после уничтожения университета " << endl;
    s1.print();
    s2.print();
    s3.print();


    cout << "\n\n ПРИМЕР 4: АГРЕГАЦИЯ (БИБЛИОТЕКА И КНИГИ) " << endl;
    cout << "\n Создание книг (независимые объекты) " << endl;

    Book b1("Война и мир", "Лев Толстой", 1869, "978-5-17-118888-5");
    Book b2("Преступление и наказание", "Фёдор Достоевский", 1866, "978-5-17-119999-7");
    Book b3("Мастер и Маргарита", "Михаил Булгаков", 1967, "978-5-17-120000-0");

    cout << "\n Создание библиотеки и добавление книг " << endl;

    Library library("Российская государственная библиотека");

    library.addBook(&b1);
    library.addBook(&b2);
    library.addBook(&b3);

    library.print();

    cout << "\n Удаление книги из библиотеки " << endl;
    library.removeBook("978-5-17-119999-7");

    library.print();

    cout << "\n--- Книги продолжают существовать после удаления из библиотеки ---" << endl;
    b2.print();





    return 0;
}