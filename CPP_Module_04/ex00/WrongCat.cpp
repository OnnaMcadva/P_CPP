#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "\033[35mWrongCat\033[0m";
    std::cout << "\033[35mWrongCat\033[0m created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "\033[35mWrongCat\033[0m copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "\033[35mWrongCat\033[0m assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "\033[35mWrongCat\033[0m destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow? But wrong!" << std::endl;
}
