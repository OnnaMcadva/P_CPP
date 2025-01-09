#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap("\033[32mClappy\033[0m");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav("\033[33mScavvy\033[0m");
    scav.attack("\033[36mEnemy\033[0m");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n--- Testing ScavTrap Copy ---" << std::endl;
    ScavTrap scavCopy = scav;
    scavCopy.attack("\033[34mAnother Enemy\033[0m");

    return 0;
}
