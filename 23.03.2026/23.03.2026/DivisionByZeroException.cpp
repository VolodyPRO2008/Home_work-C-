#define _CRT_SECURE_NO_WARNINGS

#include "DivisionByZeroException.h"

DivisionByZeroException::DivisionByZeroException(const string& msg)
    : message(msg) {
}

const char* DivisionByZeroException::what() const noexcept {
    return message.c_str();
}