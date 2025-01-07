#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Monster");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- Testing FragTrap Copy ---" << std::endl;
    FragTrap fragCopy = frag;
    fragCopy.attack("Another Monster");

    return 0;
}
