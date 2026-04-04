#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pageCount;

public:
    // explicit конструктор
    explicit Book(int year = 0);

    // Полный конструктор
    Book(const string& author, const string& title, const string& publisher,
        int year, int pageCount);

    // Конструктор копирования
    Book(const Book& other);

    // Константные методы для отображения информации
    void display() const;

    // Геттеры (константные методы)
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getPageCount() const { return pageCount; }

    // Сеттеры
    void setAuthor(const string& author) { this->author = author; }
    void setTitle(const string& title) { this->title = title; }
    void setPublisher(const string& publisher) { this->publisher = publisher; }
    void setYear(int year) { this->year = year; }
    void setPageCount(int pageCount) { this->pageCount = pageCount; }
};

#endif