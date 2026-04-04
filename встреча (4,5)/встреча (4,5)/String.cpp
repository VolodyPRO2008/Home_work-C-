#include "String.h"
#include <cstring>

// Конструктор по умолчанию (80 символов)
String::String() {
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    cout << "Создана пустая строка размером 80 символов" << endl;
}

// Конструктор для создания строки произвольного размера
String::String(int size) {
    if (size > 0) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        cout << "Создана пустая строка размером " << length << " символов" << endl;
    }
    else {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
        cout << "Некорректный размер. Создана строка размером 80 символов" << endl;
    }
}

// Конструктор для инициализации строкой от пользователя
String::String(const char* input) {
    if (input != nullptr) {
        length = static_cast<int>(strlen(input));  // Явное преобразование size_t -> int
        str = new char[length + 1];
        // Используем strcpy_s вместо strcpy для безопасности
#ifdef _WIN32
        strcpy_s(str, length + 1, input);
#else
        strcpy(str, input);
#endif
        cout << "Создана строка: \"" << str << "\"" << endl;
    }
    else {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
        cout << "Создана пустая строка размером 80 символов" << endl;
    }
}

// Конструктор копирования
String::String(const String& other) {
    length = other.length;
    str = new char[length + 1];
#ifdef _WIN32
    strcpy_s(str, length + 1, other.str);
#else
    strcpy(str, other.str);
#endif
    cout << "Создана копия строки: \"" << str << "\"" << endl;
}

// Деструктор
String::~String() {
    cout << "Удалена строка: \"" << str << "\"" << endl;
    delete[] str;
}

// Ввод строки с клавиатуры
void String::inputFromKeyboard() {
    cout << "Введите строку: ";
    cin.getline(str, length + 1);
    // Обновляем длину после ввода
    length = static_cast<int>(strlen(str));  // Явное преобразование size_t -> int
    cout << "Строка успешно введена" << endl;
}

// Вывод строки на экран
void String::display() const {
    cout << "Строка: \"" << str << "\", Длина: " << length << endl;
}

// Получение строки
const char* String::getString() const {
    return str;
}

// Получение длины
int String::getLength() const {
    return length;
}