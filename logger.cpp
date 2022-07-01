#include "logger.hpp"

int Logger::count_logger_instance = 0;
Logger* Logger::logger_instance = nullptr;

Logger::Logger()
{
    count_logger_instance++ ; 
    std::cout << "New logger instance created. No. of instances = " << count_logger_instance << std::endl;
}

void Logger::log(std::string msg)
{
    std::cout << msg << std::endl;
}

Logger* Logger::get_logger_instance()
{
    if(logger_instance == nullptr)
    {
        logger_instance = new Logger();
    }
    return logger_instance;    

}