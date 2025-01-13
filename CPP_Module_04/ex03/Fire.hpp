#pragma once
#include "AMateria.hpp"

class Fire : public AMateria {
public:
    Fire() : AMateria("fire") {}
    virtual ~Fire() {}

    AMateria* clone() const {
        return new Fire();
    }

    virtual void use(ICharacter& target);
};
