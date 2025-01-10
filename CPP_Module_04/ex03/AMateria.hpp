#pragma once
#include <string>
#include <iostream>

class ICharacter; // Forward declaration

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const &type_param) : type(type_param) {}
    virtual ~AMateria() {}

    std::string const &getType() const { return type; }

    virtual void use(ICharacter& target) {
        (void)target;
    }

    virtual AMateria* clone() const = 0;
};

