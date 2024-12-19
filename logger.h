#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h" // Включите этот заголовок для цветных логгеров

class Logger {
public:
    Logger(); // Конструктор класса Logger
    void logInfo(const std::string& message);    // Метод для логирования информационных сообщений
    void logWarning(const std::string& message); // Метод для логирования предупреждений
    void logError(const std::string& message);   // Метод для логирования ошибок
    
private:
    std::shared_ptr<spdlog::logger> console_logger; // Логгер для консольного вывода
    std::shared_ptr<spdlog::logger> file_logger;    // Логгер для записи в файл
};

// Функция для вычисления площади прямоугольника
void calculateArea(Logger& logger);

#endif // LOGGER_H
