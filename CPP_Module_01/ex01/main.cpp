
#include "Zombie.hpp"

int main() {
    int N = 7;
    std::string name = "myLittleZomby";

    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    for (int i = 0; i < N; ++i) {
        horde[i].~Zombie();
    }
    operator delete[](horde);

    return 0;
}
