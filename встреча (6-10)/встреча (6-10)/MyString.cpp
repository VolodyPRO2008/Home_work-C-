#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"

MyString::MyString() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
    cout << "Создана пустая строка" << endl;
}

MyString::MyString(const char* input) {
    if (input != nullptr) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
    }
    else {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    cout << "Создана строка: \"" << str << "\"" << endl;
}

MyString::MyString(const MyString& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
    cout << "Создана копия строки" << endl;
}

MyString::~MyString() {
    cout << "Уничтожена строка: \"" << str << "\"" << endl;
    delete[] str;
}

bool MyString::contains(char c) const {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) return true;
    }
    return false;
}

bool MyString::alreadyInResult(char c, const char* result, int resultLen) const {
    for (int i = 0; i < resultLen; i++) {
        if (result[i] == c) return true;
    }
    return false;
}

MyString MyString::operator*(const MyString& other) const {
    char* result = new char[length + 1];
    int resultIndex = 0;

    for (int i = 0; i < length; i++) {
        if (other.contains(str[i]) && !alreadyInResult(str[i], result, resultIndex)) {
            result[resultIndex++] = str[i];
        }
    }

    result[resultIndex] = '\0';
    MyString resultStr(result);
    delete[] result;
    return resultStr;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    return *this;
}

ostream& operator<<(ostream& output, const MyString& s) {
    output << s.str;
    return output;
}

istream& operator>>(istream& input, MyString& s) {
    char buffer[1000];
    input >> buffer;
    s = MyString(buffer);
    return input;
}