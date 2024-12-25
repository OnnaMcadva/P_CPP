#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << "\033[32m" << _name << " is destroyed\033[0m\n";
}

void Zombie::announce(void) {
    std::cout << "\033[35m" << _name << ": BraiiiiiiinnnzzzZ...\033[0m\n";
}

