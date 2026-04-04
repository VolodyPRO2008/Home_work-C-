#include "Book.h"

// explicit конструктор
Book::Book(int year) : year(year) {
    author = "Неизвестен";
    title = "Без названия";
    publisher = "Неизвестно";
    pageCount = 0;
    cout << "Создана книга-заглушка (explicit конструктор)" << endl;
}

// Полный конструктор
Book::Book(const string& author, const string& title, const string& publisher,
    int year, int pageCount)
    : author(author), title(title), publisher(publisher), year(year), pageCount(pageCount) {
    cout << "Создана книга: \"" << title << "\" автора " << author << endl;
}

// Конструктор копирования
Book::Book(const Book& other)
    : author(other.author), title(other.title), publisher(other.publisher),
    year(other.year), pageCount(other.pageCount) {
    cout << "Создана копия книги: \"" << title << "\"" << endl;
}

// Константный метод для отображения информации
void Book::display() const {
    cout << "=== Книга ===" << endl;
    cout << "Автор: " << author << endl;
    cout << "Название: " << title << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Год издания: " << year << endl;
    cout << "Количество страниц: " << pageCount << endl;
}