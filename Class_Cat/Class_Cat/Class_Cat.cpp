#include "Cat.h"
#include <memory>

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание объектов разных типов
    HouseCat murka("Мурка", 3, "рыжий", "Анна");
    cout << endl;

    WildCat lynx("Рысь", 5, "пятнистый", "тайга");
    cout << endl;

    PersianCat fluffy("Пушинка", 2, "белый", 8);
    cout << endl;

    HouseCat barsik("Барсик", 4, "серый", "Иван");
    cout << endl;

    WildCat tiger("Тигр", 7, "полосатый", "джунгли");
    cout << endl;

    // Демонстрация цепочки вызовов конструкторов и деструкторов видна при создании
    // и будет видна при уничтожении объектов в конце main()


    // HouseCat
    cout << "--- Домашняя кошка Мурка ---" << endl;
    murka.printInfo();
    murka.sound();
    murka.play();
    cout << endl;

    // WildCat
    cout << "--- Дикая кошка Рысь ---" << endl;
    lynx.printInfo();
    lynx.sound();
    lynx.hunt();
    cout << endl;

    // PersianCat
    cout << "--- Персидская кошка Пушинка ---" << endl ;
    fluffy.printInfo();
    fluffy.sound();
    fluffy.groom();
    cout << endl << endl;

    Cat* catPtr1 = &murka;
    Cat* catPtr2 = &lynx;
    Cat* catPtr3 = &fluffy;

    cout << "Вызов sound() через указатель на Cat (объект HouseCat): ";
    catPtr1->sound();  // Вызовется Cat::sound(), а не HouseCat::sound()
    cout << endl << endl;
    cout << "Вызов sound() через указатель на Cat (объект WildCat): ";
    catPtr2->sound();  // Вызовется Cat::sound()
    cout << endl << endl;
    cout << "Вызов sound() через указатель на Cat (объект PersianCat): ";
    catPtr3->sound();  // Вызовется Cat::sound()
    cout << endl << endl;
    cout << "\nВызов printInfo() через указатель на Cat: " << endl;
    catPtr1->printInfo();  // Вызовется Cat::printInfo() без информации о хозяине
    cout << endl << endl;

    Cat& catRef = murka;
    cout << "Вызов sound() через ссылку на Cat: ";
    catRef.sound();  // Также вызовется Cat::sound()

    return 0;
}