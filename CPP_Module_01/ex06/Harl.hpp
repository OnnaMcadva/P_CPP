#pragma once

#include <iostream>
#include <string>

class Harl {
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error();
    enum LogLevel { DEBUG, INFO, WARNING, ERROR, UNKNOWN };
    LogLevel getLogLevel(std::string level);
};