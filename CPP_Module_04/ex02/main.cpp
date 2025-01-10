#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Polymorphism
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n--- Testing Animal Array ---\n";

    AAnimal* animals[4];
    for (int i = 0; i < 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Testing Deep Copy ---\n";

    Dog dog1;
    dog1.makeSound();
    Dog dog2 = dog1;

    return 0;
}
