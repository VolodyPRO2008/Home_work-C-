#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class Library {
private:
    string name;
    vector<Book*> books;  // Агрегация: хранит указатели, не управляет временем жизни

public:
    Library(const string& n = "Неизвестная библиотека");
    Library(const Library& other);
    ~Library();

    void addBook(Book* book);  // Добавление книги (по указателю)
    void removeBook(const string& isbn);
    Book* getBook(int index);
    int getBookCount() const;

    void print() const;

    Library& operator=(const Library& other);
};

#endif