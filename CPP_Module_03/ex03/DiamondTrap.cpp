#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &diamondName)
    : FragTrap(diamondName + "_clap_name"), ScavTrap(diamondName + "_clap_name"),
    name(diamondName) {
    this->FragTrap::m_hitPoints = FragTrap::m_hitPoints;
    this->ScavTrap::m_energyPoints = ScavTrap::m_energyPoints;
    this->FragTrap::m_attackDamage = FragTrap::m_attackDamage;
    std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap " << this->name << " copied!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << FragTrap::getName() << std::endl;
}
