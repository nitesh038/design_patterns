#include<thread>
#include "logger.hpp"

void user1_logs()
{
    Logger* logger1 = Logger::get_logger_instance();
    logger1->log("This message is from User 1");
}

void user2_logs()
{
    Logger* logger2 = Logger::get_logger_instance();
    logger2->log("This message is from User 2");

}

int main()
{
    /* Logger* logger1 = new Logger();
    logger1->log("This message is from User 1");

    Logger* logger2 = new Logger();
    logger1->log("This message is from User 2"); */

    std::thread t1(user1_logs);
    std::thread t2(user2_logs);

    t1.join();
    t2.join();

    return 0;
}