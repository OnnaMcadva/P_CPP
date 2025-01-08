#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &diamondName)
    : ClapTrap(diamondName + "_clap_name"),  // Явно передаем имя в ClapTrap
      FragTrap(diamondName),  // Передаем имя в FragTrap
      ScavTrap(diamondName),  // Передаем имя в ScavTrap
      name(diamondName) {     // Инициализация переменной name
    std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),  // Инициализация ClapTrap в конструкторе копирования
      FragTrap(other),   // Инициализация FragTrap в конструкторе копирования
      ScavTrap(other),   // Инициализация ScavTrap в конструкторе копирования
      name(other.name) { // Инициализация переменной name
    std::cout << "DiamondTrap " << this->name << " copied!" << std::endl;
}

// Деструктор
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

// Реализация метода атаки
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

// Реализация метода получения урона
void DiamondTrap::takeDamage(unsigned int amount) {
    FragTrap::takeDamage(amount);
}

// Реализация метода восстановления здоровья
void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}

// Реализация метода whoAmI
void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
