#include "logger.hpp"

int Logger::count_logger_instance = 0;
Logger* Logger::logger_instance = nullptr;
//for thread-safety
std::mutex Logger::mtx;

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
    //fifth point to remember
    //"double check locking" , we don't need lock all the time
    //because once the instance is created we don't need lock at all
    //mutex are costly so we check again once before 
    if(logger_instance == nullptr)
    {
        mtx.lock();
        if(logger_instance == nullptr)
        {
            logger_instance = new Logger();
        }
        mtx.unlock();
    }
    return logger_instance;    
    
}