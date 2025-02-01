#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : m_name(name) {}

Zombie::~Zombie() {
    std::cout << "\033[32m" << m_name << " is destroyed\033[0m\n";
}

void Zombie::announce(void) {
    std::cout << "\033[35m" << m_name << ": BraiiiiiiinnnzzzZ...\033[0m\n";
}

