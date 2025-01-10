#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "\033[35mAAAAAnimal created\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "AAnimal assigned" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "\033[31mAAAAAnimal destroyed\033[0m" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}

// It’s true, they make no sound!
