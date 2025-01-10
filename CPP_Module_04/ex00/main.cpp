#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    // std::cout << "\n--- Testing Copy and Assignment ---\n";

    // Dog dog1;
    // Dog dog2 = dog1;
    // Dog dog3;
    // dog3 = dog1;

    // std::cout << "\n--- Testing Array of Animals ---\n";

    // const Animal* animals[2] = { new Dog(), new Cat() };

    // for (int i = 0; i < 2; ++i) {
    //     animals[i]->makeSound();
    //     delete animals[i];
    // }

    std::cout << "\n--- Testing WrongAnimal and WrongCat ---\n";

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
