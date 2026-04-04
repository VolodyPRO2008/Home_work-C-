#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string isbn;

public:
    Book(const string& t = "Без названия", const string& a = "Неизвестен", int y = 0, const string& i = "");
    Book(const Book& other);
    ~Book();

    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    string getIsbn() const;

    void setTitle(const string& t);
    void setAuthor(const string& a);
    void setYear(int y);
    void setIsbn(const string& i);

    void print() const;

    Book& operator=(const Book& other);
};

#endif