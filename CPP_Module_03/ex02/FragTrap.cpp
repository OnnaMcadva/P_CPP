#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "FragTrap " << m_name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << m_name << " copied!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << m_name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (m_hitPoints > 0 && m_energyPoints > 0) {
        std::cout << "FragTrap " << m_name << " attacks " << target
                  << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    } else {
        std::cout << "FragTrap " << m_name
                  << " cannot attack due to insufficient energy or health!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << m_name << " is requesting a high five!" << std::endl;
}
