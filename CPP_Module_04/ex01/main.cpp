#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog; // Is destructor correct
    delete cat;

    std::cout << "\n--- Testing Animal Array ---\n";

    Animal* animals[4];
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
    dog1.setIdea(0, "Fetch the ball!");
    Dog dog2 = dog1;

    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "Chase the cat!");

    std::cout << "Dog1 idea after change: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea after change: " << dog2.getIdea(0) << std::endl;

    return 0;
}
