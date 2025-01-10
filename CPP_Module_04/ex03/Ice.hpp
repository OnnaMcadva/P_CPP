#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice() : AMateria("ice") {}
    virtual ~Ice() {}

    AMateria* clone() const {
        return new Ice();
    }

    virtual void use(ICharacter& target);
};
