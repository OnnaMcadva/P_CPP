#include "Zombie.hpp"

Zombie::Zombie() {
    _name = "Unnamed";
}

Zombie::Zombie(std::string name) {
    _name = name;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed\n";
}

void Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
    _name = name;
}
