#ifndef DIVISION_BY_ZERO_EXCEPTION_H
#define DIVISION_BY_ZERO_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

// Собственное исключение, унаследованное от std::exception
class DivisionByZeroException : public exception {
private:
    string message;

public:
    DivisionByZeroException(const string& msg = "Ошибка: деление на ноль!");

    // Переопределяем метод what()
    const char* what() const noexcept override;
};

#endif