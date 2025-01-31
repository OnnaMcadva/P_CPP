#include "Harl.hpp"

#define DEF_COLOR "\033[0;39m"
#define RED "\033[0;91m"
#define ORANGE "\033[38;5;214m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;92m"
#define BLUE "\033[0;94m"
#define INDIGO "\033[38;5;54m"
#define VIOLET "\033[38;5;129m"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << VIOLET << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my" << std::endl;
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!\n" << DEF_COLOR << std::endl;
}

void Harl::info() {
    std::cout << GREEN << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!\n" << DEF_COLOR << std::endl;
}

void Harl::warning() {
    std::cout << ORANGE << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month.\n" << DEF_COLOR << std::endl;
}

void Harl::error() {
    std::cout << RED << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now.\n" << DEF_COLOR << std::endl;
}

Harl::LogLevel Harl::getLogLevel(std::string level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return UNKNOWN;
}

void Harl::complain(std::string level) {
    LogLevel logLevel = getLogLevel(level);

    switch (logLevel) {
        case DEBUG:
            debug();
            // fallthrough
        case INFO:
            info();
            // fallthrough
        case WARNING:
            warning();
            // fallthrough
        case ERROR:
            error();
            break;
        default:
            std::cout << VIOLET << "[ Probably complaining about insignificant problems ]" << DEF_COLOR << std::endl;
            break;
    }
}