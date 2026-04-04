#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

using namespace std;

// Базовый класс Cat
class Cat {
protected:
    string name;
    int age;
    string color;

public:
    // Конструктор
    Cat(const string& name, int age, const string& color);

    // Виртуальный деструктор для корректного удаления через указатель на базовый класс
    virtual ~Cat();

    // Методы
    void printInfo() const;
    void sound() const;

    // Геттеры (опционально)
    string getName() const { return name; }
    int getAge() const { return age; }
    string getColor() const { return color; }
};

// Производный класс HouseCat
class HouseCat : public Cat {
private:
    string ownerName;

public:
    HouseCat(const string& name, int age, const string& color, const string& owner);
    ~HouseCat();

    void sound() const;
    void printInfo() const;
    void play() const;
};

// Производный класс WildCat
class WildCat : public Cat {
private:
    string habitat;

public:
    WildCat(const string& name, int age, const string& color, const string& habitat);
    ~WildCat();

    void sound() const;
    void printInfo() const;
    void hunt() const;
};

// Производный класс PersianCat
class PersianCat : public Cat {
private:
    int woolLength;

public:
    PersianCat(const string& name, int age, const string& color, int woolLength);
    ~PersianCat();

    void sound() const;
    void printInfo() const;
    void groom() const;
};

#endif