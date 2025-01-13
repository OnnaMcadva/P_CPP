#include "Fire.hpp"
#include "ICharacter.hpp"

    void Fire::use(ICharacter& target) {
        std::cout << "* shoots a fireball at " << target.getName() << " *" << std::endl;
    }