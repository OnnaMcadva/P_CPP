#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// Используем виртуальное наследование от ClapTrap для FragTrap и ScavTrap
class DiamondTrap : public virtual FragTrap, public virtual ScavTrap {
private:
    std::string name;

public:
    DiamondTrap(const std::string &diamondName);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
