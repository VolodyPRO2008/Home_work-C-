#include <iostream>
#include "fraction.h"
#include "PhoneBook.h"
#include "String.h"
using namespace std;

int main() {
    setlocale(0, "Ru");

    Fraction f1, f2;
    cout << "Введите первую дробь:\n";
    f1.input();
    cout << "Введите вторую дробь:\n";
    f2.input();
    cout << "f1 = "; f1.output(); cout << endl;
    cout << "f2 = "; f2.output(); cout << endl;
    Fraction sum = f1.add(f2);
    cout << "Сумма = "; sum.output(); cout << endl;


    PhoneBook pb;
    int choice;
    do {
        cout << "\n1. Добавить абонента\n";
        cout << "2. Удалить абонента\n";
        cout << "3. Найти абонента\n";
        cout << "4. Показать всех\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        char name[100];
        switch (choice) {
        case 1: pb.addAbonent(); break;
        case 2: cout << "Введите ФИО: "; cin.ignore(); cin.getline(name, 100); pb.removeAbonent(name); break;
        case 3: cout << "Введите ФИО: "; cin.ignore(); cin.getline(name, 100); pb.searchByName(name); break;
        case 4: pb.showAll(); break;
        case 5: pb.saveToFile("phonebook.txt"); break;
        case 6: pb.loadFromFile("phonebook.txt"); break;
        }
    } while (choice != 0);

    String s1;
    String s2(50);
    String s3("Hello, world!");
    cout << "s3: "; s3.output();
    cout << "Создано объектов: " << String::getObjectCount() << endl;
    s1.input();
    cout << "s1: "; s1.output();

    return 0;
}