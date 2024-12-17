#include "logger.h"

std::shared_ptr<spdlog::logger> Logger::initLogger() {
    try {
        // Создание sink для логов в консоль
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::info);  // Уровень логирования для консоли

        // Создание sink для логов в файл
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("app.log", true);

        // Создание логгера с использованием нескольких sinks
        auto logger = std::make_shared<spdlog::logger>("multi_sink", spdlog::sinks_init_list{console_sink, file_sink});
        logger->set_level(spdlog::level::trace); // Общий уровень логгера

        // Установка уровней для каждого sink отдельно
        logger->sinks()[0]->set_level(spdlog::level::info);  // Консоль
        logger->sinks()[1]->set_level(spdlog::level::err);   // Файл

        return logger;
    } catch (const spdlog::spdlog_ex& ex) {
        throw std::runtime_error(std::string("Log initialization failed: ") + ex.what());
    }
}
