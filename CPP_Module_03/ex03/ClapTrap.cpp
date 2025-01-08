#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
    std::cout << "ClapTrap " << m_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : m_name(other.m_name), m_hitPoints(other.m_hitPoints),
    m_energyPoints(other.m_energyPoints), m_attackDamage(other.m_attackDamage) {
    std::cout << "ClapTrap " << m_name << " copied!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << m_name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (m_hitPoints <= 0) {
        std::cout << "ClapTrap " << m_name 
        << " cannot attack because it has no hit points!" << std::endl;
        return;
    }
    if (m_energyPoints <= 0) {
        std::cout << "ClapTrap " << m_name
        << " cannot attack because it has no energy points!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << m_name << " attacks "
    << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
    m_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_hitPoints <= 0) {
        std::cout << "ClapTrap " << m_name
        << " has no hit points left to take damage!" << std::endl;
        return;
    }
    m_hitPoints = (amount >= m_hitPoints) ? 0 : (m_hitPoints - amount);
    std::cout << "ClapTrap " << m_name << " takes "
    << amount << " points of damage! Current HP: " << m_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_hitPoints <= 0) {
        std::cout << "ClapTrap " << m_name
        << " cannot repair itself because it has no hit points!" << std::endl;
        return;
    }
    if (m_energyPoints <= 0) {
        std::cout << "ClapTrap " << m_name
        << " cannot repair itself because it has no energy points!" << std::endl;
        return;
    }
    m_hitPoints += amount;
    m_energyPoints--;
    std::cout << "ClapTrap " << m_name << " repairs itself, gaining "
    << amount << " hit points! Current HP: " << m_hitPoints << std::endl;
}

// Реализация метода getName
std::string ClapTrap::getName() const {
    return m_name;
}
