#include "Zombie.hpp"

extern Zombie* newZombie(std::string name);
extern void randomChump(std::string name);

int main() {
    Zombie* zombie1 = newZombie("Foo");
    zombie1->announce();
    delete zombie1;

    randomChump("Bar");

    return 0;
}
