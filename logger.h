#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

class Logger {
public:
    static std::shared_ptr<spdlog::logger> initLogger();
};

#endif // LOGGER_H



