#include "Cat.h"

// === Cat ===
Cat::Cat(const string& name, int age, const string& color)
    : name(name), age(age), color(color) {
    cout << "Создан объект Cat: " << name << endl;
}

Cat::~Cat() {
    cout << "Cat \"" << name << "\" уничтожен" << endl;
}

void Cat::printInfo() const {
    cout << "=== Информация о кошке ===" << endl;
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << " лет" << endl;
    cout << "Окрас: " << color << endl;
}

void Cat::sound() const {
    cout << name << " издаёт звук: Мяу!" << endl;
}

// === HouseCat ===
HouseCat::HouseCat(const string& name, int age, const string& color, const string& owner)
    : Cat(name, age, color), ownerName(owner) {
    cout << "Добавлены свойства домашней кошки" << endl;
}

HouseCat::~HouseCat() {
    cout << "HouseCat \"" << name << "\" уничтожен" << endl;
}

void HouseCat::sound() const {
    cout << name << " мурлычет: Мрр-мрр-мрр" << endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    cout << "Имя хозяина: " << ownerName << endl;
}

void HouseCat::play() const {
    cout << name << " играет с мячиком" << endl;
}

// === WildCat ===
WildCat::WildCat(const string& name, int age, const string& color, const string& habitat)
    : Cat(name, age, color), habitat(habitat) {
    cout << "Добавлены свойства дикой кошки" << endl;
}

WildCat::~WildCat() {
    cout << "WildCat \"" << name << "\" уничтожен" << endl;
}

void WildCat::sound() const {
    cout << name << " рычит: Рррр!" << endl;
}

void WildCat::printInfo() const {
    Cat::printInfo();
    cout << "Среда обитания: " << habitat << endl;
}

void WildCat::hunt() const {
    cout << name << " охотится" << endl;
}

// === PersianCat ===
PersianCat::PersianCat(const string& name, int age, const string& color, int woolLength)
    : Cat(name, age, color), woolLength(woolLength) {
    cout << "Добавлены свойства персидской кошки" << endl;
}

PersianCat::~PersianCat() {
    cout << "PersianCat \"" << name << "\" уничтожен" << endl;
}

void PersianCat::sound() const {
    cout << name << " тихо говорит: Мяу" << endl;
}

void PersianCat::printInfo() const {
    Cat::printInfo();
    cout << "Длина шерсти: " << woolLength << " см" << endl;
}

void PersianCat::groom() const {
    cout << name << " нуждается в груминге" << endl;
}