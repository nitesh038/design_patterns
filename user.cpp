#include "logger.hpp"

int main()
{
    /* Logger* logger1 = new Logger();
    logger1->log("This message is from User 1");

    Logger* logger2 = new Logger();
    logger1->log("This message is from User 2"); */

    Logger* logger1 = Logger::get_logger_instance();
    logger1->log("This message is from User 1");

    Logger* logger2 = Logger::get_logger_instance();
    logger1->log("This message is from User 2");


    return 0;
}