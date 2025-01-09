#include "DiamondTrap.hpp"

int main() {
    std::cout << "--- Testing DiamondTrap ---" << std::endl;

    DiamondTrap diamond("\033[34m💎 Diamond\033[0m");

    diamond.attack("\033[32mEnemy\033[0m");

    diamond.whoAmI();

    diamond.takeDamage(30);
    diamond.beRepaired(10);

    DiamondTrap diamondCopy = diamond;
    diamondCopy.attack("\033[33mAnother Enemy\033[0m");

    return 0;
}
