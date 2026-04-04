#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

// Базовый класс Animal
class Animal {
public:
    // Виртуальный метод (будет переопределён в производных классах)
    virtual void speak() const;

    // Виртуальный деструктор (для корректного удаления через указатель на базовый класс)
    virtual ~Animal();
};

// Производный класс Dog
class Dog : public Animal {
public:
    void speak() const override;
    ~Dog();
};

// Производный класс Cat
class Cat : public Animal {
public:
    void speak() const override;
    ~Cat();
};

// Производный класс Cow
class Cow : public Animal {
public:
    void speak() const override;
    ~Cow();
};

// Производный класс Horse
class Horse : public Animal {
public:
    void speak() const override;
    ~Horse();
};

// Дополнительный класс Bird (по желанию)
class Bird : public Animal {
public:
    void speak() const override;
    ~Bird();
};

#endif