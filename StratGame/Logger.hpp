#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>
#include <ctime>
#include <stdexcept>
#include <chrono>
#include <iostream>
#include <filesystem>

class Logger 
{
public:
    enum class Level 
    {
        INFO,
        WARNING,
        Error
    };

    static Logger& Get() 
    {
        static Logger instance;
        return instance;
    }

    class LogStream {
    public:
        LogStream(Logger& logger, Logger::Level level)
            : logger(logger), level(level) 
        {
        }

        template<typename T>
        LogStream& operator<<(const T& value) 
        {
            buffer << value;
            return *this;
        }

        ~LogStream() 
        {
            logger.write(level, buffer.str());
        }

    private:
        Logger& logger;
        Logger::Level level;
        std::ostringstream buffer;
    };

    LogStream Info() { return LogStream(*this, Level::INFO); }
    LogStream Warning() { return LogStream(*this, Level::WARNING); }
    LogStream Error() { return LogStream(*this, Level::Error); }

private:
    std::ofstream logfile;
    std::mutex mtx;
    std::string filename;

    Logger() {
        // Creating folder "logs", if not exists
        std::filesystem::path logDir("logs");
        if (!std::filesystem::exists(logDir)) 
        {
            std::filesystem::create_directory(logDir);
        }

        // Setting log file name
        filename = (logDir / "app.log").string();

        logfile.open(filename, std::ios::trunc);
        if (!logfile.is_open()) 
        {
            throw std::runtime_error("Nie mo¿na otworzyæ pliku logu: " + filename);
        }
    }

    ~Logger() 
    {
        logfile.close();
    }

    void write(Level level, const std::string& message) 
    {
        std::lock_guard<std::mutex> lock(mtx);
        logfile << "[" << timestamp() << "] "
                << "[" << levelToString(level) << "] "
                << message << std::endl;
    }

    static std::string levelToString(Level level) 
    {
        switch (level) 
        {
        case Level::INFO:    return "INFO";
        case Level::WARNING: return "WARN";
        case Level::Error:   return "ERROR";
        default:             return "UNKNOWN";
        }
    }

    static std::string timestamp() 
    {
        using namespace std::chrono;
        auto now = system_clock::now();
        std::time_t t = system_clock::to_time_t(now);
        std::tm tm_buf{};

#ifdef _WIN32
        localtime_s(&tm_buf, &t);
#else
        localtime_r(&t, &tm_buf);
#endif

        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_buf);
        return buf;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#define log Logger::Get()
#define LOG_FUNC() ("[" __FUNCTION__ "]")
