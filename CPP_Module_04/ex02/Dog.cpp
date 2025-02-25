#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    type = "Dog";
    std::cout << "\033[33mDog created\033[0m" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "\033[31mDog destroyed\033[0m" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "\033[33mWoof! Woof!\033[0m" << std::endl;
}
