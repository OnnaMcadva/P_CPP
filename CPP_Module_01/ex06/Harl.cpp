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

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlFunction)();
    HarlFunction functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (size_t i = 0; i < 4; i++) {
        if (levels[i] == level) {
            for (size_t j = i; j < 4; j++) {
                (this->*functions[j])();
            }
            return;
        }
    }

    std::cout << VIOLET << "[ Probably complaining about insignificant problems ]" << DEF_COLOR << std::endl;
}
