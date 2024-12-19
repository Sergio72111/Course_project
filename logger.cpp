// #include "Logger.h"
// #include <iostream>
// #include <cctype> // Для функции isalpha

// // Конструктор класса Logger
// Logger::Logger() {
//     // Создание консольного логгера
//     console_logger = spdlog::stdout_color_mt("console_logger");
    
//     // Создание файлового логгера
//     auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
//     file_logger = std::make_shared<spdlog::logger>("file_logger", file_sink);

//     // Установка глобального уровня логирования на предупреждение
//     spdlog::set_level(spdlog::level::warn);
// }

// void Logger::logInfo(const std::string& message) {
//     console_logger->info(message);  // Логирование информационного сообщения в консоль
//     file_logger->info(message);      // Логирование информационного сообщения в файл
// }

// void Logger::logWarning(const std::string& message) {
//     console_logger->warn(message);   // Логирование предупреждения в консоль
//     file_logger->warn(message);       // Логирование предупреждения в файл
// }

// void Logger::logError(const std::string& message) {
//     console_logger->error(message);   // Логирование ошибки в консоль
//     file_logger->error(message);       // Логирование ошибки в файл
// }

// // Функция для проверки наличия русских символов в строке
// bool containsRussianCharacters(const std::string& str) {
//     for (char c : str) {
//         if ((unsigned char)c >= 192 && (unsigned char)c <= 255) { // Диапазон кириллицы в кодировке UTF-8
//             return true;
//         }
//     }
//     return false;
// }

// // Реализация функции для вычисления площади прямоугольника
// void calculateArea(Logger& logger) {
//     double width, length;

//     std::cout << "Введите ширину прямоугольника: ";
    
//     std::string widthInput;
//     std::getline(std::cin, widthInput);

//     if (containsRussianCharacters(widthInput)) {
//         logger.logError("Ошибка: введена ширина с русскими символами: " + widthInput);
//         std::cout << "Ошибка: введена ширина с русскими символами. Программа завершена." << std::endl;
//         exit(EXIT_FAILURE); // Завершение программы при вводе русских символов
//     }

//     try {
//         width = std::stod(widthInput);
//     } catch (const std::invalid_argument&) {
//         logger.logError("Некорректный ввод ширины: " + widthInput);
//         std::cout << "Некорректный ввод ширины." << std::endl;
//         return;
//     }

//     logger.logInfo("Пользователь ввел ширину: " + std::to_string(width));

//     std::cout << "Введите длину прямоугольника: ";
    
//     std::string lengthInput;
//     std::getline(std::cin, lengthInput);

//     if (containsRussianCharacters(lengthInput)) {
//         logger.logError("Ошибка: введена длина с русскими символами: " + lengthInput);
//         std::cout << "Ошибка: введена длина с русскими символами. Программа завершена." << std::endl;
//         exit(EXIT_FAILURE); // Завершение программы при вводе русских символов
//     }

//     try {
//         length = std::stod(lengthInput);
//     } catch (const std::invalid_argument&) {
//         logger.logError("Некорректный ввод длины: " + lengthInput);
//         std::cout << "Некорректный ввод длины." << std::endl;
//         return;
//     }

//     logger.logInfo("Пользователь ввел длину: " + std::to_string(length));

//     // Проверка на корректность ввода
//     if (width <= 0 || length <= 0) {
//         logger.logError("Ширина и длина должны быть положительными числами. Введенные значения - ширина: " + widthInput + ", длина: " + lengthInput);
//         std::cout << "Ошибка: Ширина и длина должны быть положительными числами." << std::endl;
//         return;
//     }

//     double area = width * length; // Вычисление площади

//     logger.logInfo("Выполнено умножение: " + std::to_string(width) + " * " + std::to_string(length) + " = " + std::to_string(area));
    
//     logger.logInfo("Вычислена площадь прямоугольника: " + std::to_string(area));
    
//     std::cout << "Площадь прямоугольника: " << area << std::endl;
// }



#include "Logger.h"
#include <iostream>
#include <cctype> // Для функции isalpha

// Конструктор класса Logger
Logger::Logger() {
    // Создание консольного логгера
    console_logger = spdlog::stdout_color_mt("console_logger");
    
    // Создание файлового логгера
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
    file_logger = std::make_shared<spdlog::logger>("file_logger", file_sink);

    // Установка глобального уровня логирования на предупреждение
    spdlog::set_level(spdlog::level::trace); // Устанавливаем уровень на trace для полного логирования
}

void Logger::logInfo(const std::string& message) {
    console_logger->info(message);  // Логирование информационного сообщения в консоль
    file_logger->info(message);      // Логирование информационного сообщения в файл
}

void Logger::logWarning(const std::string& message) {
    console_logger->warn(message);   // Логирование предупреждения в консоль
    file_logger->warn(message);       // Логирование предупреждения в файл
}

void Logger::logError(const std::string& message) {
    console_logger->error(message);   // Логирование ошибки в консоль
    file_logger->error(message);       // Логирование ошибки в файл
}

// Функция для проверки наличия русских символов в строке
bool containsRussianCharacters(const std::string& str) {
    for (char c : str) {
        if ((unsigned char)c >= 192 && (unsigned char)c <= 255) { // Диапазон кириллицы в кодировке UTF-8
            return true;
        }
    }
    return false;
}

// Реализация функции для вычисления площади прямоугольника
void calculateArea(Logger& logger) {
    double width, length;

    logger.logInfo("Запрос ширины прямоугольника.");
    std::cout << "Введите ширину прямоугольника: ";
    
    std::string widthInput;
    std::getline(std::cin, widthInput);

    if (containsRussianCharacters(widthInput)) {
        logger.logError("Ошибка: введена ширина с русскими символами: " + widthInput);
        std::cout << "Ошибка: введена ширина с русскими символами. Программа завершена." << std::endl;
        exit(EXIT_FAILURE); // Завершение программы при вводе русских символов
    }

    try {
        width = std::stod(widthInput);
    } catch (const std::invalid_argument&) {
        logger.logError("Некорректный ввод ширины: " + widthInput);
        std::cout << "Некорректный ввод ширины." << std::endl;
        return;
    }

    logger.logInfo("Пользователь ввел ширину: " + std::to_string(width));

    logger.logInfo("Запрос длины прямоугольника.");
    std::cout << "Введите длину прямоугольника: ";
    
    std::string lengthInput;
    std::getline(std::cin, lengthInput);

    if (containsRussianCharacters(lengthInput)) {
        logger.logError("Ошибка: введена длина с русскими символами: " + lengthInput);
        std::cout << "Ошибка: введена длина с русскими символами. Программа завершена." << std::endl;
        exit(EXIT_FAILURE); // Завершение программы при вводе русских символов
    }

    try {
        length = std::stod(lengthInput);
    } catch (const std::invalid_argument&) {
        logger.logError("Некорректный ввод длины: " + lengthInput);
        std::cout << "Некорректный ввод длины." << std::endl;
        return;
    }

    logger.logInfo("Пользователь ввел длину: " + std::to_string(length));

    if (width <= 0 || length <= 0) {
        logger.logError("Ширина и длина должны быть положительными числами. Введенные значения - ширина: " + widthInput + ", длина: " + lengthInput);
        std::cout << "Ошибка: Ширина и длина должны быть положительными числами." << std::endl;
        return;
    }

    double area = width * length; // Вычисление площади

    logger.logInfo("Выполнено умножение: " + std::to_string(width) + " * " + std::to_string(length) + " = " + std::to_string(area));
    
    logger.logInfo("Вычислена площадь прямоугольника: " + std::to_string(area));
    
    std::cout << "Площадь прямоугольника: " << area << std::endl;
}
