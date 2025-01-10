#pragma once

#include "AAnimal.hpp"

class Cat : public AAnimal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
};
