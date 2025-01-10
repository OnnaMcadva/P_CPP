#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "\033[35mAnimal created\033[0m" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "\033[31mAnimal destroyed\033[0m" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a generic sound" << std::endl;
}
