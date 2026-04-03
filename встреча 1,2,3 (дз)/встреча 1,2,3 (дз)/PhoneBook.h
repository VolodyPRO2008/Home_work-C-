#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
using namespace std;

class Abonent {
private:
    string fullName;        // теперь string, а не char*
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    Abonent();
    Abonent(const string& name, const string& home, const string& work, const string& mobile, const string& info);

    string getFullName() const;
    void display() const;
    friend class PhoneBook;
};

class PhoneBook {
private:
    Abonent* abonents;      // массив объектов, а не указателей
    int count;
    int capacity;
    void resize();

public:
    PhoneBook();
    ~PhoneBook();
    void addAbonent();
    void removeAbonent(const string& name);
    void searchByName(const string& name) const;
    void showAll() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};

#endif