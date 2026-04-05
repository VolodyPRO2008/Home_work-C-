#include "Logger.h"
#include <iostream>
#include <fstream>

namespace Logger {
    void log(LogLevel level, const std::string& message) {
        switch (level) {
        case LogLevel::INFO:
            std::cout << "[INFO] " << message << std::endl;
            break;
        case LogLevel::WARNING:
            std::cout << "[WARNING] " << message << std::endl;
            break;
        case LogLevel::ERROR:
            std::cout << "[ERROR] " << message << std::endl;
            break;
        }
    }

    namespace FileLogger {
        void logToFile(const std::string& filename, const std::string& message) {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << message << std::endl;
                file.close();
            }
            else {
                std::cout << "[ОШИБКА] Не удалось открыть файл: " << filename << std::endl;
            }
        }
    }
}