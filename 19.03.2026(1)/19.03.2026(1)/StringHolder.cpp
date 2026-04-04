#define _CRT_SECURE_NO_WARNINGS

#include "StringHolder.h"

// ========== StringHolder ==========
StringHolder::StringHolder(const char* input) {
    if (input != nullptr) {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
        cout << "Конструктор: выделена память для \"" << str << "\"" << endl;
    }
    else {
        str = new char[1];
        str[0] = '\0';
        cout << "Конструктор: выделена память для пустой строки" << endl;
    }
}

StringHolder::~StringHolder() {
    cout << "Деструктор: освобождена память для \"" << (str ? str : "nullptr") << "\"" << endl;
    delete[] str;
}

void StringHolder::print() const {
    cout << "Исходная строка: \"" << (str ? str : "") << "\"" << endl;
}

const char* StringHolder::getString() const {
    return str;
}

// ========== ReverseString ==========
ReverseString::ReverseString(const char* input) : StringHolder(input) {
    // Выделяем память для перевёрнутой строки
    int len = strlen(str);
    reversedStr = new char[len + 1];

    // Создаём перевёрнутую копию
    for (int i = 0; i < len; i++) {
        reversedStr[i] = str[len - 1 - i];
    }
    reversedStr[len] = '\0';

    cout << "Конструктор: создана перевёрнутая версия \"" << reversedStr << "\"" << endl;
}

ReverseString::~ReverseString() {
    cout << "Деструктор: освобождена память для перевёрнутой строки \"" << reversedStr << "\"" << endl;
    delete[] reversedStr;
}

void ReverseString::print() const {
    cout << "Перевёрнутая строка: \"" << reversedStr << "\" (оригинал: \"" << str << "\")" << endl;
}