#pragma once

#include "AAnimal.hpp"

class Dog : public AAnimal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void makeSound() const;
};
