#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure() : AMateria("cure") {}
    virtual ~Cure() {}

    AMateria* clone() const {
        return new Cure();
    }

    void use(ICharacter& target);
};
