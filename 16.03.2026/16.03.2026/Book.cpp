#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"

Book::Book(const string& t, const string& a, int y, const string& i)
    : title(t), author(a), year(y), isbn(i) {
    cout << "[Книга] Создана: \"" << title << "\" (" << author << ", " << year << ")" << endl;
}

Book::Book(const Book& other)
    : title(other.title), author(other.author), year(other.year), isbn(other.isbn) {
    cout << "[Книга] Создана копия: \"" << title << "\"" << endl;
}

Book::~Book() {
    cout << "[Книга] Уничтожена: \"" << title << "\"" << endl;
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
string Book::getIsbn() const { return isbn; }

void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }
void Book::setYear(int y) { year = y; }
void Book::setIsbn(const string& i) { isbn = i; }

void Book::print() const {
    cout << "Книга: \"" << title << "\", " << author << ", " << year << " (ISBN: " << isbn << ")" << endl;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        year = other.year;
        isbn = other.isbn;
    }
    return *this;
}