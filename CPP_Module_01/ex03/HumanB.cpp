#include "HumanB.hpp"
#include <iostream>

#define YELLOW "\033[0;93m"
#define CYAN "\033[0;96m"
#define DEF_COLOR "\033[0;39m"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << CYAN << name << DEF_COLOR << " attacks with their " 
                  << YELLOW << weapon->getType() << DEF_COLOR << std::endl;
    } else {
        std::cout << CYAN << name << DEF_COLOR << " has no weapon to attack with!" << std::endl;
    }
}
