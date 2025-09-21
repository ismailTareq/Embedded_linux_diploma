#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>

enum class LogLevel {INFO, WARNING, CRITICAL};

enum class OutputDestination { FILE_ONLY, CONSOLE_ONLY, BOTH };


class Logger
{
private:
    static Logger *instance;
    std::ofstream logFile;
public:
    Logger();
    static Logger* getInstance();
    void log(const std::string& message, LogLevel level, OutputDestination dest = OutputDestination::FILE_ONLY);
    ~Logger();
};

#endif // LOGGER_HPP