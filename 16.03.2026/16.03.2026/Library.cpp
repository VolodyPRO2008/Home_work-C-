#define _CRT_SECURE_NO_WARNINGS

#include "Library.h"

Library::Library(const string& n) : name(n) {
    cout << "[Библиотека] Создана: " << name << endl;
}

Library::Library(const Library& other) : name(other.name) {
    // Агрегация: копируем только указатели
    for (Book* b : other.books) {
        books.push_back(b);
    }
    cout << "[Библиотека] Создана копия: " << name << endl;
}

Library::~Library() {
    cout << "[Библиотека] Уничтожена: " << name << endl;
    // Агрегация: НЕ удаляем книги
    books.clear();
}

void Library::addBook(Book* book) {
    if (book != nullptr) {
        books.push_back(book);
        cout << "[Библиотека] Добавлена книга: \"" << book->getTitle() << "\" в " << name << endl;
    }
}

void Library::removeBook(const string& isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getIsbn() == isbn) {
            cout << "[Библиотека] Удалена книга: \"" << (*it)->getTitle() << "\" из " << name << endl;
            books.erase(it);
            return;
        }
    }
    cout << "Книга с ISBN " << isbn << " не найдена" << endl;
}

Book* Library::getBook(int index) {
    if (index >= 0 && index < (int)books.size()) {
        return books[index];
    }
    return nullptr;
}

int Library::getBookCount() const {
    return books.size();
}

void Library::print() const {
    cout << "\n=== БИБЛИОТЕКА: " << name << " ===" << endl;
    cout << "Количество книг: " << books.size() << endl;
    for (size_t i = 0; i < books.size(); i++) {
        cout << "  " << i + 1 << ". ";
        books[i]->print();
    }
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        name = other.name;
        books.clear();
        for (Book* b : other.books) {
            books.push_back(b);
        }
    }
    return *this;
}