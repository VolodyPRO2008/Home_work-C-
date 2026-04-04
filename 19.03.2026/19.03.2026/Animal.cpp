#define _CRT_SECURE_NO_WARNINGS

#include "Animal.h"

// ========== Animal ==========
void Animal::speak() const {
    cout << "I am an animal" << endl;
}

Animal::~Animal() {
    cout << "Деструктор животными" << endl;
}

// ========== Dog ==========
void Dog::speak() const {
    cout << "Гав! Гав!" << endl;
}

Dog::~Dog() {
    cout << "Деструктор собаки" << endl;
}

// ========== Cat ==========
void Cat::speak() const {
    cout << "Мяу!" << endl;
}

Cat::~Cat() {
    cout << "Деструктор кошку" << endl;
}

// ========== Cow ==========
void Cow::speak() const {
    cout << "Мууу!" << endl;
}

Cow::~Cow() {
    cout << " Деструктор коровы" << endl;
}

// ========== Horse ==========
void Horse::speak() const {
    cout << "И-го-го!" << endl;
}

Horse::~Horse() {
    cout << "Деструктор лошоди" << endl;
}

// ========== Bird (дополнительно) ==========
void Bird::speak() const {
    cout << "Чирик-чирик!" << endl;
}

Bird::~Bird() {
    cout << "Деструктор птицы" << endl;
}