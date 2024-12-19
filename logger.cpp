#include "Logger.h"

Logger::Logger() {
    // Create console logger
    console_logger = spdlog::stdout_color_mt("console_logger");
    
    // Create a file logger
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
    file_logger = std::make_shared<spdlog::logger>("file_logger", file_sink);

    // Set global log level to warn
    spdlog::set_level(spdlog::level::warn);
}

void Logger::logInfo(const std::string& message) {
    console_logger->info(message);
    file_logger->info(message);
}

void Logger::logWarning(const std::string& message) {
    console_logger->warn(message);
    file_logger->warn(message);
}

void Logger::logError(const std::string& message) {
    console_logger->error(message);
    file_logger->error(message);
}
