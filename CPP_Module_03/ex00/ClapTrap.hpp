#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string m_name;
    unsigned int m_hitPoints;
    unsigned int m_energyPoints;
    unsigned int m_attackDamage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif
