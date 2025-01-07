#include "DiamondTrap.hpp"

int main() {
    std::cout << "--- Testing DiamondTrap ---" << std::endl;

    DiamondTrap diamond("Diamond");

    diamond.attack("Enemy");

    diamond.whoAmI();

    diamond.takeDamage(30);
    diamond.beRepaired(10);

    DiamondTrap diamondCopy = diamond;
    diamondCopy.attack("Another Enemy");

    return 0;
}
