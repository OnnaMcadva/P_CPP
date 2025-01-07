#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string m_name;
    unsigned int m_hitPoints;
    unsigned int m_energyPoints;
    unsigned int m_attackDamage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    virtual ~ClapTrap();
    
    std::string getName() const {
        return m_name;
    }

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
