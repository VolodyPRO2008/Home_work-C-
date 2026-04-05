#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace Logger {
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    void log(LogLevel level, const std::string& message);

    namespace FileLogger {
        void logToFile(const std::string& filename, const std::string& message);
    }
}

#endif