#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "\033[32mDog created\033[0m" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
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
