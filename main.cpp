#include <iostream>
#include "logger.h"

int main() {
    try {
        auto logger = Logger::initLogger();
        spdlog::set_default_logger(logger);

        // Пример логирования
        spdlog::info("This is an info message.");
        spdlog::error("This is an error message.");
        spdlog::warn("This is a warning message.");
        spdlog::debug("This is a debug message (won't appear due to current level setting).\n");

        // Уведомление о завершении
        spdlog::info("Application finished successfully.");
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

