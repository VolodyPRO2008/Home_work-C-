#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class MyString {
public:
    char* str;
    int length;

    MyString();
    MyString(const char* input);
    MyString(const MyString& other);
    ~MyString();

    // Вспомогательные функции (в public)
    bool contains(char c) const;
    bool alreadyInResult(char c, const char* result, int resultLen) const;

    // Операторы
    MyString operator*(const MyString& other) const;
    MyString& operator=(const MyString& other);

    friend ostream& operator<<(ostream& output, const MyString& s);
    friend istream& operator>>(istream& input, MyString& s);
};

#endif