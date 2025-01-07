#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n--- Testing ScavTrap Copy ---" << std::endl;
    ScavTrap scavCopy = scav;
    scavCopy.attack("Another Enemy");

    return 0;
}
