#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h" // Include this for color sinks

class Logger {
public:
    Logger();
    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    
private:
    std::shared_ptr<spdlog::logger> console_logger;
    std::shared_ptr<spdlog::logger> file_logger;
};

#endif // LOGGER_H
