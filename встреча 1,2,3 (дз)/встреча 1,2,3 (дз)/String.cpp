#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

int String::objectCount = 0;

String::String() : length(80) {
    data = new char[length + 1];
    data[0] = '\0';
    objectCount++;
}

String::String(int size) : length(size) {
    data = new char[length + 1];
    data[0] = '\0';
    objectCount++;
}

String::String(const char* str) : length(strlen(str)) {
    data = new char[length + 1];
    strcpy_s(data, length + 1, str);  
    objectCount++;
}

String::~String() {
    delete[] data;
    objectCount--;
}

void String::input() {
    cout << "Enter string: ";
    cin.getline(data, length + 1);
}

void String::output() const {
    cout << data << endl;
}

int String::getObjectCount() {
    return objectCount;
}