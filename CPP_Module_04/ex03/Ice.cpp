#include "Ice.hpp"
#include "ICharacter.hpp"

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
