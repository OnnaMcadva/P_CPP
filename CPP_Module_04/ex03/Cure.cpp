#include "Cure.hpp"
#include "ICharacter.hpp"

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
