#include "logger.hpp"

Logger* Logger::instance = nullptr;

Logger::Logger() {
    logFile.open("logfile.log", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Logger initialized...\n";
    }
}

Logger::~Logger() {
    delete instance;
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const std::string& message, LogLevel level, OutputDestination dest) {
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        logFile << std::put_time(std::localtime(&now_c), "%Y-%m-%d %X %p ");

        switch (level) {
            case LogLevel::INFO: logFile << "[INFO] "; break;
            case LogLevel::WARNING: logFile << "[WARNING] "; break;
            case LogLevel::CRITICAL: logFile << "[CRITICAL] "; break;
            default : break;
        }
        if(dest == OutputDestination::CONSOLE_ONLY || dest == OutputDestination::BOTH){
            std::cout << message << std::endl;
        }
        logFile << message << std::endl;

    }
    else {
        std::cerr << "Logger error: " << message << std::endl;
    }
}