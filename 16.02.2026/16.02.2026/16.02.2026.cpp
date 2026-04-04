#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Fraction.h"
#include "Person.h"
#include "String.h"
#include "House.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");



    cout << "\n\n ЗАДАНИЕ 1: КЛАСС «ДРОБЬ» " << endl;

    Fraction f1(2, 3);
    Fraction f2(3, 4);

    cout << "f1 = "; f1.print(); cout << endl;
    cout << "f2 = "; f2.print(); cout << endl;

    cout << "\n Арифметические операции " << endl;
    Fraction sum = f1.add(f2);
    cout << "f1 + f2 = "; sum.print(); cout << endl;

    Fraction diff = f1.subtract(f2);
    cout << "f1 - f2 = "; diff.print(); cout << endl;

    Fraction prod = f1.multiply(f2);
    cout << "f1 * f2 = "; prod.print(); cout << endl;

    cout << "\n Операции с целым числом " << endl;
    Fraction sumInt = f1.add(2);
    cout << "f1 + 2 = "; sumInt.print(); cout << endl;

    cout << "\n Цепочки вызовов (используя this) " << endl;
    Fraction f3(1, 2);
    cout << "f3 = "; f3.print(); cout << endl;

    f3.addToThis(f1).multiplyByThis(f2);
    cout << "(f3 + f1) * f2 = "; f3.print(); cout << endl;

    
    cout << "\n\n ЗАДАНИЕ 2: КЛАСС «ЧЕЛОВЕК» " << endl;

    Date birth1(15, 5, 1990);
    Person p1(1, "Иванов", "Иван", "Иванович", birth1);
    p1.print();

    cout << "\n--- Копирование человека ---" << endl;
    Person p2 = p1;
    p2.setId(2);
    p2.print();

    cout << "\n--- Статический счётчик ---" << endl;
    cout << "Всего создано людей: " << Person::getTotalCount() << endl;

    
    cout << "\n\n ЗАДАНИЕ 3: КЛАСС «СТРОКА» " << endl;

    String s1("Привет, мир!");
    s1.print();

    String s2(20);
    s2.print();

    String s3 = s1;
    s3.print();

    s2.setString("Новая строка");
    s2.print();

    
    cout << "\n\n ЗАДАНИЕ 4: МНОГОКВАРТИРНЫЙ ДОМ " << endl;

    House house("ул. Ленина, д. 10");

    // Создаём квартиры и жильцов
    Date birth2(10, 3, 1985);
    Date birth3(20, 7, 1992);
    Date birth4(5, 12, 1978);

    Person person1(1, "Петров", "Пётр", "Сергеевич", birth2);
    Person person2(2, "Сидорова", "Анна", "Ивановна", birth3);
    Person person3(3, "Козлов", "Дмитрий", "Алексеевич", birth4);

    Apartment apt1(1);
    apt1.addResident(person1);
    apt1.addResident(person2);

    Apartment apt2(2);
    apt2.addResident(person3);

    house.addApartment(apt1);
    house.addApartment(apt2);

    house.print();

    // Демонстрация доступа к квартире
    cout << "\n Доступ к квартире 1 через getApartment() " << endl;
    Apartment& apt = house.getApartment(0);
    apt.print();
 
    return 0;
}