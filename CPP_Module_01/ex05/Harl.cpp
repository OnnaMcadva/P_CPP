#include "Harl.hpp"

#define DEF_COLOR "\033[0;39m"
#define RED "\033[0;91m"
#define ORANGE "\033[38;5;214m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;92m"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << GREEN "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" DEF_COLOR << std::endl;
}

void Harl::info() {
    std::cout << YELLOW "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" DEF_COLOR << std::endl;
}

void Harl::warning() {
    std::cout << ORANGE "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." DEF_COLOR << std::endl;
}

void Harl::error() {
    std::cout << RED "[ERROR] This is unacceptable! I want to speak to the manager now." DEF_COLOR << std::endl;
}

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlMemFn)();
    HarlMemFn funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << DEF_COLOR "[UNKNOWN LEVEL] Harl does not understand this level!" DEF_COLOR << std::endl;
}
