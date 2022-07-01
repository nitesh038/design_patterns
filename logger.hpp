#ifndef logger_hpp
#define logger_hpp

#include <iostream>
#include <string>

class Logger
{
    private:
        static int count_logger_instance;
        //third point to remember
        //this is the single instance that is going to be used by all users
        static Logger* logger_instance;
        // first point to remember
        // making constructor private
        Logger(); 
    public:
        // second point to remember 
        // belongs to class itself not to particular instance of class
        // we need this as we need one instance of logger class
        static Logger* get_logger_instance(); 
        void log(std::string msg);

};

#endif /* logger_hpp */
