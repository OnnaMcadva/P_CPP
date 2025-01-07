#include "ClapTrap.hpp"
#include <sstream>

int main() {

    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    std::cout << "\n--- Testing Attack ---" << std::endl;
    clap1.attack("Target 1");
    clap1.attack("Target 2");

    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    clap2.takeDamage(5);
    clap2.takeDamage(7);
    clap2.takeDamage(1);

    std::cout << "\n--- Testing Repair ---" << std::endl;
    clap1.beRepaired(5);
    clap1.beRepaired(15);
    clap2.beRepaired(5);

    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    ClapTrap noEnergy("NoEnergy");
    for (int i = 0; i < 11; i++) {
        std::stringstream ss;
        ss << "Dummy Target " << (i + 1);
        noEnergy.attack(ss.str());
    }
    noEnergy.beRepaired(10);

    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap clapCopy(clap1);
    clapCopy.attack("Copied Target");

    std::cout << "\n--- Testing Exhausted ClapTrap ---" << std::endl;
    ClapTrap exhausted("Exhausted");
    exhausted.takeDamage(10);
    exhausted.attack("Nobody");
    exhausted.beRepaired(5);

    return 0;
}
