#ifndef logger_hpp
#define logger_hpp

#include <iostream>
#include <string>
#include <mutex>

class Logger
{
    private:
        static int count_logger_instance;
        //third point to remember
        //this is the single instance that is going to be used by all users
        static Logger* logger_instance;
        //fourth point to remember
        //to make Singleton thread-safe
        //Since we also have to use in static function
        //it has to be static
        static std::mutex mtx;
        // first point to remember
        // making constructor private
        Logger(); 
        // sixth point to remember
        // Making Copy Constructor and Assignment Operator not
        // available to be called
        Logger(const Logger&);
        Logger operator=(const Logger &);
        //seventh point to remember
        // From C++11 onwards we have a keyword as "delete"
        // using which we can avoid declaring Logger constructors and assignment operator 
        // in private and just use "delete" keyword , keeping it in public also

    public:
        // second point to remember 
        // belongs to class itself not to particular instance of class
        // we need this as we need one instance of logger class
        static Logger* get_logger_instance(); 
        void log(std::string msg);

};

#endif /* logger_hpp */
