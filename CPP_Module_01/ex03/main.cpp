#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define DEF_COLOR "\033[0;39m"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        std::cout << BLUE << "Testing HumanA:" << DEF_COLOR << std::endl;
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        std::cout << MAGENTA << "Testing HumanB:" << DEF_COLOR << std::endl;
        jim.attack(); // Jim has no weapon
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}


/*Weapon как ссылка в HumanA:

    Ссылка используется, потому что HumanA всегда имеет оружие.
    Ссылка обязана быть инициализирована, а HumanA получает Weapon
    через конструктор.

Weapon как указатель в HumanB:

    Указатель используется, потому что HumanB может не иметь оружия.
    Указатель может быть установлен на nullptr для обозначения
    отсутствия оружия.*/