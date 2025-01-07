#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "ScavTrap " << m_name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << m_name << " copied!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << m_name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (m_hitPoints > 0 && m_energyPoints > 0) {
        std::cout << "ScavTrap " << m_name << " ferociously attacks " << target 
                  << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    } else {
        std::cout << "ScavTrap " << m_name
        << " cannot attack due to insufficient energy or health!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << m_name << " is now in Gate Keeper mode!" << std::endl;
}
