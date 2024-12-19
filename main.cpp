// #include <iostream>
// #include "Logger.h"

// int main() {
//     Logger logger; // Создание объекта логгера

//     // Логирование заранее заданных сообщений
//     logger.logInfo("Welcome to spdlog!"); // Информационное сообщение
//     logger.logWarning("This is a warning message."); // Предупреждение
//     logger.logError("This is an error message."); // Ошибка

//     // Это информационное сообщение не будет показано из-за установленного уровня логирования
//     logger.logInfo("This info message will not be displayed.");

//     // Запрос ввода у пользователя для логирования
//     std::string userInput;
    
//     std::cout << "Введите сообщение для логирования (или 'exit' для выхода): ";

//     // Цикл для ввода сообщений пользователем
//     while (std::getline(std::cin, userInput)) {
//         if (userInput == "exit") {
//             logger.logInfo("Пользователь ввел команду 'exit'. Завершение программы.");
//             break; // Выход из цикла при вводе 'exit'
//         }
        
//         // Логирование введенного сообщения как информационного
//         logger.logInfo(userInput);
        
//         std::cout << "Введите следующее сообщение (или 'exit' для выхода): ";
//     }

//     // Вызов функции для вычисления площади прямоугольника
//     calculateArea(logger);

//     logger.logInfo("Программа завершена."); // Логируем завершение программы
//     return 0; // Завершение программы
// }







#include <iostream>
#include "Logger.h"

int main() {
    Logger logger; // Создание объекта логгера

    logger.logInfo("Запуск программы."); // Логируем запуск программы

    // Запрос ввода у пользователя для логирования
    std::string userInput;

    while (true) {
        std::cout << "Введите сообщение для логирования (или 'exit' для запроса ширины и длины): ";
        
        if (!std::getline(std::cin, userInput)) break; // Проверка на конец ввода

        if (userInput == "exit") {
            logger.logInfo("Пользователь ввел команду 'exit'. Запрос ширины и длины прямоугольника.");
            break; // Выход из цикла при вводе 'exit'
        }
        
        logger.logInfo(userInput); // Логируем введенное сообщение
    }

    // Запрос ширины и длины прямоугольника
    calculateArea(logger); // Вызов функции для вычисления площади прямоугольника

    logger.logInfo("Программа завершена."); // Логируем завершение программы

    return 0; // Завершение программы
}
