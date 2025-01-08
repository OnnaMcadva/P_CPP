# include "ClapTrap.hpp"
# include <sstream>

int main() {

    ClapTrap clap1("\033[32mClappy\033[0m");
    ClapTrap clap2("\033[33mTrappy\033[0m");

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
    ClapTrap noEnergy("\033[34mNoEnergy\033[0m");
    for (int i = 0; i < 11; i++) {
        std::stringstream ss;
        ss << "\033[36mDummy Target\033[0m " << (i + 1);
        noEnergy.attack(ss.str());
    }
    noEnergy.beRepaired(10);

    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap clapCopy(clap1);
    clapCopy.attack("Copied Target");

    std::cout << "\n--- Testing Exhausted ClapTrap ---" << std::endl;
    ClapTrap exhausted("\033[35mExhausted\033[0m");
    exhausted.takeDamage(10);
    exhausted.attack("Nobody");
    exhausted.beRepaired(5);

    return 0;
}
