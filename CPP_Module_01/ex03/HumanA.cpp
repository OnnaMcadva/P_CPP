#include "HumanA.hpp"
#include <iostream>

#define GREEN "\033[0;92m"
#define RED "\033[0;91m"
#define DEF_COLOR "\033[0;39m"

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon) {}

void HumanA::attack() const {
    std::cout << GREEN << name << DEF_COLOR << " attacks with their " 
              << RED << weapon.getType() << DEF_COLOR << std::endl;
}
