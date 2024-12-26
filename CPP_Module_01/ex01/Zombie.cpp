#include "Zombie.hpp"

#define DEF_COLOR "\033[0;39m"
#define RED "\033[0;91m"
#define ORANGE "\033[38;5;214m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;92m"
#define BLUE "\033[0;94m"
#define INDIGO "\033[38;5;54m"
#define VIOLET "\033[38;5;129m"

Zombie::Zombie() : name("") {
    std::cout << "Zombie created!" << std::endl;
}

Zombie::Zombie(std::string newName) : name(newName) {
    std::cout << "Zombie " << name << " created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed!" << std::endl;
}

void Zombie::setName(std::string newName) {
    name = newName;
}

void Zombie::announce() const {
    std::cout << getColor() << name << ": BraiiiiiiinnnzzZ..." << DEF_COLOR << std::endl;
}

std::string Zombie::getColor() const {
    if (name.find("#1") != std::string::npos) {
        return RED;
    } else if (name.find("#2") != std::string::npos) {
        return ORANGE;
    } else if (name.find("#3") != std::string::npos) {
        return YELLOW;
    } else if (name.find("#4") != std::string::npos) {
        return GREEN;
    } else if (name.find("#5") != std::string::npos) {
        return BLUE;
    } else if (name.find("#6") != std::string::npos) {
        return INDIGO;
    }else if (name.find("#7") != std::string::npos) {
        return VIOLET;
    }
    return DEF_COLOR;
}
