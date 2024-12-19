#include <iostream>
#include "Logger.h"

int main() {
    Logger logger;

    // Log messages with various severity levels
    logger.logInfo("Welcome to spdlog!");
    logger.logWarning("This is a warning message.");
    logger.logError("This is an error message.");

    // This info message will not be shown due to the global level setting
    logger.logInfo("This info message will not be displayed.");

    return 0;
}
