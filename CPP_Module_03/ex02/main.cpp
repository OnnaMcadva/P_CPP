#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag("\033[35mFraggy\033[0m");
    frag.attack("\033[34mMonster\033[0m");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- Testing FragTrap Copy ---" << std::endl;
    FragTrap fragCopy = frag;
    fragCopy.attack("\033[31mAnother Monster\033[0m");

    return 0;
}
