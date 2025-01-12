#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    type = "Cat";
    std::cout << "\033[32mCat created\033[0m" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "\033[31mCat destroyed\033[0m" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "\033[32mMeow! Meow!\033[0m" << std::endl;
}
