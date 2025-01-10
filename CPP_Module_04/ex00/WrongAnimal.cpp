#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "\033[34mWrongAnimal created\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "WrongAnimal assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "\033[31mWrongAnimal destroyed\033[0m" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}
